/*1015 Reversible Primes （20 分）
A reversible prime in any number system is a prime whose "reverse" in that number system is also a prime. For example in the decimal system 73 is a reversible prime because its reverse 37 is also a prime.

Now given any two positive integers N (<10
​5
​​ ) and D (1<D≤10), you are supposed to tell if N is a reversible prime with radix D.

Input Specification:
The input file consists of several test cases. Each case occupies a line which contains two integers N and D. The input is finished by a negative N.

Output Specification:
For each test case, print in one line Yes if N is a reversible prime with radix D, or No if not.

Sample Input:
73 10
23 2
23 10
-2
Sample Output:
Yes
Yes
No
*/ 

/*
总结:
坑点有两个，素数筛法的1漏了,1不是素数。
还有一个就是原大小100000内，但是反转后会超出10的5次，所以范围应该定在10的六次。
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
int ch[1000005];

string tento_other(int a,int radix){
    string temp;
    while(a != 0){
        int rle = a%radix;
        temp += (rle + '0');
        a = (a-rle)/radix;
    }
    return temp;
}
int otherto_ten(string a,int radix){
    int a_len = a.size();
    reverse(a.begin(),a.end());
    int sum = 0;
    for(int i = 0;i<a_len;i++){
        sum += pow(radix,i)*(a[i]-'0');
    }
    return sum;
}

int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    memset(ch,0,sizeof(ch));
    ch[1] = 1;
    for(int i = 2;(i*i)<=100005;i++){
        if(ch[i] == 0){
            for(int z = i+i;z<100005;z += i){
                ch[z] = 1;
            }
        }
    }
    for(;;){
        int N,D; cin >> N >> D;
        if(N<0){break;}
        int ok_1 = 1,ok_2 = 1;
        string temp = tento_other(N,D);
        int N_1 = otherto_ten(temp,D);
        ok_1 = ch[N];
        ok_2 = ch[N_1];
        if(ok_1 == 0 && ok_2 == 0){cout << "Yes" << endl;}
        else{cout << "No" << endl;}
    }
    return 0;
}