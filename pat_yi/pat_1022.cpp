/*
1022 D进制的A+B（20 分）
输入两个非负 10 进制整数 A 和 B (≤2
​30
​​ −1)，输出 A+B 的 D (1<D≤10)进制数。

输入格式：
输入在一行中依次给出 3 个整数 A、B 和 D。

输出格式：
输出 A+B 的 D 进制数。

输入样例：
123 456 8
输出样例：
1103
*/
/*
总结:
错误在读题，
注意读题,A和B是非负整数，也就是说两者都是0的情况也会出现
所以得对这情况特殊讨论。
*/



#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    long long A,B; cin >> A >> B;
    int D; cin >> D;
    long long sum = A+B;
    if(sum == 0){cout<< 0;return 0;}
    string D_number;
    while(sum > 0){
        int p_number;
        p_number = sum%D;
        string st_p = to_string(p_number);
        D_number += st_p;
        sum -= p_number;
        sum = sum/D;
    }
    reverse(D_number.begin(),D_number.end());
    cout << D_number;
    return 0;
}