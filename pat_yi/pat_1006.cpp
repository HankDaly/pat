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
    string a;
    string c_0,c_1,c_2;
    cin >> a;
    int b = a.size();
    for(int i = 0;i<b;i++){
        int c = a[b-i-1] - '0';
        if(i == 0){
            for(int z = 0;z<c;z++){c_0 += to_string(z+1);}
        }
        else if(i == 1){string tem(c,'S');c_1 = tem;}
        else{string te(c,'B');c_2 = te;}
    }
    cout << c_2 << c_1 << c_0;

}


