/*
1142 Maximal Clique （25 分）
A clique is a subset of vertices of an undirected graph such that every two distinct vertices in the clique are adjacent. A maximal clique is a clique that cannot be extended by including one more adjacent vertex. (Quoted from https://en.wikipedia.org/wiki/Clique_(graph_theory))

Now it is your job to judge if a given subset of vertices can form a maximal clique.

Input Specification:
Each input file contains one test case. For each case, the first line gives two positive integers Nv (≤ 200), the number of vertices in the graph, and Ne, the number of undirected edges. Then Ne lines follow, each gives a pair of vertices of an edge. The vertices are numbered from 1 to Nv.

After the graph, there is another positive integer M (≤ 100). Then M lines of query follow, each first gives a positive number K (≤ Nv), then followed by a sequence of K distinct vertices. All the numbers in a line are separated by a space.

Output Specification:
For each of the M queries, print in a line Yes if the given subset of vertices can form a maximal clique; or if it is a clique but not a maximal clique, print Not Maximal; or if it is not a clique at all, print Not a Clique.

Sample Input:
8 10
5 6
7 8
6 4
3 6
4 5
2 3
8 2
2 7
5 3
3 4
6
4 5 4 3 6
3 2 8 7
2 2 3
1 1
3 4 3 6
3 3 2 1
Sample Output:
Yes
Yes
Yes
Yes
Not Maximal
Not a Clique
*/
/*
总结：
图论,总结特性格,遍历做
*/

#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cctype>
#include<queue>
using namespace std;

int graph[205][205];
vector<int> ve;

int main(){
#ifdef LOCAL 
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    fill(graph[0],graph[0]+205*205,0);
    int Nv,Ne; cin >> Nv >> Ne;
    for(int i = 0;i<Ne;i++){
        int first,end; cin >> first >> end;
        graph[first][end] = 1;
        graph[end][first] = 1;
    }
    //图建立完毕
    int K; cin >> K;
    for(int i = 0;i<K;i++){
        ve.clear();
        int number; cin >> number;
        for(int z = 0;z<number;z++){
            int temp; cin >> temp;
            ve.push_back(temp);
        }
        //将所有数字读入
        int if_cq = 0,if_maxcq = 0;
        for(int z = 0;z<ve.size();z++){
            for(int p = z+1;p<ve.size();p++){
                if(graph[ve[z]][ve[p]] == 0){if_cq = 1;} //如果中间有个没连通的，意味不是cq
            }
        }

        if(if_cq == 1){printf("Not a Clique\n");}
        //如果是cq的话，判断是否是最大cq
        else{
            for(int z = 0;z<205;z++){
                int flag = 0;
                for(int q = 0;q<ve.size();q++){
                    if(graph[z][ve[q]] == 0){flag = 1;break;}
                }
                if(flag == 0){if_maxcq = 1;break;}
            }
            if(if_maxcq == 1){printf("Not Maximal\n");}
            else{printf("Yes\n");}
        }
    }

    return 0;
    
}