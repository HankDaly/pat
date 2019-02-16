/*
1083 List Grades （25 分）
Given a list of N student records with name, ID and grade. You are supposed to sort the records with respect to the grade in non-increasing order, and output those student records of which the grades are in a given interval.

Input Specification:
Each input file contains one test case. Each case is given in the following format:

N
name[1] ID[1] grade[1]
name[2] ID[2] grade[2]
... ...
name[N] ID[N] grade[N]
grade1 grade2
where name[i] and ID[i] are strings of no more than 10 characters with no space, grade[i] is an integer in [0, 100], grade1 and grade2 are the boundaries of the grade's interval. It is guaranteed that all the grades are distinct.

Output Specification:
For each test case you should output the student records of which the grades are in the given interval [grade1, grade2] and are in non-increasing order. Each student record occupies a line with the student's name and ID, separated by one space. If there is no student's grade in that interval, output NONE instead.

Sample Input 1:
4
Tom CS000001 59
Joe Math990112 89
Mike CS991301 100
Mary EE990830 95
60 100
Sample Output 1:
Mike CS991301
Mary EE990830
Joe Math990112
Sample Input 2:
2
Jean AA980920 60
Ann CS01 80
90 95
Sample Output 2:
NONE

*/

/*
总结:基础的排序题，就是不知道为什么sort后如果大于grade2其实后面应该都是不符合了，那么按理应该break
可是会报错，这里不明白.
*/

#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<unordered_map>

using namespace std;



struct Node{
    string name;
    string id;
    int grade;
};
vector<Node> ve;
bool cmp(Node a,Node b){
    if(a.grade > b.grade){return true;}
    else{return false;}
}

int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    int N; cin >> N;
    for(int i = 0;i<N;i++){
        Node node; cin >> node.name >> node.id >> node.grade;
        ve.push_back(node);   
    }
    sort(ve.begin(),ve.end(),cmp);

    int grade1,grade2;cin >> grade1 >> grade2;
    int flag = 0;
    for(int i = 0;i<ve.size();i++){
        if(ve[i].grade>=grade1 && ve[i].grade<=grade2){flag = 1;cout << ve[i].name << " " << ve[i].id << "\n";}
    }
    if(flag == 0){cout << "NONE";}
    return 0;
}