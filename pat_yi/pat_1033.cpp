/*
1033 旧键盘打字（20 分）
旧键盘上坏了几个键，于是在敲一段文字的时候，对应的字符就不会出现。现在给出应该输入的一段文字、以及坏掉的那些键，打出的结果文字会是怎样？

输入格式：
输入在 2 行中分别给出坏掉的那些键、以及应该输入的文字。其中对应英文字母的坏键以大写给出；每段文字是不超过 10
​5
​​  个字符的串。可用的字符包括字母 [a-z, A-Z]、数字 0-9、以及下划线 _（代表空格）、,、.、-、+（代表上档键）。题目保证第 2 行输入的文字串非空。

注意：如果上档键坏掉了，那么大写的英文字母无法被打出。

输出格式：
在一行中输出能够被打出的结果文字。如果没有一个字符能被打出，则输出空行。

输入样例：
7+IE.
7_This_is_a_test.
输出样例：
_hs_s_a_tst
*/

/*
总结:
用hash散列储存，然后用cctype中的isupper,islower,tolower,toupper对大小写字母进行处理和判断.
注意的一个点是第一行可能为空，所以用getline输入两行，还是一个审题的问题.
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
int ch[305];

main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    memset(ch,0,sizeof(ch));
    string A,B; getline(cin,A); getline(cin,B);
    int A_len = A.size(),B_len = B.size();
    int add = '+';
    for(int i = 0;i<A_len;i++){
        int temp = A[i];
        ch[temp] = 1;
    }
    for(int i = 0;i<B_len;i++){
        if(isupper(B[i])){
            int temp = B[i];
            if(ch[add] == 1){continue;}
            else if(ch[temp] == 1){continue;}
            else{cout << B[i];}
        }
        else if(islower(B[i])){
            int temp = toupper(B[i]);
            if(ch[temp] == 1){continue;}
            else{cout << B[i];}
        }
        else{
            int temp = B[i];
            if(ch[temp] == 1){continue;}
            else{cout << B[i];}
        }    
    }
    cout << "\n";
    return 0;
}
