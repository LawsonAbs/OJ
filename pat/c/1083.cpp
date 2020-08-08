#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#define maxn 10005
using namespace std;

struct student{
	string name;
	string id;
	int grade;
};

student stu[maxn];
student fin[maxn];

int cmp(student s1,student s2){
	return s1.grade > s2.grade;
}

int main(){
	int N;
	cin >>N;
	int i,j,index = 0;
	int minGrade,maxGrade;
	for(i = 0;i < N;i++){
		cin>> stu[i].name >> stu[i].id >> stu[i].grade;		
	}
	cin >> minGrade >> maxGrade;
	
	
	for(i = 0;i < N;i++){
		if(stu[i].grade >= minGrade && stu[i].grade <=maxGrade)
		{
			fin[index].id = stu[i].id;
			fin[index].name = stu[i].name;
			fin[index].grade = stu[i].grade;
			index ++;
		}
	}
	
	if(index == 0) {
		cout <<"NONE"<<"\n";			
	}
	else{
		sort(fin,fin+index,cmp);
		for(i = 0;i < index;i++){
			cout << fin[i].name <<" "<< fin[i].id <<"\n";
		}
	}
}
/*
4
Tom CS000001 59
Joe Math990112 89
Mike CS991301 100
Mary EE990830 95
60 100

4
Tom CS000001 59
Joe Math990112 89
Mike CS991301 100
Mary EE990830 95
100 100
*/
