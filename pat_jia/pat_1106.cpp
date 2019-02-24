/*
1106 Lowest Price in Supply Chain （25 分）
A supply chain is a network of retailers（零售商）, distributors（经销商）, and suppliers（供应商）-- everyone involved in moving a product from supplier to customer.

Starting from one root supplier, everyone on the chain buys products from one's supplier in a price P and sell or distribute them in a price that is r% higher than P. Only the retailers will face the customers. It is assumed that each member in the supply chain has exactly one supplier except the root supplier, and there is no supply cycle.

Now given a supply chain, you are supposed to tell the lowest price a customer can expect from some retailers.

Input Specification:
Each input file contains one test case. For each case, The first line contains three positive numbers: N (≤10
​5
​​ ), the total number of the members in the supply chain (and hence their ID's are numbered from 0 to N−1, and the root supplier's ID is 0); P, the price given by the root supplier; and r, the percentage rate of price increment for each distributor or retailer. Then N lines follow, each describes a distributor or retailer in the following format:

K
​i
​​  ID[1] ID[2] ... ID[K
​i
​​ ]

where in the i-th line, K
​i
​​  is the total number of distributors or retailers who receive products from supplier i, and is then followed by the ID's of these distributors or retailers. K
​j
​​  being 0 means that the j-th member is a retailer. All the numbers in a line are separated by a space.

Output Specification:
For each test case, print in one line the lowest price we can expect from some retailers, accurate up to 4 decimal places, and the number of retailers that sell at the lowest price. There must be one space between the two numbers. It is guaranteed that the all the prices will not exceed 10
​10
​​ .

Sample Input:
10 1.80 1.00
3 2 3 5
1 9
1 4
1 7
0
2 6 1
1 8
0
0
0
Sample Output:
1.8362 2
*/
/*
树的DFS遍历,读懂题意要紧,找到深度最低的叶节点
*/

#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<unordered_map>

using namespace std;

vector<int> ch[100005];
int mi = 10000000;
int cnt = 0;

void DFS(int min_deep,int index){
    if(ch[index].size() == 0){
        if(min_deep < mi){cnt = 1;mi = min_deep;}
        else if(min_deep == mi){cnt++;}
    }
    else{
        for(int i = 0;i<ch[index].size();i++){
            DFS(min_deep+1,ch[index][i]);
        }
    }
}

vector<int> ve;
int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    int N; scanf("%d",&N);
    double P,r; scanf("%lf%lf",&P,&r);
    for(int i = 0;i<N;i++){
        int temp; scanf("%d",&temp);
        for(int z = 0;z<temp;z++){
            int index; scanf("%d",&index);
            ch[i].push_back(index);
        }
    }
    //处理完毕
    DFS(0,0);
    double p = 1+r/100;
    for(int i = 0;i<mi;i++){
        P = P*p;
    }
    printf("%.4f %d",P,cnt);
    return 0;
}