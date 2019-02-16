/*
1084 Broken Keyboard （20 分）
On a broken keyboard, some of the keys are worn out. So when you type some sentences, the characters corresponding to those keys will not appear on screen.

Now given a string that you are supposed to type, and the string that you actually type out, please list those keys which are for sure worn out.

Input Specification:
Each input file contains one test case. For each case, the 1st line contains the original string, and the 2nd line contains the typed-out string. Each string contains no more than 80 characters which are either English letters [A-Z] (case insensitive), digital numbers [0-9], or _ (representing the space). It is guaranteed that both strings are non-empty.

Output Specification:
For each test case, print in one line the keys that are worn out, in the order of being detected. The English letters must be capitalized. Each worn out key must be printed once only. It is guaranteed that there is at least one worn out key.

Sample Input:
7_This_is_a_test
_hs_s_a_es
Sample Output:
7TI
*/
/*
总结：
常规的hash题目,注意大写
*/




#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<unordered_map>

using namespace std;
int ch[200];

int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    memset(ch,0,sizeof(ch));
    string A,B;cin >> A >> B;
    for(int i = 0;i<A.size();i++){
        if(isalpha(A[i])){A[i] = toupper(A[i]);}
    }
    for(int i = 0;i<B.size();i++){
        if(isalpha(B[i])){B[i] = toupper(B[i]);}
    }
    for(int i = 0;i<B.size();i++){
        int index = B[i]-'!';
        ch[index] = 1;
    }
    for(int i = 0;i<A.size();i++){
        int index = A[i]-'!';
        if(ch[index] == 0){
            cout << A[i];
            ch[index] = 1;
        }

    }
    return 0;
}