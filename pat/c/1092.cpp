#include <stdio.h>
#include <string.h> 

/*
1.int array[128] ={0} ;//��������Լ�ʹ�õ����������ֵ������29�У�����ô���������и�ֵ 
*/ 
 
#define N 1001
char str1[N],str2[N];

int main(){
	gets(str1);	
	gets(str2);	
	
	int len1 = strlen(str1) ,len2 = strlen(str2) ,i ;
	int array1[128] ={0} , array2[128] ={0} ;
	
	//�洢�ַ���1 //�洢�ַ���2 	
	for (i = 0;i < len1 || i<len2 ;i++){		
		if(i<len1){
			array1[str1[i]] ++;	
		} 
		if(i<len2){
			array2[str2[i]] ++;	
		}
	}
	
	
	int count = 0 , flag = 1;
	i= 0; //�����˳�ʼ�������� 
	while(i< 123){
		if(array2[i] <= array1[i]){//�������� 			
			count  += array1[i] - array2[i]; 
		}
		else{
			flag = 0;//��־No 
			count = 0;
			break;//������ѭ�� 
		} 
		i++; 
	} 
	
	if(!flag ){
		printf("No ");		
		while(i< 123){
			if(array2[i] > array1[i]){//�������� 				
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
