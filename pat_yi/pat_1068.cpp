/*
1068 万绿丛中一点红（20 分）
对于计算机而言，颜色不过是像素点对应的一个 24 位的数值。现给定一幅分辨率为 M×N 的画，要求你找出万绿丛中的一点红，即有独一无二颜色的那个像素点，并且该点的颜色与其周围 8 个相邻像素的颜色差充分大。

输入格式：
输入第一行给出三个正整数，分别是 M 和 N（≤ 1000），即图像的分辨率；以及 TOL，是所求像素点与相邻点的颜色差阈值，色差超过 TOL 的点才被考虑。随后 N 行，每行给出 M 个像素的颜色值，范围在 [0,2
​24
​​ ) 内。所有同行数字间用空格或 TAB 分开。

输出格式：
在一行中按照 (x, y): color 的格式输出所求像素点的位置以及颜色值，其中位置 x 和 y 分别是该像素在图像矩阵中的列、行编号（从 1 开始编号）。如果这样的点不唯一，则输出 Not Unique；如果这样的点不存在，则输出 Not Exist。

输入样例 1：
8 6 200
0 	 0 	  0 	   0	    0 	     0 	      0        0
65280 	 65280    65280    16711479 65280    65280    65280    65280
16711479 65280    65280    65280    16711680 65280    65280    65280
65280 	 65280    65280    65280    65280    65280    165280   165280
65280 	 65280 	  16777015 65280    65280    165280   65480    165280
16777215 16777215 16777215 16777215 16777215 16777215 16777215 16777215
输出样例 1：
(5, 3): 16711680
输入样例 2：
4 5 2
0 0 0 0
0 0 3 0
0 0 0 0
0 5 0 0
0 0 0 0
输出样例 2：
Not Unique
输入样例 3：
3 3 5
1 2 3
3 4 5
5 6 7
输出样例 3：
Not Exist
*/
/*
注意两个点:这个点必须是这个屏幕中唯一的点，没有重复出现过。
还有一个点，用循环减的时候,别减了自己。
*/

#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
long ch[1005][1005]; 
int ch_1[100000005];
vector<long> ve;
main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    memset(ch,0,sizeof(ch));
    int M,N,TOL; cin >> M >> N >> TOL; //M(x列),N(y行)
    for(int i = 0;i<N;i++){
        for(int z = 0;z<M;z++){
            int temp; cin >> temp;
            ch_1[temp]++;
            ch[z][i] = temp;
        }
    }
    for(int i = 0;i<N;i++){
        for(int z = 0;z<M;z++){
            int temp; temp = ch[z][i];
            if(ch_1[temp] == 1){ve.push_back(temp);}
        }
    }
    
    int cnt = 0;
    int now_x,now_y;
    for(int q = 0;q<N;q++){
        for(int p = 0;p<M;p++){
            int ok = 1;
            for(int i = q-1;i<=q+1;i++){
                if(i<0 || i>N-1){continue;}
                for(int z = p-1;z<=p+1;z++){
                    if(z<0 || z>M-1){continue;}
                    else{
                        if(z == p && i == q){continue;}
                        if(abs(ch[p][q]-ch[z][i]) <= TOL){ok = 0;}
                    }
                }
            }
            if(ok == 1 && count(ve.begin(),ve.end(),ch[p][q])){cnt++;now_x=p;now_y=q;}
        }
    }
    if(cnt == 0){cout << "Not Exist";}
    if(cnt == 1){printf("(%d, %d): %ld",now_x+1,now_y+1,ch[now_x][now_y]);}
    if(cnt >= 2){printf("Not Unique");}
    return 0;
}
