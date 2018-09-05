/*
1015 德才论（25 分）
宋代史学家司马光在《资治通鉴》中有一段著名的“德才论”：“是故才德全尽谓之圣人，才德兼亡谓之愚人，德胜才谓之君子，才胜德谓之小人。凡取人之术，苟不得圣人，君子而与之，与其得小人，不若得愚人。”

现给出一批考生的德才分数，请根据司马光的理论给出录取排名。

输入格式：
输入第一行给出 3 个正整数，分别为：N（≤10
​5
​​ ），即考生总数；L（≥60），为录取最低分数线，即德分和才分均不低于 L 的考生才有资格被考虑录取；H（<100），为优先录取线——德分和才分均不低于此线的被定义为“才德全尽”，此类考生按德才总分从高到低排序；才分不到但德分到线的一类考生属于“德胜才”，也按总分排序，但排在第一类考生之后；德才分均低于 H，但是德分不低于才分的考生属于“才德兼亡”但尚有“德胜才”者，按总分排序，但排在第二类考生之后；其他达到最低线 L 的考生也按总分排序，但排在第三类考生之后。

随后 N 行，每行给出一位考生的信息，包括：准考证号 德分 才分，其中准考证号为 8 位整数，德才分为区间 [0, 100] 内的整数。数字间以空格分隔。

输出格式：
输出第一行首先给出达到最低分数线的考生人数 M，随后 M 行，每行按照输入格式输出一位考生的信息，考生按输入中说明的规则从高到低排序。当某类考生中有多人总分相同时，按其德分降序排列；若德分也并列，则按准考证号的升序输出。

*/

/*
总结:
用node储存，然后按照条件分类和排序,注意struct定义和初始化都不需要括号
定义完struct记得加;
*/


#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
using namespace std;
struct Node{
    long test_number;
    int de;
    int cai;
    int sum_n;
};

vector<Node> ve_1;
vector<Node> ve_2;
vector<Node> ve_3;
vector<Node> ve_4;

bool cmp(Node a,Node b){
    if(a.sum_n == b.sum_n && a.de != b.de){return a.de>b.de;}
    else if(a.sum_n == b.sum_n && a.de == b.de){return a.test_number<b.test_number;}
    else{return a.sum_n > b.sum_n;}
}
int main(){
#ifdef LOCAL 
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    int N,min_n,max_n; cin >> N >> min_n >> max_n;
    int cont = 0;
    for(int i = 0;i<N;i++){
        long test_number; cin >> test_number;
        int de,cai; cin >> de >> cai;
        Node node;
        node.test_number = test_number; node.de = de; node.cai = cai; node.sum_n = de+cai;
        if(de >= max_n && cai >= max_n){ve_1.push_back(node);}
        else if(de >= max_n && cai >= min_n){ve_2.push_back(node);}
        else if(de >= min_n && cai >= min_n && de >= cai){ve_3.push_back(node);}
        else if(de < min_n || cai < min_n){cont++;}
        else{ve_4.push_back(node);}
    }
    sort(ve_1.begin(),ve_1.end(),cmp);
    sort(ve_2.begin(),ve_2.end(),cmp);
    sort(ve_3.begin(),ve_3.end(),cmp);
    sort(ve_4.begin(),ve_4.end(),cmp);
    cout << N-cont << "\n";
    for(int i = 0;i<ve_1.size();i++){
        cout << ve_1[i].test_number <<" "<< ve_1[i].de <<" "<< ve_1[i].cai << "\n";
    }
    for(int i = 0;i<ve_2.size();i++){
        cout << ve_2[i].test_number <<" "<< ve_2[i].de <<" "<< ve_2[i].cai << "\n";
    }
    for(int i = 0;i<ve_3.size();i++){
        cout << ve_3[i].test_number <<" "<< ve_3[i].de <<" "<< ve_3[i].cai << "\n";
    }
    for(int i = 0;i<ve_4.size();i++){
        cout << ve_4[i].test_number <<" "<< ve_4[i].de <<" "<< ve_4[i].cai << "\n";
    }
 
    return 0;
}