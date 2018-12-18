/*
1033 To Fill or Not to Fill （25 分）
With highways available, driving a car from Hangzhou to any other city is easy. But since the tank capacity of a car is limited, we have to find gas stations on the way from time to time. Different gas station may give different price. You are asked to carefully design the cheapest route to go.

Input Specification:
Each input file contains one test case. For each case, the first line contains 4 positive numbers: C
​max
​​  (≤ 100), the maximum capacity of the tank; D (≤30000), the distance between Hangzhou and the destination city; D
​avg
​​  (≤20), the average distance per unit gas that the car can run; and N (≤ 500), the total number of gas stations. Then N lines follow, each contains a pair of non-negative numbers: P
​i
​​ , the unit gas price, and D
​i
​​  (≤D), the distance between this station and Hangzhou, for i=1,⋯,N. All the numbers in a line are separated by a space.

Output Specification:
For each test case, print the cheapest price in a line, accurate up to 2 decimal places. It is assumed that the tank is empty at the beginning. If it is impossible to reach the destination, print The maximum travel distance = X where X is the maximum possible distance the car can run, accurate up to 2 decimal places.

Sample Input 1:
50 1300 12 8
6.00 1250
7.00 600
7.00 150
7.10 0
7.20 200
7.50 400
7.30 1000
6.85 300
Sample Output 1:
749.17
Sample Input 2:
50 1300 12 2
7.10 0
7.00 600
Sample Output 2:
The maximum travel distance = 1200.00
*/
/*
总结:
一道贪心算法题目,最后提炼的算法是比当前便宜的时候灌走到便宜处的油即可，如果下面全部是贵的，选择最便宜的灌满了
过去即可。
边界点:
道路及油量都要用double,如果没有0的加油站(虽然现实中很荒谬),那么最远距离就是0.00
反思:
还是不熟悉英文环境导致的，没有中文时对边界那么敏感了，其实上面的边界都有考虑过，但是后来去想的时候忘记了没有0加油站
这个边界条件。
应对方法,拿到题目审完题后就把给的变量的类型都标出来，然后思考一下可能会出现的边界条件，后面在思考算法的时候，如果
有对边界条件的想法随时标记在变量类型那块区域。
*/



#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>

using namespace std;
struct Node{
    double price;
    double distance;
};

vector<Node> ve;

double calcu_price(const vector<Node>& vec,double C_max,double D,double D_avg,double& price,int& stationindex,double& capacity,int& flag){
    //检测还有几个加油站
    int cnt = 0;
    double max_runpath = C_max*D_avg; //cnt计数加油站个数,max_runpath代表最大路径
    for(int i = stationindex+1;i<vec.size();i++){
         //如果超过了，则退出
        if(vec[i].distance-vec[stationindex].distance > max_runpath){break;}
        else{
            if(vec[i].price < vec[stationindex].price){
                price += ((vec[i].distance - vec[stationindex].distance - capacity)/D_avg)*vec[stationindex].price;
                capacity = 0; //到便宜地方后油箱必定被清空
                stationindex = i;
                return calcu_price(vec,C_max,D,D_avg,price,stationindex,capacity,flag);
            }
            else{++cnt;}
        }
    }
    //现在已经排除了便宜加油站的可能
    //讨论没有加油站和有贵加油站两种情况
    //如果到的了
    if(vec[stationindex].distance + max_runpath >= D){
        price += ((D-vec[stationindex].distance-capacity)/D_avg)*vec[stationindex].price;
        return price;
    }
    //如果到不了
    else{
        //没有下面的站台了
        if (cnt == 0){flag = 0;return vec[stationindex].distance + max_runpath;}
        //只剩下贵的站台
        else{
            int temp_index = 1;
            double cheap = vec[stationindex+1].price;
            for(int i = 1;i<=cnt;i++){
                if(vec[stationindex+i].price < cheap){
                    cheap = vec[stationindex+i].price;
                    temp_index = i;
                }
            }
            //找到贵的里面最便宜的,然后灌满了过去
            int index = stationindex+temp_index;
            price += ((max_runpath-capacity)/D_avg)*vec[stationindex].price;
            capacity = max_runpath-(vec[index].distance - vec[stationindex].distance);
            stationindex = index;
            return calcu_price(vec,C_max,D,D_avg,price,stationindex,capacity,flag);
        }
    }
}

bool cmp(Node a,Node b){return a.distance < b.distance;}

int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    // C_max是最大储油量，D是路程，D_avg是每升油开的路，N是加油站的个数
    double C_max,D,D_avg; cin >> C_max >> D >> D_avg; 
    int N; cin >> N;
    int stationindex = 0; //price统计价格,runpath统计站点,capacity统计油量
    double price = 0.0,capacity = 0;
    int flag = 1;
    double anwser = 0;
    for(int i = 0;i<N;i++){
        double prices;
        double distance;
        cin >> prices >> distance;
        Node node; node.price = prices; node.distance = distance;
        ve.push_back(node);
    }
    sort(ve.begin(),ve.end(),cmp);
    //前期准备完成
    anwser =  calcu_price(ve,C_max,D,D_avg,price,stationindex,capacity,flag);
    if(ve[0].distance > 0){printf("The maximum travel distance = 0.00");}
    else if(flag == 0){printf("The maximum travel distance = %.2f",anwser);}
    else{printf("%.2f",anwser);}
    return 0;
}