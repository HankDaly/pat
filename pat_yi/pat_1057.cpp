/*
1057 数零壹（20 分）
给定一串长度不超过 10
​5
​​  的字符串，本题要求你将其中所有英文字母的序号（字母 a-z 对应序号 1-26，不分大小写）相加，得到整数 N，然后再分析一下 N 的二进制表示中有多少 0、多少 1。例如给定字符串 PAT (Basic)，其字母序号之和为：16+1+20+2+1+19+9+3=71，而 71 的二进制是 1000111，即有 3 个 0、4 个 1。

输入格式：
输入在一行中给出长度不超过 10
​5
​​ 、以回车结束的字符串。

输出格式：
在一行中先后输出 0 的个数和 1 的个数，其间以空格分隔。

输入样例：
PAT (Basic)
输出样例：
3 4
*/
/*
总结:
这个方法有个弊端，就是数变得很大时要求位数时，要进行大数运算。
更好的方法是除2，然后判断有无余数，有的加在一上面，没得就加在零上面。
直到除到0为之。
*/


#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<string>
#include<cstring>
#include<cstdio>
#include<cctype>

using namespace std;
#define MAXN 10000005


int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    string a;
    int b = 0; //b记录字符串的值
    getline(cin,a);
    int a_length = a.size();
    for(int i = 0;i<a_length;i++){
        if(islower(a[i])){b += (a[i]-'a')+1;}
        if(isupper(a[i])){b += (a[i]-'A')+1;}
    }

    int n = 0;
    int one_number = 0;
    int zero_number = 0;
    for(;pow(2,n)<=b;n++);
    n = n-1;
    cout << n << endl;
    for(int i = n;i>=0;i--){
        if(b>pow(2,i)){b = b-pow(2,i);one_number++;}
        else if(b<pow(2,i)){zero_number++;}
        else{b = 0;one_number++;}
    }
    cout << zero_number << " " << one_number;
    return 0;
}