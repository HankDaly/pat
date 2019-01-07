/*1042 Shuffling Machine （20 分）
Shuffling is a procedure used to randomize a deck of playing cards. Because standard shuffling techniques are seen as weak, and in order to avoid "inside jobs" where employees collaborate with gamblers by performing inadequate shuffles, many casinos employ automatic shuffling machines. Your task is to simulate a shuffling machine.

The machine shuffles a deck of 54 cards according to a given random order and repeats for a given number of times. It is assumed that the initial status of a card deck is in the following order:

S1, S2, ..., S13, 
H1, H2, ..., H13, 
C1, C2, ..., C13, 
D1, D2, ..., D13, 
J1, J2
where "S" stands for "Spade", "H" for "Heart", "C" for "Club", "D" for "Diamond", and "J" for "Joker". A given order is a permutation of distinct integers in [1, 54]. If the number at the i-th position is j, it means to move the card from position i to position j. For example, suppose we only have 5 cards: S3, H5, C1, D13 and J2. Given a shuffling order {4, 2, 5, 3, 1}, the result will be: J2, H5, D13, S3, C1. If we are to repeat the shuffling again, the result will be: C1, H5, S3, J2, D13.

Input Specification:
Each input file contains one test case. For each case, the first line contains a positive integer K (≤20) which is the number of repeat times. Then the next line contains the given order. All the numbers in a line are separated by a space.

Output Specification:
For each test case, print the shuffling results in one line. All the cards are separated by a space, and there must be no extra space at the end of the line.

Sample Input:
2
36 52 37 38 3 39 40 53 54 41 11 12 13 42 43 44 2 4 23 24 25 26 27 6 7 8 48 49 50 51 9 10 14 15 16 5 17 18 19 1 20 21 22 28 29 30 31 32 33 34 35 45 46 47
Sample Output:
S7 C11 C10 C12 S1 H7 H8 H9 D8 D9 S11 S12 S13 D10 D11 D12 S3 S4 S6 S10 H1 H2 C13 D2 D3 D4 H6 H3 D13 J1 J2 C1 C2 C3 C4 D1 S5 H5 H11 H12 C6 C7 C8 C9 S2 S8 S9 H10 D5 D6 D7 H4 H13 C5

*/
/*
总结：
开新旧两个数组,然后前后转换。注意数组不能直接赋值，要for一下.
坑点在转换的地方，因为是从1-13所以用13余之前要先减1.
*/


#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>

using namespace std;

int ch_old[55];
int ch_new[55];
char ch_iter[] = {'S','H','C','D','J'};

vector<int> ve;


void transfer(int* ch_old,int* ch_new,vector<int>& ve){
    for(int i = 0;i<54;i++){
        int number = ve[i];
        ch_new[number] = ch_old[i+1];
    }
    for(int i = 1;i<=54;i++){ch_old[i] = ch_new[i];}//赋值给旧的
}

int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    memset(ch_new,0,sizeof(ch_new));
    for(int i =1;i<=54;i++){ch_old[i] = i;}
    int K; cin >> K;
    for(int i = 0;i<54;i++){
        int temp; cin >> temp;
        ve.push_back(temp);
    }
    //准备完毕
    for(int z = 0;z<K;z++){transfer(ch_old,ch_new,ve);}
    for(int z = 1;z<=54;z++){
        if(z != 1){cout << " ";}
        int number = ch_old[z]-1;
        cout << ch_iter[number/13] << number%13+1;
    }
    return 0;
}