/*
1132 Cut Integer （20 分）
Cutting an integer means to cut a K digits lone integer Z into two integers of (K/2) digits long integers A and B. For example, after cutting Z = 167334, we have A = 167 and B = 334. It is interesting to see that Z can be devided by the product of A and B, as 167334 / (167 × 334) = 3. Given an integer Z, you are supposed to test if it is such an integer.

Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (≤ 20). Then N lines follow, each gives an integer Z (10 ≤ Z <2
​31
​​ ). It is guaranteed that the number of digits of Z is an even number.

Output Specification:
For each case, print a single line Yes if it is such a number, or No if not.

Sample Input:
3
167334
2333
12345678
Sample Output:
Yes
No
No
*/
/*
可能会切到000的情况，注意
*/
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<unordered_map>

using namespace std;
int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    int N; cin >> N;
    for(int i = 0;i<N;i++){
        int flag = 0;
        int number; cin >> number;
        string st_number = to_string(number);
        int length = st_number.size();
        if(length%2 != 0){flag = 0;}
        else{
            int K = length/2;
            int left = stoi(st_number.substr(0,K));
            int right = stoi(st_number.substr(K,K));
            if( left!=0 && right !=0 && number%(left*right)==0){flag = 1;}
        }
        if(flag == 1){cout << "Yes\n";}
        else{cout << "No\n";}

   }
    return 0;
}