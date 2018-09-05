#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<cctype>
#include<cmath>
#include<algorithm>

using namespace std;
double temp;
main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif 
    int N; cin >> N;
    double sum = 0.0;
    for(int i = 1;i<=N;i++){
        cin >> temp;
        sum += (N-i+1)*temp*i;
    }
    printf("%.2f\n",sum);
    return 0;
}
