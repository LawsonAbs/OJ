#include <stdio.h>
#include <algorithm>
using namespace std;


int main(){
	int number ;
	scanf("%d",&number);
	int i ;
	int array[4];//用来存储四位数
	 
	do{		
		array[0] = number%10;//求出个位
		array[1] = (number/10) % 10;//求出十位
		array[2] = (number/100) % 10;//求出百位
		array[3] = number /1000;//千位
		
		if(array[0] == array[1] && array[1] == array[2] && array[2] == array[3]){
			printf("%d - %d = 0000\n",number,number);
			return 0;
		}
		
		//递增排序 
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
