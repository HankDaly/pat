/*
1086 Tree Traversals Again （25 分）
An inorder binary tree traversal can be implemented in a non-recursive way with a stack. For example, suppose that when a 6-node binary tree (with the keys numbered from 1 to 6) is traversed, the stack operations are: push(1); push(2); push(3); pop(); pop(); push(4); pop(); pop(); push(5); push(6); pop(); pop(). Then a unique binary tree (shown in Figure 1) can be generated from this sequence of operations. Your task is to give the postorder traversal sequence of this tree.


Figure 1
Input Specification:
Each input file contains one test case. For each case, the first line contains a positive integer N (≤30) which is the total number of nodes in a tree (and hence the nodes are numbered from 1 to N). Then 2N lines follow, each describes a stack operation in the format: "Push X" where X is the index of the node being pushed onto the stack; or "Pop" meaning to pop one node from the stack.

Output Specification:
For each test case, print the postorder traversal sequence of the corresponding tree in one line. A solution is guaranteed to exist. All the numbers must be separated by exactly one space, and there must be no extra space at the end of the line.

Sample Input:
6
Push 1
Push 2
Push 3
Pop
Pop
Push 4
Pop
Pop
Push 5
Push 6
Pop
Pop
Sample Output:
3 4 2 6 5 1
*/

/*
总结：
树的中序遍历非递归实现倒推，如果理解正的顺序，倒推很简单。注意理解
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

int ch[50];
stack<int> st;
void post_travel(int index){
    if(ch[index] != 0){
        post_travel(index*2);
        post_travel(index*2+1);
        if(ch[index] != ch[1]){cout << ch[index] << " ";}
        else{cout << ch[index];}
    }
}

int main(){

#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    memset(ch,0,sizeof(ch));
    int N; cin >> N;
    string A;
    int X;
    int index = 1; //当前所在的父节点
    int left_right = 0;

    while(cin >> A){
        if(A == "Push"){
            cin >> X;
            st.push(index);
            ch[index] = X;
            index = index*2;
        }
        else{
            index = st.top();
            st.pop();
            index = index*2+1;
        }
    }
    //处理完毕
    index = 1;
    int cnt = 0;
    post_travel(index);    
    return 0;
}