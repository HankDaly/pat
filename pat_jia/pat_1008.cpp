#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    int N; cin >> N;
    int flr = 0,sum = 0;
    for(int i = 0;i<N;i++){
        int next_floor; cin >> next_floor;
        int move = next_floor - flr;
        if(move<0){
            sum += move*(-1)*4+5;
        }
        else{sum += move*6 + 5;}
        flr = next_floor;
    }
    cout << sum;
    return 0;
}