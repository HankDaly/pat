
/*
1064 朋友数（20 分）
如果两个整数各位数字的和是一样的，则被称为是“朋友数”，而那个公共的和就是它们的“朋友证号”。例如 123 和 51 就是朋友数，因为 1+2+3 = 5+1 = 6，而 6 就是它们的朋友证号。给定一些整数，要求你统计一下它们中有多少个不同的朋友证号。

输入格式：
输入第一行给出正整数 N。随后一行给出 N 个正整数，数字间以空格分隔。题目保证所有数字小于 10
​4
​​ 。

输出格式：
首先第一行输出给定数字中不同的朋友证号的个数；随后一行按递增顺序输出这些朋友证号，数字间隔一个空格，且行末不得有多余空格。

输入样例：
8
123 899 51 998 27 33 36 12
输出样例：
4
3 6 9 26
*/

#include<iostream>
#include<cmath>
#include<cstdio>
#include<string>
#include<cstring>

using namespace std;
int ch[105];
main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    memset(ch,0,sizeof(ch));
    int N; cin >> N;
    for(int i = 0;i<N;i++){
        string temp; cin >> temp;
        int sum = 0;
        for(int z = 0;z<temp.size();z++){
            sum += (temp[z] - '0');
        }
        ch[sum] = 1;
    }
    int cont = 0;
    for(int i = 0;i<105;i++){
        if(ch[i] != 0){cont++;}
    }
    cout << cont << "\n";
    int kase = 0;
    for(int i = 0;i<105;i++){
        if(ch[i] != 0){
            if(kase != 0){cout << " ";}
            cout << i;
            kase++;
        }
    }
    return 0;
}
