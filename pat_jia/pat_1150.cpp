/*
1150 Travelling Salesman Problem （25 分）
The "travelling salesman problem" asks the following question: "Given a list of cities and the distances between each pair of cities, what is the shortest possible route that visits each city and returns to the origin city?" It is an NP-hard problem in combinatorial optimization, important in operations research and theoretical computer science. (Quoted from "https://en.wikipedia.org/wiki/Travelling_salesman_problem".)

In this problem, you are supposed to find, from a given list of cycles, the one that is the closest to the solution of a travelling salesman problem.

Input Specification:
Each input file contains one test case. For each case, the first line contains 2 positive integers N (2<N≤200), the number of cities, and M, the number of edges in an undirected graph. Then M lines follow, each describes an edge in the format City1 City2 Dist, where the cities are numbered from 1 to N and the distance Dist is positive and is no more than 100. The next line gives a positive integer K which is the number of paths, followed by K lines of paths, each in the format:

n C
​1
​​  C
​2
​​  ... C
​n
​​ 

where n is the number of cities in the list, and C
​i
​​ 's are the cities on a path.

Output Specification:
For each path, print in a line Path X: TotalDist (Description) where X is the index (starting from 1) of that path, TotalDist its total distance (if this distance does not exist, output NA instead), and Description is one of the following:

TS simple cycle if it is a simple cycle that visits every city;
TS cycle if it is a cycle that visits every city, but not a simple cycle;
Not a TS cycle if it is NOT a cycle that visits every city.
Finally print in a line Shortest Dist(X) = TotalDist where X is the index of the cycle that is the closest to the solution of a travelling salesman problem, and TotalDist is its total distance. It is guaranteed that such a solution is unique.

Sample Input:
6 10
6 2 1
3 4 1
1 5 1
2 5 1
3 1 8
4 1 6
1 6 1
6 3 1
1 2 1
4 5 1
7
7 5 1 4 3 6 2 5
7 6 1 3 4 5 2 6
6 5 1 4 3 6 2
9 6 2 1 6 3 4 5 2 6
4 1 2 5 1
7 6 1 2 5 4 3 1
7 6 3 2 5 4 1 6
Sample Output:
Path 1: 11 (TS simple cycle)
Path 2: 13 (TS simple cycle)
Path 3: 10 (Not a TS cycle)
Path 4: 8 (TS cycle)
Path 5: 3 (Not a TS cycle)
Path 6: 13 (Not a TS cycle)
Path 7: NA (Not a TS cycle)
Shortest Dist(4) = 8

*/
/*
总结
图论的题目，找规律
*/


#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cctype>
#include<queue>
using namespace std;

int graph[205][205];
int hs[205];

int main(){
#ifdef LOCAL 
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    fill(graph[0],graph[0]+205*205,0);
    int N,M; cin >> N >> M;
    for(int i = 0;i<M;i++){
        int start,end,length; cin >> start >> end >> length;
        graph[start][end] = length;
        graph[end][start] = length;
    }
    //储存完毕
    int K; cin >> K;
    int min_length = 999999;
    int min_index = 0;
    for(int i = 0;i<K;i++){
        int n; cin >> n;
        fill(hs,hs+205,0);
        int length = 0,intart_flag = 0; //intart_flag统计是否有断路
        int pre; cin >> pre; //取第一个作为起始点
        int first = pre;
        hs[pre] = 1;
        for(int z = 0;z<n-1;z++){
            int now; cin >> now;
            hs[now]++;
            //判断是否有连通
            if(graph[pre][now] > 0){
                length += graph[pre][now];
            }
            else{intart_flag = 1;}
            pre = now;
        }
        int noorigin = 0;
        if(first != pre){noorigin = 1;}
        int notall_go = 0,repeat = 0; //
        for(int i = 1;i<=N;i++){
            if(i != first && hs[i] > 1){repeat = 1;}
            if(hs[i] == 0){notall_go = 1;}
        }
        int change = 0;
        //打印
        //如果有断路
        if(intart_flag == 1){printf("Path %d: NA (Not a TS cycle)",i+1);change = 1;}
        //没断路但是没走完或每回原点
        else if(notall_go == 1 || noorigin == 1){printf("Path %d: %d (Not a TS cycle)",i+1,length);change = 1;}
        //符合但是有重复
        else if(repeat == 1){printf("Path %d: %d (TS cycle)",i+1,length);}
        else{printf("Path %d: %d (TS simple cycle)",i+1,length);}
        if(length < min_length && change == 0){min_length = length;min_index = i+1;}
        printf("\n");
    }
    printf("Shortest Dist(%d) = %d",min_index,min_length);
    

    return 0;
    
}