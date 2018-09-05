/*
1072 开学寄语（20 分）
下图是上海某校的新学期开学寄语：天将降大任于斯人也，必先删其微博，卸其 QQ，封其电脑，夺其手机，收其 ipad，断其 wifi，使其百无聊赖，然后，净面、理发、整衣，然后思过、读书、锻炼、明智、开悟、精进。而后必成大器也！

本题要求你写个程序帮助这所学校的老师检查所有学生的物品，以助其成大器。

输入格式：
输入第一行给出两个正整数 N（≤ 1000）和 M（≤ 6），分别是学生人数和需要被查缴的物品种类数。第二行给出 M 个需要被查缴的物品编号，其中编号为 4 位数字。随后 N 行，每行给出一位学生的姓名缩写（由 1-4 个大写英文字母组成）、个人物品数量 K（0 ≤ K ≤ 10）、以及 K 个物品的编号。

输出格式：
顺次检查每个学生携带的物品，如果有需要被查缴的物品存在，则按以下格式输出该生的信息和其需要被查缴的物品的信息（注意行末不得有多余空格）：

姓名缩写: 物品编号1 物品编号2 ……
最后一行输出存在问题的学生的总人数和被查缴物品的总数。

输入样例：
4 2
2333 6666
CYLL 3 1234 2345 3456
U 4 9966 6666 8888 6666
GG 2 2333 7777
JJ 3 0012 6666 2333
输出样例：
U: 6666 6666
GG: 2333
JJ: 6666 2333
3 5
*/

/*
总结；
编号那边一开始用int输入,然而编号并不是普通int能表示的，比如0000。
所以以后注意人工编号方面要小心读入
*/


#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
#include<vector>
#include<set>
#include<map>
#include<cstring>
#include<math.h>
#include<string.h>
#include<cstdio>

using namespace std;

vector<string> ve;

int main()
{  
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    int a,b; //a学生人数,b物品数量
    string c; //物品编号
    int cnt = 0; 
    int p_number = 0;
    cin >> a >> b;
    for(int i = 0;i<b;i++){
        cin >> c;
        ve.push_back(c);
    }
    for(int i = 0;i<a;i++){
        string name;
        int d;
        cin >> name >> d;
        int kase = 0; //记录是否初犯
        for(int z = 0; z<d ;z++){
            string p;
            cin >> p;
            if(count(ve.begin(),ve.end(),p)){
                if(kase == 0){cout << name << ":" << " " <<p;kase++;}
                else{cout << " " << p;kase++;}
            }
            if(z == d-1 && kase>0){cout << "\n";}
        }
        if(kase){cnt += 1;}
        p_number += kase;
    }
    cout << cnt << " " << p_number;
    return 0;
}
    

    
