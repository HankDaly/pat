/*
1027 Colors in Mars （20 分）
People in Mars represent the colors in their computers in a similar way as the Earth people. That is, a color is represented by a 6-digit number, where the first 2 digits are for Red, the middle 2 digits for Green, and the last 2 digits for Blue. The only difference is that they use radix 13 (0-9 and A-C) instead of 16. Now given a color in three decimal numbers (each between 0 and 168), you are supposed to output their Mars RGB values.

Input Specification:
Each input file contains one test case which occupies a line containing the three decimal color values.

Output Specification:
For each test case you should output the Mars RGB value in the following format: first output #, then followed by a 6-digit number where all the English characters must be upper-cased. If a single color is only 1-digit long, you must print a 0 to its left.

Sample Input:
15 43 71
Sample Output:
#123456
*/
/*
总结:
就是把十进制转化为十三进制。
因为大小才168，直接开个hash表即可.
注意一点就是10的时候应该是'A'+(temp-10);而不是-9
*/
/*
单词
upper-case 大写
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
string ch[170];
int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    for(int i = 0;i<170;i++){
        int up,down;
        string up_st,down_st,result;
        up = i/13;
        down = i%13;
        if(up > 9){up_st = ('A'+(up-10));}
        else{up_st = '0'+up;}
        if(down > 9){down_st = ('A'+(down-10));}
        else{down_st = '0'+down;}
        result = up_st + down_st;
        ch[i] = result;
    }
    int A,B,C; cin >> A >> B >> C;
    cout << "#" << ch[A] << ch[B] << ch[C];
    return 0;
}