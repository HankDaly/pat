/*
1036 跟奥巴马一起编程（15 分）
美国总统奥巴马不仅呼吁所有人都学习编程，甚至以身作则编写代码，成为美国历史上首位编写计算机代码的总统。2014 年底，为庆祝“计算机科学教育周”正式启动，奥巴马编写了很简单的计算机代码：在屏幕上画一个正方形。现在你也跟他一起画吧！

输入格式：
输入在一行中给出正方形边长 N（3≤N≤20）和组成正方形边的某种字符 C，间隔一个空格。

输出格式：
输出由给定字符 C 画出的正方形。但是注意到行间距比列间距大，所以为了让结果看上去更像正方形，我们输出的行数实际上是列数的 50%（四舍五入取整）。

输入样例：
10 a
输出样例：
aaaaaaaaaa
a        a
a        a
a        a
aaaaaaaaaa
*/



#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<cmath>
using namespace std;

int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    double N ; cin >> N;
    string icon; cin >> icon;
    int H = floor(N/2+0.5);
    H = H-2;
    int zero_n = N - 2;
    string zero = icon + string(zero_n,' ') + icon;
    string star_end(N,icon[0]);
    cout << star_end << endl;
    for(int i = 0;i<H;i++){
        cout << zero << endl;
    }
    cout << star_end << endl;

    return 0;
}