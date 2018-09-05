/*
1073 多选题常见计分法（20 分）
批改多选题是比较麻烦的事情，有很多不同的计分方法。有一种最常见的计分方法是：如果考生选择了部分正确选项，并且没有选择任何错误选项，则得到 50% 分数；如果考生选择了任何一个错误的选项，则不能得分。本题就请你写个程序帮助老师批改多选题，并且指出哪道题的哪个选项错的人最多。

输入格式：
输入在第一行给出两个正整数 N（≤1000）和 M（≤100），分别是学生人数和多选题的个数。随后 M 行，每行顺次给出一道题的满分值（不超过 5 的正整数）、选项个数（不少于 2 且不超过 5 的正整数）、正确选项个数（不超过选项个数的正整数）、所有正确选项。注意每题的选项从小写英文字母 a 开始顺次排列。各项间以 1 个空格分隔。最后 N 行，每行给出一个学生的答题情况，其每题答案格式为 (选中的选项个数 选项1 ……)，按题目顺序给出。注意：题目保证学生的答题情况是合法的，即不存在选中的选项数超过实际选项数的情况。

输出格式：
按照输入的顺序给出每个学生的得分，每个分数占一行，输出小数点后 1 位。最后输出错得最多的题目选项的信息，格式为：错误次数 题目编号（题目按照输入的顺序从1开始编号）-选项号。如果有并列，则每行一个选项，按题目编号递增顺序输出；再并列则按选项号递增顺序输出。行首尾不得有多余空格。如果所有题目都没有人错，则在最后一行输出 Too simple。

输入样例 1：
3 4 
3 4 2 a c
2 5 1 b
5 3 2 b c
1 5 4 a b d e
(2 a c) (3 b d e) (2 a c) (3 a b e)
(2 a c) (1 b) (2 a b) (4 a b d e)
(2 b d) (1 e) (1 c) (4 a b c d)
输出样例 1：
3.5
6.0
2.5
2 2-e
2 3-a
2 3-b
输入样例 2：
2 2 
3 4 2 a c
2 5 1 b
(2 a c) (1 b)
(2 a c) (1 b)
输出样例 2：
5.0
5.0
Too simple
*/

/*
总结:
做起来有点烦的一道题目.
逻辑上面的坑点不多，注意没被选的也算那个选项错了一次。
程序上面，储存abcde的错误次数可以用二维数组，就不用我手打那么多次了。
有一个技巧位运算可以剩很多判断的步骤。
位运算是这样的
int a = 2;
int b = 4;
int c = a^b;
在进行^,也就是异或位运算的时候，会自动把a,b转化为二进制,a = 10,b = 100.
异或的意思是位数相等为0，不相等为1，a = 10 = 010.与b^的结果就是110，最后转化为10进制后c=6;
那么其实就可以通过位运算来判断多选题这种问题.
首先,有五个选项a,b,c,d,e。分别对应的值是1,2，4，8，16.也就是1，10，100，1000，10000。
那么选项abc加起来就是00111。比如正确选项是abcd = 01111.
两者进行异或运算后为 01000。还有，说明漏了或者错了。
接着用或运算符判断漏了，如果abc|abcd 后 = abcd 说明 abc完全被包含在了abcd里。

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
struct Node{
    double score;
    int No;
    int quest;
    int quest_ok;
    int anwser = 0;
    int one_max = 0;
    int cha[10] = {0};
};
vector<Node> ve;
bool cmp(Node a,Node b){
    if(a.one_max == b.one_max){return a.No < b.No;}
    else{return a.one_max > b.one_max;}
}

int hah[5] = {1,2,4,8,16};

int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    int N,M; cin >> N >> M;
    for(int i = 0;i<M;i++){
        Node node;
        cin >> node.score >> node.quest >> node.quest_ok;
        node.No = i+1;
        for(int z = 0;z<node.quest_ok;z++){
            string temp; cin >> temp;
            node.anwser += hah[temp[0]-'a'];
        }
        ve.push_back(node);
    }
    //题目区域整理完毕
    for(int i = 0;i<N;i++){
        char tem;
        int cnt = 0;
        double sum = 0.0;
        while((tem = getchar()) != EOF && cnt != M){
            if(tem == '('){
                int now_selected = 0;
                int anwser_n; cin >> anwser_n;
                char one;
                for(int z = 0;z<anwser_n*2;z++){
                    scanf("%c",&one);
                    if(one != ' '){now_selected += hah[one-'a'];}
                }
                int ok = ve[cnt].anwser^now_selected;
                if(ok != 0){
                    if((ve[cnt].anwser | now_selected) == ve[cnt].anwser){sum += ve[cnt].score/2;}
                    if(ok & hah[0]){ve[cnt].cha[0]++;}
                    if(ok & hah[1]){ve[cnt].cha[1]++;}
                    if(ok & hah[2]){ve[cnt].cha[2]++;}
                    if(ok & hah[3]){ve[cnt].cha[3]++;}
                    if(ok & hah[4]){ve[cnt].cha[4]++;}
                }
                else{sum += ve[cnt].score;}
                cnt++;
            }
        }
        printf("%.1lf\n",sum);
    }
    //对错统计完毕
    for(int i = 0;i < ve.size();i++){
        int max = 0;
        for(int z = 0;z<5;z++){
            if(ve[i].cha[z] > max){max = ve[i].cha[z];}
        }
        ve[i].one_max = max;
    }
    sort(ve.begin(),ve.end(),cmp);
    if(ve[0].one_max == 0){cout <<"Too simple";}
    else{
        for(int i = 0;i < ve.size();i++){
            if(ve[i].one_max < ve[0].one_max){break;}
            for(int z = 0;z<5;z++){
                char temp = 'a'+z;
                if(ve[i].cha[z] == ve[0].one_max){cout << ve[i].cha[z] << " " << ve[i].No << "-" << temp << "\n";}
            }
        }
    }
    return 0;
}