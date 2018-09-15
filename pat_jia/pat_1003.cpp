/*
1005 Spell It Right （20 分）
Given a non-negative integer N, your task is to compute the sum of all the digits of N, and output every digit of the sum in English.

Input Specification:
Each input file contains one test case. Each case occupies one line which contains an N (≤10
​100
​​ ).

Output Specification:
For each test case, output in one line the digits of the sum in English words. There must be one space between two consecutive words, but no extra space at the end of a line.

Sample Input:
12345
Sample Output:
one five
*/
/*
总结:
九拼错了。。
*/



#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>

using namespace std;
string ch[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};

int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    string N; cin >> N;
    int N_len = N.size();
    int sum = 0;
    for(int i = 0;i<N_len;i++){
        sum += (N[i]-'0');
    }
    string sum_st = to_string(sum);
    int sum_st_len = sum_st.size();
    for(int i = 0;i<sum_st_len;i++){
        if(i != 0){cout << " ";}
        cout << ch[sum_st[i]-'0'];
    }
    return 0;
}