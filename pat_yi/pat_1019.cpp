// 7:30
/*
1019 数字黑洞 (20)（20 分）
给定任一个各位数字不完全相同的4位正整数，如果我们先把4个数字按非递增排序，再按非递减排序，然后用第1个数字减第2个数字，将得到一个新的数字。一直重复这样做，我们很快会停在有“数字黑洞”之称的6174，这个神奇的数字也叫Kaprekar常数。

例如，我们从6767开始，将得到

7766 - 6677 = 1089\ 9810 - 0189 = 9621\ 9621 - 1269 = 8352\ 8532 - 2358 = 6174\ 7641 - 1467 = 6174\ ... ...

现给定任意4位正整数，请编写程序演示到达黑洞的过程。

输入格式：

输入给出一个(0, 10000)区间内的正整数N。

输出格式：

如果N的4位数字全相等，则在一行内输出“N - N = 0000”；否则将计算的每一步在一行内输出，直到6174作为差出现，输出格式见样例。注意每个数字按4位数格式输出。

输入样例1：

6767
输出样例1：

7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174
输入样例2：

2222
输出样例2：

2222 - 2222 = 0000
*/

/*
总结:
这道题巩固了不少知识点。
1.sort的用法,前两个是范围,后面是默认的从小到大，如果要改，则加上greater<类型>().对于vector,sort(ve.begin(),ve.end(),greater<ve中的类型>())
对于string,如果想排里面的数字,sort(st.begin(),st.end(),greater<int(比较的是ASIC码)>()),对于数组,sort(ch,ch+3,...)。以及，sort是对对象操作，不返回值，所以无法赋值。
2.insert的用法,(a,b,c)a表示插入a这个位置的前方，b是插入的个数，c是插入的元素，b可以不填默认为0. 对于vector,insert(ve.begin(),3,2)就是在开头插入3个2。对于string，insert(0,4,0)
就是在开头插入4个0.
3.函数假如要改变外界的字符串，则传入的形参是(string& a),实参(a).
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

string ok(string a){
    string a_min,a_max;
    if(a[0] == a[1]&&a[1] == a[2]&&a[2]==a[3]){cout << a << " - " << a << " = 0000" ;a = "0000";return a;}
    else{
        sort(a.begin(),a.end(),less<int>());
        a_min = a;
        sort(a.begin(),a.end(),greater<int>());
        a_max = a;
        int tem = stoi(a_max)-stoi(a_min);
        a = to_string(tem);
        a.insert(0,4-a.size(),'0');
        cout << a_max << " - " << a_min << " = " << a << endl;
        return a;
    }
}

int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    string a;
    cin >> a;
    a.insert(0,4-a.size(),'0');
    do{
        a = ok(a);
    }while(a != "6174" && a != "0000");
    return 0;
}