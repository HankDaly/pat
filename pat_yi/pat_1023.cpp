#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<string>
#include<cstring>
#include<cstdio>
#include<cctype>

using namespace std;
#define MAXN 10000005

vector<int> ve;

int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif 
    int key = 0;
    int ok = 0;
    for(int i = 0;i<10;i++){
        int a;
        cin >> a;
        for(;a>0;a--){
            if(i != 0 && ok == 0){
                key = i;
                ok = 1; 
            }
            else{ve.push_back(i);}
        }
    }
    cout << key;
    for(auto i = ve.begin();i!=ve.end();i++){
        cout << *i;
    }
    return 0;
}