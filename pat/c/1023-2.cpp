#include <stdio.h>
#include <string.h>

#define size 30//���ֹ���20λ 

int main(){
	int array1[10]={0},array2[10] = {0};//�Ƚ��������ĸ�������С 
	int array[size];
	int i,j ;
	 
	char string[size];//ʹ��20λ�ַ���
	scanf("%s",&string);//�������� 	 
	
	int length = strlen(string);
		
	//12312378  ----> 87321321ʽ�洢������������ 
	int index = 0;//����ʹ��index��Ϊ�±꡾��Ҫ�������� 
	for(i = length - 1 ;i >= 0 ;i--){
		array[index++] = string[i]-'0';//����λ�洢��int��array[]�� 
	}
	
	int flag = 0; //��λ��־	 
	for(i = 0 ;i < length ; i++){
		array1[array[i]]++;//��¼���֣����� 
		
		array[i] *= 2;
		array[i] += flag;//�ӽ�λ 
		flag = array[i] /10;//������λ 
		if(array[i] >= 10){			
			array[i] %= 10;//���� 
		}
	}
	if(flag>0)
	{
		array[length++] = flag;
		flag = 0;//���� 
	}
		
	for(i = 0;i < length;i++ ) {
		array2[array[i]] ++;//���ִ��� 	
	}
	
	//�Ƚ��������� ----> Ҫ�����Ȼ�����Ǵ�1��9,��������ΪɶҲҪ�Ƚ�0��ԭ�� 
	for(i = 0;i<=9;i++){
		if(array1[i] != array2[i]){
			break;
		}
	}
	
	
	if(i > 9){//���û�б�����--->����ȫ��� 
		printf("Yes\n");		 
	}
	else{
		printf("No\n");
	}
	for(i = length - 1;i >= 0 ;i--){
		printf("%d",array[i]);	
	} 	 	
}
/*
1234567899
5634567899
9999
9000000000000000000009
99999999
5
10122448866
325
300
*/

