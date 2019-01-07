/*1046 Shortest Distance （20 分）
The task is really simple: given N exits on a highway which forms a simple cycle, you are supposed to tell the shortest distance between any pair of exits.

Input Specification:
Each input file contains one test case. For each case, the first line contains an integer N (in [3,10
​5
​​ ]), followed by N integer distances D
​1
​​  D
​2
​​  ⋯ D
​N
​​ , where D
​i
​​  is the distance between the i-th and the (i+1)-st exits, and D
​N
​​  is between the N-th and the 1st exits. All the numbers in a line are separated by a space. The second line gives a positive integer M (≤10
​4
​​ ), with M lines follow, each contains a pair of exit numbers, provided that the exits are numbered from 1 to N. It is guaranteed that the total round trip distance is no more than 10
​7
​​ .

Output Specification:
For each test case, print your results in M lines, each contains the shortest distance between the corresponding given pair of exits.

Sample Input:
5 1 2 4 14 9
3
1 3
2 5
4 1
Sample Output:
3
10
7
*/
/*
总结:
注意直接用数组储存每次累加的距离,利用线性表的特征，求中间一段距离只需要最长减去前面一段即可。
*/

#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cctype>
using namespace std;

int ch[100005];

int main(){
#ifdef LOCAL 
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    int N; cin >>N;
    int sum = 0;
    memset(ch,0,sizeof(ch));
    for(int i = 1;i<=N;i++){
        int temp; cin >> temp;
        sum += temp;
        ch[i] = sum;
    }
    int M; cin >> M;
    for(int i = 0;i<M;i++){
        int temp1,temp2; cin >> temp1 >> temp2;
        int a,b; a = min(temp1,temp2); b = max(temp1,temp2);
        int anwser = ch[b-1]-ch[a-1];
        cout << min(anwser,sum-anwser);
        cout << "\n";
    }
    return 0;
}