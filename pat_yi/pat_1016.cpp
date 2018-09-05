/*
1016 部分A+B（15 分）

输入样例 1：
3862767 6 13530293 3
输出样例 1：
399
输入样例 2：
3862767 1 13530293 8
输出样例 2：
0
*/
/*
总结:
这里有个小点，就是string[]下标出来的元素无法去和整个string做对比,应该是string[] 对 string[].
*/


#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cctype>

using namespace std;

int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    string A,a,r_a,B,b,r_b;
    cin >> A >> a >> B >> b;
    int kase_a = 0,kase_b = 0;
    for(int i = 0;i<A.size();i++){
        if(A[i] == a[0]){r_a += A[i];kase_a++;}
    }
    for(int i = 0;i<B.size();i++){
        if(B[i] == b[0]){r_b += B[i];kase_b++;}
    }
    if(kase_a == 0){r_a = "0";}
    if(kase_b == 0){r_b = "0";}
    cout << stoi(r_a) + stoi(r_b);
    return 0;
}   

    
