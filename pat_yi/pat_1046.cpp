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

int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif 
    int j_lose = 0,y_lose = 0;
    int N;
    cin >> N;
    for(int i = 0;i<N;i++){
        int j_s,j_act,y_s,y_act;
        cin >> j_s >> j_act >> y_s >> y_act;
        if(j_act == y_act){continue;}
        else if(j_act == j_s+y_s){y_lose++;continue;}
        else if(y_act == j_s+y_s){j_lose++;continue;}
        else{}
    }
    cout << j_lose <<" "<< y_lose;
    return 0;
}