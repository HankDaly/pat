/*
1065 A+B and C (64bit) （20 分）
Given three integers A, B and C in [−2
​63
​​ ,2
​63
​​ ], you are supposed to tell whether A+B>C.

Input Specification:
The first line of the input gives the positive number of test cases, T (≤10). Then T test cases follow, each consists of a single line containing three integers A, B and C, separated by single spaces.

Output Specification:
For each test case, output in one line Case #X: true if A+B>C, or Case #X: false otherwise, where X is the case number (starting from 1).

Sample Input:
3
1 2 3
2 3 4
9223372036854775807 -9223372036854775808 0
Sample Output:
Case #1: false
Case #2: true
Case #3: false
*/
/*
总结:本题主要考了一个溢出的概念,int--(2^31),long--(2^31),long long --(2^63)
比如我现在A和B最大都是2^63-1,故A+B最大为2^64-2,溢出区间为[-2^63,-2]
相对的A和B最小是-2^63,故A+B最小为-2^64,溢出区间为[0,2^63]
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


main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    int N;cin >>N;
    for(int i = 0;i<N;i++){
        long long A,B,C; cin >> A >> B >> C;
        cout << "Case #" << i+1 << ": ";
        long long anwser = A+B;
        if(A>0 && B >0 && anwser < 0){cout << "true" << "\n";}
        else if (A<0 && B<0 && anwser >=0){cout << "false" << "\n";}
        else{
            if(anwser > C){cout << "true" << "\n";}
            else{cout << "false" << "\n";}
        }
    }
    return 0;
}