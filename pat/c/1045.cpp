#include <stdio.h>

/*
1.�����������һ�����ֵ�Ψһ�ĺ�������ʤ�� 
*/
#define N 100010

int array[N];//�����洢ѡ�������
int main(){
	int number, hashArray[10002];//�����ĵ��� , ɢ�б� 
	scanf("%d",&number);	
	int i;
	int max = 0;//��ʾ�����е����ֵ 
	for(i = 0;i<number;i++){
		scanf("%d",&array[i]);
		if(array[i] > max){
			max = array[i];//��ֵ 
		} 
		hashArray[array[i]]++; //�������� 
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
