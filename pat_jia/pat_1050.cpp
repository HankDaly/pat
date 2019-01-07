/*
1050 String Subtraction （20 分）
Given two strings S
​1
​​  and S
​2
​​ , S=S
​1
​​ −S
​2
​​  is defined to be the remaining string after taking all the characters in S
​2
​​  from S
​1
​​ . Your task is simply to calculate S
​1
​​ −S
​2
​​  for any given strings. However, it might not be that simple to do it fast.

Input Specification:
Each input file contains one test case. Each case consists of two lines which gives S
​1
​​  and S
​2
​​ , respectively. The string lengths of both strings are no more than 10
​4
​​ . It is guaranteed that all the characters are visible ASCII codes and white space, and a new line character signals the end of a string.

Output Specification:
For each test case, print S
​1
​​ −S
​2
​​  in one line.

Sample Input:
They are students.
aeiou
Sample Output:
Thy r stdnts.
*/
/*
总结:
散列储存，然后一个个验证。注意空格在ascll没位置,所以空格要特别讨论。
ascll储存的话，'!'是最前面的，所以用'!'来。
*/

#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>

using namespace std;
char ch_1[10005];
char ch_2[10005];
int ch[200];
int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    memset(ch,0,sizeof(ch));
    cin.getline(ch_1,10005);
    cin.getline(ch_2,10005);
    int ch2_length = strlen(ch_2);
    for(int i = 0;i<ch2_length;i++){
        if(ch_2[i] == ' '){ch[150] = 1;}
        ch[(ch_2[i]-'!')] = 1;
    }
    int ch1_length = strlen(ch_1);
    for(int i = 0;i<ch1_length;i++){
        if(ch_1[i] == ' ' && ch[150] == 1){continue;}
        else if(ch_1[i] == ' '){printf(" ");}
        else{
            int number = ch_1[i]-'!';
            if(ch[number] == 1){continue;}
            else{printf("%c",ch_1[i]);}
        }
    }
}