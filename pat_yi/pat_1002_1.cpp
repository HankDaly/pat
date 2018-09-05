#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
#include<vector>
#include<set>
#include<map>
#include<cstring>
#include<math.h>

using namespace std;
const int maxn = 10000+10;
string ch[] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
//定义一个求位数的函数
long pice(long c){
    long pi = 0;//代表这个数是10^pi位数
    for(float z = c;z>=10;pi++){
        z = z/10;
    }
    return pi;
}

int main()
{  
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    long a = 0;
    string b; //a储存最后的总和
    cin >> b;
    for(long i = 0;i<b.size();i++){
        a += (b[i] - '0');
    }

    long pi = pice(a); //pi是位数
    long d = a; 
    for(long i = pi;i>0;i--){
        long q = pow(10,i);
        cout<< ch[d/q] << " " ;
        d = d-q;
    }
    cout << ch[a%10] << endl; //单独打印个位，后面不带空
    
}