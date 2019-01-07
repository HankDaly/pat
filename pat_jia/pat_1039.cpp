/*
1039 Course List for Student （25 分）
Zhejiang University has 40000 students and provides 2500 courses. Now given the student name lists of all the courses, you are supposed to output the registered course list for each student who comes for a query.

Input Specification:
Each input file contains one test case. For each case, the first line contains 2 positive integers: N (≤40,000), the number of students who look for their course lists, and K (≤2,500), the total number of courses. Then the student name lists are given for the courses (numbered from 1 to K) in the following format: for each course i, first the course index i and the number of registered students N
​i
​​  (≤200) are given in a line. Then in the next line, N
​i
​​  student names are given. A student name consists of 3 capital English letters plus a one-digit number. Finally the last line contains the N names of students who come for a query. All the names and numbers in a line are separated by a space.

Output Specification:
For each test case, print your results in N lines. Each line corresponds to one student, in the following format: first print the student's name, then the total number of registered courses of that student, and finally the indices of the courses in increasing order. The query results must be printed in the same order as input. All the data in a line must be separated by a space, with no extra space at the end of the line.

Sample Input:
11 5
4 7
BOB5 DON2 FRA8 JAY9 KAT3 LOR6 ZOE1
1 4
ANN0 BOB5 JAY9 LOR6
2 7
ANN0 BOB5 FRA8 JAY9 JOE4 KAT3 LOR6
3 1
BOB5
5 9
AMY7 ANN0 BOB5 DON2 FRA8 JAY9 KAT3 LOR6 ZOE1
ZOE1 ANN0 BOB5 JOE4 JAY9 FRA8 DON2 AMY7 KAT3 LOR6 NON9
Sample Output:
ZOE1 2 4 5
ANN0 3 1 2 5
BOB5 5 1 2 3 4 5
JOE4 1 2
JAY9 4 1 2 4 5
FRA8 3 2 4 5
DON2 2 4 5
AMY7 1 5
KAT3 3 2 4 5
LOR6 4 1 2 4 5
NON9 0
*/
/*
总结：
开hash表贮存后读取。难点在于对于大量的字符数据这次的规模大概是40000*2500*4
string不太合适,应该用char数组储存。然后用字符转int的hash方式来储存。
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

int getid(char *name){
    int id = 0;
    for(int i = 0;i<3;i++){
        id = 26*id + (name[i] - 'A');
    }
    id = id*10 + (name[3] - '0');
    return id;
}

struct Node{
    int id;
    vector<int> ve;
};

unordered_map<int,Node> mp;

main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    char name[5];
    int N,K; cin >> N >> K;
    for(int i = 0;i<K;i++){
        int class_i,Ni; cin >> class_i >> Ni;
        for(int z = 0;z<Ni;z++){
            scanf("%s",name);
            int id = getid(name);
            //如果不存在,新建一个node
            if(!mp.count(id)){
                Node node;
                node.id = id;
                node.ve.push_back(class_i);
                mp[id] = node;
            }
            else{mp[id].ve.push_back(class_i);}
        }
    }
    for(int i = 0;i<N;i++){
        scanf("%s",name);
        int id = getid(name);
        //如果不存在，输出0
        if(!mp.count(id)){printf("%s 0",name);}
        else{
            int length = mp[id].ve.size();
            sort(mp[id].ve.begin(),mp[id].ve.end());
            printf("%s %d",name,length);
            for(int z = 0;z<length;z++){
                printf(" %d",mp[id].ve[z]);
            }
        }
        printf("\n");
    }
    return 0;
}