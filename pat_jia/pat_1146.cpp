/*
1146 Topological Order （25 分）
This is a problem given in the Graduate Entrance Exam in 2018: Which of the following is NOT a topological order obtained from the given directed graph? Now you are supposed to write a program to test each of the options.

gre.jpg

Input Specification:
Each input file contains one test case. For each case, the first line gives two positive integers N (≤ 1,000), the number of vertices in the graph, and M (≤ 10,000), the number of directed edges. Then M lines follow, each gives the start and the end vertices of an edge. The vertices are numbered from 1 to N. After the graph, there is another positive integer K (≤ 100). Then K lines of query follow, each gives a permutation of all the vertices. All the numbers in a line are separated by a space.

Output Specification:
Print in a line all the indices of queries which correspond to "NOT a topological order". The indices start from zero. All the numbers are separated by a space, and there must no extra space at the beginning or the end of the line. It is graranteed that there is at least one answer.

Sample Input:
6 8
1 2
1 3
5 2
5 4
2 3
2 6
3 4
6 4
5
1 5 2 3 6 4
5 1 2 6 3 4
5 1 2 3 6 4
5 2 1 6 3 4
1 2 3 4 5 6
Sample Output:
3 4
*/
/*
总结：
拓扑排序题目，把握好当前能输出的只能是入度为0的即可.
注意读取的时候不要break，每排都要读完
*/

#include<iostream>
#include<cstdio>
#include<unordered_map>
#include<cctype>
#include<string>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cmath>
#include<stack>
#include<queue>
using namespace std;
int graph[1005][1005];
int in_degree[1005];
int out_degree[1005];
int time_in[1005];
int time_out[1005];
vector<int> ve;
int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    fill(graph[0],graph[0]+1005*1005,0);
    fill(in_degree,in_degree+1005,0);
    fill(out_degree,out_degree+1005,0);
    int N,M; cin >> N >> M;
    for(int i = 0;i<M;i++){
        int a,b; cin >> a >> b;
        graph[a][b] = 1;
        out_degree[a]++;
        in_degree[b]++;
    }
    //图以及入度出度建立完毕
    int K; cin >> K;
    for(int i = 0;i<K;i++){
        fill(time_in,time_in+1005,0);
        fill(time_out,time_out+1005,0);
        int flag = 0;
        for(int z = 0;z<N;z++){
            int number; cin >> number;
            int in_number = in_degree[number]-time_in[number]; //当前入度等于总入度减去及时入度
            //如果入度为0，代表可行
            if(in_number == 0){
                //将当前连到的入度都减去1
                for(int q = 0;q<1005;q++){
                    if(graph[number][q] != 0){
                        time_in[q]++;
                    }
                }
            }
            /*
            错误点1
            else{flag = 1;break;}
            不该break
            */
            else{flag = 1;}
        }
        if(flag == 1){ve.push_back(i);}
    }
    //打印
    for(int i = 0;i<ve.size();i++){
        if(i!=0){cout << " ";}
        cout << ve[i];
    }
    return 0;
} 
