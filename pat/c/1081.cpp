#include <stdio.h>

#define size 102

//ʹ��շת������õ����Լ�� 
int  getBigNumber(int a ,int b){
	if(a % b == 0){
		return b;
	}
	else if(b % a == 0){
		return a;
	}
	
	int remain = a % b;
	while(remain != 0){//�������������0 
		remain = a % b;
		a = b;
		b = remain;				 
	}
	return a; //�������Լ��
} 

int main(){
	int number;
	long array[size][2];//�ֱ�洢���ӣ���ĸ
	
	scanf("%d",&number);
	int i;
	for(i = 0;i<number;i++){
		scanf("%d/%d",&array[i][0],&array[i][1]);//������ӷ�ĸ 
	}
	
	int a = 0, b=1  ; //aΪ���ӣ�bΪ��ĸ 
	//����������� 
	for (i = 0;i<number;i++){
		if(array[i][1] != b){//������߷�ĸ��һ�� --->ͬ��ĸ 
			if(array[i][1] % b == 0){ 
				a = a * (array[i][1] / b) + array[i][0];
				b = array[i][1] ;
			}
			else if( b % array[i][1] == 0 ){
				a = a + array[i][0] * (b / array[i][1]);
			}
			else{
				a  *= array[i][1];
				array[i][0] *=b;
				a += array[i][0];
				b *= array[i][1];
			}
		}
		else{//���������� 
			a += array[i][0];//aΪ������ӣ�b���� 			
		}
		
		//���������� 
		int n = getBigNumber(a,b);
		a /= n;
		b /= n; 
	}
	
	int  flag = 0; 
	if(a == 0){
		printf("0\n");
		return 0;
	}
	if(a > b){		
		printf("%d",a/b);
		a %= b;	
		flag = 1;
	}
	if(a != 0){
		//printf("%d/%d\n",a,b);
		int n = getBigNumber(a,b);
		//printf("n = %d\n",n);
		
		//���ƿո� 
		if(flag){
			printf(" %d/%d\n",a/n,b/n);	
		}
		else{
			printf("%d/%d\n",a/n,b/n);	
		}		
	}
}

/*
5
2/5 4/15 1/30 -2/60 8/3

4
1/3 -1/3 -1/3 1/3

3
1/3 -1/6 1/8
**/
