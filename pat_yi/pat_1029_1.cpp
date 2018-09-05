/*
1029 旧键盘（20 分）
旧键盘上坏了几个键，于是在敲一段文字的时候，对应的字符就不会出现。现在给出应该输入的一段文字、以及实际被输入的文字，请你列出肯定坏掉的那些键。

输入格式：
输入在 2 行中分别给出应该输入的文字、以及实际被输入的文字。每段文字是不超过 80 个字符的串，由字母 A-Z（包括大、小写）、数字 0-9、以及下划线 _（代表空格）组成。题目保证 2 个字符串均非空。

输出格式：
按照发现顺序，在一行中输出坏掉的键。其中英文字母只输出大写，每个坏键只输出一次。题目保证至少有 1 个坏键。

输入样例：
7_This_is_a_test
_hs_s_a_es
输出样例：
7TI
*/
/*
总结:
第二种做法，用hash表作为判断的依据，用ASCII码作为唯一的标记,键盘上比较小的是"!",位于33位。
直接int a = stringb[..]就可以得到他们
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
using namespace std;
int ch[1000];
int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    memset(ch,0,sizeof(ch));
    string A,B; cin >> A >> B;
    int A_len = A.size(),B_len = B.size();
    for(int i = 0;i<A_len;i++){
        A[i] == toupper(A[i]);
        ch[A[i]-'!'] = 1;
    }
    for(int i = 0;i<B_len;i++){
        B[i] = toupper(B[i]);
        ch[B[i]-'!'] = 0;
    }
    for(int i = 0;i<A_len;i++){
        if(ch[A[i] - '!'] == 1){cout << A[i];ch[A[i] - '!'] = 0;}
    }
    return 0;
}




