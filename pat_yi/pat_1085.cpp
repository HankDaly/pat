/*
1085 PAT单位排行（25 分）
每次 PAT 考试结束后，考试中心都会发布一个考生单位排行榜。本题就请你实现这个功能。

输入格式：
输入第一行给出一个正整数 N（≤10
​5
​​ ），即考生人数。随后 N 行，每行按下列格式给出一个考生的信息：

准考证号 得分 学校
其中准考证号是由 6 个字符组成的字符串，其首字母表示考试的级别：B代表乙级，A代表甲级，T代表顶级；得分是 [0, 100] 区间内的整数；学校是由不超过 6 个英文字母组成的单位码（大小写无关）。注意：题目保证每个考生的准考证号是不同的。

输出格式：
首先在一行中输出单位个数。随后按以下格式非降序输出单位的排行榜：

排名 学校 加权总分 考生人数
其中排名是该单位的排名（从 1 开始）；学校是全部按小写字母输出的单位码；加权总分定义为乙级总分/1.5 + 甲级总分 + 顶级总分*1.5的整数部分；考生人数是该属于单位的考生的总人数。

学校首先按加权总分排行。如有并列，则应对应相同的排名，并按考生人数升序输出。如果仍然并列，则按单位码的字典序输出。

输入样例：
10
A57908 85 Au
B57908 54 LanX
A37487 60 au
T28374 67 CMU
T32486 24 hypu
A66734 92 cmu
B76378 71 AU
A47780 45 lanx
A72809 100 pku
A03274 45 hypu
输出样例：
5
1 cmu 192 2
1 au 192 3
3 pku 100 1
4 hypu 81 2
4 lanx 81 2
*/

/*
总结:
用unordered_map做散列比map做算量小
*/


#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cctype>
#include<vector>
#include<unordered_map>


using namespace std;
struct Node{
	string name;
	double all;
	int student_number;
};

vector<string> ve_st;

vector<Node> ve;
unordered_map<string,Node> mp;

bool cmp(Node a,Node b){
	if(a.all == b.all && a.student_number == b.student_number){return a.name < b.name;}
	if(a.all == b.all){return a.student_number < b.student_number;}
	return a.all > b.all;
}
int main(){
#ifdef LOCAL
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int N; cin >> N;
	int sum_school = 0;
	for(int i = 0;i<N;i++){
		string test_id; cin >> test_id;
		double number; cin >> number;
		string name; cin >> name;
		double now_number;
		if(test_id[0] == 'B'){now_number = number/1.5;}
		if(test_id[0] == 'A'){now_number = number;}
		if(test_id[0] == 'T'){now_number = number*1.5;}
		for(int z = 0;z<name.size();z++){
			name[z] = tolower(name[z]);
		}
		if(!mp.count(name)){
			++sum_school;
			Node node;
			node.all = 0;
			node.student_number = 1;
			node.name = name;
			ve_st.push_back(name);
			node.all += now_number;
            mp[name] = node;
		}
		else{mp[name].all += now_number;mp[name].student_number++;}
	}
	for(int i = 0;i<ve_st.size();i++){
		int temp = mp[ve_st[i]].all;
		mp[ve_st[i]].all = temp;
		ve.push_back(mp[ve_st[i]]);
	}
	sort(ve.begin(),ve.end(),cmp);
	//
    cout << sum_school << endl;
	int list = 1;
	cout << list << " " << ve[0].name << " " << ve[0].all << " " << ve[0].student_number << endl;
	for(int i = 1;i<ve.size();i++){
		if(ve[i].all != ve[i-1].all){list = i+1;}
        cout << list << " " << ve[i].name << " " << ve[i].all << " " << ve[i].student_number << endl;
	}
	return 0;
}