#include <stdio.h>

typedef struct {
	char id[20];
	char gender;//表示性别
	char name[20]; 	
	int grade;//表示学生成绩	 
}Student;

int main(){
	int number;
	scanf("%d",&number);
	Student stu,maxF,minM;//每次输入值，女性最小值，男性最大值
	
	int i  = 0;
	maxF.grade = -1,minM.grade = 101;//保证极端情况也成立 
	for(i = 0;i<number;i++){
		scanf("%s %c %s %d",stu.name,&stu.gender,stu.id,&stu.grade);
		if(stu.gender =='M' && minM.grade > stu.grade){
			minM = stu;			
			
		}
		else if(stu.gender =='F' && maxF.grade < stu.grade){
			maxF = stu;
			
		}
	} 
	
	int flag = 0;

	if(maxF.grade == -1){
		printf("Absent\n"); 
		flag = 1;
	}
	else{
		printf("%s %s\n",maxF.name,maxF.id);
	}

	if(minM.grade == 101){
		printf("Absent\n");
		flag = 1;
	}
	else{
		printf("%s %s\n",minM.name,minM.id);
	}
	

	
	if(flag){
		printf("NA\n");
	}
	else{
		printf("%d\n",maxF.grade - minM.grade);		
	}
	
}

/**
3
Joe M Math990112 89
Mike M CS991301 100
Mary F EE990830 95

1
Jean M AA980920 60
**/
