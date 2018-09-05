/*
1013 数素数 (20)（20 分）
令P~i~表示第i个素数。现任给两个正整数M <= N <= 10^4^，请输出P~M~到P~N~的所有素数。

输入格式：

输入在一行中给出M和N，其间以空格分隔。

输出格式：

输出从P~M~到P~N~的所有素数，每10个数字占1行，其间以空格分隔，但行末不得有多余空格。

输入样例：

5 27
输出样例：

11 13 17 19 23 29 31 37 41 43
47 53 59 61 67 71 73 79 83 89
97 101 103
*/

/*
总结:
1.检查if(==)的情况
2.15分数的题目边界条件过于考虑,money其实不会给你0开始的
3.cout输出这种格式不如printf来的直观方便
*/

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
    int money,round;
    cin >> money >> round;
    for(int i = 0;i<round;i++){
        int n1,b,t,n2;
        cin >> n1 >> b >> t >> n2;
        if(money == 0){cout <<  "Game Over.";break;}
        else if(t > money){cout << "Not enough tokens.  Total = " << money << "." << endl;continue;}
        //赢得情况
        else if((n1 > n2 && b == 0) || (n1 < n2 && b == 1)){
            money += t;
            cout << "Win "<<t<<"!  Total = " << money << "."<<endl;
        } 
        //输的情况
        else if((n1 < n2 && b == 0) || (n1 > n2 && b == 1)){
            money -= t;
            cout << "Lose "<<t<<".  Total = " << money << "."<<endl;
            if(money == 0){cout << "Game Over.";break;}
        }
        else{}
    }
    return 0;
}
    

    
