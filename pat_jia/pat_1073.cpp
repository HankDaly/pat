/*
1073 Scientific Notation （20 分）
Scientific notation is the way that scientists easily handle very large numbers or very small numbers. The notation matches the regular expression [+-][1-9].[0-9]+E[+-][0-9]+ which means that the integer portion has exactly one digit, there is at least one digit in the fractional portion, and the number and its exponent's signs are always provided even when they are positive.

Now given a real number A in scientific notation, you are supposed to print A in the conventional notation while keeping all the significant figures.

Input Specification:
Each input contains one test case. For each case, there is one line containing the real number A in scientific notation. The number is no more than 9999 bytes in length and the exponent's absolute value is no more than 9999.

Output Specification:
For each test case, print in one line the input number A in the conventional notation, with all the significant figures kept, including trailing zeros.

Sample Input 1:
+1.23400E-03
Sample Output 1:
0.00123400
Sample Input 2:
-1.2E+10
Sample Output 2:
-12000000000
*/
/*
总结：科学计数法转化为普通数，注意正负时候的讨论，以及0的时候
*/



#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>

using namespace std;



int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    string A; getline(cin,A);
    int A_length = A.size();
    int E_place = 0;
    int dicimal_pona = 0; //判断小数位正负
    string ma; //ma储存主体
    string dicimal; // dicimal储存0得数量
    int int_dicimal;
    //判断
    for(int i = 1;i<A_length;i++){
        if(A[i] == 'E'){E_place = i;}
    }
    //
    if(A[E_place+1] == '+'){dicimal_pona = 1;}
    else{dicimal_pona = -1;}
    //
    ma = A.substr(1,E_place-1);
    string ma_no = ma.substr(0,1)+ma.substr(2,ma.size()-2);
    dicimal = A.substr(E_place+2,A_length-E_place-2);
    int_dicimal = stoi(dicimal);
    //完毕
    if(A[0] == '-'){cout << "-";}
    if(int_dicimal == 0){cout << ma;}
    else{
        if(dicimal_pona < 0){
            cout << "0.";
            for(int i = 1;i<int_dicimal;i++){
                cout << "0";
            }
            cout << ma_no;
        }
        else{
            int number = 1+int_dicimal;
            if(number > ma_no.size()){
                cout << ma_no;
                for(int i = 0;i<number-ma_no.size();i++){
                    cout << "0";
                }
            }
            else if(number == ma_no.size()){
                cout << ma_no;
            }
            else{
                cout << ma_no.substr(0,number);
                cout << ".";
                cout << ma_no.substr(number,ma_no.size()-number);
            }
        }
    }
    return 0;
}