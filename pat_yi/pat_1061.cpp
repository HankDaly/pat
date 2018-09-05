/*
1061 判断题（15 分）
判断题的评判很简单，本题就要求你写个简单的程序帮助老师判题并统计学生们判断题的得分。

输入格式：
输入在第一行给出两个不超过 100 的正整数 N 和 M，分别是学生人数和判断题数量。第二行给出 M 个不超过 5 的正整数，是每道题的满分值。第三行给出每道题对应的正确答案，0 代表“非”，1 代表“是”。随后 N 行，每行给出一个学生的解答。数字间均以空格分隔。

输出格式：
按照输入的顺序输出每个学生的得分，每个分数占一行。

输入样例：
3 6
2 1 3 3 4 5
0 0 1 0 1 1
0 1 1 0 0 1
1 0 1 0 1 0
1 1 0 0 1 1
输出样例：
13
11
12
*/

#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<vector>
int ch_grade[105];
int ch_ok[105];

using namespace std;
main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    memset(ch_grade,0,sizeof(ch_grade));
    memset(ch_ok,0,sizeof(ch_ok));
    int N,M; cin >> N >> M;

    for(int i = 0;i<M;i++){
        int temp; cin >> temp;
        ch_grade[i] = temp;
    }
    for(int i = 0;i<M;i++){
        int temp; cin >> temp;
        ch_ok[i] = temp;
    }
    for(int i = 0;i<N;i++){
        int sum = 0;
        for(int z = 0;z<M;z++){
            int temp; cin >> temp;
            if(temp == ch_ok[z]){sum += ch_grade[z];}
        }
        cout << sum << "\n";
    }
    return 0;
}
