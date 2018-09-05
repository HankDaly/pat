#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
vector<double> ve;
int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    int N; cin >> N;
    for(int i = 0;i<N;i++){
        double temp; cin >> temp;
        ve.push_back(temp);
    }
    sort(ve.begin(),ve.end());
    double sum = floor(ve[0]/2+ve[1]/2);
    
    for(int i = 2;i<ve.size();i++){
        sum = floor(sum/2+ve[i]/2);
    }
    cout << sum;
    
    return 0;
}