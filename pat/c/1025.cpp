#include <stdio.h> 
#include <string.h>
#include <algorithm>
using namespace std;

/*
1.本题难点在于怎么知道有多少个考场，然后分别对其考场中的人进行排名 
*/ 

typedef struct{
	char name[20];
	int grade;//表示分数 
	int flag ; //标志考场号 
	int localrank;//考场排名 
	int finalRank;//最终排名 
}Student;

Student stu[30010];

//先按考场分类-->再按照排名分类 
bool cmp(Student s1,Student s2){
	if(s1.flag!=s2.flag)
		return s1.flag<s2.flag; 
	else if(s1.grade == s2.grade){
		int s = strcmp(s1.name,s2.name);		
		return s<0;
	}
	else
	return s1.grade > s2.grade;	
}

bool cmp2(Student s1,Student s2){
	if(s1.grade == s2.grade){
		int s = strcmp(s1.name,s2.name);
		
		return s<0;
	}
	else
	return s1.grade > s2.grade;
}

int main(){
	int number , j = 0 , i= 0 , k;
	scanf("%d",&number);
	
	int record[30001] ;
	while(j < number){		
		scanf("%d",&k);
		record[j] = k;//表示某一考场有多少人
		
		while(k--){
			scanf("%s %d",stu[i].name,&stu[i].grade);//输入考生信息
			stu[i++].flag = j+1;//确认考场号			
		}
		j++; 
	}		
	sort(stu,stu+i,cmp);	
	
	
	int sum = 0;
	for(int m = 0;m < j;m++){
		int a = 0;
		for(int l = sum;l < sum + record[m];l++){
			if(stu[l].grade == stu[l-1].grade && l != sum){
				stu[l].localrank = stu[l-1].localrank;
			}
			else
				stu[l].localrank = a+1;
			//printf("%d ",stu[l].localrank);
			a++;
		}
		sum += record[m] ;//对sum的值进行累加 		
	}
	
	printf("%d\n",i);
	sort(stu,stu+i,cmp2);
	for(int m = 0;m<i;m++){
		if(stu[m].grade == stu[m-1].grade && m!=0){
			stu[m].finalRank  = stu[m-1].finalRank;
		}
		else
			stu[m].finalRank = m+1;
		printf("%s %d %d %d\n",stu[m].name,stu[m].finalRank,stu[m].flag,stu[m].localrank);
	}
}

/**
2
5
1234567890001 95
1234567890005 100
1234567890003 95
1234567890002 77
1234567890004 85
4
1234567890013 65
1234567890011 25
1234567890014 100
1234567890012 85
**/
