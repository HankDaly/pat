/*

1065 单身狗（25 分）
“单身狗”是中文对于单身人士的一种爱称。本题请你从上万人的大型派对中找出落单的客人，以便给予特殊关爱。

输入格式：
输入第一行给出一个正整数 N（≤ 50 000），是已知夫妻/伴侣的对数；随后 N 行，每行给出一对夫妻/伴侣——为方便起见，每人对应一个 ID 号，为 5 位数字（从 00000 到 99999），ID 间以空格分隔；之后给出一个正整数 M（≤ 10 000），为参加派对的总人数；随后一行给出这 M 位客人的 ID，以空格分隔。题目保证无人重婚或脚踩两条船。

输出格式：
首先第一行输出落单客人的总人数；随后第二行按 ID 递增顺序列出落单的客人。ID 间用 1 个空格分隔，行的首尾不得有多余空格。

输入样例：
3
11111 22222
33333 44444
55555 66666
7
55555 44444 10000 88888 22222 11111 23333
输出样例：
5
10000 23333 44444 55555 88888
*/
/*
总结:
这题关键要解决，有伴侣的人如何确定伴侣是否来了。那么就会想到，如果有伴侣，不单单要给自己记上，也要给伴侣记上。
，或者有办法能连接到伴侣地方进行验证。
想法是构建一个二维字符串数组,下标对应每个id,[0]代表有无伴侣,[1]作为后面的标记.
第一遍循环将每个有伴侣的id的[0]的地方写入对应伴侣的id;
第二遍循环,如果读到的那个数字[0]的地方有伴侣,那么就在他和他伴侣的[1]处做上一个标记，
如果没伴侣，那么给自己的[1]处做上标记。
后面判断，在来的一些id中，[1]处如果只有一个标记，代表没伴侣或者伴侣没来，有二个标记代表伴侣来了。
*/


#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<cstdio>
#include<vector>

using namespace std;
string ch[1000005][2];
vector<int> ve; 

main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    for(int i = 0;i<1000005;i++){
        for(int z = 0;z<2;z++){
            ch[i][z] = "-1";
        }
    }
    //将二维字符数组置'0'
    int N; cin >> N;
    for(int i = 0;i<N;i++){
        string A,B; cin >> A >> B;
        ch[stoi(A)][0] = B;
        ch[stoi(B)][0] = A;
    }
    int M; cin >> M;
    for(int i = 0;i<M;i++){
        string temp; cin >> temp;
        ve.push_back(stoi(temp));
        if(ch[stoi(temp)][0] != "-1"){
            ch[stoi(temp)][1] += '1';
            int te = stoi(ch[stoi(temp)][0]);
            ch[te][1] += '1';  //给两夫妻都加一
        }
        else{ch[stoi(temp)][1] += '1';}
    }
    int cont = 0;
    for(int i = 0;i<ve.size();i++){
        if(ch[ve[i]][1] == "-11"){cont++;}
    }
    cout << cont << "\n";
    sort(ve.begin(),ve.end());
    int kase = 0;
    for(int i = 0;i<ve.size();i++){
        if(ch[ve[i]][1] == "-11"){
            if(kase != 0){cout << " ";}
            string temp = to_string(ve[i]);
            temp.insert(temp.begin(),5-temp.size(),'0');
            kase++;
            cout << temp;
        }
    }
    return 0;
}
