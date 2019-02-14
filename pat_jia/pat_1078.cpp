/*
1078 Hashing （25 分）
The task of this problem is simple: insert a sequence of distinct positive integers into a hash table, and output the positions of the input numbers. The hash function is defined to be H(key)=key%TSize where TSize is the maximum size of the hash table. Quadratic probing (with positive increments only) is used to solve the collisions.

Note that the table size is better to be prime. If the maximum size given by the user is not prime, you must re-define the table size to be the smallest prime number which is larger than the size given by the user.

Input Specification:
Each input file contains one test case. For each case, the first line contains two positive numbers: MSize (≤10
​4
​​ ) and N (≤MSize) which are the user-defined table size and the number of input numbers, respectively. Then N distinct positive integers are given in the next line. All the numbers in a line are separated by a space.

Output Specification:
For each test case, print the corresponding positions (index starts from 0) of the input numbers in one line. All the numbers in a line are separated by a space, and there must be no extra space at the end of the line. In case it is impossible to insert the number, print "-" instead.

Sample Input:
4 4
10 6 4 15
Sample Output:
0 1 4 -
*/
/*
总结：素数以及hash表Quadratic probing(二次方探测法)的应用,即当H(a)发生冲突的时候，让a按a+1*1，
a-1*1，a+2*2,a-2*2...的顺序调整a的值,注意结果是(a+step*step)%Tsize,当步数step超过Tsize的时候
停止，因为已经超过了Tsize*Tsize最大了，继续也只是重复而已.
*/

#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<unordered_map>

using namespace std;

int ch[10050];
int anwser_ch[10050];
int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    memset(ch,0,sizeof(ch));
    memset(anwser_ch,0,sizeof(anwser_ch));
    ch[0] = 1; ch[1] = 1;
    for(int i = 2;i<10050;i++){
        int flag = 0;
        for(int z = 2;z*z<=i;z++){
            if(i%z == 0){flag = 1;break;} //等于0代表不是素数
        }
        if(flag == 1){ch[i] = 1;}
    }
    //prime number table set up complete.
    int M,N;cin >> M >> N;
    if(ch[M] == 1){
        for(int i = M;i<10050;i++){
            if(ch[i] == 0){
                M = i;
                break;
            }
        }
    }
    //M处理完毕
    for(int i = 0;i<N;i++){
        if(i!=0){cout << " ";}
        int temp; cin >> temp;
        int index = temp%M;
        if(anwser_ch[index] == 0){
            anwser_ch[index] = 1;
            cout << index;
        }
        else{
            int flag = 0;
            for(int i = 1;(temp+i*i)<10050*10050;i++){
                if(anwser_ch[(temp+i*i)%M] == 0){
                    anwser_ch[(temp+i*i)%M] = 1;
                    cout << (temp+i*i)%M;
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){cout << "-";}
        }
    }
    return 0;
}