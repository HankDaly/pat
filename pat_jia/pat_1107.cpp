/*
1107 Social Clusters （30 分）
When register on a social network, you are always asked to specify your hobbies in order to find some potential friends with the same hobbies. A social cluster is a set of people who have some of their hobbies in common. You are supposed to find all the clusters.

Input Specification:
Each input file contains one test case. For each test case, the first line contains a positive integer N (≤1000), the total number of people in a social network. Hence the people are numbered from 1 to N. Then N lines follow, each gives the hobby list of a person in the format:

K
​i
​​ : h
​i
​​ [1] h
​i
​​ [2] ... h
​i
​​ [K
​i
​​ ]

where K
​i
​​  (>0) is the number of hobbies, and h
​i
​​ [j] is the index of the j-th hobby, which is an integer in [1, 1000].

Output Specification:
For each case, print in one line the total number of clusters in the network. Then in the second line, print the numbers of people in the clusters in non-increasing order. The numbers must be separated by exactly one space, and there must be no extra space at the end of the line.

Sample Input:
8
3: 2 7 10
1: 4
2: 5 3
1: 4
1: 3
1: 4
4: 6 8 1 5
1: 4
Sample Output:
3
4 3 1
*/
/*
总结：
并查集做法,A-B,B-C,意味A-C.爱好用来定位人,如果爱好还没对应人，那么当前人为节点，爱好标记为当前人
如果爱好已经标记了，那么两个节点合并即可
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cctype>
#include<queue>
using namespace std;

vector<int> ve;
int ch_N[1005];
int ch_h[1005];
int find(int index){
    int number = ch_N[index];
    while(number >= 0){
        index = ch_N[index];
        number = ch_N[index];
    } 
    return index;
}
void Nmerge(int i,int n_number){
    if(ch_N[i] == 0){
        ch_N[i] = n_number;
        ch_N[find(n_number)]--;
        return;
    }
    int i_root = find(i);
    int n_root = find(n_number);
    if(i_root == n_root){return;}
    int i_number = ch_N[i_root];
    ch_N[n_root] += i_number;
    ch_N[i_root] = n_root;
}

int main(){
#ifdef LOCAL 
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    int N; cin >> N;
    memset(ch_N,0,sizeof(ch_N));
    memset(ch_h,0,sizeof(ch_h));
    for(int i = 0;i<1005;i++){ch_h[i] = -1;}
    for(int i = 0;i<1005;i++){ch_N[i] = 0;}

    for(int i = 1;i<=N;i++){
        int number; cin >> number;
        getchar();
        for(int z = 0;z<number;z++){
            int n; cin >> n;
            int people_status = ch_N[i]; //代表人
            int hobby_status = ch_h[n]; //代表爱好
            //如果爱好未指定人
            if(hobby_status == -1){
                ch_h[n] = i; //选择当前人
                if(ch_N[i] == 0){ch_N[i] = -1;} //如果这个人不是节点,当前人升级为节点
            }
            //如果爱好已经指定过人了,合并两个人节点
            else{
                Nmerge(i,hobby_status);
            }

        }
    }
    
    sort(ch_N+1,ch_N+N+1);
    int cnt_N = 0;

    for(int i = 1;i<=N;i++){
        if(ch_N[i] < 0){cnt_N++;}
    }
    cout << cnt_N << "\n";
    for(int i = 1;i<=cnt_N;i++){
        if(i!=1){cout << " ";}
        cout << ch_N[i]*-1;
    }
    return 0;
}