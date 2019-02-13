/*
1074 Reversing Linked List （25 分）
Given a constant K and a singly linked list L, you are supposed to reverse the links of every K elements on L. For example, given L being 1→2→3→4→5→6, if K=3, then you must output 3→2→1→6→5→4; if K=4, you must output 4→3→2→1→5→6.

Input Specification:
Each input file contains one test case. For each case, the first line contains the address of the first node, a positive N (≤10
​5
​​ ) which is the total number of nodes, and a positive K (≤N) which is the length of the sublist to be reversed. The address of a node is a 5-digit nonnegative integer, and NULL is represented by -1.

Then N lines follow, each describes a node in the format:

Address Data Next
where Address is the position of the node, Data is an integer, and Next is the position of the next node.

Output Specification:
For each case, output the resulting ordered linked list. Each node occupies a line, and is printed in the same format as in the input.

Sample Input:
00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
Sample Output:
00000 4 33218
33218 3 12309
12309 2 00100
00100 1 99999
99999 5 68237
68237 6 -1
*/
/*
总结：
注意链表题目会有无效链表，所以要对有效链表进行计数，后期用计数的cnt取代N
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

string change(int a){
    string st = to_string(a);
    string temp = st;
    if(st.size() < 5){
        for(int i = 0;i+st.size() < 5;i++){
            temp = "0"+temp;
        }
    }
    return temp;
}

struct Node{
    int address = 0;
    int data = 0;
    int next;
};
Node ch[100005];
Node order_ch[100005];

main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    int first_address,N,K; cin >> first_address >> N >> K;
    int cnt = 0;
    for(int i = 0;i<N;i++){
        Node node; cin >> node.address >> node.data >> node.next;
        ch[node.address] = node;
    }
    int temp_address = first_address;
    for(int i = 1;i<=N && temp_address != -1;i++){
        cnt++;
        order_ch[i] = ch[temp_address];
        temp_address = ch[temp_address].next;
    }
    //处理完毕
    for(int i = 1;i<=cnt;i = i+K){
        if(i+K <= cnt+1){
            for(int z = i+K-1;z>=i;z--){
                if(z == 1+K-1){cout << change(order_ch[z].address) << " " << order_ch[z].data << " ";}
                else{cout << change(order_ch[z].address) << "\n" << change(order_ch[z].address) << " " << order_ch[z].data << " ";}
            }
        }
        else{
            for(int z = i;z<=cnt;z++){
                cout << change(order_ch[z].address) << "\n" << change(order_ch[z].address) << " " << order_ch[z].data << " ";
            }
        }
    }
    cout << "-1";

    return 0;
}