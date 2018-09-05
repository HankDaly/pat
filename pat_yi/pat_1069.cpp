/*1069 微博转发抽奖（20 分）
小明 PAT 考了满分，高兴之余决定发起微博转发抽奖活动，从转发的网友中按顺序每隔 N 个人就发出一个红包。请你编写程序帮助他确定中奖名单。

输入格式：
输入第一行给出三个正整数 M（≤ 1000）、N 和 S，分别是转发的总量、小明决定的中奖间隔、以及第一位中奖者的序号（编号从 1 开始）。随后 M 行，顺序给出转发微博的网友的昵称（不超过 20 个字符、不包含空格回车的非空字符串）。

注意：可能有人转发多次，但不能中奖多次。所以如果处于当前中奖位置的网友已经中过奖，则跳过他顺次取下一位。

输出格式：
按照输入的顺序输出中奖名单，每个昵称占一行。如果没有人中奖，则输出 Keep going...。

输入样例 1：
9 3 2
Imgonnawin!
PickMe
PickMeMeMeee
LookHere
Imgonnawin!
TryAgainAgain
TryAgainAgain
Imgonnawin!
TryAgainAgain
输出样例 1：
PickMe
Imgonnawin!
TryAgainAgain
输入样例 2：
2 3 5
Imgonnawin!
PickMe
输出样例 2：
Keep going...

*/


/*
总结:
这道题问题出在审题和逻辑上面:
审题上面没有读清楚，当中奖的已经中了，顺延给下一位。这决定了我之前用余数的做法行不通。
逻辑上面，当发现之前的审题有问题的时候，应该重新写一遍伪代码，而不是改之前的框架，因为一个方法改变影响的面
非常大
之前是余数判断间隔，但是只要顺延过一次，余数就被打乱了，那么我选择直接循环。
第一个循环的次数是S次，保证先读到开始的中奖序号。接着一个大循环，注意退出的条件，是剩下的个数不足以到下一个
间隔就停止。中间是两个小循环，一个是读到间隔的个数，然后判断是否中过，如果中过继续下一个循环，直到没有中过的出现
或者读完。

切记审题仔细，如果真的没审仔细，如果问题涉及到较为核心的改动.那么发现的时候必须重写伪代码，不要在原有框架上
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

vector<string> ve;

main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    int M,N,S; cin >> M >> N >> S;
    if(S>M){cout << "Keep going...";}
    else{
        int cont = 0; string temp;
        for(int z = 0;z<S;z++){cin >> temp;cont++;}
        cout << temp; ve.push_back(temp);
        for(;M-cont >= N;){
            for(int z = 0;z<N;z++){cin >> temp;cont++;}
            while(count(ve.begin(),ve.end(),temp) != 0 && cont<M){
                cin >> temp; cont++;
            }
            if(count(ve.begin(),ve.end(),temp) == 0){cout <<"\n"<< temp;ve.push_back(temp);}
        }
    }
    
    return 0;
}
