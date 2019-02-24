/*
1109 Group Photo （25 分）
Formation is very important when taking a group photo. Given the rules of forming K rows with N people as the following:

The number of people in each row must be N/K (round down to the nearest integer), with all the extra people (if any) standing in the last row;

All the people in the rear row must be no shorter than anyone standing in the front rows;

In each row, the tallest one stands at the central position (which is defined to be the position (m/2+1), where m is the total number of people in that row, and the division result must be rounded down to the nearest integer);

In each row, other people must enter the row in non-increasing order of their heights, alternately taking their positions first to the right and then to the left of the tallest one (For example, given five people with their heights 190, 188, 186, 175, and 170, the final formation would be 175, 188, 190, 186, and 170. Here we assume that you are facing the group so your left-hand side is the right-hand side of the one at the central position.);

When there are many people having the same height, they must be ordered in alphabetical (increasing) order of their names, and it is guaranteed that there is no duplication of names.

Now given the information of a group of people, you are supposed to write a program to output their formation.

Input Specification:
Each input file contains one test case. For each test case, the first line contains two positive integers N (≤10
​4
​​ ), the total number of people, and K (≤10), the total number of rows. Then N lines follow, each gives the name of a person (no more than 8 English letters without space) and his/her height (an integer in [30, 300]).

Output Specification:
For each case, print the formation -- that is, print the names of people in K lines. The names must be separated by exactly one space, but there must be no extra space at the end of each line. Note: since you are facing the group, people in the rear rows must be printed above the people in the front rows.
*/
/*
总结：逻辑其实很清楚，别太快敲代码，搞清逻辑细节后再动手
*/


#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<unordered_map>

using namespace std;
string ch[100000];
struct Node{
    string name;
    int height;
};
bool cmp(Node a,Node b){
    if(a.height>b.height){return true;}
    else if(a.height == b.height){
        return a.name < b.name;
    }
    else{return false;}
}
vector<Node> ve;

void pushname(int left,int right){
    int number = right - left;
    int medium = number/2+1;
    int pos_na = 1;
    int cnt = 0;
    int index = left;
    int ch_place = 50000;
    for(int i = 0;i<number;i++){
        ch_place = ch_place+cnt*pos_na;
        ch[ch_place]=ve[index].name;
        cnt++;
        pos_na = pos_na*(-1);
        index++;
    }
    if(ch_place>50000){ch_place = ch_place-number+1;}
    for(int i = ch_place;i<ch_place+number;i++){
        if(i!=ch_place){cout << " ";}
        cout<<ch[i];
    }
}

int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    int N,K; scanf("%d%d",&N,&K);
    int curly = N/K;
    int end = N%curly + curly; //最后一行人数
    for(int i = 0;i<N;i++){
        Node node; cin >> node.name >> node.height;
        ve.push_back(node);
    }
    sort(ve.begin(),ve.end(),cmp);
    for(int i = 0;i<N;){
        int left,right;
        //最后一排
        if(i == 0){
            left = 0; right = end;
            pushname(left,right);
            i += end;
            cout << "\n";
        }
        else{
            left = i; right = i+curly;
            pushname(left,right);
            i += curly;
            cout << "\n";
        }
    }
    return 0;
}