#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
#include<vector>
#include<set>
#include<map>
#include<cstring>
#include<math.h>

using namespace std;

vector<int> udef ; //udef用来统计出现过的覆盖数
vector<int> sum ; //sum用来储藏所有数字

int ite(vector<int>& udef,int n){
    if(n%2 == 0){
        n = n/2;
        if(!count(udef.begin(),udef.end(),n)){udef.push_back(n);}
    }
    else if(n == 1){}
    else{
        n = ((3*n+1)/2);
        if(!count(udef.begin(),udef.end(),n)){udef.push_back(n);}
    }
    if(n != 1){ite(udef,n);}
    return 0;
}

int main()
{  
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    int a,b; //a用来储存总数,b用来储存每个数
    cin >> a;
    for(int i = 0;i<a;i++){
        cin >> b;
        ite(udef,b);
        sum.push_back(b);
    }
    sort(sum.begin(),sum.end(),greater<int>()); //从大到小
    int kase = 0;
    for(int i = 0;i<a;i++){
        if(kase == 0 && !count(udef.begin(),udef.end(),sum[i])){cout<< sum[i];kase++;}
        else if(!count(udef.begin(),udef.end(),sum[i])){cout << " " << sum[i];}
        else{}
    }
    return 0;

}


