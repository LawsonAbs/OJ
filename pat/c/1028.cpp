#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

//学生信息结构体 
typedef struct{
	int Id;//学号	
	char name[20];//姓名 
	int grade;//成绩
}Student;

Student stu[100002];
int column;

bool cmp1(Student s1,Student s2){
	return s1.Id < s2.Id;
}

bool cmp2(Student s1,Student s2){	
	int s = strcmp(s1.name,s2.name);
	if(s == 0){
		return s1.Id < s2.Id;
	}
	else
		return s < 0 ;//注意这里返回的是s，而不是s1.name < s2.name 
}

bool cmp3(Student s1,Student s2){	
	if(s1.grade == s2.grade){
		return s1.Id < s2.Id;
	}
	return s1.grade < s2.grade;	
} 



int main(){
	
	int number ,column ;//学生数
	
	scanf("%d %d",&number,&column);
	int i ;
	for (i = 0;i<number;i++){
		scanf("%d %s %d",&stu[i].Id,&stu[i].name,&stu[i].grade);
	}
	if(column == 1){
		sort(stu,stu+number,cmp1);	
	}
	else if(column == 2){
		sort(stu,stu+number,cmp2);
	}
	else {
		sort(stu,stu+number,cmp3);
	}
	
	for(int i = 0;i<number;i++){
		printf("%06d %s %d\n",stu[i].Id,stu[i].name,stu[i].grade);
	}
}
/*
3 1
000007 James 85
000010 Amy 90
000001 Zoe 60

4 2
000007 James 85
000010 Amy 90
000001 Zoe 60
000002 James 90

4 3
000007 James 85
000010 Amy 90
000001 Zoe 60
000002 James 90
*/
 
