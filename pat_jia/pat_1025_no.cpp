/*1025 PAT Ranking （25 分）
Programming Ability Test (PAT) is organized by the College of Computer Science and Technology of Zhejiang University. Each test is supposed to run simultaneously in several places, and the ranklists will be merged immediately after the test. Now it is your job to write a program to correctly merge all the ranklists and generate the final rank.

Input Specification:
Each input file contains one test case. For each case, the first line contains a positive number N (≤100), the number of test locations. Then N ranklists follow, each starts with a line containing a positive integer K (≤300), the number of testees, and then K lines containing the registration number (a 13-digit number) and the total score of each testee. All the numbers in a line are separated by a space.

Output Specification:
For each test case, first print in one line the total number of testees. Then print the final ranklist in the following format:

registration_number final_rank location_number local_rank
The locations are numbered from 1 to N. The output must be sorted in nondecreasing order of the final ranks. The testees with the same score must have the same rank, and the output must be sorted in nondecreasing order of their registration numbers.

Sample Input:
2
5
1234567890001 95
1234567890005 100
1234567890003 95
1234567890002 77
1234567890004 85
4
1234567890013 65
1234567890011 25
1234567890014 100
1234567890012 85
Sample Output:
9
1234567890005 1 1 1
1234567890014 1 2 1
1234567890001 3 1 2
1234567890003 3 1 2
1234567890004 5 1 4
1234567890012 5 2 2
1234567890002 7 1 5
1234567890013 8 2 3
1234567890011 9 2 4

*/
/*
总结:
题目大意是进行一个rank排名，主要就是并列时候的处理。大致手法是，设置一个temp分数与cnt，一开始为-1。每当当前的分数与
temp分数不同的时候，cnt就重置为当前的总计数。并且temp变为当前的分数。
区域之间的排名采用二重数组解决
*/
/*
单词:
immediately 立即
register 注册
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
struct Node{
    string id;
    int grade;
    int local_number;
};
vector<Node> ve;
bool cmp(Node a,Node b){
    if(a.grade == b.grade){return a.id < b.id;}
    else{return a.grade > b.grade;}
}
int ch[105][3];
int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    memset(ch,0,sizeof(ch));
    int N; cin >> N;
    for(int i = 0;i<N;i++){
        int K; cin >> K;
        for(int z = 0;z<K;z++){
            Node node;
            cin >> node.id >> node.grade;
            node.local_number = i+1;
            ve.push_back(node);
        }
    }
    for(int i = 0;i<105;i++){
        ch[i][0] = -1;
    }
    sort(ve.begin(),ve.end(),cmp);
    int ve_len = ve.size();
    int common_nu = 0;
    int temp = -1,cnt = 1;
    cout << ve_len << endl;
    for(int i = 0;i<ve_len;i++){
        cout << ve[i].id << " ";
        if(ve[i].grade != temp){temp = ve[i].grade;cnt = i+1;}
        cout << cnt << " ";
        cout << ve[i].local_number << " ";
        ++ch[ve[i].local_number][1];
        if(ch[ve[i].local_number][0] != ve[i].grade){ch[ve[i].local_number][0] = ve[i].grade;ch[ve[i].local_number][2] = ch[ve[i].local_number][1];}
        cout << ch[ve[i].local_number][2] << endl;
    }
    return 0;
}