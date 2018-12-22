/*
1036 Boys vs Girls （25 分）
This time you are asked to tell the difference between the lowest grade of all the male students and the highest grade of all the female students.

Input Specification:
Each input file contains one test case. Each case contains a positive integer N, followed by N lines of student information. Each line contains a student's name, gender, ID and grade, separated by a space, where name and ID are strings of no more than 10 characters with no space, gender is either F (female) or M (male), and grade is an integer between 0 and 100. It is guaranteed that all the grades are distinct.

Output Specification:
For each test case, output in 3 lines. The first line gives the name and ID of the female student with the highest grade, and the second line gives that of the male student with the lowest grade. The third line gives the difference grade
​F
​​ −grade
​M
​​ . If one such kind of student is missing, output Absent in the corresponding line, and output NA in the third line instead.

Sample Input 1:
3
Joe M Math990112 89
Mike M CS991301 100
Mary F EE990830 95
Sample Output 1:
Mary EE990830
Joe Math990112
6
Sample Input 2:
1
Jean M AA980920 60
Sample Output 2:
Absent
Jean AA980920
NA
*/

/*
总结：
常规的一道排序题
*/

#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>

using namespace std;
struct Node{
    string name;
    string fm;
    string id;
    int grade;
};

vector<Node> ve_f;
vector<Node> ve_m;


bool cmp_small(Node a,Node b){return a.grade < b.grade;}
bool cmp_big(Node a,Node b){return a.grade > b.grade;}

int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    int N; cin >> N;
    for(int i = 0;i<N;i++){
        Node node;
        cin >> node.name >> node.fm >> node.id >> node.grade;
        if(node.fm == "M"){ve_m.push_back(node);}
        else{ve_f.push_back(node);} 
    }
    sort(ve_f.begin(),ve_f.end(),cmp_big);
    sort(ve_m.begin(),ve_m.end(),cmp_small);
    //前期准备完成
    if(ve_f.size() == 0){
        cout << "Absent" << "\n" << ve_m[0].name  << " " << ve_m[0].id << "\n" << "NA";
    }
    else if(ve_m.size() == 0){
        cout << ve_f[0].name << " " << ve_f[0].id << "\n" << "Absent" << "\n" << "NA";
    }
    else{
        cout << ve_f[0].name << " " << ve_f[0].id;
        cout << "\n";
        cout << ve_m[0].name << " " << ve_m[0].id;
        cout << "\n";
        cout << ve_f[0].grade-ve_m[0].grade;
    }
   return 0;
}