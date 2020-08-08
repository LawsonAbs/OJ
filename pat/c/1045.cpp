#include <stdio.h>

/*
1.题意分析：第一个出现的唯一的号码则是胜者 
*/
#define N 100010

int array[N];//用来存储选择的数据
int main(){
	int number, hashArray[10002];//输入打赌的人 , 散列表 
	scanf("%d",&number);	
	int i;
	int max = 0;//表示输入中的最大值 
	for(i = 0;i<number;i++){
		scanf("%d",&array[i]);
		if(array[i] > max){
			max = array[i];//赋值 
		} 
		hashArray[array[i]]++; //将其增加 
	} 

	for( i = 0;i< number ;i++){
		if(hashArray[array[i]]!=0 && hashArray[array[i]]==1){
			printf("%d",array[i]);
			break;
		}
	}
	if(i == number){
		printf("None\n");
	}
} 

/**
7 5 31 5 88 67 88 17
5 888 666 666 888 888
*/
