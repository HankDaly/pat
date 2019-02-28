/*
1111 Online Map （30 分）
Input our current position and a destination, an online map can recommend several paths. Now your job is to recommend two paths to your user: one is the shortest, and the other is the fastest. It is guaranteed that a path exists for any request.

Input Specification:
Each input file contains one test case. For each case, the first line gives two positive integers N (2≤N≤500), and M, being the total number of streets intersections on a map, and the number of streets, respectively. Then M lines follow, each describes a street in the format:

V1 V2 one-way length time
where V1 and V2 are the indices (from 0 to N−1) of the two ends of the street; one-way is 1 if the street is one-way from V1 to V2, or 0 if not; length is the length of the street; and time is the time taken to pass the street.

Finally a pair of source and destination is given.

Output Specification:
For each case, first print the shortest path from the source to the destination with distance D in the format:

Distance = D: source -> v1 -> ... -> destination
Then in the next line print the fastest path with total time T:

Time = T: source -> w1 -> ... -> destination
In case the shortest path is not unique, output the fastest one among the shortest paths, which is guaranteed to be unique. In case the fastest path is not unique, output the one that passes through the fewest intersections, which is guaranteed to be unique.

In case the shortest and the fastest paths are identical, print them in one line in the format:

Distance = D; Time = T: source -> u1 -> ... -> destination
Sample Input 1:
10 15
0 1 0 1 1
8 0 0 1 1
4 8 1 1 1
3 4 0 3 2
3 9 1 4 1
0 6 0 1 1
7 5 1 2 1
8 5 1 2 1
2 3 0 2 2
2 1 1 1 1
1 3 0 3 1
1 4 0 1 1
9 7 1 3 1
5 1 0 5 2
6 5 1 1 2
3 5
Sample Output 1:
Distance = 6: 3 -> 4 -> 8 -> 5
Time = 3: 3 -> 1 -> 5
Sample Input 2:
7 9
0 4 1 1 1
1 6 1 1 3
2 6 1 1 1
2 5 1 2 2
3 0 0 1 1
3 1 1 1 3
3 2 1 1 2
4 5 0 2 2
6 5 1 1 2
3 5
Sample Output 2:
Distance = 3; Time = 4: 3 -> 2 -> 5

*/
/*
总结：单源最短路径，如果还有其他条件，放到dj算法中判断
*/

#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cctype>
#include<queue>
using namespace std;

const int maxnu = 9999999;

struct Node{
    int flag = -1;
    int length;
    int time;
};

Node graph[505][505]; //储存graph

int ch_collect[505];  //记录统计情况
int ch_path[505]; //记录路径节点
int ch_length[505]; //记录路径长度
int ch_time[505]; //记录时间
int time_node[505]; //记录时间的节点数量

vector<int> length_path;
vector<int> time_path;

void findpath(int end_node,int start_node){
    if(end_node != start_node){
        length_path.push_back(end_node);
        findpath(ch_path[end_node],start_node);
    }
}
void findtime(int end_node,int start_node){
    if(end_node != start_node){
        time_path.push_back(end_node);
        findtime(ch_path[end_node],start_node);
    }
}


int main(){
#ifdef LOCAL 
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif

    int distance,time;
    //初始化
    fill(ch_path,ch_path+505,0);
    fill(ch_collect,ch_collect+505,0);
    fill(ch_length,ch_length+505,maxnu);
    fill(ch_time,ch_time+505,maxnu);

    //储存图
    int N,M; cin >> N >> M;
    for(int i = 0;i<M;i++){
        int start,end; cin >> start >> end;
        Node node; cin >> node.flag >> node.length >> node.time;
        graph[start][end] = node;
        if(node.flag == 0){graph[end][start] = node;} //0意味双向
    }
    int start_node,end_node; cin >> start_node >> end_node;

    //路径Dj
    ch_length[start_node] = 0; ch_collect[start_node] = 1; ch_time[start_node] = 0;
    for(int i = 0;i<505;i++){
        if(graph[start_node][i].flag >= 0){
            ch_length[i] = graph[start_node][i].length;
            ch_path[i] = start_node;
            ch_time[i] = graph[start_node][i].time;
        }
    }
    //前期准备完毕，正式开始
    while(1){
        //找到未收录的最近点
        int index = -1;int min = maxnu;
        for(int i = 0;i<N;i++){
            if(ch_collect[i] == 0 && ch_length[i] < min){
                index = i;
                min = ch_length[i];
            }
        }
        if(index == -1){break;}
        ch_collect[index] = 1; //收录
        for(int i = 0;i<505;i++){
            //如果有邻接点并且未被收录
            if(graph[index][i].flag >= 0 && ch_collect[i] == 0){
                //如果路径可以变小
                if(min+graph[index][i].length < ch_length[i]){
                    ch_length[i] = min+graph[index][i].length; //更新长度
                    ch_time[i] = ch_time[index]+graph[index][i].time; //更新时间
                    ch_path[i] = index; //更新路径
                }
                //如果路径相等但是时间可以减少
                else if(min+graph[index][i].length == ch_length[i] && ch_time[index]+graph[index][i].time < ch_time[i]){
                    ch_time[i] = ch_time[index]+graph[index][i].time;//更新时间
                    ch_path[i] = index;//更新路径
                }
            }
        }
    }

    findpath(ch_path[end_node],start_node); // 路径解决完毕
    distance = ch_length[end_node];

    //初始化时间顺序
    fill(ch_path,ch_path+505,0); //节点
    fill(ch_collect,ch_collect+505,0); //收录
    fill(ch_time,ch_time+505,maxnu); //时间
    fill(time_node,time_node+505,0); //时间的节点数
    //时间Dj
    time_node[start_node] = 0; ch_collect[start_node] = 1; ch_time[start_node] = 0;
    for(int i = 0;i<505;i++){
        if(graph[start_node][i].flag >= 0){
            time_node[i] = 1;
            ch_path[i] = start_node;
            ch_time[i] = graph[start_node][i].time;
        }
    }
    //前期准备完毕，正式开始
    while(1){
        //找到未收录的最近点
        int index = -1;int min = maxnu;
        for(int i = 0;i<N;i++){
            if(ch_collect[i] == 0 && ch_time[i] < min){
                index = i;
                min = ch_time[i];
            }
        }
        if(index == -1){break;}
        ch_collect[index] = 1; //收录
        for(int i = 0;i<505;i++){
            //如果有邻接点并且未被收录
            if(graph[index][i].flag >= 0 && ch_collect[i] == 0){
                //如果时间可以变小
                if(min+graph[index][i].time < ch_time[i]){
                    time_node[i] = time_node[index]+1; //更新节点数量
                    ch_time[i] = ch_time[index]+graph[index][i].time; //更新时间
                    ch_path[i] = index; //更新路径
                }
                //如果时间相等但是路径可以减少
                else if(min+graph[index][i].time == ch_time[i] && time_node[index]+1< time_node[i]){
                    time_node[i] = time_node[index]+1;//更新节点数量
                    ch_path[i] = index; //更新节点
                }
            }
        }
    }

    findtime(ch_path[end_node],start_node); // 时间解决完毕
    time = ch_time[end_node];


    //
    reverse(length_path.begin(),length_path.end());
    reverse(time_path.begin(),time_path.end());
    if(time_path == length_path){
        cout << "Distance = " << distance << "; Time = " << time <<":";
        cout << " " << start_node;
        for(int i = 0;i<time_path.size();i++){
            cout << " -> " << time_path[i];
        }
        cout << " -> " << end_node;
    }

    else{
        cout << "Distance = " << distance << ":";
        cout << " " << start_node;
        for(int i = 0;i<length_path.size();i++){
            cout << " -> " << length_path[i];
        }
        cout << " -> " << end_node;
        cout << "\n";
        cout << "Time = " << time << ":";
        cout << " " << start_node;
        for(int i = 0;i<time_path.size();i++){
            cout << " -> " << time_path[i];
        }
        cout << " -> " << end_node;
    }
}