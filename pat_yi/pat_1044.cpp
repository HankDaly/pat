/*
1044 火星数字（20 分）
火星人是以 13 进制计数的：

地球人的 0 被火星人称为 tret。
地球人数字 1 到 12 的火星文分别为：jan, feb, mar, apr, may, jun, jly, aug, sep, oct, nov, dec。
火星人将进位以后的 12 个高位数字分别称为：tam, hel, maa, huh, tou, kes, hei, elo, syy, lok, mer, jou。
例如地球人的数字 29 翻译成火星文就是 hel mar；而火星文 elo nov 对应地球数字 115。为了方便交流，请你编写程序实现地球和火星数字之间的互译。

输入格式：
输入第一行给出一个正整数 N（<100），随后 N 行，每行给出一个 [0, 169) 区间内的数字 —— 或者是地球文，或者是火星文。

输出格式：
对应输入的每一行，在一行中输出翻译后的另一种语言的数字。

输入样例：
4
29
5
elo nov
tam
输出样例：
hel mar
may
115
13
*/
/*
总结:
问题有二点，1.就是如果能被13整除，那么后面不用带零。
2.前面的字符不一定是3，也有可能是4(因为是零)。

注意一开始的数组要检查,就是因为中间有个空搞得检查了半天。
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
string ch_h[13] = {"###","tam","hel","maa","huh","tou","kes","hei","elo","syy ","lok","mer","jou"};
string ch_l[13] = {"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};


int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    int N; cin >> N;
    getchar();
    for(int ii = 0;ii<N;ii++){
        string A; getline(cin,A);
        if(isdigit(A[0])){
            int temp = stoi(A);
            int high = temp/13,lower = temp%13;
            if(high == 0){cout << ch_l[lower] << endl;}
            else{
                cout << ch_h[high];
                if(lower != 0){
                    cout << " " << ch_l[lower];
                }
                cout << endl;
            }
        }
        else{
            //cout << "Aa" << A << endl;
            int A_len = A.size();
            int sum = 0;
            if(A_len>4){
                int a = A_len - 3;
                string high = A.substr(0,3),lower = A.substr(a,3);
                cout << high << lower << endl
                for(int i = 0;i<13;i++){
                    if(ch_h[i] == high){sum += i*13;break;}
                }
                for(int i = 0;i<13;i++){
                    if(ch_l[i] == lower){sum += i;break;}
                }
            }
            else{
                for(int i = 0;i<13;i++){
                    if(ch_l[i] == A){sum = i;break;}
                    else if(ch_h[i] == A){sum = i*13;break;}
                }
            }
            cout << sum << endl;
        } 
    }
    return 0;
}
