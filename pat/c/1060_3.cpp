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
	
	//��ָ�� 
	while(str1[i]!='.' && str1[i]!='\0'){//ת���ַ�str1 
		i++;
		count1++;//��Ϊ�� 
	}
	while(str2[j]!='.'&& str2[j]!='\0'){//ת���ַ�str2 
		j++;
		count2 ++; 
	}
//	printf("count1 = %d count2 = %d\n",count1 ,count2);
	
	//ת�������� 
	i = 0;j = 0;//����Ϊ0 
	int len1 = 0,len2 = 0;//���鳤�� 
	while(str1[i]!='\0'){//ת���ַ�str1 
		if(str1[i]!='.'){
			array1[len1++] = str1[i] - '0';
		}
		i++;
	}
	while(str2[j]!='\0'){//ת���ַ�str2 
		if(str2[j]!='.'){
			array2[len2++] = str2[j] - '0';
		}
		j++;
	}
	
	if(str1[0]-'0' != 0 && str2[0]-'0' != 0) {	
		if(count1 == count2 ){ 
			for( i = 0;i < digit ;i++){
				if(array1[i]!=array2[i])	
				{
					printf("NO 0.");
				
					//���numOne 
					for( j = 0;j <digit ; j++){
						printf("%d",array1[j]);
					}
					if(str1[0] -'0' == 0){
						printf("*10^0");
					}	
					else	printf("*10^%d ",count1);
					
					//���numTwo 
					printf("0.");
					for(j = 0;j <  digit;j++){
						printf("%d",array2[j]);
					}	
					if(str2[0] -'0' == 0){
						printf("*10^0");
					}	
					else	printf("*10^%d ",count2);
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
	else if(str1[0]-'0' == 0 && str2[0]-'0' == 0){
		for( i = 1;i < digit +1 ;i++){
				if(array1[i]!=array2[i])	
				{
					printf("NO 0.");
				
					//���numOne 
					for( j = 1;j <digit+1 ; j++){
						printf("%d",array1[j]);
					}
					printf("*10^0 ");
									
					//���numTwo 
					printf("0.");
					for(j = 1;j < digit + 1 ;j++){
						printf("%d",array2[j]);
					}	
					printf("*10^0");				
					break;
				}
			}  
		if(i == digit + 1 ){
			printf("YES 0.");
			for(j = 1;j < digit + 1;j++){
				printf("%d",array1[j]);
			}		
			printf("*10^0"); 	
		}	
	}
} 
/*
2 1.111 1.112
3 12300 12358.9
3 120 128
1 0.11 0.12
2 0.11 0.12
2 1.12 1.21
4 0 0000.00
*/ 
