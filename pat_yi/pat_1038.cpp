#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
#include<vector>
#include<set>
#include<map>
#include<cstring>
#include<math.h>
#include<string.h>

using namespace std;
int sum;
int ch[105];

int main()
{  
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    memset(ch,0,sizeof(ch));
    scanf("%d",&sum);
    int a;
    for(int i = 0;i<sum;i++){
        scanf("%d",&a);
        ch[a]++;
    }
    int b;
    scanf("%d",&b);
    int kase = 0;
    for(int i = 0;i<b;i++){
        int c;
        scanf("%d",&c);
        if(kase == 0){printf("%d",ch[c]);kase++;}
        else{printf(" %d",ch[c]);}
    }
}


