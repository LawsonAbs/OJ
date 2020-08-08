#include <stdio.h>
#include <algorithm>
using namespace std;

typedef struct {
	char Id[20];
	int hourIn;
	int minuteIn;
	int secondIn;
	
	int hourOut;
	int minuteOut;
	int secondOut;
}Student;



//找出第一个到的 
bool cmp1(Student a ,Student b){
	if(a.hourIn == b.hourIn ){
		if(a.minuteIn == b.minuteIn){
			return a.secondIn < b.secondIn;
		}
		else
		return a.minuteIn < b.minuteIn;
	}
	else{
		return a.hourIn < b.hourIn;
	}
}

//找出最后一个离开 
bool cmp2(Student a ,Student b){
	if(a.hourOut == b.hourOut ){
		if(a.minuteOut == b.minuteOut){
			return a.secondOut > b.secondOut;
		}
		else
		return a.minuteOut > b.minuteOut;
	}
	else{
		return a.hourOut > b.hourOut;
	}
}



int main(){
	int M;
	scanf("%d",&M);
	Student stu[100];
	for(int i = 0;i<M;i++){
		scanf("%s %d:%d:%d %d:%d:%d",stu[i].Id,&stu[i].hourIn,&stu[i].minuteIn,&stu[i].secondIn,&stu[i].hourOut,&stu[i].minuteOut,&stu[i].secondOut);				
	}
	
	sort(stu,stu+M,cmp1);
	printf("%s ",stu[0].Id);
	
	sort(stu,stu+M,cmp2);
	printf("%s",stu[0].Id);		
}

/*** 
3
CS301111 07:30:28 17:00:10
SC3021234 07:30:27 11:25:25
CS301133 21:45:00 21:58:40

1
CS301133 21:45:00 21:58:40
*/ 
