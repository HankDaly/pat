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

char ch[] = {'A','B','C','D'};

int main()
{  
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    int a = 0;
    cin >> a;
    for(int i = 0;i<a;i++){
        string s_1,s_2,s_3,s_4;
        cin >> s_1 >> s_2 >> s_3 >> s_4;
        if(s_1[2] == 'T'){cout << (s_1[0]-'A')+1;}
        else if(s_2[2] == 'T'){cout << (s_2[0] - 'A') +1;}
        else if(s_3[2] == 'T'){cout << (s_3[0] - 'A') +1;}
        else{cout << (s_4[0] - 'A') +1;}
    }
    return 0;
}
    

    
