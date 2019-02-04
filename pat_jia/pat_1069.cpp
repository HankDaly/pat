/*
1069 The Black Hole of Numbers （20 分）
For any 4-digit integer except the ones with all the digits being the same, if we sort the digits in non-increasing order first, and then in non-decreasing order, a new number can be obtained by taking the second number from the first one. Repeat in this manner we will soon end up at the number 6174 -- the black hole of 4-digit numbers. This number is named Kaprekar Constant.

For example, start from 6767, we'll get:

7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174
7641 - 1467 = 6174
... ...
Given any 4-digit number, you are supposed to illustrate the way it gets into the black hole.

Input Specification:
Each input file contains one test case which gives a positive integer N in the range (0,10
​4
​​ ).

Output Specification:
If all the 4 digits of N are the same, print in one line the equation N - N = 0000. Else print each step of calculation in a line until 6174 comes out as the difference. All the numbers must be printed as 4-digit numbers.

Sample Input 1:
6767
Sample Output 1:
7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174
Sample Input 2:
2222
Sample Output 2:
2222 - 2222 = 0000
*/
/*
总结:
细节题目，需要注意得地方有
1.给出6174时还得运算一步，所以用do-while
2.给的N是数字，但是用string运算的话要提前加好0，而不是输出得时候加0
3.重复而且长度为4得时候（注意）才直接打印0000
*/

#include<iostream>
#include<cstdio>
#include<unordered_map>
#include<cctype>
#include<string>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cmath>

using namespace std;
int ch[100005];
bool cmp_max(char a,char b){
    if(a>b){return true;}
    else{return false;}
}
string add_zero(string N){
    string temp = N;
    if(N.size() != 4){
        for(int i = 0;i<4-N.size();i++){
            temp = "0" + temp;
        }
        return temp;
    }
    else{return N;}
}
main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    string N; cin >> N;
    int flag = 0;
    for(int i = 0;i<N.size();i++){
        if(N[i] != N[0]){flag = 1;}
    }
    if(flag == 0 && N.size() == 4){cout << add_zero(N) << " - " << add_zero(N) << " = 0000";}
    //重复处理完毕
    else{
            do{
            string N_max = add_zero(N),N_min = add_zero(N);
            sort(N_max.begin(),N_max.end(),cmp_max);
            sort(N_min.begin(),N_min.end());
            N = to_string(stoi(N_max)-stoi(N_min));
            N = add_zero(N);
            cout << N_max << " - " << N_min << " = " << N << "\n";
        }while(N != "6174");
    }
    return 0;
}