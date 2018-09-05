/*
1051 复数乘法（15 分）
复数可以写成 (A+Bi) 的常规形式，其中 A 是实部，B 是虚部，i 是虚数单位，满足 i
​2
​​ =−1；也可以写成极坐标下的指数形式 (R×e
​(Pi)
​​ )，其中 R 是复数模，P 是辐角，i 是虚数单位，其等价于三角形式 (R(cos(P)+isin(P))。

现给定两个复数的 R 和 P，要求输出两数乘积的常规形式。

输入格式：
输入在一行中依次给出两个复数的 R
​1
​​ , P
​1
​​ , R
​2
​​ , P
​2
​​ ，数字间以空格分隔。

输出格式：
在一行中按照 A+Bi 的格式输出两数乘积的常规形式，实部和虚部均保留 2 位小数。注意：如果 B 是负数，则应该写成 A-|B|i 的形式。

输入样例：
2.3 3.5 5.2 0.4
输出样例：
-8.68-8.23i
*/

/*
总结；
本题难点有两个
1.在于对题目理解，其实pat考的一些概念无需你了解，它会给出能解的条件，这道题目里的解的条件就是把后面的拓展公式与前面的联系起来.
2.难点在于输出时候的一些转化，一个小知识点是负的浮点进位时变成-0...,所以需要转化为0...，还有就是负的时候自带-号，但是正的时候就得自己加上去。
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;
#define MAXN 10000005


int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    double a,b,r1,p1,r2,p2;
    cin >> r1 >> p1 >> r2 >> p2;
    a = (r1*r2)*(cos(p1)*cos(p2) - sin(p1)*sin(p2));
    b = (r1*r2)*(cos(p1)*sin(p2) + sin(p1)*cos(p2));
    if(a > -0.005 && a<0){printf("0.00");}
    else{printf("%.2f",a);}
    if(b > -0.005 && b<0){printf("+0.00i");}
    else if(b>=0){printf("+%.2fi",b);}
    else{printf("%.2fi",b);}
}