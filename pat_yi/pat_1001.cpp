#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
#include<vector>
#include<set>
#include<map>
#include<cstring>

using namespace std;
const int maxn = 10000+10;

int iter(int n,int* kase){
    if(n>=2 && n%2 == 0){n = n/2;(*kase)++;}
    if(n>=2 && n%2 != 0){n = (3*n+1)/2;(*kase)++;}
    if(n != 1){iter(n,kase);}
    return 0;
}

int main()
{  
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    int a,kase = 0;
    cin >> a;
    iter(a,&kase);
    cout << kase << endl;
}


