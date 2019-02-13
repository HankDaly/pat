/*
1071 Speech Patterns （25 分）
People often have a preference among synonyms of the same word. For example, some may prefer "the police", while others may prefer "the cops". Analyzing such patterns can help to narrow down a speaker's identity, which is useful when validating, for example, whether it's still the same person behind an online avatar.

Now given a paragraph of text sampled from someone's speech, can you find the person's most commonly used word?

Input Specification:
Each input file contains one test case. For each case, there is one line of text no more than 1048576 characters in length, terminated by a carriage return \n. The input contains at least one alphanumerical character, i.e., one character from the set [0-9 A-Z a-z].

Output Specification:
For each test case, print in one line the most commonly occurring word in the input text, followed by a space and the number of times it has occurred in the input. If there are more than one such words, print the lexicographically smallest one. The word should be printed in all lower case. Here a "word" is defined as a continuous sequence of alphanumerical characters separated by non-alphanumerical characters or the line beginning/end.

Note that words are case insensitive.

Sample Input:
Can1: "Can a can can a can?  It can!"
Sample Output:
can 5
*/
/*
总结：题意一开始没读清，对于单词得理解每到位，题目意思是字母数字都算单词其他标点当作空格处理，然后统计数量。
具体实现用map，还有一个分割字符串得设计.
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

unordered_map<string,int> mp;
vector<string> ve;
main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    string N; getline(cin,N);
    int N_length = N.size();
    int first_block = 0,second_block = 0;
    for(int i = 0;i<N_length;i++){
        if(isalnum(N[i])){
            first_block = i;
            int flag = 0;
            //取得单词得末尾点得后一位
            for(int z = i;z<N_length;z++){
                if(!isalnum(N[z])){second_block = z;flag = 1;break;}
            }
            //注意最后得情况
            if(flag == 0){second_block = N_length;}
            //取完
            string sub = N.substr(first_block,second_block - first_block);
            for(int z = 0;z<sub.size();z++){
                sub[z] = tolower(sub[z]);
            }
            //如果存在
            if(mp.count(sub)){mp[sub]++;}
            //如果不存在
            else{mp[sub] = 1;ve.push_back(sub);}
            i = second_block;
        }
    }
    string anwser;
    int cnt = 0;
    for(int i = 0;i<ve.size();i++){
        if(mp[ve[i]]>cnt){
            anwser = ve[i];
            cnt = mp[ve[i]];
        }
        if(mp[ve[i]] == cnt){
            if(ve[i]<anwser){
                anwser = ve[i];
            }
        }
    }
    cout << anwser << " " << cnt;
    return 0;
}