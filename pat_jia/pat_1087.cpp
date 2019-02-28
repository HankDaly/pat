/*
1087 All Roads Lead to Rome （30 分）
Indeed there are many different tourist routes from our city to Rome. You are supposed to find your clients the route with the least cost while gaining the most happiness.

Input Specification:
Each input file contains one test case. For each case, the first line contains 2 positive integers N (2≤N≤200), the number of cities, and K, the total number of routes between pairs of cities; followed by the name of the starting city. The next N−1 lines each gives the name of a city and an integer that represents the happiness one can gain from that city, except the starting city. Then K lines follow, each describes a route between two cities in the format City1 City2 Cost. Here the name of a city is a string of 3 capital English letters, and the destination is always ROM which represents Rome.

Output Specification:
For each test case, we are supposed to find the route with the least cost. If such a route is not unique, the one with the maximum happiness will be recommanded. If such a route is still not unique, then we output the one with the maximum average happiness -- it is guaranteed by the judge that such a solution exists and is unique.

Hence in the first line of output, you must print 4 numbers: the number of different routes with the least cost, the cost, the happiness, and the average happiness (take the integer part only) of the recommanded route. Then in the next line, you are supposed to print the route in the format City1->City2->...->ROM.

Sample Input:
6 7 HZH
ROM 100
PKN 40
GDN 55
PRS 95
BLN 80
ROM GDN 1
BLN ROM 1
HZH PKN 1
PRS ROM 2
BLN HZH 2
PKN GDN 1
HZH PRS 1
Sample Output:
3 3 195 97
HZH->PRS->ROM
*/
/*
总结：
DJ加DFS解决,注意DFS中的length在同一层遍历中不要改变
*/

#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<unordered_map>

using namespace std;

unordered_map<string,int> mp;
int graph[205][205];
int happnes[205];
string ch_name[205];
int least;

//Dj数组准备
const int maxnu = 999999;
int path[205]; //储存节点
int hap[205]; //储存幸福值
int length[205]; //储存长度
int collect[205]; //是否访问
vector<int> ve_path;

void find_path(int index){
    if(index != 1){
        ve_path.push_back(index);   
        index = path[index];
        find_path(index);
    }
    else{return;}
}

//DFS
int lab[205];

void DFS(int length,int &cnt,int index){
    lab[index] = 1;
    for(int i = 1;i<205;i++){
        //如果有路并且未收录
        if(graph[index][i] > 0 && lab[i] == 0){
            //如果就是罗马
            if(ch_name[i] == "ROM"){
                length += graph[index][i];
                if(least == length){cnt++;}
            }
            //如果不是
            else{
                DFS(length+graph[index][i],cnt,i);
                lab[i] = 0;
            }
        }
    }
    
}

int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    fill(lab,lab+205,0);
    fill(graph[0],graph[0] + 205*205,0);
    fill(happnes,happnes+205,0);
    int N,K; scanf("%d%d",&N,&K);
    string first; cin >> first; mp[first] = 1; ch_name[1] = first; //定义起始点下标为1
    for(int i = 2;i<=N;i++){
        string temp; cin >> temp;
        int h; cin >> h;
        mp[temp] = i; happnes[i] = h; //记录hash映射和幸福值
        ch_name[i] = temp;
    }
    for(int i = 0;i<K;i++){
        string st,end; cin >> st >> end;
        int length; cin >> length;
        int st_nu = mp[st],end_nu = mp[end]; 
        graph[st_nu][end_nu] = length;
        graph[end_nu][st_nu] = length;
    }
    //准备完毕
    //DJ
    fill(path,path+205,0);
    fill(hap,hap+205,-1); //幸福一开始是负，后面变高
    fill(length,length+205,maxnu);
    fill(collect,collect+205,0);
    collect[1] = 1; length[1] = 0;
    for(int i = 1;i<205;i++){
        if(graph[1][i] > 0){
            length[i] = graph[1][i];
            hap[i] = happnes[i];
            path[i] = 1;
        }
    }
    //Dj准备完毕
    while(1){
        //遍历找未被标记的最小length节点
        int flag = 0,min_index = 0,min_length = maxnu;
        for(int i = 1;i<=N;i++){
            if(collect[i] == 0 && length[i] < min_length){
                flag = 1; min_index = i; min_length = length[i];
            }
        }
        if(flag == 0){break;}
        collect[min_index] = 1; //收录
        //遍历这个节点的邻接节点，更新信息,目前的头index是:min_index
        for(int i = 1;i<205;i++){
            if(graph[min_index][i] > 0){
                if(length[min_index]+graph[min_index][i] < length[i]){
                    length[i] = length[min_index]+graph[min_index][i]; //更新长度
                    hap[i] = hap[min_index]+happnes[i]; //更新幸福度
                    path[i] = min_index; //更新节点
                }
                else if(length[min_index]+graph[min_index][i] == length[i] && hap[min_index]+happnes[i]>hap[i]){
                    hap[i] = hap[min_index] + happnes[i]; //更新幸福度
                    path[i] = min_index; //更新节点
                }
            }
        }
    }
    least = length[mp["ROM"]];
    //Dj结束
    //DFS找重复最短路
    int cnt = 0;
    DFS(0,cnt,1);
    //打印
    find_path(path[mp["ROM"]]);
    reverse(ve_path.begin(),ve_path.end());
    int allpath = ve_path.size()+1;
    cout << cnt << " " << least << " " << hap[mp["ROM"]] << " " << hap[mp["ROM"]]/allpath << "\n";
    cout << first;
    for(int i = 0;i<ve_path.size();i++){
        cout << "->";
        cout << ch_name[ve_path[i]];
    }
    cout << "->ROM";

    return 0;
}