/*
1029 Median （25 分）
Given an increasing sequence S of N integers, the median is the number at the middle position. For example, the median of S1 = { 11, 12, 13, 14 } is 12, and the median of S2 = { 9, 10, 15, 16, 17 } is 15. The median of two sequences is defined to be the median of the nondecreasing sequence which contains all the elements of both sequences. For example, the median of S1 and S2 is 13.

Given two increasing sequences of integers, you are asked to find their median.

Input Specification:
Each input file contains one test case. Each case occupies 2 lines, each gives the information of a sequence. For each sequence, the first positive integer N (≤2×10
​5
​​ ) is the size of that sequence. Then N integers follow, separated by a space. It is guaranteed that all the integers are in the range of long int.

Output Specification:
For each test case you should output the median of the two given sequences in a line.

Sample Input:
4 11 12 13 14
5 9 10 15 16 17
Sample Output:
13
*/
/*
总结:
给的空间很少，所以开不了hash表做。想一想最少用多少空间？需要为两个line都开空间吗？
最省空间的就是只给一个line开空间，剩下一个line在线读。
分别讨论三种情况，第一个line读完了还没到中位数。第二个line读完了还没到中位数。读到中间就达到了中位数。
如果存的读完了，那么第二组继续cin>>,直到cin>>到中位数的数字(注意这里由于读完的那次判断已经多cin了一次，所以后面单独的时候要少一次)
如果cin>>完了还没到，那么就在存的数组里面往后+直接索引即可
如果中途就达到了，选取当时情况下较小的那个数当作答案即可。
注意计算median数的时候需要相加N_1与N_2,应该用long long 存。
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
int  ch_1[200005];

main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    long N_1; cin >> N_1;
    memset(ch_1,0,sizeof(ch_1));
    for(int i = 0;i<N_1;i++){
        cin >> ch_1[i];
    }
    long N_2; cin >> N_2;
    long long N_sum = N_1+N_2;
    long N_median;
    long anwser;
    long cnt_1 = 0,cnt_2 = 0;
    if(N_sum%2 == 0){N_median = N_sum/2 - 1;}
    else{N_median = N_sum/2;}
    int ok = 0;
    long temp;
    for(int i = 0;i<N_2;i++){
        cin >> temp;
        for(int z = cnt_1;z<N_1;z++){
            if(cnt_1 + cnt_2 == N_median){anwser = ch_1[cnt_1] <= temp?ch_1[cnt_1]:temp;ok = 1;break;}
            if(ch_1[z]<=temp){++cnt_1;}
            else{break;}
        }
        if(ok != 0){break;}
        if(cnt_1 == N_1){ok = 2;break;}
        ++cnt_2;
    }
    if(ok == 1){cout << anwser;}
    else if(ok == 0){cout << ch_1[N_median-N_2];}
    else{
        for(int i = 0;i<=N_median-N_1;i++){
            long temp_1;
            if(i == 0){temp_1 = temp;}
            else{cin >> temp_1;}
            if(i == N_median-N_1){cout << temp_1;}
        }
    }
    return 0;
}