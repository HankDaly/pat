/*
1114 Family Property （25 分）
This time, you are supposed to help us collect the data for family-owned property. Given each person's family members, and the estate（房产）info under his/her own name, we need to know the size of each family, and the average area and number of sets of their real estate.

Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (≤1000). Then N lines follow, each gives the infomation of a person who owns estate in the format:

ID Father Mother k Child
​1
​​ ⋯Child
​k
​​  M
​estate
​​  Area

where ID is a unique 4-digit identification number for each person; Father and Mother are the ID's of this person's parents (if a parent has passed away, -1 will be given instead); k (0≤k≤5) is the number of children of this person; Child
​i
​​ 's are the ID's of his/her children; M
​estate
​​  is the total number of sets of the real estate under his/her name; and Area is the total area of his/her estate.

Output Specification:
For each case, first print in a line the number of families (all the people that are related directly or indirectly are considered in the same family). Then output the family info in the format:

ID M AVG
​sets
​​  AVG
​area
​​ 

where ID is the smallest ID in the family; M is the total number of family members; AVG
​sets
​​  is the average number of sets of their real estate; and AVG
​area
​​  is the average area. The average numbers must be accurate up to 3 decimal places. The families must be given in descending order of their average areas, and in ascending order of the ID's if there is a tie.

Sample Input:
10
6666 5551 5552 1 7777 1 100
1234 5678 9012 1 0002 2 300
8888 -1 -1 0 1 1000
2468 0001 0004 1 2222 1 500
7777 6666 -1 0 2 300
3721 -1 -1 1 2333 2 150
9012 -1 -1 3 1236 1235 1234 1 100
1235 5678 9012 0 1 50
2222 1236 2468 2 6661 6662 1 300
2333 -1 3721 3 6661 6662 6663 1 100
Sample Output:
3
8888 1 1.000 1000.000
0001 15 0.600 100.000
5551 4 0.750 100.000
*/

/*
总结:
并查集解法,注意并查集的查是递归的，剩下就是处理并查集的关系了.
最后注意sort一下
*/

#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<unordered_map>

using namespace std;

struct Node{
    int id;
    int flag = -2; //默认为-2表示未被访问过,-1为根节点，上面就是指向别的节点
    //下面是根节点的数据
    int set = 0;
    int area = 0;
    int people_number = 0;
}ch[100005];

vector<Node> ve;

bool cmp(Node a,Node b){
    if(double(a.area)/a.people_number == double(b.area)/b.people_number){
        return a.id < b.id;
    }
    else{
        return double(a.area)/a.people_number > double(b.area)/b.people_number;
    }
}
void creat_root(int index){
    if(ch[index].flag == -2){
        ch[index].flag = -1; //标记为根节点
    } 
}

int find_root(int index){
    if(ch[index].flag != -1){
        index = ch[index].flag;
        return find_root(index);
    }
    else{return index;}
}

void merge_root(int a,int b){
    int a_root = find_root(a);
    int b_root = find_root(b);
    if(a_root == b_root){return;}//根节点一致，无需合并
    else{
        //如果a_root小于b_root
        if(a_root < b_root){
            ch[b_root].flag = a_root;
            ch[a_root].area += ch[b_root].area;
            ch[a_root].set += ch[b_root].set;
        } //将b指向a

        else{
            ch[a_root].flag = b_root;
            ch[b_root].area += ch[a_root].area;
            ch[b_root].set += ch[a_root].set;
        }
    }
}

int main(){
#ifdef LOCAL
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif

    int N; cin >> N;
    for(int i = 0;i<N;i++){
        int person,father,mather; cin >> person >> father >> mather;
        creat_root(person);
        ch[person].id = person;
        if(father != -1){
            creat_root(father);
            ch[father].id = father;
            merge_root(person,father);
            }
        if(mather != -1){
            creat_root(mather);
            ch[mather].id = mather;
            merge_root(person,mather);
        }
        //自己，父，母处理完毕
        int child; cin >> child;
        for(int i = 0;i<child;i++){
            int temp; cin >> temp;
            creat_root(temp);
            ch[temp].id = temp; 
            merge_root(person,temp);
        }
        //向根节点中记录套数和面积
        int root_index = find_root(person);
        int set,area; cin >> set >> area;
        ch[root_index].area += area;
        ch[root_index].set += set;
    }
    //处理完毕
    int cnt = 0;
    for(int i = 0;i<10005;i++){
        if(ch[i].flag == -1){
            cnt++;
        }
        if(ch[i].flag != -2){
            int root_index = find_root(i);
            ch[root_index].people_number++;
        }
    }
    for(int i = 0;i<10005;i++){
        if(ch[i].flag == -1){ve.push_back(ch[i]);}
    }
    cout << cnt << "\n";
    sort(ve.begin(),ve.end(),cmp);
    for(int i = 0;i<ve.size();i++){
        double avg_set,avg_area;
        avg_set = double(ve[i].set)/ve[i].people_number;
        avg_area = double(ve[i].area)/ve[i].people_number;
        printf("%04d %d %.3f %.3f\n",ve[i].id,ve[i].people_number,avg_set,avg_area);
    }

    return 0;
}