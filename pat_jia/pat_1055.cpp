/*1055 The World's Richest （25 分）
Forbes magazine publishes every year its list of billionaires based on the annual ranking of the world's wealthiest people. Now you are supposed to simulate this job, but concentrate only on the people in a certain range of ages. That is, given the net worths of N people, you must find the M richest people in a given range of their ages.

Input Specification:
Each input file contains one test case. For each case, the first line contains 2 positive integers: N (≤10
​5
​​ ) - the total number of people, and K (≤10
​3
​​ ) - the number of queries. Then N lines follow, each contains the name (string of no more than 8 characters without space), age (integer in (0, 200]), and the net worth (integer in [−10
​6
​​ ,10
​6
​​ ]) of a person. Finally there are K lines of queries, each contains three positive integers: M (≤100) - the maximum number of outputs, and [Amin, Amax] which are the range of ages. All the numbers in a line are separated by a space.

Output Specification:
For each query, first print in a line Case #X: where X is the query number starting from 1. Then output the M richest people with their ages in the range [Amin, Amax]. Each person's information occupies a line, in the format

Name Age Net_Worth
The outputs must be in non-increasing order of the net worths. In case there are equal worths, it must be in non-decreasing order of the ages. If both worths and ages are the same, then the output must be in non-decreasing alphabetical order of the names. It is guaranteed that there is no two persons share all the same of the three pieces of information. In case no one is found, output None.

Sample Input:
12 4
Zoe_Bill 35 2333
Bob_Volk 24 5888
Anny_Cin 95 999999
Williams 30 -22
Cindy 76 76000
Alice 18 88888
Joe_Mike 32 3222
Michael 5 300000
Rosemary 40 5888
Dobby 24 5888
Billy 24 5888
Nobody 5 0
4 15 45
4 30 35
4 5 95
1 45 50
Sample Output:
Case #1:
Alice 18 88888
Billy 24 5888
Bob_Volk 24 5888
Dobby 24 5888
Case #2:
Joe_Mike 32 3222
Zoe_Bill 35 2333
Williams 30 -22
Case #3:
Anny_Cin 95 999999
Michael 5 300000
Alice 18 88888
Cindy 76 76000
Case #4:
None
*/

/*
总结：
排序题目，边界条件M<100没注意，意味着每个年龄段的富豪排在100名以后就不必考虑了，因为是英文题目所以
会漏掉一些边界条件。对于一些列出的><符号等等要第一时间注意，在纸上写出。不要嫌麻烦！！！
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
    string name;
    int age;
    int money;
};
bool cmp(Node a,Node b){
    if(a.money == b.money && a.age == b.age){return a.name < b.name;}
    else if(a.money == b.money){return a.age < b.age;}
    else{return a.money > b.money;}
}
vector<Node> ve;
vector<Node> ve_1;
int Age_number[205]; //记录某一个年龄段的人数
main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    int N,K; cin >> N >> K;
    memset(Age_number,0,sizeof(Age_number));
    for(int i = 0;i<N;i++){
        Node node;
        cin >> node.name;
        scanf("%d%d",&node.age,&node.money);
        ve.push_back(node);
    }
    sort(ve.begin(),ve.end(),cmp);
    int ve_length = ve.size();
    for(int i = 0;i<ve_length;i++){
        Age_number[ve[i].age]++;
        if(Age_number[ve[i].age] >= 100){}
        else{ve_1.push_back(ve[i]);}
    }
    int ve1_length = ve_1.size();
    //人处理完毕
    for(int i = 0;i<K;i++){
        int number,Amin,Amax; cin >> number >> Amin >> Amax;
        cout << "Case #" << i+1 << ":" << "\n";
        int cunt = 0; //cunt用来计数
        for(int z = 0;z<ve1_length;z++){
            if(ve_1[z].age>=Amin && ve_1[z].age<=Amax){
                cout << ve_1[z].name << " " << ve_1[z].age << " " << ve_1[z].money << "\n";
                cunt++;
            }
            if(cunt == number){break;}
        }
        if(cunt == 0){cout << "None" << "\n";}
    }
    
/*
    for(int i = 0;i<ve.size();i++){
        cout << ve[i].name << " "<< ve[i].age << endl;
    }
*/
    return 0;
}