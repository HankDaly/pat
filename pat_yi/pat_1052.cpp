#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cctype>


using namespace std;
string ch[5][20];
int ic_nu[10];
int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    string icon;
    string tes_1 = "[";
    string tes_2 = "]";
    memset(ch,0,sizeof(ch));
    memset(ic_nu,0,sizeof(ic_nu));
    int kase = 0;
    int tim = 0;
    for(;;){
        string a; a = getchar();
        string temp; temp.clear();
        if(a == "\n"){ic_nu[kase] = tim;tim = 0;kase++;}
        if(kase == 3){break;}
        if(a == tes_1){
            for(;;){
                string b; b = getchar();
                if(b == tes_2){break;}
                temp += b;
            }
            ch[kase][tim++] = temp;
        }
    }
    int K; cin >> K;
    for(int i = 0;i<K;i++){
        string pu_ic;
        int a_1,a_2,a_3,a_4,a_5; cin >> a_1 >> a_2 >> a_3 >> a_4 >> a_5;
        if(a_1<=ic_nu[0] && a_5 <= ic_nu[0] && a_2<=ic_nu[1] && a_4<=ic_nu[1] && a_3<=ic_nu[2] && a_1>=1 && a_2>=1 && a_3>=1 && a_4>=1 && a_5>=1){
            cout << ch[0][a_1-1] <<"("<< ch[1][a_2-1] << ch[2][a_3-1] << ch[1][a_4-1] <<")"<< ch[0][a_5-1] << endl;
        }
        else{cout << "Are you kidding me? @" << "\\" << "/@" << endl;}
    }
   return 0;
}