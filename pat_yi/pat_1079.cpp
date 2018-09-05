/*1079 延迟的回文数（20 分）
给定一个 k+1 位的正整数 N，写成 a
​k
​​ ⋯a
​1
​​ a
​0
​​  的形式，其中对所有 i 有 0≤a
​i
​​ <10 且 a
​k
​​ >0。N 被称为一个回文数，当且仅当对所有 i 有 a
​i
​​ =a
​k−i
​​ 。零也被定义为一个回文数。

非回文数也可以通过一系列操作变出回文数。首先将该数字逆转，再将逆转数与该数相加，如果和还不是一个回文数，就重复这个逆转再相加的操作，直到一个回文数出现。如果一个非回文数可以变出回文数，就称这个数为延迟的回文数。（定义翻译自 https://en.wikipedia.org/wiki/Palindromic_number ）

给定任意一个正整数，本题要求你找到其变出的那个回文数。

输入格式：
输入在一行中给出一个不超过1000位的正整数。

输出格式：
对给定的整数，一行一行输出其变出回文数的过程。每行格式如下

A + B = C
其中 A 是原始的数字，B 是 A 的逆转数，C 是它们的和。A 从输入的整数开始。重复操作直到 C 在 10 步以内变成回文数，这时在一行中输出 C is a palindromic number.；或者如果 10 步都没能得到回文数，最后就在一行中输出 Not found in 10 iterations.。

输入样例 1：
97152
输出样例 1：
97152 + 25179 = 122331
122331 + 133221 = 255552
255552 is a palindromic number.
输入样例 2：
196
输出样例 2：
196 + 691 = 887
887 + 788 = 1675
1675 + 5761 = 7436
7436 + 6347 = 13783
13783 + 38731 = 52514
52514 + 41525 = 94039
94039 + 93049 = 187088
187088 + 880781 = 1067869
1067869 + 9687601 = 10755470
10755470 + 07455701 = 18211171
Not found in 10 iterations.
*/
/*
总结:有几个坑点:
1.用c++判断回文只需要reverse该字符串一下就行了，c的时候还要自己写函数，现在不要浪费时间。
2.将1000位看成1000，所以一开始用stoi去做，结果人家是1000位的，手动写相加函数把...
3.题目tm不是判断延迟回文吗？？？一开始给回文几个意思？？？不过条件的确没写一开始不给回文，所以要做好准备.
让自己的程序更加鲁棒。
*/





#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;


string add(string& a,string& b){
    int a_len = a.size();
    string temp;
    int q,q_1,q_2 = 0;
    for(int i = a_len-1;i>=0;i--){
        q = (a[i]-'0') + (b[i]-'0')+q_2;
        q_1 = q%10;
        q_2 = q/10;
        temp += to_string(q_1);
    }
    if(q_2){temp += to_string(q_2);}
    reverse(temp.begin(),temp.end());
    return temp;
}

int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    string st_A,st_B,st_C;
    cin >> st_A;
    int kase = 0;
    while(kase<10){
        st_B = st_A;
        reverse(st_B.begin(),st_B.end());
        if(st_B == st_A){break;}
        st_C = add(st_A,st_B);
        cout << st_A << " + " << st_B << " = " << st_C << "\n";
        st_A = st_C;
        kase++;
    }
    if(kase<10){
        cout << st_A << " is a palindromic number.";
    }
    else{cout <<"Not found in 10 iterations.";} 
    return 0;
}