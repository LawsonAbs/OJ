#include <stdio.h>

#define size 1001
/*
1.ȥ�أ�����list��������������¥�� 
*/ 

int main(){
	int number;	
	int array[size], dealWithArray[size]={0};//һ��ʼ������ʹ��������� 
	
	scanf("%d",&number);
	int i ;
	array[0] = 0;//the start is zero floor 
	for(i = 1;i <= number;i++){
		scanf("%d",&array[i]);
			dealWithArray[i-1] = array[i] - array[i-1];//�������¥��֮��ľ��� 						
	}
	//����������һ�����ֽ����ж� 
	if( array[number] !=1){
		dealWithArray[number] = 1 - array[number];//�����һ¥�ľ���
		number++;
		//printf("���= %d, i = %d",dealWithArray[number],i);		
	}
	
	int sum = 0 ;//��ʼ��sum��ֵΪ0
	sum = number * 5;//��������¥��ͣ��ʱ�� 
	
	int count = 0;//��ʾ��������ͬ¥���� 
	for(i = 0; i<number ;i++){
		//printf("%d\n",dealWithArray[i]);
		if(dealWithArray[i] < 0){
			sum = sum + ((-1) * dealWithArray[i] * 4) ;
		}
		else if(dealWithArray[i]>0)
			sum = sum +( dealWithArray[i] * 6 );
		else
		{
			//printf("%d",i);
			count ++;//����¥������һ 
		}			
	}
	printf("%d\n",sum);
	//printf("count = %d\n",count);
	sum = sum - (count * 5); 
	printf("%d",sum);
}
/**
3 2 3 1
1 0
**/
