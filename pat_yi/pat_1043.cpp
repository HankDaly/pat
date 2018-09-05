/*
PAT (Basic Level) Practice （中文）
1700 分
编程题共 85 小题，共计 1700 分
原PAT网站用户可在 https://patest.cn/bind_old_pat_user 页面绑定至拼题A账号。绑定后，原PAT网站的提交将被合并至拼题A网站用户的对应题目集中。
编程题
1043 输出PATest（20 分）
给定一个长度不超过 10
​4
​​  的、仅由英文字母构成的字符串。请将字符重新调整顺序，按 PATestPATest.... 这样的顺序输出，并忽略其它字符。当然，六种字符的个数不一定是一样多的，若某种字符已经输出完，则余下的字符仍按 PATest 的顺序打印，直到所有字符都被输出。

输入格式：
输入在一行中给出一个长度不超过 10
​4
​​  的、仅由英文字母构成的非空字符串。

输出格式：
在一行中按题目要求输出排序后的字符串。题目保证输出非空。

输入样例：
redlesPayBestPATTopTeePHPereatitAPPT
输出样例：
PATestPATestPTetPTePePee


*/







#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<cctype>
#include<cmath>
#include<algorithm>
using namespace std;
int ch[10005];

main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    memset(ch,0,sizeof(ch));
    string A; cin >> A;
    string B = "PATest";
    int a_len = A.size(),b_len = B.size();
    for(int i = 0;i<a_len;i++){
        for(int z = 0;z<b_len;z++){
            if(A[i] == B[z]){ch[int(A[i])]++;}
        }
    }
    for(int i = 0;i<a_len;i++){
        for(int z = 0;z<b_len;z++){
            if(ch[int(B[z])] != 0){cout << B[z];ch[int(B[z])]--;}
        }
    }
    return 0;
}
