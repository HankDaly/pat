/*
1024 科学计数法（20 分）
科学计数法是科学家用来表示很大或很小的数字的一种方便的方法，其满足正则表达式 [+-][1-9].[0-9]+E[+-][0-9]+，即数字的整数部分只有 1 位，小数部分至少有 1 位，该数字及其指数部分的正负号即使对正数也必定明确给出。

现以科学计数法的格式给出实数 A，请编写程序按普通数字表示法输出 A，并保证所有有效位都被保留。

输入格式：
每个输入包含 1 个测试用例，即一个以科学计数法表示的实数 A。该数字的存储长度不超过 9999 字节，且其指数的绝对值不超过 9999。

输出格式：
对每个测试用例，在一行中按普通数字表示法输出 A，并保证所有有效位都被保留，包括末尾的 0。

输入样例 1：
+1.23400E-03
输出样例 1：
0.00123400
输入样例 2：
-1.2E+10
输出样例 2：
-12000000000
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
main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    string A; cin >> A;
    int A_len = A.size();
    int point_n = 0,point_E_end = 0; //point_n储存小数点后到E(E不算)的位数，point_E_end储存E后面运算符的下标位置
    for(int i = 1;i<A_len;i++){
        point_n++;
        if(A[i] == '.'){point_n = 0;}
        if(A[i] == 'E'){point_E_end = i+1;point_n --;break;}
    }
    string mas; //mas储存字符串去掉点的主体
    for(int i = 1;i<A_len;i++){
        if(A[i] == '.'){}
        else if(A[i] == 'E'){break;}
        else{mas += A[i];}
    }
    //cout << mas << endl;
    string en;          //en储存最后的位数
    for(int i = point_E_end+1;i<A_len;i++){
        en += A[i];
    }

    if(A[point_E_end] == '-'){
        mas.insert(mas.begin(),stoi(en),'0');
        if(A[0] == '-'){cout << "-";}
        for(int i = 0;i<mas.size();i++){
            cout << mas[i];
            if(i == 0){cout << ".";}
        }
    }
    else{
        if(stoi(en)>=point_n){
            mas.insert(mas.end(),stoi(en)-point_n,'0');
            if(A[0] == '-'){cout << "-";}
            cout << mas;
        }
        else{
            int lose = point_n - stoi(en);
            if(A[0] == '-'){cout << "-";}
            for(int i = 0;i<mas.size();i++){
                cout << mas[i];
                if(i == mas.size()-1-lose){cout << '.';}
            }
        }
    }


    return 0;
}
