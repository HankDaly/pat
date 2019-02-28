/*
1118 Birds in Forest （25 分）
Some scientists took pictures of thousands of birds in a forest. Assume that all the birds appear in the same picture belong to the same tree. You are supposed to help the scientists to count the maximum number of trees in the forest, and for any pair of birds, tell if they are on the same tree.

Input Specification:
Each input file contains one test case. For each case, the first line contains a positive number N (≤10
​4
​​ ) which is the number of pictures. Then N lines follow, each describes a picture in the format:

K B
​1
​​  B
​2
​​  ... B
​K
​​ 

where K is the number of birds in this picture, and B
​i
​​ 's are the indices of birds. It is guaranteed that the birds in all the pictures are numbered continuously from 1 to some number that is no more than 10
​4
​​ .

After the pictures there is a positive number Q (≤10
​4
​​ ) which is the number of queries. Then Q lines follow, each contains the indices of two birds.

Output Specification:
For each test case, first output in a line the maximum possible number of trees and the number of birds. Then for each query, print in a line Yes if the two birds belong to the same tree, or No if not.

Sample Input:
4
3 10 1 2
2 3 4
4 1 5 7 8
3 9 6 4
2
10 5
3 7
Sample Output:
2 10
Yes
No

*/
/*
总结：
标准的并查集做法，注意查的时候的标准，这次==-1错了，应该是小于零
*/


#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cctype>
#include<queue>
using namespace std;

int UNI[10005]; //并查集
void creat(int index){
    //如果未被定义过，那么将这个设为根节点
    if(UNI[index] == 0){
        UNI[index] = -1;
    }
}
int search(int index){
    while(UNI[index] > 0){
        index = UNI[index];
    }
    return index;
}
void mearge(int a,int b){
    int a_root = search(a);
    int b_root = search(b);
    if(a_root == b_root){return;}
    else{
        if(UNI[a_root] < UNI[b_root]){
            UNI[a_root] += UNI[b_root];
            UNI[b_root] = a_root;
        }
        else{
            UNI[b_root] += UNI[a_root];
            UNI[a_root] = b_root;
        }
    }
}

int main(){
#ifdef LOCAL 
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    fill(UNI,UNI+10005,0);
    int N; cin >> N;
    for(int i = 0;i<N;i++){
        int temp; cin >> temp;
        int first_number; cin >> first_number;
        creat(first_number);
        for(int z = 0;z<temp-1;z++){
            int other_number; cin >> other_number;
            creat(other_number);
            mearge(first_number,other_number);
        }
    }
    int cnt_max = 0,cnt_sum = 0;
    for(int i = 0;i<10005;i++){
        if(UNI[i] < 0){cnt_max++;}
        if(UNI[i] != 0){cnt_sum++;}
    }
    cout << cnt_max << " " << cnt_sum << "\n"; 
    int Q; cin >> Q;
    for(int i = 0;i<Q;i++){
        int a,b; cin >> a >> b;
        int a_root = search(a);
        int b_root = search(b);
        if(a_root == b_root){cout << "Yes" << "\n";}
        else{cout << "No" << "\n";}
    }
    return 0;
    
}