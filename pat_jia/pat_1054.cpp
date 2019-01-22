/*
1054 The Dominant Color （20 分）
Behind the scenes in the computer's memory, color is always talked about as a series of 24 bits of information for each pixel. In an image, the color with the largest proportional area is called the dominant color. A strictly dominant color takes more than half of the total area. Now given an image of resolution M by N (for example, 800×600), you are supposed to point out the strictly dominant color.

Input Specification:
Each input file contains one test case. For each case, the first line contains 2 positive numbers: M (≤800) and N (≤600) which are the resolutions of the image. Then N lines follow, each contains M digital colors in the range [0,2
​24
​​ ). It is guaranteed that the strictly dominant color exists for each input image. All the numbers in a line are separated by a space.

Output Specification:
For each test case, simply print the dominant color in a line.

Sample Input:
5 3
0 0 255 16777215 24
24 24 0 0 24
24 0 24 24 24
Sample Output:
24
*/

/*
总结：
普通数组内存过大，用map。
注意大量数据尽量用scanf！！！
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

unordered_map<int,int> mp;

main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    int M,N; cin >> M >> N;
    int max_count = 0;
    int max_number = 0;
    int sum = (M*N)/2;
    int flag = 0;
    for(int i = 0;i<N;i++){
        if(flag == 1){break;}
        for(int z = 0;z<M;z++){
            int temp; scanf("%d",&temp);
            if(!mp.count(temp)){mp[temp] = 1;}
            else{mp[temp]++;}
            //发现过半直接退出
            if(mp[temp] > sum){max_number = temp;flag = 1;break;}

        }
    }
    cout << max_number;
    return 0;
}