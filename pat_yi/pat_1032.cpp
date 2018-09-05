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
int main()
{  
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    memset(ch,0,sizeof(ch));
    int a,maxn = 0,maxn_i = 0; 
    cin >> a;
    int b,c;
    for(int i = 0;i<a;i++){
        cin >> b >> c;
        ch[b] += c;
        if(ch[b] > maxn){maxn = ch[b];maxn_i = b;}
    }
    cout << maxn_i << " " << ch[maxn_i];
    return 0;
}
    

    
