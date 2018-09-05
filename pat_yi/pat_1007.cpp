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
    int a;
    cin >> a;
    for(int i = 2;i<=a;i++){
        int ok = 1;
        if(i == 2){} //一开始ve里没有素数的时候,添加最小素数，也就是二。
        else{
            for(auto be = ve.begin();be!=ve.end() && (*be)*(*be) <= i;be++){
                if(i%(*be) == 0){ok = 0;}
            }
        }
        if(ok == 1){ve.push_back(i);}
    }
     
    int b = ve.size();
    int c = 0;
    if(b == 1){cout<< 0;}
    else{
        for(int i = 0;i<b-1;i++){
            if(ve[i+1]-ve[i] == 2){c++;}
        }
        cout<< c;
    }
}


