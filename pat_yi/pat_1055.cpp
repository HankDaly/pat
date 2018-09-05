/*
1055 集体照（25 分）
拍集体照时队形很重要，这里对给定的 N 个人 K 排的队形设计排队规则如下：

每排人数为 N/K（向下取整），多出来的人全部站在最后一排；

后排所有人的个子都不比前排任何人矮；

每排中最高者站中间（中间位置为 m/2+1，其中 m 为该排人数，除法向下取整）；

每排其他人以中间人为轴，按身高非增序，先右后左交替入队站在中间人的两侧（例如5人身高为190、188、186、175、170，则队形为175、188、190、186、170。这里假设你面对拍照者，所以你的左边是中间人的右边）；

若多人身高相同，则按名字的字典序升序排列。这里保证无重名。

现给定一组拍照人，请编写程序输出他们的队形。

输入格式：
每个输入包含 1 个测试用例。每个测试用例第 1 行给出两个正整数 N（≤10
​4
​​ ，总人数）和 K（≤10，总排数）。随后 N 行，每行给出一个人的名字（不包含空格、长度不超过 8 个英文字母）和身高（[30, 300] 区间内的整数）。

输出格式：
输出拍照的队形。即K排人名，其间以空格分隔，行末不得有多余空格。注意：假设你面对拍照者，后排的人输出在上方，前排输出在下方。

输入样例：
10 3
Tom 188
Mike 170
Eva 168
Tim 160
Joe 190
Ann 168
Bob 175
Nick 186
Amy 160
John 159
输出样例：
Bob Tom Joe Nick
Ann Mike Eva
Tim Amy John
*/
/*
总结:
主要一个就是怎么去按左右排，后来想到存到另一个数组就行了。
思路按部就班的下来，速度要再提高一点
*/



#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;

struct Node{
    string name;
    int high;
};
Node list[10005];
Node ch[10005];

bool cmp(Node a,Node b){
    if(a.high == b.high){return a.name<b.name;}
    else{return a.high>b.high;}
}

int main()
{
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    memset(ch,0,sizeof(ch));
    memset(list,0,sizeof(list));
    int N,K; cin >> N >> K;
    for(int i = 0;i<N;i++){
        Node node; cin >> node.name >> node.high;
        list[i] = node;
    }
    sort(list,list+N,cmp);
    int each_p = N/K,last_p = N-(N/K)*(K-1); //计算出每排和最后一排的人数。
    int z = 0;
    for(int i = 0;i<K;i++){
        int p_number= i==0? last_p:each_p; //p_number是当前排的人数。
        int max = 5002,min = 5002;
        int cont = 5002;
        int p = 0,q = 1;

        for(int now_z = z+p_number;z<now_z&&z<N;z++){
            cont += p*q;
            if(cont > max){max = cont;}
            if(cont < min){min = cont;}
            ch[cont] = list[z];
            ++p; q *= -1;
        }
        for(int j = min;j<=max;j++){
            if(j != min){cout << " ";}
            cout << ch[j].name;
        }
        cout << "\n";
        memset(ch,0,sizeof(ch));
    }
	return 0;
}