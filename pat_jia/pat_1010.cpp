/*
1010 Radix （25 分）
Given a pair of positive integers, for example, 6 and 110, can this equation 6 = 110 be true? The answer is yes, if 6 is a decimal number and 110 is a binary number.

Now for any pair of positive integers N
​1
​​  and N
​2
​​ , your task is to find the radix of one number while that of the other is given.

Input Specification:
Each input file contains one test case. Each case occupies a line which contains 4 positive integers:


N1 N2 tag radix

Here N1 and N2 each has no more than 10 digits. A digit is less than its radix and is chosen from the set { 0-9, a-z } where 0-9 represent the decimal numbers 0-9, and a-z represent the decimal numbers 10-35. The last number radix is the radix of N1 if tag is 1, or of N2 if tag is 2.

Output Specification:
For each test case, print in one line the radix of the other number so that the equation N1 = N2 is true. If the equation is impossible, print Impossible. If the solution is not unique, output the smallest possible radix.

Sample Input 1:
6 110 1 10
Sample Output 1:
2
Sample Input 2:
1 ab 1 2
Sample Output 2:
Impossible
*/

/*
总结:
题目大意是，给你一个N1，N2，然后知道其中一个的进制，求另外一个取多少进制能和另一个的值相等。
刚开始的想法是，将其他进制的值都转化为十进制比较。比如110，从2开始往上遍历，每次都转化成十进制和另一个值比较。
直到等于或者大于为止。
但是这个方法需要一个一个往上加上去，有两个case点超时了。
想到用二分查找的方法，下限知道，但是我只知道上限的十进制值，而不知道上限的进制数是多少。
网上看了别人的做法，直接拿最大的值当作最大进制数，也就是说当N等于1的时候，直接取这个进制就等于对面的值了。
后来想了一下，的确二分法的上限是要高于答案的,我之前一直在想怎么把值转化为进制的条件。但其实这个条件足够当作
二分法的high了
。
坑点，用long long 也会溢出，溢出的话就是负值，所以负的时候也是算很大的情况。
还有一个点:二分法中当一开始lower高于high的时候，不要直接退出，取high等于lower，有可能有特殊的情况在内.

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
long long conversion(string& N,long long radix){
    int N_len = N.size();
    long long sum = 0;
    int cnt = 0;
    for(int i = N_len-1;i >= 0;i--){
        int N_int;
        if(isdigit(N[i])){N_int = N[i] - '0';}
        else{N_int = (N[i] - 'a') + 10;}
        sum += pow(radix,cnt)*N_int;
        ++cnt;
    }
    return sum;
}

long long find_radix(string N,long long now_number,int low_int){
    long long low = low_int;
    long long high = max(low,now_number);
    while(low<=high){
        long long mid = (low+high)/2;
        long long temp = conversion(N,mid);
        cout << temp << endl;
        if(temp > now_number||temp < 0){high = mid-1;}
        else if(temp == now_number){return mid;}
        else{low = mid+1;}
    }
    return -1;
}

int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    string N1,N2; cin >> N1 >> N2;
    int tag; cin >> tag;
    long long radix; cin >> radix;
    string wait,now;
    if(tag == 1){now = N1;wait = N2;}
    else{now = N2;wait = N1;}

    long long now_int = conversion(now,radix);
    int max = 0,wait_len = wait.size();
    for(int i = 0;i<wait_len;i++){
        int wait_int;
        if(isdigit(wait[i])){wait_int = wait[i]-'0';}
        else{wait_int = (wait[i]-'a')+10;}
        if(wait_int > max){max = wait_int;}
    }
    int wait_radix = max+1;
    long long reluse = find_radix(wait,now_int,wait_radix);
    if(reluse == -1){cout << "Impossible";}
    else{cout << reluse;}
    return 0;
}