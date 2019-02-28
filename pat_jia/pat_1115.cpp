/*
1115 Counting Nodes in a BST （30 分）
A Binary Search Tree (BST) is recursively defined as a binary tree which has the following properties:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Insert a sequence of numbers into an initially empty binary search tree. Then you are supposed to count the total number of nodes in the lowest 2 levels of the resulting tree.

Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (≤1000) which is the size of the input sequence. Then given in the next line are the N integers in [−10001000] which are supposed to be inserted into an initially empty binary search tree.

Output Specification:
For each case, print in one line the numbers of nodes in the lowest 2 levels of the resulting tree in the format:

n1 + n2 = n
where n1 is the number of nodes in the lowest level, n2 is that of the level above, and n is the sum.

Sample Input:
9
25 30 42 16 20 20 35 -5 28
Sample Output:
2 + 4 = 6
*/
/*
总结：
链表建立BST，
注意点 NULL 和 return T， return T放在函数的最后.
*/

#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cctype>
#include<queue>
using namespace std;

int ch_leve[1005];
int leve = 0;

struct BST{
    BST* left;
    BST* right;
    int data;
};

BST* insert(BST* T,int value,int le){
    if(T == NULL){
        T = new BST(); T->right = NULL; T->left = NULL;
        if(le > leve){leve = le;} //更新最深高度
        ch_leve[le]++;
        T->data = value;
    }
    else{
        if(value>T->data){T->right = insert(T->right,value,le+1);}
        else if(value<=T->data){T->left = insert(T->left,value,le+1);}
    }
    return T;
}


int main(){
#ifdef LOCAL 
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    fill(ch_leve,ch_leve+1005,0);
    int N; cin >> N;
    int le = 0;
    BST* T = NULL;
    for(int i = 0;i<N;i++){
        int temp; cin >> temp;
        T = insert(T,temp,le);
    }
    //树建立完毕
    int n1 = ch_leve[leve];
    int n2;
    if(leve == 0){n2 = 0;}
    else{n2 = ch_leve[leve-1];}
    cout << n1 << " + " << n2 << " = " << n1+n2;
    return 0;
    
}#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cctype>
#include<queue>
using namespace std;

int ch_leve[1005];
int leve = 0;

struct BST{
    BST* left;
    BST* right;
    int data;
};

BST* insert(BST* T,int value,int le){
    if(T == NULL){
        T = new BST(); T->right = NULL; T->left = NULL;
        if(le > leve){leve = le;} //更新最深高度
        ch_leve[le]++;
        T->data = value;
    }
    else{
        if(value>T->data){T->right = insert(T->right,value,le+1);}
        else if(value<=T->data){T->left = insert(T->left,value,le+1);}
    }
    return T;
}


int main(){
#ifdef LOCAL 
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    fill(ch_leve,ch_leve+1005,0);
    int N; cin >> N;
    int le = 0;
    BST* T = NULL;
    for(int i = 0;i<N;i++){
        int temp; cin >> temp;
        T = insert(T,temp,le);
    }
    //树建立完毕
    int n1 = ch_leve[leve];
    int n2;
    if(leve == 0){n2 = 0;}
    else{n2 = ch_leve[leve-1];}
    cout << n1 << " + " << n2 << " = " << n1+n2;
    return 0;
    
}