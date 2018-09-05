#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
#include<vector>
#include<set>
#include<map>
#include<cstring>
#include<math.h>

using namespace std;

int main()
{  
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    int a;
    cin >> a;
    for(int i = 0;i<a;i++){
        string b;
        cin >> b;
        // 四个条件，b中只有PAT三个字符，PT数量只有一个,T的下标-P的下标>1,并且<b.size()-T的下标
        int ka = 0; //ka用来检测是否只有PAT
        int num_pp = 0,num_tt = 0; //num用来检测pt的数量
        int fi = 0; // fi用来检测下标运算
        int lis_tt = 0,lis_pp = 0; // lis 用来储存 b.size()-T的下标
        for(auto cha : b){
            if(cha != 'P' && cha != 'A' && cha != 'T'){ka = 1;break;}
            if(cha == 'P'){num_pp++;}
            if(cha == 'T'){num_tt++;}
        }
        if(ka == 0 && num_tt == 1 && num_pp == 1){
            int tem_a = b.find("P"),tem_b = b.find("T");
            fi = tem_b - tem_a - 1;
            lis_tt = b.size() - tem_b - 1;
            lis_pp = tem_a;
        }
        if(fi>0 && num_pp == 1 && num_tt == 1 && ka == 0 && lis_pp*fi == lis_tt){cout<<"YES"<<endl;}
        else{cout<<"NO"<<endl;}
    }
}


