#include <stdio.h>
#include <algorithm>
using namespace std;


int main(){
	int number ;
	scanf("%d",&number);
	int i ;
	int array[4];//�����洢��λ��
	 
	do{		
		array[0] = number%10;//�����λ
		array[1] = (number/10) % 10;//���ʮλ
		array[2] = (number/100) % 10;//�����λ
		array[3] = number /1000;//ǧλ
		
		if(array[0] == array[1] && array[1] == array[2] && array[2] == array[3]){
			printf("%d - %d = 0000\n",number,number);
			return 0;
		}
		
		//�������� 
		sort(array,array+4);
		int a  = array[3] * 1000 +array[2] * 100 + array[1] * 10 +array[0];
		int b =  array[0] * 1000 +array[1] * 100 + array[2] * 10 +array[3];
		printf("%04d - %04d = %04d\n",a,b,a-b);
		number = a - b;
	}while(number!=6174);	 
} 
/**
6767
6174
**/
