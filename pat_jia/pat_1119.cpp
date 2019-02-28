/*
1119 Pre- and Post-order Traversals （30 分）
Suppose that all the keys in a binary tree are distinct positive integers. A unique binary tree can be determined by a given pair of postorder and inorder traversal sequences, or preorder and inorder traversal sequences. However, if only the postorder and preorder traversal sequences are given, the corresponding tree may no longer be unique.

Now given a pair of postorder and preorder traversal sequences, you are supposed to output the corresponding inorder traversal sequence of the tree. If the tree is not unique, simply output any one of them.

Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (≤ 30), the total number of nodes in the binary tree. The second line gives the preorder sequence and the third line gives the postorder sequence. All the numbers in a line are separated by a space.

Output Specification:
For each test case, first printf in a line Yes if the tree is unique, or No if not. Then print in the next line the inorder traversal sequence of the corresponding binary tree. If the solution is not unique, any answer would do. It is guaranteed that at least one solution exists. All the numbers in a line must be separated by exactly one space, and there must be no extra space at the end of the line.

Sample Input 1:
7
1 2 3 4 6 7 5
2 6 7 4 5 3 1
Sample Output 1:
Yes
2 1 6 4 7 3 5
Sample Input 2:
4
1 2 3 4
2 4 3 1
Sample Output 2:
No
2 1 3 4
*/
/*
总结：
知道前序后序推中序，还是递归解决，观察是否出现最小并集,当数量小于等于2时，如果顺序一样，则一致
最后全部格式错误，可以试一下末尾加一下\n.
*/


#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<unordered_map>

using namespace std;
vector<int> pre_ve;
vector<int> post_ve;
vector<int> in_ve;
int pre_ch[35];
int post_ch[35];
int flag = 0;

bool if_same(vector<int> a,vector<int> b){
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    if(a == b){return true;}
    else{return false;}
}
bool if_equal(vector<int> &a,vector<int> b){
    if(a==b){return true;}
    else{return false;}
}

int if_excu(int pre_left,int pre_right,int post_left,int post_right){
    pre_ve.clear(); post_ve.clear();
    int length = pre_right-pre_left; //除去根节点还剩的数量
    //当左子树或右子树只剩下一个或两个的时候
    if(length <= 1){
        for(int i = pre_left;i<= pre_right;i++){pre_ve.push_back(pre_ch[i]);}
        for(int i = post_left;i<= post_right;i++){post_ve.push_back(post_ch[i]);}
        //如果不相等
        if(!if_equal(pre_ve,post_ve)){flag = 1;}
        for(int i = 0;i<pre_ve.size();i++){in_ve.push_back(pre_ve[i]);}
    }
    else{
        int root = pre_ch[pre_left]; //找出根节点
        pre_left = pre_left+1; pre_right = pre_right; //更新前序和后序的左右界限
        post_left = post_left; post_right = post_right-1;
        int index;
        for(int i = 0;i<length;i++){
            pre_ve.push_back(pre_ch[pre_left+i]);
            post_ve.push_back(post_ch[post_left+i]);
            if(if_same(pre_ve,post_ve)){index = i;break;}
        }
        //递归左子树
        if_excu(pre_left,pre_left+index,post_left,post_left+index);
        in_ve.push_back(root);
        //递归右子树
        if_excu(pre_left+index+1,pre_right,post_left+index+1,post_right);
    } 
}

int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    int N; cin >> N;
    for(int i = 0;i<N;i++){cin >> pre_ch[i];}
    for(int i = 0;i<N;i++){cin >> post_ch[i];}
    int left = 0,right = N-1;
    if_excu(left,right,left,right);

    if(flag == 0){cout << "Yes" << "\n";}
    else{cout << "No" << "\n";}
    for(int i = 0;i<in_ve.size();i++){
        if(i!=0){cout << " ";}
        cout << in_ve[i];
    }
    cout << "\n";

    return 0;
}