#include <stdio.h>
#include <string.h>
/*
1.ʹ��ȫ�ֱ��������������鷶Χ 
*/
#define size  100001
	
int main(){
	char string[size];//�洢�ַ��� 
	
	scanf("%s",string);//�����ַ���
	int length;
	length = strlen(string);//����ַ����ĳ���
	//printf("%d",length);
	 
 	int i, j ,k ;	
 	int total  = 0;//������ʾ�ж��ٸ�pat 
	int sumP = 0,sumT = 0;//��ʾ�ַ�AǰP ���T����Ŀ 
	int array[size][2] ,index = 0;
	//���� 
	for(i = 0;i<length;i++){
		if(string[i] == 'A'){
			array[index++][0]  = sumP;
		} 
		if(string[i] == 'P'){
			sumP++;//���Ϊ�ַ�P�����һ 
		}
	}
	//indexΪ�ַ�����A����Ŀ 
	int temp = index; 
	for(i = length - 1;i >= 0;i--){
		if(string[i] == 'A'){
			array[--index][1]  = sumT;
		} 
		if(string[i] == 'T'){
			sumT++;//���Ϊ�ַ�P�����һ 
		}
	}  
	
	for(i = 0;i<temp;i++){
	//	printf("%d %d\n",array[i][0] ,array[i][1]);
		total += (array[i][0] * array[i][1]);
		total %= 1000000007;
	}
	printf("%d",total);
}

/*
APPAPT

PAT

ATPAPAPAT
**/
