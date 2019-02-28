#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<unordered_map>

using namespace std;

unordered_map<int,int> line;
vector<vector<int>> graph(10000);
int Mincnt,Mintransfer; //最小停站和最小穿越数
vector<int> path,temp_path; //记录途径路径
int visit[10005];

void DFS(int index,int cnt,int end,int transfer,int perline){
    //如果找到end
    if(index == end){
        //如果总停靠小于或者（等于并且穿越次数小于之前）
        if(cnt < Mincnt || (cnt == Mincnt && transfer < Mintransfer)){
            Mincnt = cnt; //更新cnt 
            Mintransfer = transfer; //更新transfer 
            path = temp_path; //更新路径
        }
        return;
    }
    for(int i = 0;i<graph[index].size();i++){
        int number = graph[index][i];
        if(visit[number] == 0){
            //如果刚开始未定义的情况
            visit[number] = 1;
            if(perline == -1){perline = line[index*10000+number];}

            if(line[index*10000+number] == perline){
                temp_path.push_back(index);
                DFS(number,cnt+1,end,transfer,perline);
                visit[number] = 0;
                temp_path.pop_back();
            }
            else{
                temp_path.push_back(index);
                DFS(number,cnt+1,end,transfer+1,line[index*10000+number]);
                visit[number] = 0;
                temp_path.pop_back();
            }
        }
    }

}


int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    int N; cin >> N;
    for(int i = 0;i<N;i++){
        int M,pre; cin >> M >> pre;
        for(int z = 0;z<M-1;z++){
            int now; cin >> now;
            graph[pre].push_back(now); //分别储存邻接点
            graph[now].push_back(pre);
            line[pre*10000+now] = i+1; //记录这两个点之间的线路
            line[now*10000+pre] = i+1;
            pre = now; //更新前面的节点
        }

    }
    //图和线路建立完成
    int K; cin >> K;
    for(int i = 0;i<K;i++){
        fill(visit,visit+10005,0);
        Mincnt = 999999; Mintransfer = 999999;
        int start,end; cin >> start >> end;
        visit[start] = 1;
        DFS(start,0,end,0,-1);
        path.push_back(end);
        cout << Mincnt << "\n";
        int pre_line = 0;
        for(int i = 1;i<path.size();i++){
            int now_line = line[path[i-1]*10000+path[i]];
            if(pre_line == 0){
                cout << "Take Line#" << now_line << " from " << path[i-1] << " to " ; 
            }
            else if(pre_line != now_line){
                cout << path[i-1] << ".\nTake Line#" << now_line << " from " << path[i-1] << " to ";
            }
            pre_line = now_line;
        }
        cout << end << ".\n";

    }
    return 0;
}