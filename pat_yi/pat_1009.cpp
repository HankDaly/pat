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
vector<string> ve;
int main()
{  
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    string a;
    while(cin >> a){
        ve.push_back(a);
    }
    int c = ve.size();
    for(int i = 0;i<c;i++){
        if(i == 0){cout << ve[c-i-1];}
        else{cout << " " << ve[c-i-1];}
    }
    return 0;

}
    

    
