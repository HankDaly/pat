/*
1070 Mooncake （25 分）
Mooncake is a Chinese bakery product traditionally eaten during the Mid-Autumn Festival. Many types of fillings and crusts can be found in traditional mooncakes according to the region's culture. Now given the inventory amounts and the prices of all kinds of the mooncakes, together with the maximum total demand of the market, you are supposed to tell the maximum profit that can be made.

Note: partial inventory storage can be taken. The sample shows the following situation: given three kinds of mooncakes with inventory amounts being 180, 150, and 100 thousand tons, and the prices being 7.5, 7.2, and 4.5 billion yuans. If the market demand can be at most 200 thousand tons, the best we can do is to sell 150 thousand tons of the second kind of mooncake, and 50 thousand tons of the third kind. Hence the total profit is 7.2 + 4.5/2 = 9.45 (billion yuans).

Input Specification:
Each input file contains one test case. For each case, the first line contains 2 positive integers N (≤1000), the number of different kinds of mooncakes, and D (≤500 thousand tons), the maximum total demand of the market. Then the second line gives the positive inventory amounts (in thousand tons), and the third line gives the positive prices (in billion yuans) of N kinds of mooncakes. All the numbers in a line are separated by a space.

Output Specification:
For each test case, print the maximum profit (in billion yuans) in one line, accurate up to 2 decimal places.

Sample Input:
3 200
180 150 100
7.5 7.2 4.5
Sample Output:
9.45
*/
/*
总结：
排序题
注意存在库存不够的情况
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
struct Node{
    double amount;
    double money;
};
bool cmp(Node a,Node b){
    if(a.money/a.amount > b.money/b.amount){return true;}
    else{return false;}
}
vector<Node> ve;
main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    int N,D; cin >> N >> D;
    for(int i = 0;i<N;i++){
        Node node;
        cin >> node.amount;
        ve.push_back(node);
    }
    for(int i = 0;i<N;i++){
        cin >> ve[i].money;
    }
    sort(ve.begin(),ve.end(),cmp);
    //整理完成
    int cnt = 0;
    double anwser = 0;
    double now_amount = 0;
    while(now_amount < D && cnt < ve.size()){
        if(now_amount + ve[cnt].amount >= D){
            anwser += (((D-now_amount)/ve[cnt].amount)*ve[cnt].money);
            break;
        }
        else{
            anwser += ve[cnt].money;
            now_amount += ve[cnt].amount;
            cnt++;
        }
    }
    printf("%.2f",anwser);
    return 0;
}