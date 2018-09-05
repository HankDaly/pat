/*
1050 螺旋矩阵（25 分）
本题要求将给定的 N 个正整数按非递增的顺序，填入“螺旋矩阵”。所谓“螺旋矩阵”，是指从左上角第 1 个格子开始，按顺时针螺旋方向填充。要求矩阵的规模为 m 行 n 列，满足条件：m×n 等于 N；m≥n；且 m−n 取所有可能值中的最小值。

输入格式：
输入在第 1 行中给出一个正整数 N，第 2 行给出 N 个待填充的正整数。所有数字不超过 10
​4
​​ ，相邻数字以空格分隔。

输出格式：
输出螺旋矩阵。每行 n 个数字，共 m 行。相邻数字以 1 个空格分隔，行末不得有多余空格。

输入样例：
12
37 76 20 98 76 42 53 95 60 81 58 93
输出样例：
98 95 93
42 37 81
53 20 76
58 60 76
*/
/*
总结:
对于蛇形输入的要点就是分成四个循环去做，先设置一个x,y。
看蛇形的顺序从哪里开始，这道题是右下左上，那么就按这几个方向设置循环。
循环退出的条件比如是往右边的，那么就是右边的坐标超出了.同时还要判断是否下个空没被使用过。
其中的小技巧是，一开始的格子是(-1,0),那么就会判断(0,0)是否合法。检查是去检查下一个位子。
x与y的位置不要搞错。
*/


#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;

vector<int> ve;
int ch[10005][10005];

int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    memset(ch,0,sizeof(ch));
    int N; cin >> N;
    int n_max = 0;
    for(int i = 1;i*i<=N;i++){
        if(!(N%i)){n_max = i;}
    }
    int n = n_max,m = N/n;
    //m是行y,n是列x
    for(int i = 0;i<N;i++){
        int temp; cin >> temp;
        ve.push_back(temp);
    }
    sort(ve.begin(),ve.end(),greater<int>());
    //开始放置蛇形
    //方向为右下左上右;
    int kase = 0;
    int x = -1,y = 0;
    while(kase < N){
        while(x+1 < n && ch[y][x+1] == 0){ch[y][++x] = ve[kase++];}
        while(y+1 < m && ch[y+1][x] == 0){ch[++y][x] = ve[kase++];}
        while(x-1 >= 0 && ch[y][x-1] == 0){ch[y][--x] = ve[kase++];}
        while(y-1 >= 0 && ch[y-1][x] == 0){ch[--y][x] = ve[kase++];}
    }
    for(int i = 0;i<m;i++){
        for(int z = 0;z<n;z++){
            if(z == 0){cout << ch[i][z];}
            else{cout << " " << ch[i][z];}
        }
        if(i+1 != m){cout << "\n";}
    }
    return 0;
}