/*
1019 General Palindromic Number （20 分）
A number that will be the same when it is written forwards or backwards is known as a Palindromic Number. For example, 1234321 is a palindromic number. All single digit numbers are palindromic numbers.

Although palindromic numbers are most often considered in the decimal system, the concept of palindromicity can be applied to the natural numbers in any numeral system. Consider a number N>0 in base b≥2, where it is written in standard notation with k+1 digits a
​i
​​  as ∑
​i=0
​k
​​ (a
​i
​​ b
​i
​​ ). Here, as usual, 0≤a
​i
​​ <b for all i and a
​k
​​  is non-zero. Then N is palindromic if and only if a
​i
​​ =a
​k−i
​​  for all i. Zero is written 0 in any base and is also palindromic by definition.

Given any positive decimal integer N and a base b, you are supposed to tell if N is a palindromic number in base b.

Input Specification:
Each input file contains one test case. Each case consists of two positive numbers N and b, where 0<N≤10
​9
​​  is the decimal number and 2≤b≤10
​9
​​  is the base. The numbers are separated by a space.

Output Specification:
For each test case, first print in one line Yes if N is a palindromic number in base b, or No if not. Then in the next line, print N as the number in base b in the form "a
​k
​​  a
​k−1
​​  ... a
​0
​​ ". Notice that there must be no extra space at the end of output.

Sample Input 1:
27 2
Sample Output 1:
Yes
1 1 0 1 1
Sample Input 2:
121 5
Sample Output 2:
No
4 4 1
*/

/*
总结:
主要是题目意思没有理解清楚，这里题目的回文代表的意思是每次除余下的数字当作最小单位，比如余下一个12那么就是把12存
到第一个数组里面，而不是将12拆开。主要还是没读清楚题目的意思。
另外一个就是0的情况需要注意.
*/
/*
单词：
decimal 十进制
concept 概念
stander 标准
notation 符号
*/



#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>


using namespace std;
int ch[40];

int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif 
    int N,b; cin >> N >> b;
    int len = 0;
    while(N != 0){
        ch[len++] = (N%b);
        N = N-N%b;
        N /= b;
    }
    int ok = 1;
    for(int i = 0;i<(len/2);i++){
        if(ch[i] != ch[len-i-1]){ok = 0;break;}
    }

    if(ok == 1){cout << "Yes" << endl;}
    else{cout << "No" << endl;}
    for(int i = len - 1;i >= 0;i--){
        if(i != len-1){cout << " ";}
        cout << ch[i];
    }
    if(len == 0){cout << "0";}
}