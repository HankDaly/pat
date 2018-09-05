/*
1077 互评成绩计算（20 分）
在浙大的计算机专业课中，经常有互评分组报告这个环节。一个组上台介绍自己的工作，其他组在台下为其表现评分。最后这个组的互评成绩是这样计算的：所有其他组的评分中，去掉一个最高分和一个最低分，剩下的分数取平均分记为 G
​1
​​ ；老师给这个组的评分记为 G
​2
​​ 。该组得分为 (G
​1
​​ +G
​2
​​ )/2，最后结果四舍五入后保留整数分。本题就要求你写个程序帮助老师计算每个组的互评成绩。

输入格式：
输入第一行给出两个正整数 N（> 3）和 M，分别是分组数和满分，均不超过 100。随后 N 行，每行给出该组得到的 N 个分数（均保证为整型范围内的整数），其中第 1 个是老师给出的评分，后面 N−1 个是其他组给的评分。合法的输入应该是 [0,M] 区间内的整数，若不在合法区间内，则该分数须被忽略。题目保证老师的评分都是合法的，并且每个组至少会有 3 个来自同学的合法评分。

输出格式：
为每个组输出其最终得分。每个得分占一行。

输入样例：
6 50
42 49 49 35 38 41
36 51 50 28 -1 30
40 36 41 33 47 49
30 250 -25 27 45 31
48 0 0 50 50 1234
43 41 36 29 42 29
输出样例：
42
33
41
31
37
39
*/

/*
总结：
这次的错误出在小组平均数的除数没有除去不符合规范的那些数字，
属于逻辑上面的疏漏，在审题和前期的逻辑细节地方要再分配点时间。
尽量每个变量的计算都来自于最直接的计算。
*/



#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
#define MAXN 10000005


int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    int a,b; //a组数，b最高分
    cin >> a >> b;
    for(int i = 0;i<a;i++){
      int min = b,max = 0,sum = 0;
      int techer;
      int kase = 0;
      cin >> techer;
      for(int z = 0;z<a-1;z++){
        int student;
        cin >> student;
        if(student>=0 && student<=b){
          sum += student;
          kase++;
          if(student >= max){max = student;}
          if(student <= min){min = student;}
        }
      }
      sum -= max;
      sum -= min;
      double g_1  = sum/(kase-2);
      int en_g = (g_1+techer)/2+0.5;
      cout << en_g << endl;
    }
}