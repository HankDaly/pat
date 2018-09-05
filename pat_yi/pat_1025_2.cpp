/*
1025 反转链表（25 分）
给定一个常数 K 以及一个单链表 L，请编写程序将 L 中每 K 个结点反转。例如：给定 L 为 1→2→3→4→5→6，K 为 3，则输出应该为 3→2→1→6→5→4；如果 K 为 4，则输出应该为 4→3→2→1→5→6，即最后不到 K 个元素不反转。

输入格式：
每个输入包含 1 个测试用例。每个测试用例第 1 行给出第 1 个结点的地址、结点总个数正整数 N (≤10
​5
​​ )、以及正整数 K (≤N)，即要求反转的子链结点的个数。结点的地址是 5 位非负整数，NULL 地址用 −1 表示。

接下来有 N 行，每行格式为：

Address Data Next
其中 Address 是结点地址，Data 是该结点保存的整数数据，Next 是下一结点的地址。

输出格式：
对每个测试用例，顺序输出反转后的链表，其上每个结点占一行，格式与输入相同。

输入样例：
00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
输出样例：
00000 4 33218
33218 3 12309
12309 2 00100
00100 1 99999
99999 5 68237
68237 6 -1
*/

/*
总结:
做法二，比做法一减去了多余的储存空间，注意到了无用节点的bug
*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int data[100005];
int end_ad[100005];
int list[100005];

int main(){
#ifdef LOCAL
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    int first,N,K; cin >> first >> N >> K;
    for(int i = 0;i<N;i++){
        int temp; cin >> temp;
        cin >> data[temp];
        cin >> end_ad[temp];
    }
    int sum = 0;
    while(first != -1){
        list[sum++] = first;
        first = end_ad[first];
    }
    int kase = 0,len = sum;
    while(len/K>0){
        reverse(list+kase*K,list+(kase+1)*K);
        len = len - K;
        kase++;
    }
    for(int i = 0;i<sum;i++){
        if(i+1 != sum){printf("%05d %d %05d\n",list[i],data[list[i]],list[i+1]);}
        else{printf("%05d %d %d\n",list[i],data[list[i]],-1);}
    }
    
    return 0;   
}