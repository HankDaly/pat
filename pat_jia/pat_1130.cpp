/*
pat 1130
*/
/*
总结：
重建树并且中序遍历得到中序表达式
卡在如何写括号上面，其实用中序的遍历，遇到运算符输出括号，运算符的遍历结束输出反括号即可。
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

struct Node{
    int left = 0;
    int right = 0;
    string data;
}Tree[25];

bool if_op(string a){
    if(a.size() == 1 && !isalnum(a[0])){return true;}
    else{return false;}
}

int root;
void inorder(int index){
    if(index != -1){
        string data = Tree[index].data;
        int left = Tree[index].left,right = Tree[index].right;
        if(if_op(Tree[index].data) && index != root){cout << "(";}
        inorder(left);
        cout << Tree[index].data;
        inorder(right);
        if(if_op(Tree[index].data) && index != root){cout << ")";}
    }
}

int ch[25];
int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    fill(ch,ch+25,0);
    int N; cin >> N;
    for(int i = 1;i<=N;i++){
        Node node; cin >> node.data >> node.left >> node.right;
        Tree[i] = node;
        if(node.left != -1){ch[node.left] = 1;}
        if(node.right != -1){ch[node.right] = 1;}
    }
    for(int i = 1;i<=N;i++){
        if(ch[i] == 0){root = i;break;}
    }
    //树建立完毕
    //中序遍历输出树
    inorder(root);
    return 0;
} 
