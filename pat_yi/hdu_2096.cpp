#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
string two(string A){
    string temp;
    int A_len = A.size();
    if(A_len >= 2){
        temp += A[A_len-2];
        temp += A[A_len-1];
        return temp;
    }
    else{
        A.insert(0,2-A_len,'0');
        temp = A;
        return temp;
    }
}
string add(string A,string B){
    string temp;
    int q,q_1,q_2 = 0;
    for(int i = 1;i>=0;i--){
        q = (A[i] - '0')+(B[i] - '0')+q_2;
        q_1 = q%10;
        q_2 = q/10;
        temp += to_string(q_1);
    }
    reverse(temp.begin(),temp.end());
    return temp;
}

int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif 
    int N; cin >> N;
    for(int i = 0;i<N;i++){
        string A,B; cin >> A >> B;
        string two_A = two(A),two_B = two(B);
        string anwser = add(two_A,two_B);
        cout << stoi(anwser) << endl;
    }
 
    return 0;
}