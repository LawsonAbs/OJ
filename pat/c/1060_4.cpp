#include <cstdio>
#include <string.h>
#define maxn 100

int main(){
	int digit;//��Чλ 
	char str1[maxn],str2[maxn];
	int array1[maxn],array2[maxn];
	int count1 = 0,count2 = 0;
	int i= 0,j = 0;
	int index1 = 0,index2 = 0;//����������±����� 
	int len1 = 0, len2 = 0; 
	int temp;
		
	scanf("%d %s %s",&digit,&str1,&str2);
	
	//��str1���� 
	//1.ɾ��ǰ��0 
	while(strlen(str1)>0 && str1[index1] == '0' ){
		index1++; 
	}//index1��ʱ��Ϊ��һ����Ϊ0���ַ����ڵ��±� 
	//2.��ָ�� ������ 
	if(str1[index1] == '.'){//���Ϊ000.00123
		index1 ++;//������С���� 
		temp = index1;//С�����������±� 
		while( str1[index1]!='\0' && str1[index1] == '0'){//�����ָ�� 
			count1--;//��Ϊ�� 
			index1 ++; 
		} 
		if(str1[index1]!='\0'){
			while(str1[index1]!='\0'){
				array1[len1++] = str1[index1] - '0';//��ֵ��array1������ 
				index1++;
			}	
		}
		else{
			count1 = 0;//����Ϊ0 
			for(i = 0;i < digit ;i++){
				array1[i] = 0;
			}
		}	
	}
	else if(str1[index1] == '\0'){//�����Ϊ0�������ѵ�ĩβ 
		for(i = 0;i < digit ;i++){
			array1[i] = 0;
		}
	}
	else{//���Ϊ000012.123 
		temp = index1 ;	
		while(str1[index1]!='.' && str1[index1]!='\0'){ 
			index1++;
			count1++;//��Ϊ�� 			
		}
		index1 =  temp;
		while(str1[index1]!='\0'){
			if(str1[index1]!='.'){
				array1[len1++] = str1[index1] - '0';	
			}
			index1++;
		}
	}
	
	//��str2���� 
	//1.ɾ��ǰ��0 
	while(strlen(str2)>0 && str2[index2] == '0' ){
		index2++; 
	}
	//2.��ָ�� ������ 
	if(str2[index2]=='.'){//���Ϊ000.00123
		index2 ++;//������С���� 
		temp = index2;//С�����������±� 
		while( str2[index2]!='\0' && str2[index2] == '0'){//�����ָ�� 
			count2--;//��Ϊ�� 
			index2 ++; 
		} 
		if(str2[index2]!='\0'){
			while(str2[index2]!='\0'){
				array2[len2++] = str2[index2] - '0';//��ֵ��array1������ 
				index2++;
			}		
		} 		
		else{
			count2 = 0;//����Ϊ0 
			for(i = 0;i < digit ;i++){
				array2[i] = 0;
			}
		}	
	}
	else if(str2[index2] =='\0'){
		for(i = 0;i<digit;i++){
			array2[i] = 0;
		}
	}
	else{//���Ϊ000012.123 
		temp = index2 ;	
		while(str2[index2]!='.' && str2[index2]!='\0'){ 
			index2++;
			count2++;//��Ϊ�� 			
		}
		index2 =  temp;
		while(str2[index2]!='\0'){
			if(str2[index2]!='.'){
				array2[len2++] = str2[index2] - '0';	
			}
			index2++;
		}
	}
	
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
1.double�ͱ�������ʹ��lf%����f%���룬���Ǳ���ʹ��lf%��������������lf%����float�ͱ���������lf%��������Ǳ�����f%���루�����f%���� 
2.����ֱ�ӶԸ�����ȡ��������������4��������� 
3.û��ȫ�濼�ǲ������� 
4.ɾ��ǰ��0 
5.c�����У�strlen()�������ڻ�ȡ�ַ�������


*/ 
