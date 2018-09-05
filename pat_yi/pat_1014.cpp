/*V1014 福尔摩斯的约会（20 分）
大侦探福尔摩斯接到一张奇怪的字条：我们约会吧！ 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm。大侦探很快就明白了，字条上奇怪的乱码实际上就是约会的时间星期四 14:04，因为前面两字符串中第 1 对相同的大写英文字母（大小写有区分）是第 4 个字母 D，代表星期四；第 2 对相同的字符是 E ，那是第 5 个英文字母，代表一天里的第 14 个钟头（于是一天的 0 点到 23 点由数字 0 到 9、以及大写字母 A 到 N 表示）；后面两字符串第 1 对相同的英文字母 s 出现在第 4 个位置（从 0 开始计数）上，代表第 4 分钟。现给定两对字符串，请帮助福尔摩斯解码得到约会的时间。

输入格式：
输入在 4 行中分别给出 4 个非空、不包含空格、且长度不超过 60 的字符串。

输出格式：
在一行中输出约会的时间，格式为 DAY HH:MM，其中 DAY 是某星期的 3 字符缩写，即 MON 表示星期一，TUE 表示星期二，WED 表示星期三，THU 表示星期四，FRI 表示星期五，SAT 表示星期六，SUN 表示星期日。题目输入保证每个测试存在唯一解。

输入样例：
3485djDkxh4hhGE 
2984akDfkkkkggEdsb 
s&hgsfdk 
d&Hyscvnm
输出样例：
THU 14:04
*/

/*
总结:
主要是读题，第一个数的条件是第一对相等的大写字母并且在A-G的范围内，第二个数的条件是在第一对后面的下一对相等的
字符，如果是字母，那么必须是大写字母大小必须在A-G的范围内。
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

int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    string ch[] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};
    string s_0,s_1,s_2,s_3;
    cin >> s_0 >> s_1 >> s_2 >> s_3;
    int sl_0,sl_1,sl_2,sl_3;
    sl_0 = s_0.size();
    sl_1 = s_1.size();
    sl_2 = s_2.size();
    sl_3 = s_3.size();
    int ka = 0;
    for(int i = 0;i<sl_0&&i<sl_1;i++){
        if(s_1[i] == s_0[i] && ka == 0){
            if(isupper(s_1[i])&&s_1[i]>= 'A'&&s_1[i]<='G'){cout<< ch[s_0[i]-'A'] << " ";ka++;}
        }
        else if(s_1[i] == s_0[i] && ka == 1){
            if(isupper(s_1[i]) && s_1[i] >= 'A' && s_1[i] <= 'N'){printf("%02d:",(s_0[i]-'A')+10);ka++;}
            if(isdigit(s_1[i])){printf("%02d:",s_1[i]-'0');ka++;}
        }
        else{}
        
        if(ka == 2){break;}
    }
    for(int i = 0;i<sl_2&&i<sl_3;i++){
        if(isalpha(s_2[i])){
            if(s_2[i] == s_3[i]){printf("%02d",i);break;}
        }
    }
    return 0;
}
