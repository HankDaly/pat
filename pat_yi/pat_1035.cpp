/*
1035 插入与归并（25 分）
根据维基百科的定义：

插入排序是迭代算法，逐一获得输入数据，逐步产生有序的输出序列。每步迭代中，算法从输入序列中取出一元素，将之插入有序序列中正确的位置。如此迭代直到全部元素有序。

归并排序进行如下迭代操作：首先将原始序列看成 N 个只包含 1 个元素的有序子序列，然后每次迭代归并两个相邻的有序子序列，直到最后只剩下 1 个有序的序列。

现给定原始序列和由某排序算法产生的中间序列，请你判断该算法究竟是哪种排序算法？

输入格式：
输入在第一行给出正整数 N (≤100)；随后一行给出原始序列的 N 个整数；最后一行给出由某排序算法产生的中间序列。这里假设排序的目标序列是升序。数字间以空格分隔。

输出格式：
首先在第 1 行中输出Insertion Sort表示插入排序、或Merge Sort表示归并排序；然后在第 2 行中输出用该排序算法再迭代一轮的结果序列。题目保证每组测试的结果是唯一的。数字间以空格分隔，且行首尾不得有多余空格。

输入样例 1：
10
3 1 2 8 7 5 9 4 6 0
1 2 3 7 8 5 9 4 6 0
输出样例 1：
Insertion Sort
1 2 3 5 7 8 9 4 6 0
输入样例 2：
10
3 1 2 8 7 5 9 4 0 6
1 3 2 8 5 7 4 9 0 6
输出样例 2：
Merge Sort
1 2 3 8 4 5 7 9 0 6
*/
/*
总结:
一开始想过是否是模拟，后来想想如果每一步都要对比可能会超时，所以就去找规律了。
比如归并排序，我是否可以选择出前面最大连续有序数列的长度，然后去和2的n次去匹配，然后再验证，但这个方法弊端在于你不知道
初始值是有多巧，有可能初始值给你安排的很好，你可能无法获得正确的结果，还是得模拟归并，和插入的步骤来。
*/



#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int ch_ori[105];
int ch_now[105];
int main(){
#ifdef LOCAL
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    int N; cin >> N;
    for(int i = 0;i<N;i++){
        int temp; cin >> temp;
        ch_ori[i] = temp;
    }
    for(int i = 0;i<N;i++){
        int temp; cin >> temp;
        ch_now[i] = temp;
    }
    int i,j;
    for(i = 0;i<N-1 && ch_now[i]<=ch_now[i+1];i++);
    for(j = i+1;j<N && ch_now[j] == ch_ori[j];j++);
    if(j == N){
        cout << "Insertion Sort" << endl;
        sort(ch_ori,ch_ori+i+2);
    }
    else{
        cout << "Merge Sort" << endl;
        int kase = 1,flag = 1;
        while(flag){
            flag = 0;
            for(int k = 0;k<N;k++){
                if(ch_now[k] != ch_ori[k]){flag = 1;}
            }
            kase = kase*2;
            for(i = 0;i<(N/kase);i++){
                sort(ch_ori+i*kase,ch_ori+(i+1)*kase);
            }
            sort(ch_ori + N/kase*kase,ch_ori+N);
        }
    }
    for(j = 0;j<N;j++){
        if(j!=0){cout << " ";};
        cout << ch_ori[j];
    }
    return 0;
}