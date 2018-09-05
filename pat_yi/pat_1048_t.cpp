#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cctype>


using namespace std;

int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    string A,B; cin >> A >> B;
    int a_l = A.size()-1;
    int b_l = B.size()-1;
    int kase = 1;
    while(a_l>=0&&b_l>=0){
        int sum;
        if(kase%2){
            sum = ((A[a_l]-'0')+(B[b_l]-'0'))%13;
            if(sum > 9){
                if(sum == 10){B[b_l] = 'J';}
                if(sum == 11){B[b_l] = 'Q';}
                if(sum == 12){B[b_l] = 'K';}
                }
            else{B[b_l] = to_string(sum)[0];}
        }
        else{
            sum = (B[b_l]-'0')-(A[a_l]-'0');
            if(sum<0){B[b_l] = to_string(sum+10)[0];}
            else{B[b_l] = to_string(sum)[0];}
        }
        kase++;
        a_l--; b_l--;
    }
    cout << B;
   return 0;
}