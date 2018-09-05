


#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
#define MAXN 10000005

int ch[MAXN]; 

int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif

  int a = 0; //a用来计数
  int m,n;
  cin >> m >> n;
  for(int i = 2;;i++){
    int ok = 1;
    if(i == 2){ch[a] = i;a++;ok=0;}
    else{
      for(int z = 2; z*z <= i ;z++){
        if(i%z == 0){ok = 0;break;}
      }
    }
    if(ok == 1){ch[a] = i;a++;}
    if(a == n){break;}
  }
  int kase = 1;
  for(int i = m-1;i < n;i++){
      if(kase%10 == 1){cout << ch[i];}
      else{cout << " " << ch[i];}
      if(kase%10 == 0){cout << "\n";}
      kase++;
  }
  return 0;
  
}