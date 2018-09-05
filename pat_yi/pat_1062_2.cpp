/*1062 最简分数（20 分）
一个分数一般写成两个整数相除的形式：N/M，其中 M 不为0。最简分数是指分子和分母没有公约数的分数表示形式。

现给定两个不相等的正分数 N
​1
​​ /M
​1
​​  和 N
​2
​​ /M
​2
​​ ，要求你按从小到大的顺序列出它们之间分母为 K 的最简分数。

输入格式：
输入在一行中按 N/M 的格式给出两个正分数，随后是一个正整数分母 K，其间以空格分隔。题目保证给出的所有整数都不超过 1000。

输出格式：
在一行中按 N/M 的格式列出两个给定分数之间分母为 K 的所有最简分数，按从小到大的顺序，其间以 1 个空格分隔。行首尾不得有多余空格。题目保证至少有 1 个输出。

输入样例：
7/18 13/20 12
输出样例：
5/12 7/12
*/
/*
总结:
解法二用哈希表，这道题的难度就在于如何确定分子和分母有没有共同的公因子,
那么就可以用筛法，先将分母的因子都求出来，那么就可以将1000内的所有分母的因子的倍数在表上标记上。
联想到素数,素数的筛法就是将范围内所有的合数标记出来，那么范围内所有的合数就是以质数做因子在范围内的所有倍数。
*/


#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
int ch[1005];

int main(){
#ifdef LOCAL 
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    memset(ch,0,sizeof(ch));
    double A_s,A_m,B_s,B_m;
    int K;
    cin >> A_s;
    getchar();
    cin >> A_m >> B_s;
    getchar();
    cin >> B_m >> K;
    double max_s,max_m,min_s,min_m;
    if(A_s/A_m > B_s/B_m){max_s = A_s;max_m = A_m;min_s = B_s;min_m = B_m;}
    else{max_s = B_s;max_m = B_m;min_s = A_s;min_m = A_m;}
    for(int i = 2;i<=K;i++){
        if(K%i == 0){
            for(int z = i;z<1003;z += i){
                ch[z] = 1;
            }
        }
    }
    int kase = 0;
    for(int i = 0;;i++){
        if((double(i)/K)>=(max_s/max_m)){break;}
        if(ch[i]==0 && (double(i)/K>(min_s/min_m))){
            if(kase != 0){cout << " ";}
            cout << i  << "/" << K;
            kase++;
        }
    }
    return 0;
}