/*
1075 PAT Judge （25 分）
The ranklist of PAT is generated from the status list, which shows the scores of the submissions. This time you are supposed to generate the ranklist for PAT.

Input Specification:
Each input file contains one test case. For each case, the first line contains 3 positive integers, N (≤10
​4
​​ ), the total number of users, K (≤5), the total number of problems, and M (≤10
​5
​​ ), the total number of submissions. It is then assumed that the user id's are 5-digit numbers from 00001 to N, and the problem id's are from 1 to K. The next line contains K positive integers p[i] (i=1, ..., K), where p[i] corresponds to the full mark of the i-th problem. Then M lines follow, each gives the information of a submission in the following format:

user_id problem_id partial_score_obtained
where partial_score_obtained is either −1 if the submission cannot even pass the compiler, or is an integer in the range [0, p[problem_id]]. All the numbers in a line are separated by a space.

Output Specification:
For each test case, you are supposed to output the ranklist in the following format:

rank user_id total_score s[1] ... s[K]
where rank is calculated according to the total_score, and all the users with the same total_score obtain the same rank; and s[i] is the partial score obtained for the i-th problem. If a user has never submitted a solution for a problem, then "-" must be printed at the corresponding position. If a user has submitted several solutions to solve one problem, then the highest score will be counted.

The ranklist must be printed in non-decreasing order of the ranks. For those who have the same rank, users must be sorted in nonincreasing order according to the number of perfectly solved problems. And if there is still a tie, then they must be printed in increasing order of their id's. For those who has never submitted any solution that can pass the compiler, or has never submitted any solution, they must NOT be shown on the ranklist. It is guaranteed that at least one user can be shown on the ranklist.

Sample Input:
7 4 20
20 25 25 30
00002 2 12
00007 4 17
00005 1 19
00007 2 25
00005 1 20
00002 2 2
00005 1 15
00001 1 18
00004 3 25
00002 2 25
00005 3 22
00006 4 -1
00001 2 18
00002 1 20
00004 1 15
00002 4 18
00001 3 4
00001 4 2
00005 2 -1
00004 2 0
Sample Output:
1 00002 63 20 25 - 18
2 00005 42 20 0 22 -
2 00007 42 - 25 - 17
2 00001 42 18 18 4 2
5 00004 40 15 0 25 -
*/
/*
总结：挺烦的一道排序题，基本思路是map加vector，只不过要注意很多细小的规则，尤其是如果该生有一道编译通过
了，则就应该显示出来，而不是按他的分数是否大于0去显示
*/


#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<unordered_map>

using namespace std;

struct Node{
    int flag = 0;
    string id;
    int grade = 0;
    int ch[6];
    int prefer = 0;
};
int ch_grade[10];
unordered_map<string,Node> mp;
vector<Node> ve;
vector<string> ve_id;

bool cmp(Node a,Node b){
    if(a.grade == b.grade){
        if(a.prefer > b.prefer){return true;}
        else if(a.prefer == b.prefer){
            if(a.id < b.id){return true;}
            else{return false;}
        }
        else{return false;}
    }
    else{
        if(a.grade > b.grade){return true;}
        else{return false;}
    }
}

int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    memset(ch_grade,0,sizeof(ch_grade));
    int N,K,M; cin >> N >> K >> M;
    for(int i = 1;i<=K;i++){
        cin >> ch_grade[i];
    }
    for(int i = 0;i<M;i++){
        string id; cin >> id;
        if(!mp.count(id)){
            //如果不存在，创建
            Node node; node.id = id;
            for(int z = 0;z<=K;z++){node.ch[z] = -2;}
            mp[id] = node;
            ve_id.push_back(id);
        }
        int number,score; cin >> number >> score;
        if(score > mp[id].ch[number]){
            mp[id].ch[number] = score;
        }
    }
    for(int i = 0;i<ve_id.size();i++){
        Node node = mp[ve_id[i]];
        for(int z = 1;z<=K;z++){
            if(node.ch[z] > 0){node.grade += node.ch[z];}
            if(node.ch[z] == ch_grade[z]){node.prefer++;}
            if(node.ch[z] >=0){node.flag = 1;}
        }
        ve.push_back(node);
    }
    sort(ve.begin(),ve.end(),cmp);
    //处理完毕
    int cnt = 1;
    int temp = 0;
    for(int i = 0;i<ve.size();i++){
        if(ve[i].flag == 1){
            if(ve[i].grade != temp){cout << i+1;temp = ve[i].grade;cnt = i+1;}
            else{cout << cnt;}
            cout << " " << ve[i].id << " " << ve[i].grade;
            for(int z = 1;z<=K;z++){
                cout << " ";
                if(ve[i].ch[z] == -2){cout << "-";}
                else if(ve[i].ch[z] <= 0){cout << 0;}
                else{cout << ve[i].ch[z];}
            }
            cout << "\n";
        }
    }
    return 0;
}