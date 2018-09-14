/*1001 A+B Format （20 分）
Calculate a+b and output the sum in standard format -- that is, the digits must be separated into groups of three by commas (unless there are less than four digits).

Input Specification:
Each input file contains one test case. Each case contains a pair of integers a and b where −10
​6
​​ ≤a,b≤10
​6
​​ . The numbers are separated by a space.

Output Specification:
For each test case, you should output the sum of a and b in one line. The sum must be written in the standard format.

Sample Input:
-1000000 9
Sample Output:
-999,991
*/
/*
总结:
大意是将a+b的和按照标准格式输出。
转字符串，然后总数减去i后能被3余的后面加上逗号。排除i等于0的情况。
*/

#include<iostream>
#include<cstdio>
#include<unordered_map>
#include<cctype>
#include<string>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    int a,b; cin >> a >> b;
    long sum = a+b;
    if(sum < 0){cout << "-";sum *= -1;}
    string st_sum = to_string(sum);
    int sum_len = st_sum.size();
    for(int i = 0;i<sum_len;i++){
        if(i != 0 && (sum_len-i)%3 == 0){cout << ",";}
        cout << st_sum[i];
    }
    return 0;
}