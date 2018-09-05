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
string ch[] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};

int main()
{  
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    string a;
    cin >> a;
    int sum = 0;
    for(int i = 0;i < a.size();i++){
        sum += a[i] - '0';
    }
    string num = to_string(sum);
    for(int i = 0;i < num.size();i++){
        if(i == num.size()-1){cout << ch[num[i]-'0'] << endl;}
        else{cout << ch[num[i] - '0'] << " " ;}
    }

}


