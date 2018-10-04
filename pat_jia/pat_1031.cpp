/*1031 Hello World for U （20 分）
Given any string of N (≥5) characters, you are asked to form the characters into the shape of U. For example, helloworld can be printed as:

h  d
e  l
l  r
lowo
That is, the characters must be printed in the original order, starting top-down from the left vertical line with n
​1
​​  characters, then left to right along the bottom line with n
​2
​​  characters, and finally bottom-up along the vertical line with n
​3
​​  characters. And more, we would like U to be as squared as possible -- that is, it must be satisfied that n
​1
​​ =n
​3
​​ =max { k | k≤n
​2
​​  for all 3≤n
​2
​​ ≤N } with n
​1
​​ +n
​2
​​ +n
​3
​​ −2=N.

Input Specification:
Each input file contains one test case. Each case contains one string with no less than 5 and no more than 80 characters in a line. The string contains no white space.

Output Specification:
For each test case, print the input string in the shape of U as specified in the description.

Sample Input:
helloworld!
Sample Output:
h   !
e   d
l   l
lowor

*/
/*
总结: 把规律找到,就是底部的一排长度>=两边的竖排的长度。然后底部一排长度+两边竖排的长度*2 = 原字符串长度+2。
*/
/*
vertical 垂直
satisfied 满足
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
    string N; cin >> N;
    int N_len = N.size();
    int n1 = (N_len+2)/3;
    int n2 = (N_len+2) - n1*2;
    string block;
    string bottom = N.substr(n1-1,n2);
    for(int i = 0;i<n2-2;i++){
        block += " ";
    }
    for(int i = 0;i<n1-1;i++){
        cout << N[i] << block << N[N_len-i-1] << "\n";
    }
    cout << bottom;
    return 0;
}