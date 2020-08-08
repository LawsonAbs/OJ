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
	
	//求指数 
	while(str1[i]!='.' && str1[i]!='\0'){//转化字符str1 
		i++;
		count1++;//作为幂 
	}
	while(str2[j]!='.'&& str2[j]!='\0'){//转化字符str2 
		j++;
		count2 ++; 
	}
	//printf("count1 = %d count2 = %d\n",count1 ,count2);
	
	//转化成数组 
	i = 0;j = 0;//重置为0 
	int len1 = 0,len2 = 0;//数组长度 
	while(str1[i]!='\0'){//转化字符str1 
		if(str1[i]!='.'){
			array1[len1++] = str1[i] - '0';
	//		printf("haha%d ",str1[i] - '0');
		}
		i++;
	}
	while(str2[j]!='\0'){//转化字符str2 
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
	//			printf("不等于时i = %d\n",i);
				printf("NO 0.");
				//输出numOne 
				for( j = 0;j <digit ; j++){
					printf("%d",array1[j]);
				}	
				printf("*10^%d ",count1);
				
				//输出numTwo 
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
