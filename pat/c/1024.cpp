#include <stdio.h>
#include <string.h>
 
#define size 10000
/*
1.֮���Ի�Խ�磬����Ϊ�����ǳ�ָ�������ӵģ�2-->4-->8-->16 
*/ 

char string[size];//ʹ��20λ�ַ���
int array[size];//�������� 
int length = 0;//Ϊ��ǰ���ֵĳ��� 
 
//ִ�мӷ����� 
void operate(){
	int flag = 0; //��λ��־	 
	int i,j ;//��ʱ���� 
	int tempArray[size];//�ݴ� 
	for(i = 0;i < length ;i++){
		tempArray[i] = array[i];
	}
	
	for(i = 0 ,j = length -1;i < length,j>=0 ; i++,j--){		
		array[i] += tempArray[j] ;
		array[i] += flag;//�ӽ�λ 
		flag = array[i] /10;//������λ 
		if(array[i] >= 10){			
			array[i] %= 10;//���� 
		}
	}
	if(flag>0)
	{
		array[length++] = flag;
	}
}

//�ж�һ�����Ƿ��ǻ����� 
bool isPalindromicNumber() {
	int i = 0 ;//ע�������i��Ҫ��ʼ���������õ��δ�����Ҫ������ 
	if(length == 1 ){//ֻ��һλ�� 
		return true;
	}
		
	int index ;//�Ӻ���ǰ���� 
	for(int j = 0,index = length-1;j < length/2 ;j++,index--){
		if(array[j] != array[index]){
			return false;
		} 
	} 
	return true;
}

int main(){
	scanf("%s",&string);//�������� 	 		
	int k ;//�����Ĳ��� 
	scanf("%d",&k);
		
	int i , step = 0; //����
	length = strlen(string);
	
	int index = 0;//����ʹ��index��Ϊ�±꡾��Ҫ�������� 
	for(i = length - 1 ;i >= 0 ;i--){
		array[index++] = string[i]-'0';//����λ�洢��int��array[]�� 
	}

	//����ǻ����� 
	if(isPalindromicNumber()){
		for(int m  = 0;m<index;m++){
			printf("%d",array[m]);//ֱ��������� 			
		}printf("\n0");		
	}
	else{//�������		 
		do{ 			
			operate();//����	
			step ++; 
		}while(!isPalindromicNumber() && (--k)>0);
		
		for(i = length - 1;i >= 0 ;i--){
			printf("%d",array[i]);
		}printf("\n");
		printf("%d\n",step);	
	}
}

/*
121 2
10000001 1
67 2
69 3
10000000000 100
90000000008 100
3 3
0 1
**/
