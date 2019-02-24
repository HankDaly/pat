/*
1064 Complete Binary Search Tree （30 分）
A Binary Search Tree (BST) is recursively defined as a binary tree which has the following properties:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
A Complete Binary Tree (CBT) is a tree that is completely filled, with the possible exception of the bottom level, which is filled from left to right.

Now given a sequence of distinct non-negative integer keys, a unique BST can be constructed if it is required that the tree must also be a CBT. You are supposed to output the level order traversal sequence of this BST.

Input Specification:
Each input file contains one test case. For each case, the first line contains a positive integer N (≤1000). Then N distinct non-negative integer keys are given in the next line. All the numbers in a line are separated by a space and are no greater than 2000.

Output Specification:
For each test case, print in one line the level order traversal sequence of the corresponding complete binary search tree. All the numbers in a line must be separated by a space, and there must be no extra space at the end of the line.

Sample Input:
10
1 2 3 4 5 6 7 8 9 0
Sample Output:
6 3 8 1 5 7 9 0 2 4
*/
/*
总结：测试搜索树和完全树的考点，利用两者的特性，大小以及完整，可以推导出每个节点,然后利用递归.
最后只剩一个的时候就写个if把，不可能 总是刚好可以解决的.
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
#include<stack>
using namespace std;

int ch_1[1005];
int ch_tree[1005];

void solve(int L,int R,int sum,int root){
    if(sum <= 0){return;}
    if(L==R){ch_tree[root] = ch_1[L];return;}
    //
    int two_n = -1;
    int number = 0;
    for(int i = 1;i<=sum;i = i*2){
        two_n++;
        number = i;
    }
    int difference = sum-number+1;
    int left,right;
    if(difference>number/2){left = number/2;right = difference-number/2;}
    else{left = difference;right = 0;}
    int index = ((L+left)+(R-right))/2;
    /*
    cout << "\n";
    cout << index << "\n";
    cout <<"L= "<< L << "R= " << R << "sum= "<< sum << "\n";
    */
    //
    ch_tree[root] = ch_1[index];
    //L
    solve(L,index-1,index-L,root*2);
    //R
    solve(index+1,R,R-index,root*2+1);
}

int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    memset(ch_1,0,sizeof(ch_1));
    memset(ch_tree,0,sizeof(ch_tree));
    int N;cin >> N;
    for(int i = 0;i<N;i++){
        cin >> ch_1[i];
    }
    sort(ch_1,ch_1+N);
    //
    solve(0,N-1,N,1);
    //
    for(int i = 1;i<=N;i++){
        if(i != 1){cout << " ";}
        cout << ch_tree[i];
    }
    return 0;
} 
