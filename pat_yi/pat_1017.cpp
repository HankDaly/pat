/*
PAT (Basic Level) Practice （中文）
1700 分
编程题共 85 小题，共计 1700 分
原PAT网站用户可在 https://patest.cn/bind_old_pat_user 页面绑定至拼题A账号。绑定后，原PAT网站的提交将被合并至拼题A网站用户的对应题目集中。
编程题
1017 A除以B（20 分）
本题要求计算 A/B，其中 A 是不超过 1000 位的正整数，B 是 1 位正整数。你需要输出商数 Q 和余数 R，使得 A=B×Q+R 成立。

输入格式：
输入在一行中依次给出 A 和 B，中间以 1 空格分隔。

输出格式：
在一行中依次输出 Q 和 R，中间以 1 空格分隔。

输入样例：
123456789050987654321 7
输出样例：
17636684150141093474 3
作者: CHEN, Yue
单位: 浙江大学
时间限制: 100 ms
内存限制: 64 MB
代码长度限制: 16 KB

*/
/*
总结：
卡在了只有个位数的情况，0在开头无法输出，单独讨论解决.
*/

#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<cctype>
#include<cmath>
#include<algorithm>

using namespace std;
int ch[1005];

main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif 
    string A; cin >> A;
    int B; cin >> B;
    int A_len = A.size();
    for(int i = 0;i<A_len;i++){
        string temp; temp.clear();
        temp += A[i];
        ch[i] = stoi(temp);
    }
    string anwser;
    string anwser_heand;
    int ok = 0;
    for(int i = 0;i<A_len;i++){
        if(i == 0){
            if(ch[i]/B){anwser += to_string(ch[i]/B);ch[i] = ch[i]%B;ok = 1;} //如果第一位大于除数的，就操作，不然保持原样
        }
        else{
            int k = ch[i-1]*10+ch[i];
            if(k/B){anwser += to_string(k/B);ch[i] = k%B;}
            else{anwser += "0";}
        }
    }
    if(A_len == 1 && ok == 0){cout << 0 << " " << A;}
    else{cout << anwser << " " << ch[A_len-1];}
    return 0;
}
