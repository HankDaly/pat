/*1042 字符统计（20 分）
请编写程序，找出一段给定文字中出现最频繁的那个英文字母。

输入格式：
输入在一行中给出一个长度不超过 1000 的字符串。字符串由 ASCII 码表中任意可见字符及空格组成，至少包含 1 个英文字母，以回车结束（回车不算在内）。

输出格式：
在一行中输出出现频率最高的那个英文字母及其出现次数，其间以空格分隔。如果有并列，则输出按字母序最小的那个字母。统计时不区分大小写，输出小写字母。

输入样例：
This is a simple TEST.  There ARE numbers and other symbols 1&2&3...........
输出样例：
e 7
*/

/*
注意不区分大小写.
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
int ch[1005];
int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    memset(ch,0,sizeof(ch));
    string A; getline(cin,A);
    int A_len = A.size();
    int max = 0; string max_s;
    for(int i = 0;i<A_len;i++){
        if(isalpha(A[i])){
            A[i] = tolower(A[i]);
            int temp = A[i];
            string temp_s;
            temp_s = A[i];
            ch[temp]++;
            if(ch[temp] > max){max = ch[temp];max_s = temp_s;}
            if(ch[temp] == max){
                if(temp_s<max_s){max_s = temp_s;}
            }
        }
    }
    cout << max_s << " " << max;
    

    return 0;
}
