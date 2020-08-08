#include <stdio.h>
#include <math.h>

#define size 100000
/*
1.���ӱ��ҵ���˳�����Ǵ�С����
*/
bool isPrime(int number){
	int i;	
	for(i = 2;i <= sqrt(number);i++){				
		if(number % i == 0 ){//���˵�ܹ�����		
			return false;//����ѭ�� 				
			}
		}
	return true;
}	
	
int main(){
	int number;
	scanf("%d",&number);
	
	int i ;
	int array[size]={0};//����array[]�����洢�������ӣ���С��ʾΪָ�� 
		
	int tempNum = number;
	int compare = 0 , count = 0;
	bool primeFlag = true;//Ĭ��Ϊ���� 
	
	for(i = 2;i <= sqrt(tempNum) ;i++){
		if(number % i == 0 && isPrime(i)){//�ܹ�������������Ϊ���� 
			primeFlag = false; 
			if(compare != i){
				count++;//��ʾ�ж���������� 
				compare  = i;
			}
			array[i] ++ ;//��ʾ���� 
			number /= i;
			i--;//���ܻ��ᱻ��ǰ��������			
		}
	}
	printf("%d=",tempNum); 
	if(primeFlag){
		printf("%d",tempNum);
		return 0;
	}
		
	int j = 0;
	for(j = 2;j<sqrt(tempNum);j++){
		if(array[j]>0){
			count --;
			if(array[j]>1){
				printf("%d^%d",j,array[j]);
			}
			else
				printf("%d",j);
			if(count!=0){
				printf("*");
			}
		}
	} 
}
/*
64
97532468
*/
