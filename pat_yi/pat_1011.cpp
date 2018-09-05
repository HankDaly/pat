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

int main()
{  
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    int gt; //gt储存总共的行数
    cin >> gt;
    for(int i = 0;i<gt;i++){
        long a,b,c; //a,b,c分别储存每行的数字
        cin >> a >> b >> c;
        if(a+b>c){cout << "Case #" << i+1 <<": true"<<endl;}
        else{cout << "Case #" << i+1 <<": false"<<endl;}
    }
}
    

    
