/*
1040 Longest Symmetric String （25 分）
Given a string, you are supposed to output the length of the longest symmetric sub-string. For example, given Is PAT&TAP symmetric?, the longest symmetric sub-string is s PAT&TAP s, hence you must output 11.

Input Specification:
Each input file contains one test case which gives a non-empty string of length no more than 1000.

Output Specification:
For each test case, simply print the maximum length in a line.

Sample Input:
Is PAT&TAP symmetric?
Sample Output:
11
*/
/*
总结:
典型的一道求最长子回文长度的题目。传统的做法是迭代中心，然后分成奇，偶回文去讨论。
还有插入值来规避偶数情况的Manacher算法。
建议这种题目不要用string，直接开字符数组。

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

int LongestPalindrome(const char *s,int n){
    int i, j, max, c;
    if (s == 0 || n<1){return 0;}
    max = 0;
    for(i = 0; i<n; ++i){
        for(j = 0; (i-j>=0) && (i+j < n); ++j){
            if(s[i-j] != s[i+j]){break;}
            c = j*2 + 1;
        }
        if(c>max){max = c;}
        for(j = 0; (i-j >= 0) && (i+j+1 < n);++j){
            if(s[i-j] != s[i+j+1]){break;}
            c = j*2 +2;
        }
        if(c>max){max = c;}
    }
    return max;
}
char s[1005];

main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    cin.getline(s,1005);
    int n = strlen(s);
    int anwser = LongestPalindrome(s,n);
    printf("%d",anwser);
    return 0;
}