/*
1058 A+B in Hogwarts （20 分）
If you are a fan of Harry Potter, you would know the world of magic has its own currency system -- as Hagrid explained it to Harry, "Seventeen silver Sickles to a Galleon and twenty-nine Knuts to a Sickle, it's easy enough." Your job is to write a program to compute A+B where A and B are given in the standard form of Galleon.Sickle.Knut (Galleon is an integer in [0,10
​7
​​ ], Sickle is an integer in [0, 17), and Knut is an integer in [0, 29)).

Input Specification:
Each input file contains one test case which occupies a line with A and B in the standard form, separated by one space.

Output Specification:
For each test case you should output the sum of A and B in one line, with the same format as the input.

Sample Input:
3.2.1 10.16.27
Sample Output:
14.1.28
*/
/*
总结：一道进制转化题目，注意进制转化时候，进位数最好单独表示，不然容易搞混。
*/



#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>

using namespace std;

void getdigit(string A,int& G,int& S,int& K){
    string temp;
    int count = 0; 
    for(int i = 0;i<A.size();i++){
        if(A[i] == '.'){
            if(count == 0){G = stoi(temp);temp.clear();count++;}
            else if(count == 1){
                S = stoi(temp);
                temp.clear();
                temp = A.substr(i+1,A.size()-i);
                K = stoi(temp);
                break;
            }
        }
        else{temp += A[i];}
    }
}

int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    string A,B;cin >> A >> B;
    int G1,S1,K1;
    int G2,S2,K2;
    long G3;
    int S3,K3,Kj,Sj;
    getdigit(A,G1,S1,K1);
    getdigit(B,G2,S2,K2);
    K3 = (K1+K2)%29;
    Kj = (K1+K2)/29;
    S3 = (S1+S2+Kj)%17;
    Sj = (S1+S2+Kj)/17;
    G3 = G1 + G2 + Sj;
    cout << G3 << "." << S3 << "." << K3;
    return 0;
}