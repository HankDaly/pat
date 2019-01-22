/*
1048 Find Coins （25 分）
Eva loves to collect coins from all over the universe, including some other planets like Mars. One day she visited a universal shopping mall which could accept all kinds of coins as payments. However, there was a special requirement of the payment: for each bill, she could only use exactly two coins to pay the exact amount. Since she has as many as 10
​5
​​  coins with her, she definitely needs your help. You are supposed to tell her, for any given amount of money, whether or not she can find two coins to pay for it.

Input Specification:
Each input file contains one test case. For each case, the first line contains 2 positive numbers: N (≤10
​5
​​ , the total number of coins) and M (≤10
​3
​​ , the amount of money Eva has to pay). The second line contains N face values of the coins, which are all positive numbers no more than 500. All the numbers in a line are separated by a space.

Output Specification:
For each test case, print in one line the two face values V
​1
​​  and V
​2
​​  (separated by a space) such that V
​1
​​ +V
​2
​​ =M and V
​1
​​ ≤V
​2
​​ . If such a solution is not unique, output the one with the smallest V
​1
​​ . If there is no solution, output No Solution instead.

Sample Input 1:
8 15
1 2 8 7 2 4 11 15
Sample Output 1:
4 11
Sample Input 2:
7 14
1 8 7 2 4 11 15
Sample Output 2:
No Solution
*/
/*
总结:
用twopint的思想，排序后从两头开始匹配。因为前面是从小到大的，所以从末尾逐渐向头排的时候，要记录小于M的情况
第二次排就从小于M的那个数开始，因为我们知道，1号位大于0号位，所以与0号位相加大于M,与1号位相加也肯定大于M。
还有注意一开始就可以将大于M的数去掉。
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
vector<int> ve;

main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    int N,M; cin >> N >> M;
    for(int i = 0;i<N;i++){
        int temp; cin >> temp;
        if(temp < M){ve.push_back(temp);}
    }
    sort(ve.begin(),ve.end());
    int ve_length = ve.size();
    int end_point = ve_length-1,start_point = 0;
    int flag = 0;
    int i = 0;
    int anwser_v1,anwser_v2;
    while(i <= end_point){
        //如果和上一个一样直接跳过
        if(i!=0 && ve[i] == ve[start_point]){i++;continue;}
        else{
            for(int z = end_point;z>i;z--){
                if(ve[z] + ve[i] == M){anwser_v1 = ve[i];anwser_v2 = ve[z];flag = 1;break;}
                else if(ve[z] + ve[i] > M){continue;}
                else{end_point = z;break;}
            }
            if(flag == 1){break;}
        }
        start_point = i++;
    }
    if(flag == 1){cout << anwser_v1 << " " << anwser_v2;}
    else{cout << "No Solution";}
    return 0;
}