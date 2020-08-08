#include <cstdio>
#include <cstring>
#include <vector> 
#include <algorithm>
using namespace std;

const int maxn = 40010;//最大学生人数
const int maxc = 2510;//最大课程门数

char name[maxn][5];//maxn个学生
vector<int> course[maxc];//course[i]存放第i门课的所有学生编号

bool cmp(int a ,int b ){
	return strcmp(name[a],name[b]) < 0;
} 

int main(){
	int n,k,c,courseID;
	scanf("%d%d",&n,&k);
	for(int i = 0;i<n;i++){
		scanf("%s %d",name[i],&c);
		for(int j = 0;j<c;j++){
			scanf("%d",&courseID);
			course[courseID].push_back(i);//将学生i加入到第courseID门课中 
		}
	}
	
	for(int i = 1;i<= k;i++){
		printf("%d %d\n",i,course[i].size());
		sort(course[i].begin(),course[i].end(),cmp);
		for(int j = 0;j<course[i].size();j++){
			printf("%s\n",name[course[i][j]]);
		}
	}
}
/*
10 5
ZOE1 2 4 5
ANN0 3 5 2 1
BOB5 5 3 4 2 1 5
JOE4 1 2
JAY9 4 1 2 5 4
FRA8 3 4 2 5
DON2 2 4 5
AMY7 1 5
KAT3 3 5 4 2
LOR6 4 2 4 1 5
*/
