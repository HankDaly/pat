/*
1056 Mice and Rice （25 分）
Mice and Rice is the name of a programming contest in which each programmer must write a piece of code to control the movements of a mouse in a given map. The goal of each mouse is to eat as much rice as possible in order to become a FatMouse.

First the playing order is randomly decided for N
​P
​​  programmers. Then every N
​G
​​  programmers are grouped in a match. The fattest mouse in a group wins and enters the next turn. All the losers in this turn are ranked the same. Every N
​G
​​  winners are then grouped in the next match until a final winner is determined.

For the sake of simplicity, assume that the weight of each mouse is fixed once the programmer submits his/her code. Given the weights of all the mice and the initial playing order, you are supposed to output the ranks for the programmers.

Input Specification:
Each input file contains one test case. For each case, the first line contains 2 positive integers: N
​P
​​  and N
​G
​​  (≤1000), the number of programmers and the maximum number of mice in a group, respectively. If there are less than N
​G
​​  mice at the end of the player's list, then all the mice left will be put into the last group. The second line contains N
​P
​​  distinct non-negative numbers W
​i
​​  (i=0,⋯,N
​P
​​ −1) where each W
​i
​​  is the weight of the i-th mouse respectively. The third line gives the initial playing order which is a permutation of 0,⋯,N
​P
​​ −1 (assume that the programmers are numbered from 0 to N
​P
​​ −1). All the numbers in a line are separated by a space.

Output Specification:
For each test case, print the final ranks in a line. The i-th number is the rank of the i-th programmer, and all the numbers must be separated by a space, with no extra space at the end of the line.

Sample Input:
11 3
25 18 0 46 37 3 19 22 57 56 10
6 0 8 7 10 5 9 1 4 2 3
Sample Output:
5 5 5 2 5 5 5 3 1 3 5
*/

/*
总结：
一道综合题目一开始的思路是保留最初的vector，每晋级一次新建一个vector，但是太过麻烦。
后来意识到vector删掉也行，用了vector的erase方法
vector.erase(ve.begin()+3) 删掉ve[3]
vector.erase(ve.begin(),ve.begin()+3) 删掉ve[0]-ve[2]
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

struct Mouse{
    int weight;
    int rank;
}ch[1005];

vector<int> ve;

main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    int Np,NG; cin >> Np >> NG;
    int count = 1;
    for(int i = 0;i<Np;i++){
        cin >> ch[i].weight;
    }
    for(int i = 0;i<Np;i++){
        int temp; cin >> temp;
        ve.push_back(temp);
    }
    //准备完毕
    while(ve.size() > 1){
        int size = ve.size();
        int rank = size/NG + 1;
        if(size%NG){rank++;}
        for(int i = 0;i<size;i+=NG){
            int length;
            if(i+NG>=size){length = size-i;}
            else{length = NG;}
            int max = ch[ve[i]].weight;
            int number = i;
            for(int z = 1;z<length;z++){
                if(ch[ve[i+z]].weight > max){
                    max = ch[ve[i+z]].weight;
                    number = i+z;
                }
            }
            ve.push_back(ve[number]);
        }
        for(int i = 0;i<ve.size();i++){ch[ve[i]].rank = rank;}
        //保留晋级的
        ve.erase(ve.begin(),ve.begin()+size);
    }
    ch[ve[0]].rank = 1;
    for(int i = 0;i<Np;i++){
        if(i != 0){cout << " ";}
        cout << ch[i].rank;
    }
    return 0;
}