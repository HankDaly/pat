/*
1082 Read Number in Chinese （25 分）
Given an integer with no more than 9 digits, you are supposed to read it in the traditional Chinese way. Output Fu first if it is negative. For example, -123456789 is read as Fu yi Yi er Qian san Bai si Shi wu Wan liu Qian qi Bai ba Shi jiu. Note: zero (ling) must be handled correctly according to the Chinese tradition. For example, 100800 is yi Shi Wan ling ba Bai.

Input Specification:
Each input file contains one test case, which gives an integer with no more than 9 digits.

Output Specification:
For each test case, print in a line the Chinese way of reading the number. The characters are separated by a space and there must be no extra space at the end of the line.

Sample Input 1:
-123456789
Sample Output 1:
Fu yi Yi er Qian san Bai si Shi wu Wan liu Qian qi Bai ba Shi jiu
Sample Input 2:
100800
Sample Output 2:
yi Shi Wan ling ba Bai
*/
/*
总结:找规律以及输出合理的，找规律发现，如果零后还有零那么这个零不发声，如果零后面是别的数字，那么零
发"ling"。这题的空格很难输出，后来发现讨论正负可以解决。最后注意0的情况。
*/

#include<iostream>
#include<cstdio>
#include<unordered_map>
#include<cctype>
#include<string>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cmath>

using namespace std;
string ch[10] = {"Yi","Qian","Bai","Shi","Wan","Qian","Bai","Shi"};
string ch_small[10] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};

int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    string A; cin >> A;
    int zero = 0;
    int flag = 0;
    if(A == "0"){cout << "ling";}
    if(A[0] == '-'){
        flag = 1;
        cout << "Fu";
        A = A.substr(1,A.size()-1);
    }
    for(int i = 0;i<A.size();i++){
        if(A[i] != '0'){zero = i;break;}
    }
    A = A.substr(zero,A.size()-zero);
    //A处理完毕
    int A_length = A.size();
    int A_index = 9-A_length;
    for(int i = 0;i<A.size()-1;i++){
        if(A[i] == '0'){
            if(A[i+1] != '0'){cout << " " << "ling";}
            if(A_index == 4){cout << " "<< ch[A_index];}
        }
        else{
            if(i == 0 && flag == 0){
                cout << ch_small[A[i]-'0'] << " " << ch[A_index];
            }
            else{cout <<" "<< ch_small[A[i]-'0'] << " " << ch[A_index];}
        }
        A_index++;
    }
    if(A[A.size()-1] != '0'){cout <<" "<< ch_small[A[A.size()-1]-'0'];}

    return 0;
}