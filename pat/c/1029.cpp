#include <stdio.h>

/*
1.ʹ��ȫ�ֱ��������������鷶Χ 
*/
#define  max  1000001
#define size  2000002
	
long long array1[max],array2[max], array3[size]; //��������������

int main(){

 int n1,n2, i ;	
	//��������array1[] 
	scanf("%d",&n1);	
	for(i = 0;i<n1;i++){
		scanf("%ld",&array1[i]);
	} 
	
	//��������array2[]��ֵ 
	scanf("%d",&n2);
	for(i = 0;i < n2;i++){
		scanf("%ld",&array2[i]);
	} 	 
	
	int j =0 ;
	long long index = 0;//indexΪarray3[]���±� 
	//��ʼѭ���Ƚ�ֵ 
	i = 0;
	while(i<n1 && j < n2){
		if(array1[i] < array2[j]){
			array3[index++] = array1[i++]; 
		} 
		else{
			array3[index++] = array2[j++];
		}				
	}
	while(i < n1){
		array3[index++] = array1[i++];		
	}
	while(j < n2){
		array3[index++] = array2[j++];		
	}
	
	printf("index = %d\n",index);
	for(i = 0;i < index;i++){
		printf("%d ",array3[i]);
	}printf("\n");
	
	printf("%ld\n",array3[(index-1)/2]);
}

/*
4 11 12 13 14
5 9 10 15 16 17

2
11 12
2
13 14
**/
