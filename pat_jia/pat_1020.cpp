/*1020 Tree Traversals （25 分）
Suppose that all the keys in a binary tree are distinct positive integers. Given the postorder and inorder traversal sequences, you are supposed to output the level order traversal sequence of the corresponding binary tree.

Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (≤30), the total number of nodes in the binary tree. The second line gives the postorder sequence and the third line gives the inorder sequence. All the numbers in a line are separated by a space.

Output Specification:
For each test case, print in one line the level order traversal sequence of the corresponding binary tree. All the numbers in a line must be separated by exactly one space, and there must be no extra space at the end of the line.

Sample Input:
7
2 3 1 5 7 6 4
1 2 3 4 5 6 7
Sample Output:
4 1 6 3 5 7 2
*/
/*
总结：如何用后序和中序重建二叉树，并且用队列读出平行序列
注意分割时候index代表得含义，需要将分割的数量表示清楚
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cctype>
#include<queue>
using namespace std;

struct BinTree{
    BinTree* Left;
    BinTree* Right;
    int data;
};
int ch_post[50];
int ch_in[50];

BinTree* create_tree(int post_begin,int post_end,int in_begin,int in_end){
    if(post_begin > post_end && in_begin > in_end){return NULL;}
    //新建树
    BinTree* T = (BinTree*)malloc(sizeof(BinTree));
    //找到端点
    int point = ch_post[post_end];
    int index;
    for(int i = 0;i<=in_end;i++){
        if(ch_in[i] == point){index = i;break;}
    }
    //
    int begin_distance = index-in_begin;
    int end_distance = in_end-index;
    T->data = point;
    T->Left = create_tree(post_begin,post_begin+begin_distance-1,in_begin,index-1);
    T->Right = create_tree(post_begin+begin_distance,post_end-1,index+1,in_end);
    return T;
}
void levelorder(BinTree* T){
    queue<BinTree*> q;
    q.push(T);
    int cnt = 0;
    while(!q.empty() && T != NULL){
        BinTree* temp = q.front();
        if(cnt != 0){cout << " ";}
        cout << temp->data; cnt++;
        if(temp->Left){q.push(temp->Left);}
        if(temp->Right){q.push(temp->Right);}
        q.pop();
    }
}

int main(){
#ifdef LOCAL 
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    memset(ch_post,0,sizeof(ch_post));
    memset(ch_in,0,sizeof(ch_in));
    int N; cin >> N;
    for(int i = 0;i<N;i++){cin >> ch_post[i];}
    for(int i = 0;i<N;i++){cin >> ch_in[i];}
    int post_begin = 0,post_end = N-1,in_begin = 0,in_end = N-1;
    BinTree* T = create_tree(post_begin,post_end,in_begin,in_end);
    //树建立完毕
    levelorder(T);
    return 0;
}