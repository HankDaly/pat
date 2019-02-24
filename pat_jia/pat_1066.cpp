/*
pat1066
*/
/*
总结：标准的avl树建立方法
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

struct Binstree{
    Binstree* left;
    Binstree* right;
    int data;
};

int gethight(Binstree* T){
    int HL,HR,Hmax;
    if(T != NULL){
        HL = gethight(T->left);
        HR = gethight(T->right);
        Hmax = HL > HR ? HL:HR;
        return Hmax+1;
    }
    else{return 0;}
}

Binstree* LL(Binstree* T){
    Binstree* B = T->left;
    T->left = B->right;
    B->right = T;
    return B;
}
Binstree* RR(Binstree* T){
    Binstree* B = T->right;
    T->right = B->left;
    B->left = T;
    return B;
}
Binstree* LR(Binstree* T){
    T->left = RR(T->left);
    return LL(T);
}
Binstree* RL(Binstree* T){
    T->right = LL(T->right);
    return RR(T);
}


Binstree* avl_insert(Binstree* T,int value){
    //未被访问的话，直接建立节点
    if(T == NULL){
        T = new Binstree();
        T->data = value;
        T->left = NULL;
        T->right = NULL;
    }
    //如果大于当前节点,转到右边
    else if(value > T->data){
        T->right = avl_insert(T->right,value);
        //检测当前的高度,右边用右减左
        if(gethight(T->right)-gethight(T->left) == 2){
            //需要右单旋
            if(value > T->right->data){T = RR(T);}
            //需要右左旋
            else{T = RL(T);}
        }
    }
    //否则转到左边
    else{
        T->left = avl_insert(T->left,value);
        //检测当前高度,左边用左减右
        if(gethight(T->left) - gethight(T->right) == 2){
            //需要左单旋
            if(value < T->left->data){T = LL(T);}
            //需要左右旋
            else{T = LR(T);}
        }
    }
    return T;
}

int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    int N; cin >> N;
    Binstree* T; T = NULL;
    for(int i = 0;i<N;i++){
        int temp; cin >> temp;
        T = avl_insert(T,temp);
    }
    cout << T->data;
    return 0;
} 
