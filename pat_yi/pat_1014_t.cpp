#include<iostream>
#include<algorithm>
#include<string>
#include<cctype>

using namespace std;
int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    string ch[] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};
    string s_0,s_1,s_2,s_3;
    cin >> s_0 >> s_1 >> s_2 >> s_3;
    int sl_0,sl_1,sl_2,sl_3;
    sl_0 = s_0.size();
    sl_1 = s_1.size();
    sl_2 = s_2.size();
    sl_3 = s_3.size();
    int ka = 0;
    for(int i = 0;i<sl_0;i++){
        if((0<=s_0[i]-'A'<=25)){
            cout << ka; //ka
            if(s_1[i] == s_0[i] && ka == 0){cout<< ch[s_0[i]-'A'] << " ";ka++;}
            else if(s_1[i] == s_0[i] && ka == 1){cout<< s_0[i] - 'A'+10 <<":";ka++;}
            else{}
        }
        if(ka == 2){break;}
    }
    for(int i = 0;i<sl_2;i++){
        if(isalpha(s_2[i])){
            if(s_2[i] == s_3[i]){printf("%02d",i);break;}
        }
    }
    return 0;
}
    

    
