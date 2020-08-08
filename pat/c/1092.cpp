#include <stdio.h>
#include <string.h> 

/*
1.int array[128] ={0} ;//如果后期自己使用到数组里面的值（代码29行），那么必须对其进行赋值 
*/ 
 
#define N 1001
char str1[N],str2[N];

int main(){
	gets(str1);	
	gets(str2);	
	
	int len1 = strlen(str1) ,len2 = strlen(str2) ,i ;
	int array1[128] ={0} , array2[128] ={0} ;
	
	//存储字符串1 //存储字符串2 	
	for (i = 0;i < len1 || i<len2 ;i++){		
		if(i<len1){
			array1[str1[i]] ++;	
		} 
		if(i<len2){
			array2[str2[i]] ++;	
		}
	}
	
	
	int count = 0 , flag = 1;
	i= 0; //别忘了初始化啊！！ 
	while(i< 123){
		if(array2[i] <= array1[i]){//满足条件 			
			count  += array1[i] - array2[i]; 
		}
		else{
			flag = 0;//标志No 
			count = 0;
			break;//跳出该循环 
		} 
		i++; 
	} 
	
	if(!flag ){
		printf("No ");		
		while(i< 123){
			if(array2[i] > array1[i]){//满足条件 				
				count  += array2[i] - array1[i]; 
			}
			i++; 
		}
	}
	else{
		printf("Yes ");	
	} 	
	printf("%d",count);		
} 

/*
ppRYYGrrYBR22
ppRYYGrrYBR225


ppRYYGrrYB225
YrR8RrY

aflngelangglkwenagklaengklagngoiq3jht03ng3olqnglqkwengklawen3ghil33ganga0ganglangalegbalkegneVALGNE0GAWN3LANEGKLANEGAELGANE
ASFGALNGKLAENG3KLGNGAKLNGAKLEGNAWKLagblsnegaklengaklegnaklegnaeklgasnegklaneglkasegn
*/
