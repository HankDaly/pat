/*
1059 Prime Factors （25 分）
Given any positive integer N, you are supposed to find all of its prime factors, and write them in the format N = p
​1
​​ 
​k
​1
​​ 
​​ ×p
​2
​​ 
​k
​2
​​ 
​​ ×⋯×p
​m
​​ 
​k
​m
​​ 
​​ .

Input Specification:
Each input file contains one test case which gives a positive integer N in the range of long int.

Output Specification:
Factor N in the format N = p
​1
​​ ^k
​1
​​ *p
​2
​​ ^k
​2
​​ *…*p
​m
​​ ^k
​m
​​ , where p
​i
​​ 's are prime factors of N in increasing order, and the exponent k
​i
​​  is the number of p
​i
​​  -- hence when there is only one p
​i
​​ , k
​i
​​  is 1 and must NOT be printed out.

Sample Input:
97532468
Sample Output:
97532468=2^2*11*17*101*1291
*/
/*
总结：
有关质因子的算法
注意，如果一个数没有x以内的质因数，那么他势必大于x*x，而不是2*x
题目的边界条件是N本身是质数的情况
*/



#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>

using namespace std;

int ch[10000];

int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    int count = 1;
    memset(ch,0,sizeof(0));
    ch[0] = 2;
    for(int i = 3;i<90000;i++){
        int ok = 1;
        for(int z = 2;z*z<=i;z++){
            if(i%z == 0){ok = 0;break;}
        }
        if(ok == 1){ch[count] = i;count++;}
    }
    //处理完毕
    long N; cin >> N;
    cout << N << "=";
    int flag = 0;
    for(int i = 0;i<count;i++){
        int cnt = 0;
        while(N%ch[i] == 0){
            cnt++;
            N = N/ch[i];
        }
        if(cnt != 0){
            flag = 1;
            cout << ch[i];
            if(cnt > 1){cout << "^" << cnt;}
            if(N == 1){break;}
            else{cout << "*";}
        }
    }
    if(flag == 0){cout << N;}
    return 0;
}