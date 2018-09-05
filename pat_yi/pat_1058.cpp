/*1058 选择题（20 分）
批改多选题是比较麻烦的事情，本题就请你写个程序帮助老师批改多选题，并且指出哪道题错的人最多。

输入格式：
输入在第一行给出两个正整数 N（≤ 1000）和 M（≤ 100），分别是学生人数和多选题的个数。随后 M 行，每行顺次给出一道题的满分值（不超过 5 的正整数）、选项个数（不少于 2 且不超过 5 的正整数）、正确选项个数（不超过选项个数的正整数）、所有正确选项。注意每题的选项从小写英文字母 a 开始顺次排列。各项间以 1 个空格分隔。最后 N 行，每行给出一个学生的答题情况，其每题答案格式为 (选中的选项个数 选项1 ……)，按题目顺序给出。注意：题目保证学生的答题情况是合法的，即不存在选中的选项数超过实际选项数的情况。

输出格式：
按照输入的顺序给出每个学生的得分，每个分数占一行。注意判题时只有选择全部正确才能得到该题的分数。最后一行输出错得最多的题目的错误次数和编号（题目按照输入的顺序从 1 开始编号）。如果有并列，则按编号递增顺序输出。数字间用空格分隔，行首尾不得有多余空格。如果所有题目都没有人错，则在最后一行输出 Too simple。

输入样例：
3 4 
3 4 2 a c
2 5 1 b
5 3 2 b c
1 5 4 a b d e
(2 a c) (2 b d) (2 a c) (3 a b e)
(2 a c) (1 b) (2 a b) (4 a b d e)
(2 b d) (1 e) (2 b c) (4 a b c d)
输出样例：
3
6
5
2 2 3 4
*/
/*
总结:
和多选题的思路类似,用结构和位运算解决问题。
注意在读取学生的选项时候，注意判断流的条件是 while((a=getchar()) != EOF),内部的一些变量
也要注意放置的层数。
*/


#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;

struct Node{
    int No;
    int score;
    int all_n;
    int true_n;
    int t_selected = 0;
    int wrong = 0;
};
bool cmp(Node a,Node b){
    if(a.wrong == b.wrong){return a.No<b.No;}
    else{return a.wrong>b.wrong;}
}
Node ch[105];
int ha[] = {1,2,4,8,16};
int main()
{
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    memset(ch,0,sizeof(ch));
    int N,M; cin >> N >> M;
    for(int i = 0;i<M;i++){
        Node node; cin >> node.score >> node.all_n >> node.true_n;
        node.No = i+1;
        for(int z = 0;z<node.true_n;z++){
            string temp; cin >> temp;
            node.t_selected += ha[(temp[0]-'a')];
        }
        ch[i] = node;
    }
    //题目整理完毕
    for(int i = 0;i<N;i++){
        char a;
        int kase = 0,student_sc = 0;
        while((a = getchar()) != EOF){
            int selected = 0;
            if(a == '('){
                int number; cin >> number;
                for(int z = 0;z<number*2;z++){
                    char c; c = getchar();
                    if(c != ' '){selected += ha[c-'a'];}
                }
                if(selected^ch[kase].t_selected){ //如果不是零，代表有不一样的
                    ++ch[kase].wrong;
                }
                else{student_sc += ch[kase].score;}
                ++kase;
            }
            if(kase == M){cout << student_sc << "\n";break;}
        }
    }
    // 学生统计完
    sort(ch,ch+105,cmp);
    if(ch[0].wrong == 0){cout << "Too simple";}
    else{
        cout << ch[0].wrong;
        for(int i = 0;ch[i].wrong == ch[0].wrong;i++){
            cout <<" "<< ch[i].No;
        }
    }
    
	return 0;
}