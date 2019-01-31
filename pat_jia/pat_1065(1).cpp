/*
是1065得错误做法，但是方法可以用来作为手动实现加减做参考
注意反向,填充短的0,最后还要看有无进位
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

using namespace std;

string addstring(string A,string B){
    if(A.size() >= B.size()){
        string temp = A;
        A = B;
        B = temp;
    }
    int A_length = A.size();
    int B_length = B.size();
    reverse(A.begin(),A.end());
    reverse(B.begin(),B.end());
    for(int i = 0;i<B_length-A_length;i++){A += "0";}
    int previous = 0;
    string temp;
    for(int i = 0;i<B_length;i++){
        int now = ((A[i]-'0')+(B[i]-'0')+previous)%10;
        previous = ((A[i]-'0')+(B[i]-'0')+previous)/10;
        temp += to_string(now);
    }
    if(previous > 0){temp += "1";}
    reverse(temp.begin(),temp.end());
    return temp;
}

string substruct(string A,string B){
    //默认A比B短
    int A_length = A.size();
    int B_length = B.size();
    reverse(A.begin(),A.end());
    reverse(B.begin(),B.end());
    for(int i = 0;i<B_length-A_length;i++){A += "0";}
    int previous = 0;
    string temp;
    for(int i = 0;i<B_length;i++){
        int now = (B[i]-'0')-(A[i]-'0')+previous;
        if(now < 0){
            now += 10;
            previous = -1;
        }
        else{previous = 0;}
        temp += to_string(now);
    }
    reverse(temp.begin(),temp.end());
    return temp;
}


main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    string A
'''
    int N; cin >> N;
    for(int i = 0;i<N;i++){
        string A,B,C; cin >> A >> B >> C;
        string anwser;
        if(A[0] == '-' && B[0] == '-'){anwser = addstring(A,B);}
        else if(A[0] != '-' && B[0] != '-'){anwser = addstring(A,B);}
        else if(A[0] != '-'){
            if(A.length() >= B.length()-1){}
            }
    }
'''
    return 0;
}