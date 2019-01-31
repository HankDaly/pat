/*
1060 Are They Equal （25 分）
If a machine can save only 3 significant digits, the float numbers 12300 and 12358.9 are considered equal since they are both saved as 0.123×10
​5
​​  with simple chopping. Now given the number of significant digits on a machine and two float numbers, you are supposed to tell if they are treated equal in that machine.

Input Specification:
Each input file contains one test case which gives three numbers N, A and B, where N (<100) is the number of significant digits, and A and B are the two float numbers to be compared. Each float number is non-negative, no greater than 10
​100
​​ , and that its total digit number is less than 100.

Output Specification:
For each test case, print in a line YES if the two numbers are treated equal, and then the number in the standard form 0.d[1]...d[N]*10^k (d[1]>0 unless the number is 0); or NO if they are not treated equal, and then the two numbers in their standard form. All the terms must be separated by a space, with no extra space at the end of a line.

Note: Simple chopping is assumed without rounding.

Sample Input 1:
3 12300 12358.9
Sample Output 1:
YES 0.123*10^5
Sample Input 2:
3 120 128
Sample Output 2:
NO 0.120*10^3 0.128*10^3

*/
/*
总结：
主要是理解题意，理解保留前三位的意思.1234保留前三位不用多说是0.123指数是10^4,但是0.01234就得从1开始保留
指数是10^-1.也就是让我们转化成科学计算数，求0.后面的数字与指数是否相同。
注意0的情况 3 0.000 0 应该输出YES 0.000*10^0
注意前面有零的情况 01234以及023.33,应该先将这些前面的零处理干净.
*/

#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>

using namespace std;

string getindiefier(string A,int& flag){
    string temp;
    for(int i = 0;i<A.size();i++){
        if(A[i] == '0'){}
        else{temp = A.substr(i,A.size()-i);break;}
    }
    if(temp[0] == '.'){
        temp = "0"+temp;
    }
    int ok = 0;
    for(int i = 0;i<temp.size();i++){
        if(temp[i] != '0' && temp[i] != '.'){ok = 1;break;}
    }
    if(ok == 0){flag = 0;return "0";}
    else if(temp[1] == '.' && temp[0] == '0'){flag = -1;return temp;}
    else{flag = 1;return temp;}
}

string getexponend(string A,int &exponend,int N){
    string re_A;
    string now_st;
    int flag;
    re_A = getindiefier(A,flag);
    if(flag == -1){
        for(int i = 2;i<re_A.size();i++){
            if(re_A[i] != '0'){now_st = re_A.substr(i,re_A.size()-i);break;}
            else{exponend--;}
        }
    }
    else if(flag == 1){
        int site = 0;
        for(int i = 0;i<re_A.size();i++){
            if(re_A[i] == '.'){site = i;break;}
            else{exponend++;}
        }
        if(site == 0){now_st = re_A;}
        else{now_st = re_A.substr(0,site)+re_A.substr(site+1,re_A.size()-site);}
    }
    else{now_st = "0",exponend = 0;}
    string now_re_st;
    for(int i = 0;i<N;i++){
        if(i+1 > now_st.size()){now_re_st+="0";}
        else{now_re_st += now_st[i];}
    }
    return now_re_st;
}

int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    int N; cin >> N;
    string A,B; cin >> A >> B;
    string A_st,B_st;
    int A_exponend = 0,B_exponend = 0;
    A_st = getexponend(A,A_exponend,N);
    B_st = getexponend(B,B_exponend,N);
    if(A_st == B_st && A_exponend == B_exponend){cout << "YES 0." << A_st << "*10^" << A_exponend;}
    else{cout << "NO 0." << A_st << "*10^" << A_exponend << " 0." << B_st << "*10^" << B_exponend;}
    return 0;
}