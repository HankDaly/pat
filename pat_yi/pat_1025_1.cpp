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
第一次的做法，最后两个通不过，一个是超时，一个条件是有错误的结点无法判断出来。
为什么要用两个二维数组存，一开始看到排列要打乱，想的就是直接用打乱后的下标去获取数组，那个数组必须安放的是排列好顺序后的数组，
再加上前面没有排列好的数组，那么就要两个二维数组。
但其实存的数据可以继续存在前面的数组里。直接用下标找就行了。然后打乱顺序我一开始直接想排好，但是不如直接用reverse打乱排列好的
列表来的直观
*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;
vector<int> ve;
int ch_1[100005][5];
int ch_2[100005][5];

int main(){
#ifdef LOCAL
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    int first_ad,N,K; cin >> first_ad >> N >> K;
    int len = N;
    int kase = 0;
    for(int i = 1;i<=N;i++){
        int  one_ad,data,end_ad; cin >> one_ad >> data >> end_ad;
        ch_1[one_ad][1] = end_ad;
        ch_1[one_ad][2] = data;
    }
    ch_2[1][0] = first_ad; ch_2[1][1] = ch_1[first_ad][1]; ch_2[1][2] = ch_1[first_ad][2];
    for(int i = 2;;i++){
        if(ch_2[i-1][1] == -1){break;}
        ch_2[i][0] = ch_2[i-1][1];
        ch_2[i][1] = ch_1[ch_2[i][0]][1];
        ch_2[i][2] = ch_1[ch_2[i][0]][2];
    }
    // 整理反转
    while(len/K>0){
        len = len - K;
        ++kase;
        for(int i = kase*K;i>(kase-1)*K;i--){
            ve.push_back(i);
        }
    }
    for(int i = kase*K+1;i<=N;i++){
        ve.push_back(i);
    }
    // 整理完毕
    for(int i = 0;i<ve.size();i++){
        string fir_st,end_st;
        int data_st;
        fir_st = to_string(ch_2[ve[i]][0]);
        if(i+1 != ve.size()){end_st = to_string(ch_2[ve[i+1]][0]);}
        else{end_st = "-1";}
        data_st = ch_2[ve[i]][2];
        fir_st.insert(0,5-fir_st.size(),'0');
        if(i+1 != ve.size()){end_st.insert(0,5-end_st.size(),'0');}
        cout << fir_st << " " << data_st << " " << end_st << endl;
    }
    return 0;   
}