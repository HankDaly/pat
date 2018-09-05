/*

1056 组合数的和（15 分）
给定 N 个非 0 的个位数字，用其中任意 2 个数字都可以组合成 1 个 2 位的数字。要求所有可能组合出来的 2 位数字的和。例如给定 2、5、8，则可以组合出：25、28、52、58、82、85，它们的和为330。

输入格式：
输入在第一行中给出 N（1 < N < 10），随后一行给出 N 个不同的非 0 个位数字。数字间以空格分隔。

输出格式：
输出所有可能组合出来的2位数字的和。

输入样例：
3
2 8 5
输出样例：
330
*/
/*
总结:
要得到所有的排序，只需要循环两遍，让每个数都能做十位就行，当然重复的去掉。
*/


#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<cctype>
#include<cmath>
#include<algorithm>
using namespace std;
int ch[105];

main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    memset(ch,0,sizeof(ch));
    int N; cin >> N;
    string A;
    for(int i = 0;i<N;i++){
        string temp; cin >> temp;
        A += temp;
    }
    int a_length = A.size();
    for(int i = 0;i<a_length;i++){
        for(int q = 0;q<a_length;q++){
            if(q != i){
                string temp_1;
                temp_1 = temp_1 + A[i] + A[q];
                int temp1_number = stoi(temp_1);
                ch[temp1_number] = 1;
            }
        }
    }
    int sum = 0;
    for(int i = 0;i<104;i++){
        if(ch[i]){sum += i;}
    }
    cout << sum;
    return 0;
}
