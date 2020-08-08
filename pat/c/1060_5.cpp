#include <cstdio>
#include <string.h>
#define maxn 100

int digit;//��Чλ 
int array1[maxn],array2[maxn];
int count1 = 0,count2 = 0;
int len1 = 0, len2 = 0; 

void process(char str[],int array[],int &len1,int &count1,int index);//���ַ������д���
void printOutcome(int array1[],int array2[]);//���ַ���������� 

int main(){
	char str1[maxn],str2[maxn];	
	int i= 0,j = 0;
	int index = 0;//������±����� 
	
	scanf("%d %s %s",&digit,&str1,&str2);
	
	process(str1,array1,len1,count1,index); 
	process(str2,array2,len2,count2,index);
	printOutcome(array1,array2);
	return 0 ; 
}

void process(char str[],int array[],int &len,int &count,int index){
	int temp,i;
	//��str1���� 
	//1.ɾ��ǰ��0 
	while(strlen(str)>0 && str[index] == '0' ){
		index++; 
	}//index1��ʱ��Ϊ��һ����Ϊ0���ַ����ڵ��±� 
	//2.��ָ�� ������ 
	if(str[index] == '.'){//���Ϊ000.00123
		index ++;//������С���� 
		temp = index;//С�����������±� 
		while( str[index]!='\0' && str[index] == '0'){//�����ָ�� 
			count--;//��Ϊ�� 
			index ++; 
		} 
		if(str[index]!='\0'){
			while(str[index]!='\0'){
				array[len++] = str[index] - '0';//��ֵ��array1������ 
				index++;
			}	
		}
		else{
			count = 0;//����Ϊ0 
			for(i = 0;i < digit ;i++){
				array[i] = 0;
			}
		}	
	}
	else if(str[index] == '\0'){//�����Ϊ0�������ѵ�ĩβ 
		for(i = 0;i < digit ;i++){
			array[i] = 0;
		}
	}
	else{//���Ϊ000012.123 
		temp = index ;	
		while(str[index]!='.' && str[index]!='\0'){ 
			index++;
			count++;//��Ϊ�� 			
		}
		index =  temp;
		while(str[index]!='\0'){
			if(str[index]!='.'){
				array[len++] = str[index] - '0';	
			}
			index++;
		}
	}
} 

void printOutcome(int array1[],int array2[]){
	int i,j;
	//�Ա����
	for(i = 0;i < digit;i++){
		if(array1[i]!=array2[i]){
			printf("NO 0.");							
			for( j = 0;j <digit ; j++){//���numOne 
				printf("%d",array1[j]);
			}
			printf("*10^%d ",count1);
								
			printf("0.");//���numTwo 
			for(j = 0;j <  digit;j++){
				printf("%d",array2[j]);
			}	
			printf("*10^%d",count2);
			break;	
		}
	} 
	if(i == digit  ){
		printf("YES 0.");
		for(j = 0;j < digit ;j++){
			printf("%d",array1[j]);
		}		
		printf("*10^%d",count1); 	
	}	
}	
	
/*
3 0012.123 12.234
2 1.111 1.112
4 1.111 1.112
3 12300 12358.9
3 120 128
1 0.11 0.12
2 0.11 0.12
2 1.12 1.21
4 0 0000.00
4 000.00 00

ע
2.����ֱ�ӶԸ�����ȡ��������������4��������� 
3.û��ȫ�濼�ǲ������� 
4.ɾ��ǰ��0  
*/ 
