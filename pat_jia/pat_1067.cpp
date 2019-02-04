/*
1067 Sort with Swap(0, i) （25 分）
Given any permutation of the numbers {0, 1, 2,..., N−1}, it is easy to sort them in increasing order. But what if Swap(0, *) is the ONLY operation that is allowed to use? For example, to sort {4, 0, 2, 1, 3} we may apply the swap operations in the following way:

Swap(0, 1) => {4, 1, 2, 0, 3}
Swap(0, 3) => {4, 1, 2, 3, 0}
Swap(0, 4) => {0, 1, 2, 3, 4}
Now you are asked to find the minimum number of swaps need to sort the given permutation of the first N nonnegative integers.

Input Specification:
Each input file contains one test case, which gives a positive N (≤10
​5
​​ ) followed by a permutation sequence of {0, 1, ..., N−1}. All the numbers in a line are separated by a space.

Output Specification:
For each case, simply print in a line the minimum number of swaps need to sort the given permutation.

Sample Input:
10
3 5 7 2 6 4 9 0 8 1
Sample Output:
9
*/
/*
总结：
一道理解题意，用计算机模拟过程的题目
大意是必须用0与其他数进行交换，最后得到排好顺序的数列，最少的步骤用几步。
基本的做法是总结规律然后计算
这道题目其实如果把零放在外部就相当于那些没对上就交换一次，但是关键在于有时候零会被交换到本身的位置
导致交换次数增多。观察后发现，其实观察每个数之间，他们很多存在闭环3-8-7-3,每多一个闭环，交换次数便
增加一次。所以只要求出闭环的数量就行，注意当0位于0index的时候需要加2，因为多交换加上少了一个正确数

其实发现这个规律用了我蛮长时间的，所以我觉得考试的时候就单纯模拟运算的步骤，然后将0一步步交换比较合理
最多思考十分钟，不然就直接上。
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
int ch[100005];

main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    int N;cin >> N;
    int wrong = 0;
    int first_place = -1;
    memset(ch,0,sizeof(ch));
    for(int i = 0;i<N;i++){
        int temp; cin >> temp;
        if(temp != i){wrong++;}
        if(first_place == -1 && temp != i){first_place = i;}
        ch[i] = temp;
    }
    int count = 0;
    for(int i = 0;i<N;i++){
        if(i != ch[i]){
            int index = i,anwser = ch[i];
            while(anwser != index){
                //将当前处理
                ch[index] = index;
                //寻找下一个
                index = anwser;
                anwser = ch[anwser];
            }
            count++;
        }
    }
    int anwser = wrong-2+count;
    if(first_place != 0){anwser += 2;}
    if(wrong == 0){cout << 0;}
    else{cout << anwser;}
    return 0;
}