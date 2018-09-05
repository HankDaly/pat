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
vector<int> ve;
int main()
{  
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    int a,b;
    int c;
    cin >> a >> b; //a储存总数 b是循环次数
    for(int i = 0;i<a;i++){
        cin >> c;
        ve.push_back(c);
    }
    for(int i = 0;i<a;i++){
        ve.push_back(ve[i]);
    }
    int pic = b%a;
    pic = a-pic;
    for(int i = 0;i<a;i++){
        if(i == 0){cout<< ve[pic];pic++;}
        else{cout << " " << ve[pic];pic++;}
    }
    return 0;
}
    

    
