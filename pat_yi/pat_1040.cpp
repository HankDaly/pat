/*
1040 有几个PAT（25 分）
字符串 APPAPT 中包含了两个单词 PAT，其中第一个 PAT 是第 2 位(P)，第 4 位(A)，第 6 位(T)；第二个 PAT 是第 3 位(P)，第 4 位(A)，第 6 位(T)。

现给定字符串，问一共可以形成多少个 PAT？

输入格式：
输入只有一行，包含一个字符串，长度不超过10
​5
​​ ，只包含 P、A、T 三种字母。

输出格式：
在一行中输出给定字符串中包含多少个 PAT。由于结果可能比较大，只输出对 1000000007 取余数的结果。

输入样例：
APPAPT
输出样例：
2
*/
/*
总结:
这类题目主要观察规律,这道题目的规律就是每个A的PAT数是左边的所有P的数量乘A右边的所有的T的数量。
找到了规律就比较好处理了，因为有左右两边的统计，所以需要两次循环。
与1045这道题对比，这道题规律稍微需要挖一下。
*/
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
int ch_p[100005];
int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    string A; cin >> A;
    int A_len = A.size();
    int sum = 0;
    int p_n = 0;
    for(int i = 0;i<A_len;i++){
        if(A[i] == 'P'){p_n++;ch_p[i] = p_n;}
        else{ch_p[i] = p_n;}
    }
    int t_n = 0;
    for(int i = A_len-1;i>=0;i--){
        if(A[i] == 'T'){t_n++;}
        if(A[i] == 'A'){sum = (sum+t_n*ch_p[i])%1000000007;}
    }
    cout << sum;
    return 0;
}
