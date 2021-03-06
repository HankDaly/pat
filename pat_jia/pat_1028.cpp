/*
1028 List Sorting （25 分）
Excel can sort records according to any column. Now you are supposed to imitate this function.

Input Specification:
Each input file contains one test case. For each case, the first line contains two integers N (≤10
​5
​​ ) and C, where N is the number of records and C is the column that you are supposed to sort the records with. Then N lines follow, each contains a record of a student. A student's record consists of his or her distinct ID (a 6-digit number), name (a string with no more than 8 characters without space), and grade (an integer between 0 and 100, inclusive).

Output Specification:
For each test case, output the sorting result in N lines. That is, if C = 1 then the records must be sorted in increasing order according to ID's; if C = 2 then the records must be sorted in non-decreasing order according to names; and if C = 3 then the records must be sorted in non-decreasing order according to grades. If there are several students who have the same name or grade, they must be sorted according to their ID's in increasing order.

Sample Input 1:
3 1
000007 James 85
000010 Amy 90
000001 Zoe 60
Sample Output 1:
000001 Zoe 60
000007 James 85
000010 Amy 90
Sample Input 2:
4 2
000007 James 85
000010 Amy 90
000001 Zoe 60
000002 James 98
Sample Output 2:
000010 Amy 90
000002 James 98
000007 James 85
000001 Zoe 60
Sample Input 3:
4 3
000007 James 85
000010 Amy 90
000001 Zoe 60
000002 James 90
Sample Output 3:
000001 Zoe 60
000007 James 85
000002 James 90
000010 Amy 90
*/
/*
总结:
简单的排序题，注意id用int读取，虽然用string方便，但是会超时，最后打印时用printf(%05d)
*/
/*
单词:
imitate 模拟
record 记录
increase 增加
column 纵行
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
    int id;
    string name;
    string grade;
};
vector<Node> ve;

bool cmp_1(Node a,Node b){return a.id < b.id;}
bool cmp_2(Node a,Node b){
    if(a.name == b.name){return a.id < b.id;}
    else{return a.name < b.name;}
}
bool cmp_3(Node a,Node b){
    if(a.grade == b.grade){return a.id < b.id;}
    else{return a.grade < b.grade;} 
}
main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    int N,C; cin >> N >> C;
    for(int i = 0;i<N;i++){
        Node node; cin >> node.id >> node.name >> node.grade;
        ve.push_back(node);
    }
    if(C == 1){sort(ve.begin(),ve.end(),cmp_1);}
    else if(C == 2){sort(ve.begin(),ve.end(),cmp_2);}
    else{sort(ve.begin(),ve.end(),cmp_3);}
    for(int i = 0;i<N;i++){
        printf("%06d",ve[i].id);
        cout << " " << ve[i].name << " " << ve[i].grade << endl;
    }
    return 0;
}