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

int main()
{  
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    int a; //a保存学生数量
    cin >> a;
    int max_grade = 0,min_grade = 100; //初始化最高成绩与最低成绩
    string max_me,min_me; //初始化最高，最低信息
    for(int i = 0;i<a;i++){
        string na,st; //na储存姓名,st储存学号
        int gra; //gra 代表分数
        cin >> na >> st >> gra;
        if(gra >= max_grade){max_grade = gra;max_me = na + " " + st;}
        if(gra <= min_grade){min_grade = gra;min_me = na + " " + st;}
    }
    cout << max_me << "\n" << min_me << endl;

}


