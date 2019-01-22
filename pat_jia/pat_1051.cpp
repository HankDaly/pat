/*
1051 Pop Sequence （25 分）
Given a stack which can keep M numbers at most. Push N numbers in the order of 1, 2, 3, ..., N and pop randomly. You are supposed to tell if a given sequence of numbers is a possible pop sequence of the stack. For example, if M is 5 and N is 7, we can obtain 1, 2, 3, 4, 5, 6, 7 from the stack, but not 3, 2, 1, 7, 5, 6, 4.

Input Specification:
Each input file contains one test case. For each case, the first line contains 3 numbers (all no more than 1000): M (the maximum capacity of the stack), N (the length of push sequence), and K (the number of pop sequences to be checked). Then K lines follow, each contains a pop sequence of N numbers. All the numbers in a line are separated by a space.

Output Specification:
For each pop sequence, print in one line "YES" if it is indeed a possible pop sequence of the stack, or "NO" if not.

Sample Input:
5 7 5
1 2 3 4 5 6 7
3 2 1 7 5 6 4
7 6 5 4 3 2 1
5 6 4 3 7 2 1
1 7 6 5 4 3 2
Sample Output:
YES
NO
NO
YES
NO
*/
/*
总结：
有关栈特性的一道题目,关键在于不能超出最大容量，并且如果后一个比前一个大的话，要看一下是否符合顺序。
注意：i直接写7了，应该用N的。
*/





#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>

using namespace std;
int judge(int M,int N){
    int old_n = 0;
    int flag = 0;
    int limit_number = 0;
    for(int i = 0;i<N;i++){
        int number; cin >> number; //获取当前数字

        if(number > i+M){flag = 1;} //判断合理
        //不是第一个的情况下
        if(i != 0){
            //比前一个大
            if(number > old_n){
                if(number > limit_number){limit_number = number;}
                else{flag = 1;}
            }
            //比前一个小
            else{}
        }
        old_n = number;
    }
    return flag;
}

int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    int M,N,K; cin >> M >> N >> K;
    for(int z = 0;z<K;z++){
        int flag = judge(M,N);
        if(flag == 1){cout << "NO" << "\n";}
        else{cout << "YES" << "\n";}
    }
    return 0;
}