#include <stdio.h>
#include <math.h>

#define size 10000

int main(){
	int number;
	scanf("%d",&number);
	
	int i ;
	int array[size]={0},tempPro;//����array[]�����洢���ȣ�temp�����洢��ǰ���Գ���number����i
	int tempNum ;

	
	int primeFlag = 1; 
	for(i = 2;i <= sqrt(number);i++){				
		tempNum = number;//�ݴ�number��ֵ 				
		if(tempNum % i == 0 ){//���˵�ܹ�����
			primeFlag = 0;	//������־ 
			array[i] ++;//����������ֵ��1 
			tempPro = i;
			tempNum /= i;//���� 
			int j = i+1; 
			while(tempNum != 0){//ֱ������ 				
				if(tempNum % j == 0){//����ܹ���j���� 
					if(j == 1 + tempPro){//������� 
						array[i]++; //���ȼ�1 
						tempPro = j;//����tempProֵ 
						tempNum /= j;  
					}			
					else
						break;
				}
				else
					break;//����ѭ�� 
				j++;//j�����1 
			}
		}
	}
	
	if(primeFlag){
		printf("1\n%d",number);
		return 0;
	}
	
	int max = 0,k;//k��������¼iֵ 
	for(i = 2;i < sqrt(number) ;i++){
	//	printf("%d ",array[i]);
		if(array[i] > max){
			max = array[i];
			k = i; 
		}
	} 
	printf("%d\n",array[k]);
	int m = k;
	while(array[k]-- > 0){
		printf("%d",m);
		if(array[k]!=0){
			printf("*");
		}
		m++;
	}printf("\n");
}
/*
630
*/
