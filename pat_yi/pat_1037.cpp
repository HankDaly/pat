/*
1037 在霍格沃茨找零钱（20 分）
如果你是哈利·波特迷，你会知道魔法世界有它自己的货币系统 —— 就如海格告诉哈利的：“十七个银西可(Sickle)兑一个加隆(Galleon)，二十九个纳特(Knut)兑一个西可，很容易。”现在，给定哈利应付的价钱 P 和他实付的钱 A，你的任务是写一个程序来计算他应该被找的零钱。

输入格式：
输入在 1 行中分别给出 P 和 A，格式为 Galleon.Sickle.Knut，其间用 1 个空格分隔。这里 Galleon 是 [0, 10
​7
​​ ] 区间内的整数，Sickle 是 [0, 17) 区间内的整数，Knut 是 [0, 29) 区间内的整数。

输出格式：
在一行中用与输入同样的格式输出哈利应该被找的零钱。如果他没带够钱，那么输出的应该是负数。

输入样例 1：
10.16.27 14.1.28
输出样例 1：
3.2.1
输入样例 2：
14.1.28 10.16.27
输出样例 2：
-3.2.1
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
    string A,B; cin >> A >> B;
    string A_1,A_2,A_3,B_1,B_2,B_3;
    int A_len = A.size(),B_len = B.size();
    int kase = 0;
    for(int i = 0;i<A_len;i++){
        if(A[i] == '.'){kase++;continue;}
        if(kase == 0){A_1 += A[i];}
        if(kase == 1){A_2 += A[i];}
        if(kase == 2){A_3 += A[i];}
    }
    kase = 0;
    for(int i = 0;i<B_len;i++){
        if(B[i] == '.'){kase++;continue;}
        if(kase == 0){B_1 += B[i];}
        if(kase == 1){B_2 += B[i];}
        if(kase == 2){B_3 += B[i];}
    }
    // cout << A_1 << A_2 << A_3 << endl; 
    // cout << B_1 << B_2 << B_3 << endl;
    string A_sum = A_1+A_2+A_3,B_sum = B_1+B_2+B_3;
    //判断大小
    int ok = 0;
    int max_1,max_2,max_3,min_1,min_2,min_3;
    if(stoi(A_1) > stoi(B_1)){max_1 = stoi(A_1);max_2 = stoi(A_2);max_3 = stoi(A_3);min_1 = stoi(B_1);min_2 = stoi(B_2);min_3 = stoi(B_3);ok = -1;}
    else if(stoi(A_1) == stoi(B_1) && stoi(A_2) > stoi(B_2)){max_1 = stoi(A_1);max_2 = stoi(A_2);max_3 = stoi(A_3);min_1 = stoi(B_1);min_2 = stoi(B_2);min_3 = stoi(B_3);ok = -1;}
    else if(stoi(A_1) == stoi(B_1) && stoi(A_2) > stoi(B_2) && stoi(A_3) >= stoi(B_3)){max_1 = stoi(A_1);max_2 = stoi(A_2);max_3 = stoi(A_3);min_1 = stoi(B_1);min_2 = stoi(B_2);min_3 = stoi(B_3);ok = -1;}
    else{max_1 = stoi(B_1);max_2 = stoi(B_2);max_3 = stoi(B_3);min_1 = stoi(A_1);min_2 = stoi(A_2);min_3 = stoi(A_3);ok = 1;}
    //判断完毕
    int now_1,now_2,now_3;
    now_1 = max_1 - min_1;
    now_2 = max_2 - min_2;
    now_3 = max_3 - min_3;
    if(now_3<0){
        now_2 -= 1;
        now_3 += 29;
    }
    if(now_2<0){
        now_1 -= 1;
        now_2 += 17;
    }
    now_1 = now_1*ok;
    cout << now_1 << "." << now_2 << "." << now_3;
    return 0;
}
