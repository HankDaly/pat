/*1023 Have Fun with Numbers （20 分）
Notice that the number 123456789 is a 9-digit number consisting exactly the numbers from 1 to 9, with no duplication. Double it we will obtain 246913578, which happens to be another 9-digit number consisting exactly the numbers from 1 to 9, only in a different permutation. Check to see the result if we double it again!

Now you are suppose to check if there are more numbers with this property. That is, double a given number with k digits, you are to tell if the resulting number consists of only a permutation of the digits in the original number.

Input Specification:
Each input contains one test case. Each case contains one positive integer with no more than 20 digits.

Output Specification:
For each test case, first print in a line "Yes" if doubling the input number gives a number that consists of only a permutation of the digits in the original number, or "No" if not. Then in the next line, print the doubled number.

Sample Input:
1234567899
Sample Output:
Yes
2469135798
*/
/*
总结:
题目大意，给一个20位以内的正整数，要求翻倍后与原来整数内各个数字数量相同，比如原来有3个9，那么翻倍后也必须有
3个9，
整数运算用除和余来做，与原有数字的判断用哈希散列判断。
*/
/*
单词
exactly 准确
consist 组成
property 属性
permutation 组成
*/

#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>


using namespace std;
int ch[25];

int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif 
    memset(ch,0,sizeof(ch));
    string A; cin >> A;
    int A_len = A.size();
    for(int i = 0;i<A_len;i++){
        ++ch[A[i]-'0'];
    }
    string temp;
    int a = 0;
    for(int i = A_len-1;i>=0;i--){
        int now_number = A[i]-'0';
        temp += to_string((now_number*2+a)%10);
        a = (now_number*2+a)/10;
    }
    if(a != 0){temp += to_string(a);}
    reverse(temp.begin(),temp.end());
    int temp_len = temp.size();
    int ok = 1;
    for(int i = 0;i<temp_len;i++){
        if(ch[(temp[i]-'0')] == 0){ok = 0;break;}
        --ch[(temp[i]-'0')];
    }
    if(ok == 0){cout << "No" << endl;}
    else{cout << "Yes" << endl;}
    cout << temp;
    return 0;
}