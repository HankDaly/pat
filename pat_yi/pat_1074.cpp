/*
1074 宇宙无敌加法器（20 分）
地球人习惯使用十进制数，并且默认一个数字的每一位都是十进制的。而在 PAT 星人开挂的世界里，每个数字的每一位都是不同进制的，这种神奇的数字称为“PAT数”。每个 PAT 星人都必须熟记各位数字的进制表，例如“……0527”就表示最低位是 7 进制数、第 2 位是 2 进制数、第 3 位是 5 进制数、第 4 位是 10 进制数，等等。每一位的进制 d 或者是 0（表示十进制）、或者是 [2，9] 区间内的整数。理论上这个进制表应该包含无穷多位数字，但从实际应用出发，PAT 星人通常只需要记住前 20 位就够用了，以后各位默认为 10 进制。

在这样的数字系统中，即使是简单的加法运算也变得不简单。例如对应进制表“0527”，该如何计算“6203 + 415”呢？我们得首先计算最低位：3 + 5 = 8；因为最低位是 7 进制的，所以我们得到 1 和 1 个进位。第 2 位是：0 + 1 + 1（进位）= 2；因为此位是 2 进制的，所以我们得到 0 和 1 个进位。第 3 位是：2 + 4 + 1（进位）= 7；因为此位是 5 进制的，所以我们得到 2 和 1 个进位。第 4 位是：6 + 1（进位）= 7；因为此位是 10 进制的，所以我们就得到 7。最后我们得到：6203 + 415 = 7201。

输入格式：
输入首先在第一行给出一个 N 位的进制表（0 < N ≤ 20），以回车结束。 随后两行，每行给出一个不超过 N 位的非负的 PAT 数。

输出格式：
在一行中输出两个 PAT 数之和。

输入样例：
30527
06203
415
输出样例：
7201
*/
/*
总结:
问题有几点.
1.A,B字符串要拓展到比stmple长一位，存在进位的可能。
2.除余的时候注意余数不能为0
3.0代表10进制
4.最后输出的时候一开始想用stoi处理前面的零，但是位数太大了，手动处理，手动的化得单独讨论都是0的情况.
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
    string simple,A,B; cin >> simple >> A >> B;
    int A_len = A.size(),B_len = B.size(),simple_len = simple.size();
    B.insert(B.begin(),simple_len-B_len+1,'0');
    A.insert(A.begin(),simple_len-A_len+1,'0');
    A_len = A.size(); B_len = B.size();
    string sum; int go_temp = 0;
    int z = simple_len - 1;
    for(int i = B_len -1;i>=0;i--){
        int sub,mu,temp;
        sub = (A[i]-'0')+(B[i]-'0')+go_temp;
        mu = (simple[z]-'0');
        if(mu == 0){temp = (sub==0)?0:sub%10;go_temp = sub/10;}
        else{
            temp = (sub==0)?0:sub%mu;
            go_temp = sub/mu;
        }
        sum += to_string(temp);
        z--;
    }
    reverse(sum.begin(),sum.end());
    int flag = -1;
    for(int i = 0;i<sum.size();i++){
        if(sum[i] != '0'){flag = i;break;}
    }
    int len = sum.size();
    if(flag == -1){cout << 0;}
    else{cout << sum.substr(flag,len-flag);}
    return 0;
}