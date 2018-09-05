/*
1062 最简分数（20 分）
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
第一份做法，用蛮力循环求分子分母余数得到,K = 2,3时需要讨论。
第二份用哈希散列进行优化.
*/



#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;

int main(){
#ifdef LOCAL 
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
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

    int kase = 0;
    for(int i = 1;;i++){
        int ok = 1;
        if((i/double(K)) >= (max_s/max_m)){break;}
        for(int z = 2;z<K;z++){
            if(i%z==0 && K%z==0){ok = 0;}
        }
        if(K == 2){
            if(i%2 != 0 && (i/double(K) > (min_s/min_m))){
                if(kase == 0){cout << i << "/" << K;kase++;}
                else{cout << " " << i << "/" << K;}
            }
        }
        else if(K == 3){
            if(i%3 != 0 && (i/double(K) > (min_s/min_m))){
                if(kase == 0){cout << i << "/" << K;kase++;}
                else{cout << " " << i << "/" << K;}
            }
        }
        else if(ok == 1 && (i/double(K)) > (min_s/min_m)){
            if(kase == 0){cout << i << "/" << K;kase++;}
            else{cout << " " << i << "/" << K;}
        }
        else{}
    }
    return 0;
    
}