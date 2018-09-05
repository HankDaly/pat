/*1045 快速排序（25 分）
著名的快速排序算法里有一个经典的划分过程：我们通常采用某种方法取一个元素作为主元，通过交换，把比主元小的元素放到它的左边，比主元大的元素放到它的右边。 给定划分后的 N 个互不相同的正整数的排列，请问有多少个元素可能是划分前选取的主元？

例如给定 $N = 5$, 排列是1、3、2、4、5。则：

1 的左边没有元素，右边的元素都比它大，所以它可能是主元；
尽管 3 的左边元素都比它小，但其右边的 2 比它小，所以它不能是主元；
尽管 2 的右边元素都比它大，但其左边的 3 比它大，所以它不能是主元；
类似原因，4 和 5 都可能是主元。
因此，有 3 个元素可能是主元。

输入格式：
输入在第 1 行中给出一个正整数 N（≤10
​5
​​ ）； 第 2 行是空格分隔的 N 个不同的正整数，每个数不超过 10
​9
​​ 。

输出格式：
在第 1 行中输出有可能是主元的元素个数；在第 2 行中按递增顺序输出这些元素，其间以 1 个空格分隔，行首尾不得有多余空格。

输入样例：
5
1 3 2 4 5
输出样例：
3
1 4 5

*/
/*
总结:
暴力算会超时,
用在线的方式，从左到右只记录当前最大的值，如果当前的值大于等于最大值，就说明这个在最大值方面通过了。
从右到左只记录当前最小的值，如果当前的值小于等于最小的值，就说明这个在最小方面通过了。
如果一个值将上面两个都通过了，则正确。
case2 要打印两个"\n",不是很懂。
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
using namespace std;
vector<long> ve;
long ch[100001];
int main(){
#ifdef LOCAL 
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    memset(ch,0,sizeof(ch));
    int N; cin >> N;
    long max = 0,min = 1000000000;
    int cont = 0;
    for(int i = 0;i<N;i++){
        long temp; cin >> temp;
        if(temp >= max){max = temp;ch[i] = temp;}
        ve.push_back(temp);
    }
    for(int i = N-1;i>=0;i--){
        if(ve[i] <= min){min = ve[i];}
        else{ch[i] = 0;}
    }
    for(int i = 0;i<N;i++){
        if(ch[i] != 0){cont++;}
    }
    cout << cont << "\n";
    int kase = 0;
    for(int i = 0;i<N;i++){
        if(ch[i] != 0){
            if(kase != 0){cout << " ";}
            cout << ch[i];
            kase++;
        }
    }
    cout << "\n"; // case 2
    return 0;
}