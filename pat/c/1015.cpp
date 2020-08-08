#include <stdio.h>
#include <math.h>

#define size 100//6λ�㹻

/*
1.���һ��������������ô������ʲô�����¶���������
*/ 

//�ڵ�ǰradix���Ʒ�ת��ת����ʮ������total 
int	reverse(int a ,int radix){//aΪ����radixΪ���� 
	int total  = 0 ,i = 0 ,j ;
	int array[size];	
	while(a!=0){//Ϊ�˵õ���λ�ϵ��� ---> ��Ҫ����10 
		array[i++] = a % radix;
		a /= radix;
	} 		
	for(j = 0;j < i;j++){
		total = total * radix + array[j];
	}	
	//printf("��ת�� = %d\n",total);
	return total;
}


//�ж�һ�����Ƿ�Ϊ���� 
bool isPrime(int total){
	if(total < 2){//�����0,1,2,��ֱ�ӷ���true 
		return false;
	}
	int i ;
	for(i = 2;i <= (int)sqrt(1.0 * total);i++){//�����жϴ�2��ʼ 
		if(total % i == 0){
			return false;//����false 
		}
	}
	return true;
} 

int main(){
	int number;
	int radix;
	while(scanf("%d %d",&number,&radix) == 2 ){
		if(number < 0){
			break;
		}
		if(number == 1 || number == 0){
			printf("No\n");
		}
		else{
			if(isPrime(number)){
				int total2 = reverse(number,radix);					
				if(isPrime(total2)){
					printf("Yes\n");
				}
				else
					printf("No\n"); 
			}
			else
				printf("No\n");			
		}		
	}		
} 
/**
73 10
23 2
23 10
0 2
-2 3
1 2
*/
