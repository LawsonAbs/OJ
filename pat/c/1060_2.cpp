#include <cstdio>
#define maxn 100

int main(){
	int digit;
	char str1[maxn];
	char str2[maxn];
	scanf("%d",&digit);	
	scanf("%s %s",&str1,&str2);
	int array1[maxn],array2[maxn];
	int count1 = 0,count2 = 0;
	int i= 0,j = 0;
	
//	printf("%s %s\n",str1,str2);
	
	//��ָ�� 
	while(str1[i]!='.' && str1[i]!='\0'){//ת���ַ�str1 
		i++;
		count1++;//��Ϊ�� 
	}
	while(str2[j]!='.'&& str2[j]!='\0'){//ת���ַ�str2 
		j++;
		count2 ++; 
	}
	//printf("count1 = %d count2 = %d\n",count1 ,count2);
	
	//ת�������� 
	i = 0;j = 0;//����Ϊ0 
	int len1 = 0,len2 = 0;//���鳤�� 
	while(str1[i]!='\0'){//ת���ַ�str1 
		if(str1[i]!='.'){
			array1[len1++] = str1[i] - '0';
	//		printf("haha%d ",str1[i] - '0');
		}
		i++;
	}
	while(str2[j]!='\0'){//ת���ַ�str2 
		if(str2[j]!='.'){
			array2[len2++] = str2[j] - '0';
	//		printf("hehe%d",array2[j]);	
		}
		j++;
	}
	if(count1 == count2){
		for( i = 0;i < digit ;i++){
			if(array1[i]!=array2[i])	
			{
	//			printf("������ʱi = %d\n",i);
				printf("NO 0.");
				//���numOne 
				for( j = 0;j <digit ; j++){
					printf("%d",array1[j]);
				}	
				printf("*10^%d ",count1);
				
				//���numTwo 
				printf("0.");
				for(j = 0;j <  digit;j++){
					printf("%d",array2[j]);
				}	
				printf("*10^%d",count2); 
				break;
			}
		} 
	} 
	if(i == digit ){
		printf("YES 0.");
		for(j = 0;j < digit ;j++){
			printf("%d",array1[j]);
		}		
		printf("*10^%d",count1); 	
	}	
} 
/*
2 1.111 1.112
3 12300 12358.9
3 120 128
1 0.11 0.12 
*/ 
