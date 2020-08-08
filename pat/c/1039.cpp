#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 40010;//总人数
const int M = 26*26*26*10 + 1;//由姓名散列成的数字上界

vector<int> selectCourse[M];//每个学生选择的课程编号 
//这是一个变长二维数组 

//根据name得到唯一的hash值 
int getId(char name[]){
	int id = 0;
	for(int i = 0;i < 3;i++ ){
		id = id * 26 + (name[i] - 'A');
	}
	id = id * 10 + (name[3] - '0');
	return id;
}

int main(){
	char name[5];
	int n,k;
	scanf("%d%d",&n,&k);//人数及课程数
	for(int i = 0;i<k;i++){
		int course,x;
		scanf("%d%d",&course,&x);
		for(int j = 0;j<x;j++){
			scanf("%s",name);
			int id = getId(name);
			selectCourse[id].push_back(course);
		}
	} 
	
	for(int i = 0;i < n;i++){
		scanf("%s",name);
		int id = getId(name);
		sort(selectCourse[id].begin(),selectCourse[id].end());//从小到大排序，为了得到升序 
		printf("%s %d",name,selectCourse[id].size());
		for(int j = 0;j<selectCourse[id].size();j++){
			printf(" %d",selectCourse[id][j]);
		} 
		printf("\n");
	}
	return 0;
} 

/**
11 5
4 7
BOB5 DON2 FRA8 JAY9 KAT3 LOR6 ZOE1
1 4
ANN0 BOB5 JAY9 LOR6
2 7
ANN0 BOB5 FRA8 JAY9 JOE4 KAT3 LOR6
3 1
BOB5
5 9
AMY7 ANN0 BOB5 DON2 FRA8 JAY9 KAT3 LOR6 ZOE1
ZOE1 ANN0 BOB5 JOE4 JAY9 FRA8 DON2 AMY7 KAT3 LOR6 NON9
*/
