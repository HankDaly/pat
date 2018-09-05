/*
1027 打印沙漏（20 分）
本题要求你写个程序把给定的符号打印成沙漏的形状。例如给定17个“*”，要求按下列格式打印

*****
 ***
  *
 ***
*****
所谓“沙漏形状”，是指每行输出奇数个符号；各行符号中心对齐；相邻两行符号数差2；符号数先从大到小顺序递减到1，再从小到大顺序递增；首尾符号数相等。

给定任意N个符号，不一定能正好组成一个沙漏。要求打印出的沙漏能用掉尽可能多的符号。

输入格式:
输入在一行给出1个正整数N（≤1000）和一个符号，中间以空格分隔。

输出格式:
首先打印出由给定符号组成的最大的沙漏形状，最后在一行中输出剩下没用掉的符号数。

输入样例:
19 *
输出样例:
*****
 ***
  *
 ***
*****
2
*/
/*
总结:
分成两块，一块处理，一块打印
*/


#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
using namespace std;

int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    int N; cin >> N;
    string icon; cin>> icon;
    int sum = 1,kase = 1;
    while(sum <= N){
        kase += 2;
        sum += (kase*2);
    }
    sum = sum - (kase*2);
    kase -= 2;
    int lose = N-sum;
    int zero_n = 0;
    //打印上半段
    for(int i = kase;i>=1;i = i-2){
        string zero(zero_n,' ');
        string ic(i,icon[0]);
        cout<< zero << ic << endl;
        zero_n++;
    }
    zero_n -= 2;
    //打印下半段l
    for(int i = 3;i<=kase;i = i+2){
        string zero(zero_n,' ');
        string ic(i,icon[0]);
        cout << zero << ic << endl;
        zero_n -= 1;
    }
    cout << lose;
    return 0;
}