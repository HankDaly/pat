/*
1077 Kuchiguse （20 分）
The Japanese language is notorious for its sentence ending particles. Personal preference of such particles can be considered as a reflection of the speaker's personality. Such a preference is called "Kuchiguse" and is often exaggerated artistically in Anime and Manga. For example, the artificial sentence ending particle "nyan~" is often used as a stereotype for characters with a cat-like personality:

Itai nyan~ (It hurts, nyan~)

Ninjin wa iyada nyan~ (I hate carrots, nyan~)

Now given a few lines spoken by the same character, can you find her Kuchiguse?

Input Specification:
Each input file contains one test case. For each case, the first line is an integer N (2≤N≤100). Following are N file lines of 0~256 (inclusive) characters in length, each representing a character's spoken line. The spoken lines are case sensitive.

Output Specification:
For each test case, print in one line the kuchiguse of the character, i.e., the longest common suffix of all N lines. If there is no such suffix, write nai.

Sample Input 1:
3
Itai nyan~
Ninjin wa iyadanyan~
uhhh nyan~
Sample Output 1:
nyan~
Sample Input 2:
3
Itai!
Ninjinnwaiyada T_T
T_T
Sample Output 2:
nai
*/
/*
总结：
理解题意即可，注意反转以及整行读取时候的换行符
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
string ch[105];
main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    memset(ch,0,sizeof(ch));
    int N; scanf("%d",&N);
    getchar();
    for(int i = 0;i<N;i++){
        string temp; getline(cin,temp);
        reverse(temp.begin(),temp.end());
        ch[i] = temp;
    }
    string anwser;
    int ok = 0;
    for(int i = 0;i<256;i++){
        int flag = 0;
        char now = ch[0][i];
        for(int z = 0;z<N;z++){
            if(ch[z].size() <= i){flag = 1;break;}
            if(ch[z][i] != now){flag = 1;break;}
        }
        if(flag == 1){break;}
        else{anwser += now; ok = 1;}
    }
    if(ok == 0){cout << "nai";}
    else{
        reverse(anwser.begin(),anwser.end());
        cout << anwser;
    }
}