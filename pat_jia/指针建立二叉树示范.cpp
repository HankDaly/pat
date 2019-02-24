#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<unordered_map>

using namespace std;

struct Binstree{
    Binstree* Left;
    Binstree* Right;
    int data;
};

Binstree* inert(Binstree* T,int value){
    if(T == NULL){
        T = new Binstree;
        T->data = value;
        T->Left = NULL; T->Right = NULL; //记得为左右都设为NULL
    }
    else{
        if(value > T->data){T->Right = inert(T->Right,value);}
        else if(value < T->data){T->Left = inert(T->Left,value);}
    }
    return T;
}
vector<int> ve;
int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    Binstree* T = new Binstree; //如果T有数据 要声明空间; 没有T = NULL;
    T->data = 1;
    T->Left = NULL;
    T->Right = NULL;
    cout << T->data;
    for(int i = 0;i<5;i++){
        T = inert(T,i);
    }
    return 0;
}