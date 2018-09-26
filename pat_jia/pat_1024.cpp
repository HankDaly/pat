/*1024 Palindromic Number （25 分）
A number that will be the same when it is written forwards or backwards is known as a Palindromic Number. For example, 1234321 is a palindromic number. All single digit numbers are palindromic numbers.

Non-palindromic numbers can be paired with palindromic ones via a series of operations. First, the non-palindromic number is reversed and the result is added to the original number. If the result is not a palindromic number, this is repeated until it gives a palindromic number. For example, if we start from 67, we can obtain a palindromic number in 2 steps: 67 + 76 = 143, and 143 + 341 = 484.

Given any positive integer N, you are supposed to find its paired palindromic number and the number of steps taken to find it.

Input Specification:
Each input file contains one test case. Each case consists of two positive numbers N and K, where N (≤10
​10
​​ ) is the initial numer and K (≤100) is the maximum number of steps. The numbers are separated by a space.

Output Specification:
For each test case, output two numbers, one in each line. The first number is the paired palindromic number of N, and the second number is the number of steps taken to find the palindromic number. If the palindromic number is not found after K steps, just output the number obtained at the Kth step and K instead.

Sample Input 1:
67 3
Sample Output 1:
484
2
Sample Input 2:
69 3
Sample Output 2:
1353
3
*/
/*
总结:
题目本身没什么难度，自己写的一个函数出了一点问题.
string add(string a){
    int a_len = a.size();
    string temp = a;
    reverse(a.begin(),a.end());
    int in = 0;
    string sum;
    for(int i = a_len -1;i>=0;i--){
        sum += (((temp[i]-'0')+(a[i]-'0')+in)%10+'0');
        in = ((temp[i]-'0')+(a[i]-'0') + in)/10;
    }
    if(in != 0){sum += (in+'0');}
    reverse(sum.begin(),sum.end());
    return sum;
}
add函数 是用来处理字符串和自身的reverse相加的函数.
主要就是处理一个进位问题。
in用作进位数，一开始置为0;
后面每一位的相加后求余和相加后求in都要加上in，这一点不要忘记。
然后最后in不是零的话还要加到sum上。
主要在纸上简单模拟一遍，不要有疏忽就好。
*/
/*
单词
via 通过
serise 系列
*/

#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>


using namespace std;
string add(string a){
    int a_len = a.size();
    string temp = a;
    reverse(a.begin(),a.end());
    int in = 0;
    string sum;
    for(int i = a_len -1;i>=0;i--){
        sum += (((temp[i]-'0')+(a[i]-'0')+in)%10+'0');
        in = ((temp[i]-'0')+(a[i]-'0') + in)/10;
    }
    if(in != 0){sum += (in+'0');}
    reverse(sum.begin(),sum.end());
    return sum;
}

int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    string N; cin >> N;
    int K; cin >> K;
    string sum = N;
    int cnt,ok = 0;
    for(int i = 0;i<K;i++){
        string temp = sum;
        reverse(temp.begin(),temp.end());
        if(temp == sum){cnt = i;ok = 1;break;}
        sum = add(sum);
    }
    if(ok == 0){cout << sum << "\n" << K;}
    else{cout << sum << "\n" << cnt;}
    return 0;
}