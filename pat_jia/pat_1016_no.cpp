#include<iostream>
#include<cstdio>
#include<unordered_map>
#include<cctype>
#include<string>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cmath>

using namespace std;
struct Node{
    string name;
    string time;
    string status;
};
vector<Node> ve;
bool cmp(Node a,Node b){
    if(a.name == b.name){return a.time < b.time;}
    else{return a.name < b.name;}
}
int ch[24];
int money(string a,string b,int& c){
    int sum = 0;
    int day_a,hour_a,minute_a;
    int day_b,hour_b,minute_b;
    day_a = (a[3]-'0')*10 + (a[4]-'0');
    hour_a = (a[6]-'0')*10 + (a[7]-'0');
    minute_a = (a[9]-'0')*10 + (a[10]-'0');
    day_b = (b[3]-'0')*10 + (b[4]-'0');
    hour_b = (b[6]-'0')*10 + (b[7]-'0');
    minute_b = (b[9]-'0')*10 + (b[10]-'0');
    //去头，去尾
    sum += ch[hour_a]*(60-minute_a);
    sum += ch[hour_b]*minute_b;
    c += (60-minute_a) + minute_b;
    ++hour_a;
    //
    int start_hour = hour_a;
    int hour_number = (day_b-day_a)*24 + (hour_b-hour_a);
    c += hour_number*60;
    for(int i = 0;i<hour_number;i++){sum += ch[(start_hour+i)%24]*60;}
    return sum;
}

int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    memset(ch,0,sizeof(ch));
    // 储存各个时段的钱数
    for(int i = 0;i<24;i++){
        int temp; cin >> temp;
        ch[i] = temp;
    }

    int N; cin >> N;
    for(int i = 0;i<N;i++){
        Node node; cin >> node.name >> node.time >> node.status;
        ve.push_back(node);
    }
    sort(ve.begin(),ve.end(),cmp);

    int ve_len = ve.size();
    string judge = "";
    double sum = 0;
    for(int i = 0;i<ve_len;i++){
        //如果名字和上一个不一样的话
        if(ve[i].name != judge){
            if(i != 0){printf("Total amount: $%.2lf\n",sum/100);sum = 0;}
            judge = ve[i].name; //将当前名字变成ve[i]
            cout << ve[i].name << " " << ve[i].time[0] << ve[i].time[1] << "\n";
        }
        else{
            if(ve[i].status == "on-line"){}
            else{
                int ok = 0;
                if(ve[i].status != ve[i-1].status){ok = 1;}
                if(ok == 0){continue;}
                else{
                    int c = 0; 
                    double temp_sum;
                    cout << ve[i-1].time.substr(3,8) << " " << ve[i].time.substr(3,8) << " ";
                    temp_sum = money(ve[i-1].time,ve[i].time,c);
                    printf("%d $%.2lf\n",c,temp_sum/100);
                    sum += temp_sum;
                }
            }
        }
        if(i+1 == ve_len){printf("Total amount: $%.2lf\n",sum/100);sum = 0;}
    }
    return 0;
}