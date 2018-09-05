/*
1075 链表元素分类（25 分）
给定一个单链表，请编写程序将链表元素进行分类排列，使得所有负值元素都排在非负值元素的前面，而 [0, K] 区间内的元素都排在大于 K 的元素前面。但每一类内部元素的顺序是不能改变的。例如：给定链表为 18→7→-4→0→5→-6→10→11→-2，K 为 10，则输出应该为 -4→-6→-2→7→0→5→10→18→11。

输入格式：
每个输入包含一个测试用例。每个测试用例第 1 行给出：第 1 个结点的地址；结点总个数，即正整数N (≤10
​5
​​ )；以及正整数K (≤10
​3
​​ )。结点的地址是 5 位非负整数，NULL 地址用 −1 表示。

接下来有 N 行，每行格式为：

Address Data Next
其中 Address 是结点地址；Data 是该结点保存的数据，为 [−10
​5
​​ ,10
​5
​​ ] 区间内的整数；Next 是下一结点的地址。题目保证给出的链表不为空。

输出格式：
对每个测试用例，按链表从头到尾的顺序输出重排后的结果链表，其上每个结点占一行，格式与输入相同。

输入样例：
00100 9 10
23333 10 27777
00000 0 99999
00100 18 12309
68237 -6 23333
33218 -4 00000
48652 -2 -1
99999 5 68237
27777 11 48652
12309 7 33218
输出样例：
33218 -4 68237
68237 -6 48652
48652 -2 12309
12309 7 00000
00000 0 99999
99999 5 23333
23333 10 00100
00100 18 27777
27777 11 -1
*/
/*
总结:
链表题目不要用链表做（笑），主要就是一个链表的思维，用开头节点做下标，二个数组一个储存值，另一个
储存下一个地址，然后分析题目去做.
*/

#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
int ch_value[100005];
int ch_last[100005];
int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    int first_node,K,N; cin >> first_node >> N >> K;
    for(int i = 0;i<N;i++){
        int temp; cin >> temp;
        cin >> ch_value[temp] >> ch_last[temp];
    }
    //首先先来一遍小于0循环
    int temp_node = first_node;
    int kase = 0;
    while(temp_node != -1){
        if(ch_value[temp_node] < 0 && kase == 0){
            printf("%05d %d",temp_node,ch_value[temp_node]);
            ++kase;
        }
        else if(ch_value[temp_node] < 0 && kase > 0){
            printf(" %05d\n%05d %d",temp_node,temp_node,ch_value[temp_node]);
        }
        else{}
        temp_node = ch_last[temp_node];
    }
    //第二遍就是0-K之间
    temp_node = first_node; // temp_node重置
    while(temp_node != -1){
        if(ch_value[temp_node] >= 0 && ch_value[temp_node] <= K && kase == 0){
            printf("%05d %d",temp_node,ch_value[temp_node]);
            ++kase;
        }
        else if(ch_value[temp_node] >= 0 && ch_value[temp_node] <= K && kase == 1){
            printf(" %05d\n%05d %d",temp_node,temp_node,ch_value[temp_node]);
        }
        else{}
        temp_node = ch_last[temp_node];
    }
    //第三遍大于K
    temp_node = first_node; // temp_node重置
    while(temp_node != -1){
        if(ch_value[temp_node] > K && kase == 0){
            printf("%05d %d",temp_node,ch_value[temp_node]);
            ++kase;
        }
        else if(ch_value[temp_node] > K && kase == 1){
            printf(" %05d\n%05d %d",temp_node,temp_node,ch_value[temp_node]);
        }
        else{}
        temp_node = ch_last[temp_node];
    }
    printf(" -1");
    return 0;
}