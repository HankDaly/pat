/*1018 锤子剪刀布 (20)（20 分）
大家应该都会玩“锤子剪刀布”的游戏：两人同时给出手势，胜负规则如图所示：



现给出两人的交锋记录，请统计双方的胜、平、负次数，并且给出双方分别出什么手势的胜算最大。

输入格式：

输入第1行给出正整数N（<=10^5^），即双方交锋的次数。随后N行，每行给出一次交锋的信息，即甲、乙双方同时给出的的手势。C代表“锤子”、J代表“剪刀”、B代表“布”，第1个字母代表甲方，第2个代表乙方，中间有1个空格。

输出格式：

输出第1、2行分别给出甲、乙的胜、平、负次数，数字间以1个空格分隔。第3行给出两个字母，分别代表甲、乙获胜次数最多的手势，中间有1个空格。如果解不唯一，则输出按字母序最小的解。

输入样例：

10
C J
J B
C B
B B
B C
C C
C B
J B
B C
J J
输出样例：

5 3 2
2 3 5
B B
*/

/*
刚开始在想有没有简便方法，后来想想还是只能一个一个判断过来.
就是在那个比较大小的地方可以稍微简便一点.
判断ABC三个数的大小四次就行了
if(A>B){
    if(A>C){A}
    else{C}
}
else{
    if(B>C){B}
    if(C>B){C}
}
*/

// 15:14-16:22
#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cctype>

using namespace std;

// 0甲输，1甲赢，2平
void win(string aa,string bb,string& a_c,string& a_j,string& a_b,string& b_c,string& b_j,string& b_b){
    if(aa == bb){}
    if(aa+bb == "CJ"){a_c += "0";}
    if(aa+bb == "CB"){b_b += "0";}
    if(aa+bb == "BC"){a_b += "0";}
    if(aa+bb == "BJ"){b_j += "0";}
    if(aa+bb == "JC"){b_c += "0";}
    if(aa+bb == "JB"){a_j += "0";}
}
string who(string c,string j,string b){
    if(c.size() == j.size()){
        if(b.size() == c.size()){return b;}
        else if(b.size() > c.size()){return b;}
        else{return c;}
    }
    else if(c.size() > j.size()){
        if(b.size() == c.size()){return b;}
        else if(b.size() > c.size()){return b;}
        else{return c;}
    }
    else{
        if(b.size() == j.size()){return b;}
        else if(b.size() > j.size()){return b;}
        else{return j;}
    }
}

int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    string a_c("C"),a_j("J"),a_b("B"),b_c("C"),b_j("J"),b_b("B");
    int n,win_n,lose_n,ok_n;
    cin >> n;
    for(int i = 0;i<n;i++){
        string aa,bb;
        cin >> aa >> bb;
        win(aa,bb,a_c,a_j,a_b,b_c,b_j,b_b);
    }
    int b_win = b_c.size()+b_j.size()+b_b.size()-3;
    int a_win = a_c.size()+a_j.size()+a_b.size()-3;
    int ab = n - a_win - b_win;
    printf("%d %d %d\n",a_win,ab,b_win);
    printf("%d %d %d\n",b_win,ab,a_win);
    string a_s = who(a_c,a_j,a_b);
    string b_s = who(b_c,b_j,b_b);
    cout << a_s[0] << " " << b_s[0];
}   

    
