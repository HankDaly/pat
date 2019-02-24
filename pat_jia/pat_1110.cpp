/*
1110 Complete Binary Tree （25 分）
Given a tree, you are supposed to tell if it is a complete binary tree.

Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (≤20) which is the total number of nodes in the tree -- and hence the nodes are numbered from 0 to N−1. Then N lines follow, each corresponds to a node, and gives the indices of the left and right children of the node. If the child does not exist, a - will be put at the position. Any pair of children are separated by a space.

Output Specification:
For each case, print in one line YES and the index of the last node if the tree is a complete binary tree, or NO and the index of the root if not. There must be exactly one space separating the word and the number.

Sample Input 1:
9
7 8
- -
- -
- -
0 1
2 3
4 5
- -
- -
Sample Output 1:
YES 8
Sample Input 2:
8
- -
4 5
0 6
- -
2 3
- 7
- -
- -
Sample Output 2:
NO 1
*/
/*
总结：判断一颗完全二叉数，一开始以为只要左树有，有树没有，或者都没有即可,但是都偏左显然不是完全二叉数,
正确的判断方法是dfs,将二叉数正常放到数组中，看最后面那个下标，如果完全二叉数，下标肯定和给的节点数一致，
如果不一致，则不是完全二叉数.
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
#include<queue>
using namespace std;

int deal_st(string a){
    if(a == "-"){return -1;}
    else{return stoi(a);}
}

struct Node{
    int left;
    int right;
};
Node ch_node[25];
int ch[25];

void if_complete(int& flag,int root,int index){
    if(index > flag){flag = index;}
    if(ch_node[root].left != -1){
        int left = index*2;
        if_complete(flag,ch_node[root].left,left);
    }
    if(ch_node[root].right != -1){
        int right = index*2+1;
        if_complete(flag,ch_node[root].right,right);
    }
}
int find_last(int root){
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int temp;
        temp = q.front();
        q.pop();
        if(ch_node[temp].left != -1){q.push(ch_node[temp].left);}
        if(ch_node[temp].right != -1){q.push(ch_node[temp].right);}
        if(q.empty()){return temp;}
    }
}

int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    memset(ch,0,sizeof(ch));
    int N; scanf("%d",&N);
    for(int i = 0;i<N;i++){
        string left_st,right_st; cin >> left_st >> right_st;
        int left = deal_st(left_st),right = deal_st(right_st);
        ch[left] = 1; ch[right] = 1;
        Node node; node.left = left; node.right = right;
        ch_node[i] = node;
    }
    //储存完毕
    int root;
    for(int i = 0;i<N;i++){
        if(ch[i] == 0){root = i;break;}
    }
    //找到root了
    //判断是否complete
    int flag = 0;
    if_complete(flag,root,1);
    if(flag == N){cout << "YES "<< find_last(root);}
    else{cout << "NO " << root;}
    return 0;
} 
