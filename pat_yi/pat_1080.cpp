/*
1080 MOOC期终成绩（25 分）
对于在中国大学MOOC（http://www.icourse163.org/ ）学习“数据结构”课程的学生，想要获得一张合格证书，必须首先获得不少于200分的在线编程作业分，然后总评获得不少于60分（满分100）。总评成绩的计算公式为 G=(G
​mid−term
​​ ×40%+G
​final
​​ ×60%)，如果 G
​mid−term
​​ >G
​final
​​ ；否则总评 G 就是 G
​final
​​ 。这里 G
​mid−term
​​  和 G
​final
​​  分别为学生的期中和期末成绩。

现在的问题是，每次考试都产生一张独立的成绩单。本题就请你编写程序，把不同的成绩单合为一张。

输入格式：
输入在第一行给出3个整数，分别是 P（做了在线编程作业的学生数）、M（参加了期中考试的学生数）、N（参加了期末考试的学生数）。每个数都不超过10000。

接下来有三块输入。第一块包含 P 个在线编程成绩 G
​p
​​ ；第二块包含 M 个期中考试成绩 G
​mid−term
​​ ；第三块包含 N 个期末考试成绩 G
​final
​​ 。每个成绩占一行，格式为：学生学号 分数。其中学生学号为不超过20个字符的英文字母和数字；分数是非负整数（编程总分最高为900分，期中和期末的最高分为100分）。

输出格式：
打印出获得合格证书的学生名单。每个学生占一行，格式为：

学生学号 G
​p
​​  G
​mid−term
​​  G
​final
​​  G

如果有的成绩不存在（例如某人没参加期中考试），则在相应的位置输出“−1”。输出顺序为按照总评分数（四舍五入精确到整数）递减。若有并列，则按学号递增。题目保证学号没有重复，且至少存在1个合格的学生。

输入样例：
6 6 7
01234 880
a1903 199
ydjh2 200
wehu8 300
dx86w 220
missing 400
ydhfu77 99
wehu8 55
ydjh2 98
dx86w 88
a1903 86
01234 39
ydhfu77 88
a1903 66
01234 58
wehu8 84
ydjh2 82
missing 99
dx86w 81
输出样例：
missing 400 -1 99 99
ydjh2 200 98 82 88
dx86w 220 88 81 84
wehu8 300 55 84 84
*/
/*
总结:
学号是数字加上数字，那么就用map存。
最后添加到vector中sort一下。
*/



#include<cstdio>
#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

struct Node{
	int mid_term;
	int final;
	int p;
	int all;
	string name;
};
map<string,Node> mp;
vector<Node> ve;
vector<string> ve_st;
bool cmp(Node a,Node b){
	if(a.all == b.all){return a.name < b.name;}
	else{return a.all > b.all;}
}
int main(){
#ifdef LOCAL
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int P,M,N; cin >> P >> M >> N;
	for(int i = 0;i<P;i++){
		string number; cin >> number;
		int p; cin >> p;
		Node node; node.final = -1; node.mid_term = -1; node.p = p; node.name = number;
		mp[number] = node;
		ve_st.push_back(number);
	}
	for(int i = 0;i<M;i++){
		string number; cin >> number;
		int mid_term; cin >> mid_term;
		if(mp.count(number)){mp[number].mid_term = mid_term;}
	}
	for(int i = 0;i<N;i++){
		string number; cin >> number;
		int final; cin >> final;
		if(mp.count(number)){mp[number].final = final;}
	}
	for(int i = 0;i<ve_st.size();i++){
		ve.push_back(mp[ve_st[i]]);
	}
	for(int i = 0;i<ve.size();i++){
		if(ve[i].p<200){ve[i].all = -1;}
		else{
			if(ve[i].mid_term > ve[i].final){
				double temp_mi = ve[i].mid_term,temp_fi = ve[i].final;
				ve[i].all = floor(temp_mi*0.4 + temp_fi*0.6 + 0.5);
			}
			else{ve[i].all = ve[i].final;}
	    }
	}
	sort(ve.begin(),ve.end(),cmp);
	for(int i = 0;i<ve.size();i++){
		if(ve[i].all < 60){break;}
		else{cout << ve[i].name << " " << ve[i].p << " " << ve[i].mid_term <<" "<< ve[i].final << " " << ve[i].all << endl;}
	}
	return 0;
}