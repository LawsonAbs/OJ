#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

#define maxn 100010


char signNum;//���ķ��� 
char signExp;//ָ���ķ��� 
int array[maxn];//�洢���� 
int count = 0;//��Ч����λ�� 
int exponent = 0;//ָ�� 

//��notation���д��� 
void deal(string str){
	int i = 1;
	signNum = str[0];
	
	while(str[i]!='E'){ 
		if(str[i]!='.'){
			array[count++] = str[i] - '0';//������  ����array�� 
		}
		i++;
	} 
	i++;//ָ���ķ���
	signExp = str[i] ; //��ָ���ķ���
	
	
	i++;//��ʼ��ָ�� 
	int temp = 0;
	while(i<str.length()){
		temp = str[i] -'0';
		exponent = exponent  * 10 + temp;
		i++; 
	}
	//printf("exponent = %d\n",exponent);
}

int main(){
	string notation;//science notation
	cin>>notation;
	deal(notation);	
	int i;
	
	if(signNum == '-')	printf("-");
	if(signExp == '-'){//˵����С�� 
		exponent--;
		printf("0.");
		while(exponent--){
			printf("0"); 
		}  		
		for(i = 0;i<count;i++){
			printf("%d",array[i]);
		}		
	}
	else{
		if(exponent >= count-1){//������ 
			for(i = 0;i<count;i++){
				printf("%d",array[i]);
			}
			exponent -= (count-1);
			while(exponent--){
				printf("0");//�����׺0 
			}
		}
		else if(exponent < count -1){//����+С���� 			
			for(i = 0;i<count;i++){
				if(exponent!=0)	printf("%d",array[i]);
				else printf("%d.",array[i]);
				exponent--;//�Լ� 
			}
		}
	} 
	
	
} 
/**
+1.23400E-03
-1.2E+10
+1.234E+02 
*/ 
