#include <stdio.h>
#include <math.h>

#define size 102
long array[2][2];//�ֱ�洢���ӣ���ĸ
//ʹ��շת������õ����Լ�� 
int  getBigNumber(int a ,int b){
	int remain = a;
	while(remain != 0){//�������������0 		
		remain = a % b;
		a = b ;
		b = remain;		
	}
	return a; //�������Լ��
} 

void first(){
	//�����һ�����ļ�д��ʽ 
	int flag1 = 0;
	if(abs(array[0][0] ) > abs(array[0][1]) ){
		printf("%d",array[0][0] / array[0][1]);//�����������
		array[0][0] %= array[0][1];
		flag1 = 1;
	}
	if(array[0][0]!=0){
		int a = getBigNumber(array[0][0],array[0][1]);		
//		printf("a = %d\n",a);	
		array[0][0] /= a;
		array[0][1] /= a;		
	}	
	if(array[0][0] != 0){
		if(flag1){
			printf(" %d/%d ",array[0][0],array[0][1]);		
		}
		else{
			printf("%d/%d ",array[0][0],array[0][1]);	
		}
	} 	
} 

void second(){
	//����ڶ������ļ�д��ʽ 
	int flag2 = 0;
	if(abs(array[1][0] ) > abs(array[1][1]) ){
		printf("%d",array[1][0] / array[1][1]);//�����������
		array[1][0] %= array[1][1];
		flag2 = 1;
	}	
	if(array[1][0]!=0){
		int b = getBigNumber(array[1][0],array[1][1]);	
//		printf("b = %d\n",b);	
		array[1][0] /= b;
		array[1][1] /= b;		
	}
	
	if(array[1][0] != 0){
		if(flag2)
			printf(" %d/%d",array[1][0],array[1][1]);	
		else
			printf("%d/%d",array[1][0],array[1][1]);	
	} 
}





int main(){
	int number;			
	scanf("%d/%d %d/%d",&array[0][0],&array[0][1],&array[1][0],&array[1][1]);//������ӷ�ĸ 	
		
	int sumA = 0, sumB = 1; //��
	int difA = 0, difB = 1;	//�� 
	int proA = 1, proB = 1; //��
	int quoA = 0, quoB = 1; //�� 	
	
	//��� �� ��� 
	if(array[0][1] != array[1][1]){
		if(array[0][1] % array[1][1] == 0){ 
			sumA = array[1][0] * (array[0][1] / array[1][1]) + array[0][0];
			sumB = array[0][1] ;
			
			difA = array[0][0] - array[1][0] * (array[0][1] / array[1][1]) ;
			difB = array[0][1] ;
		}
		else if( array[1][1] % array[0][1] == 0 ){
			sumA = array[0][0] * (array[1][1] / array[0][1]) + array[1][0];
			sumB = array[1][1];
			
			difA = array[0][0] * (array[1][1] / array[0][1]) - array[1][0];
			difB = array[1][1];
		}
		else{
			sumA = array[0][0] * array[1][1] + array[1][0] * array[0][1];
			sumB =  array[0][1] * array[1][1];
			
			difA = array[0][0] * array[1][1] - array[1][0] * array[0][1];
			difB =  array[0][1] * array[1][1];
		}
	}
	else{//���������� 
		sumA = array[0][0] + array[1][0] ;
		sumB = array[0][1];
		
		difA = array[0][0] - array[1][0] ;
		difB = array[0][1];
	}
	
	//���
	proA = array[0][0] * array[1][0] ;
	proB = array[0][1] * array[1][1];
		
	//���� 
	proA = array[0][0] * array[1][1] ;
	proB = array[0][1] * array[1][0];	
	
	
	//����Ӽ��˳� 
	first ();printf("+ ");second();printf(" = ");printf("%d/%d\n",sumA,sumB);
	first ();printf("-");second();printf(" = ");printf("%d/%d\n",difA,difB);
	first ();printf("*");second();printf(" = ");printf("%d/%d\n",proA,proB);
	first ();printf("/");second();printf(" = ");printf("%d/%d\n",proA,proB);
	
}

/*
2/3 -4/2

1/2  2/4

5/3 0/6
**/
