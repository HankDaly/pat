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
第一个思路是用count函数进行判断，如果原字符串中的字符不存在输出字符中，则添加进要打印的字符串中,bug出在每个键只打印一次;
想直接用count判断一下，但是有些字符既有小写也有大写,那么统一先变成大写存入，这样就不会出现小写的情况，然后后面直接输出即可.
处理字符串的函数是toupper(c),如果是小写字母，输出对应的大写字母，否则原样输出。定义在cctype。
*/



#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
using namespace std;


int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    string A,B; cin >> A >> B;
    string A_bad;
    int a_length = A.size();
    for(int i = 0;i<a_length;i++){
        if(!count(B.begin(),B.end(),A[i])){
            A[i] = toupper(A[i]);
            if(count(A_bad.begin(),A_bad.end(),A[i]) == 0){A_bad += A[i];}
        }
    }
    cout << A_bad;
    

   
    return 0;
}