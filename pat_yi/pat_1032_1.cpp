#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
#include<vector>
#include<set>
#include<map>
#include<cstring>
#include<math.h>
#include<cstdio>

using namespace std;
int ch[100005];
int ch_1[100005];
int ch_2[100005];
vector<int> ve;
int main()
{  
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    memset(ch,0,sizeof(ch));
    memset(ch_1,0,sizeof(ch_1));
    memset(ch_2,0,sizeof(ch_2));

    int a,maxn = 0,maxn_i = 0;
    cin >> a;
    int b,c;
    for(int i = 0;i<a;i++){
        cin >> b >> c;
        ch_1[i] = b; //储存优先的列表
        ch[b] += c;
        if(ch[b] >= maxn){maxn = ch[b];maxn_i = b;}
    }
    cout << "最大值" << maxn << endl;
    for(int i = 0;i<a;i++){
        if(ch[i] == maxn){
            for(int z = 0;z<a;z++){
                if(i == ch_1[z]){ch_2[z] = ch_1[z];break;}
            }
        }
    }
    for(int i = 0;i<a;i++){
        if(ch_2[i]){cout << ch_2[i] << endl;}
    }
    return 0;
}
    

    
