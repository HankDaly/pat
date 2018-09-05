
/*
1030 完美数列（25 分）
给定一个正整数数列，和正整数 p，设这个数列中的最大值是 M，最小值是 m，如果 M≤mp，则称这个数列是完美数列。

现在给定参数 p 和一些正整数，请你从中选择尽可能多的数构成一个完美数列。

输入格式：
输入第一行给出两个正整数 N 和 p，其中 N（≤10
​5
​​ ）是输入的正整数的个数，p（≤10
​9
​​ ）是给定的参数。第二行给出 N 个正整数，每个数不超过 10
​9
​​ 。

输出格式：
在一行中输出最多可以选择多少个数可以用它们组成一个完美数列。

输入样例：
10 8
2 3 20 4 5 1 6 7 8 9
输出样例：
8
*/
/*
总结:
这道题用twopoint的思想,
无序数列无法找到规律，只能用两次循环去迭代,但是转化为有序数列后就能使用有序数列自带的特性进行优化。
第一个点从头开始扫，第二个点从第一个点的位置加上已知的最大的数后往前扫。
这样利用了，有序数列后面永远比前面的大的特性,比如前面一次的最大战绩是3，那么下次就会从+3开始。
注意这里的距离直接用两个点的下标相减就可以得到。
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
vector<long long> ve;

main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    int N; cin >> N;
    long long p; scanf("%lld",&p);

    for(int i = 0;i<N;i++){
        long long temp; scanf("%lld",&temp);
        ve.push_back(temp);
    }
    sort(ve.begin(),ve.end());
    int lo_number = 0;
    for(int i = 0;i<N;i++){
        int temp = 0;
        for(int z = i+lo_number;z<N;z++){
            if(ve[z]<=ve[i]*p){temp = z-i+1;}
            if(temp>lo_number){lo_number = temp;}
            else{break;}
        }
    }
    cout << lo_number;
    return 0;
}
