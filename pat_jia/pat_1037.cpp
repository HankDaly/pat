/*
1037 Magic Coupon （25 分）
The magic shop in Mars is offering some magic coupons. Each coupon has an integer N printed on it, meaning that when you use this coupon with a product, you may get N times the value of that product back! What is more, the shop also offers some bonus product for free. However, if you apply a coupon with a positive N to this bonus product, you will have to pay the shop N times the value of the bonus product... but hey, magically, they have some coupons with negative N's!

For example, given a set of coupons { 1 2 4 −1 }, and a set of product values { 7 6 −2 −3 } (in Mars dollars M$) where a negative value corresponds to a bonus product. You can apply coupon 3 (with N being 4) to product 1 (with value M$7) to get M$28 back; coupon 2 to product 2 to get M$12 back; and coupon 4 to product 4 to get M$3 back. On the other hand, if you apply coupon 3 to product 4, you will have to pay M$12 to the shop.

Each coupon and each product may be selected at most once. Your task is to get as much money back as possible.

Input Specification:
Each input file contains one test case. For each case, the first line contains the number of coupons N
​C
​​ , followed by a line with N
​C
​​  coupon integers. Then the next line contains the number of products N
​P
​​ , followed by a line with N
​P
​​  product values. Here 1≤N
​C
​​ ,N
​P
​​ ≤10
​5
​​ , and it is guaranteed that all the numbers will not exceed 2
​30
​​ .

Output Specification:
For each test case, simply print in a line the maximum amount of money you can get back.

Sample Input:
4
1 2 4 -1
4
7 6 -2 -3
Sample Output:
43
*/
/*
总结:
注意最大不超过int但是合起来的答案肯定是会超过的，所以要用long long，没有说明Np是否为整数，有点疑惑。
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

 vector<double> ve_1;
 vector<double> ve_2;

main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    int NC_1,NC_2;
    cin >> NC_1;
    for(int i = 0;i<NC_1;i++){
        double temp; cin >> temp;
        ve_1.push_back(temp);
    }
    cin >> NC_2;
    for(int i = 0;i<NC_2;i++){
        double temp; cin >> temp;
        ve_2.push_back(temp);
    }
    sort(ve_1.begin(),ve_1.end());
    sort(ve_2.begin(),ve_2.end());
    //前期准备完成
    long long anwser_1 = 0,anwser_2 = 0;
    int ve1_length = ve_1.size();
    int ve2_length = ve_2.size();
    //都是负的情况
    for(int i = 0;i<ve1_length;i++){
        //i没有超过ve2的长度,并且两个ve的值都是负的
        if(i < ve2_length and ve_1[i] < 0 and ve_2[i] < 0){anwser_1 += ve_1[i]*ve_2[i];}
        else{break;}
    }
    reverse(ve_1.begin(),ve_1.end());
    reverse(ve_2.begin(),ve_2.end());
    //都是正的情况
    for(int i = 0;i<ve1_length;i++){
        //i没有超过ve2的长度,并且两个ve的值都是正的
        if(i < ve2_length and ve_1[i] > 0 and ve_2[i] > 0){anwser_2 += ve_1[i]*ve_2[i];}
        else{break;}
    }
    cout << anwser_1+anwser_2;
    return 0;
}