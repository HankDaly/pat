/*1002 A+B for Polynomials （25 分）
This time, you are supposed to find A+B where A and B are two polynomials.

Input Specification:
Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial:

K N
​1
​​  a
​N
​1
​​ 
​​  N
​2
​​  a
​N
​2
​​ 
​​  ... N
​K
​​  a
​N
​K
​​ 
​​ 

where K is the number of nonzero terms in the polynomial, N
​i
​​  and a
​N
​i
​​ 
​​  (i=1,2,⋯,K) are the exponents and coefficients, respectively. It is given that 1≤K≤10，0≤N
​K
​​ <⋯<N
​2
​​ <N
​1
​​ ≤1000.

Output Specification:
For each test case you should output the sum of A and B in one line, with the same format as the input. Notice that there must be NO extra space at the end of each line. Please be accurate to 1 decimal place.

Sample Input:
2 1 2.4 0 3.2
2 2 1.5 1 0.5
Sample Output:
3 2 1.5 1 2.9 0 3.2
*/
/*
总结:
简单的多项式加法，用数组储存多项式即可.
注意系数有可能是负数，所以用ch[0]储存即可。
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
double ch[1005];

int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    memset(ch,0,sizeof(ch));
    int cnt = 0;
    for(int i = 0;i<2;i++){
        int K; cin >> K;
        for(int z = 0;z<K;z++){
            int a; cin >> a; //a指数
            double n; cin >> n;//n系数
            if(ch[a] == 0){ch[a] = n;}
            else{ch[a] += n;}
        }
    }
    for(int i = 1004;i>=0;i--){
        if(ch[i] != 0){++cnt;}
    }
    printf("%d",cnt);
    for(int i = 1004;i>=0;i--){
        if(ch[i] != 0){printf(" %d %.1lf",i,ch[i]);}
    }
    return 0;
}