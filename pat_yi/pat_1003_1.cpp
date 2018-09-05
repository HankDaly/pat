#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

string ok(string& a){
    int a_len = a.size();
    int p_in,t_in,p_kase = 0,t_kase = 0;
    int ok = 1;
    for(int i = 0;i<a_len;i++){
        if(a[i] == 'P'){p_in = i;p_kase++;}
        else if(a[i] == 'T'){t_in = i;t_kase++;}
        else if(a[i] != 'A' && a[i] != 'P' && a[i] != 'T'){ok = 0;}
        else{}
    }
    int mdeium = t_in - p_in;
    if(p_kase != 1 || t_kase != 1 || mdeium < 2){ok = 0;}
    if(ok == 0){return "NO";}
    if(p_in*(mdeium-1) == a_len - t_in-1){return "YES";}
    else{return "NO";}

}

int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    int N; cin >> N;
    for(int i = 0;i<N;i++){
        string temp; cin >> temp;
        string a;
        a = ok(temp);
        if(i != 0){cout << "\n";}
        cout << a;
    }
    return 0;
}