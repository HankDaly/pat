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

int main()
{  
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    string pas; //pas储存密码
    int cunt,ok = 0; //cunt 代表可试用的次数,ok = 1,代表密码正确
    cin >> pas >> cunt;
    string sp; //sp除去输入的空格
    getline(cin,sp);
    string ttry;  
    for(int i = 0;i<cunt;i++){

        ttry.clear();
        getline(cin,ttry);
        if(ttry == pas){ok = 1;break;}
        else if(i == cunt -1){cout << "Wrong password: " << ttry << "\n" << "Account locked" << endl;}
        else if(ttry == "#"){break;}
        else{cout << "Wrong password: " << ttry << endl;}
    }
    if(ok == 1){cout << "Welcome in" << endl;}
    return 0;
}


