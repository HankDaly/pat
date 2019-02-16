/*
1085 Perfect Sequence （25 分）
Given a sequence of positive integers and another positive integer p. The sequence is said to be a perfect sequence if M≤m×p where M and m are the maximum and minimum numbers in the sequence, respectively.

Now given a sequence and a parameter p, you are supposed to find from the sequence as many numbers as possible to form a perfect subsequence.

Input Specification:
Each input file contains one test case. For each case, the first line contains two positive integers N and p, where N (≤10
​5
​​ ) is the number of integers in the sequence, and p (≤10
​9
​​ ) is the parameter. In the second line there are N positive integers, each is no greater than 10
​9
​​ .

Output Specification:
For each test case, print in one line the maximum number of integers that can be chosen to form a perfect subsequence.

Sample Input:
10 8
2 3 20 4 5 1 6 7 8 9
Sample Output:
8
*/
/*
总结：一道two_point题目,注意long long，还有不必刻意的优化，比如认为递增到后面可以直接break出来，这样
可能会漏掉一个得分点
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

vector<long long> ve;
int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    int N,p; cin >> N >> p;
    for(int i = 0;i<N;i++){
        long long temp; cin >> temp;
        ve.push_back(temp);
    }
    sort(ve.begin(),ve.end());
    //整理完毕
    int index = 0;
    int max = 0;
    for(int i = 0;i<ve.size();i++){
        if(i > index){break;}
        for(int z = index;z<ve.size();z++){
            long long anwser = ve[i]*p;
            if(ve[z] > anwser){index = z-1;break;}
            else{index = z;}
            //注意当最后都没超过，要把最后的赋给index
        }
        if(index-i+1 > max){max = index-i+1;}
    }
    cout << max;
    
    return 0;
}