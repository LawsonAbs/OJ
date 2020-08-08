#include <stdio.h>
#include <algorithm> 
using namespace std;

bool cmp(int a ,int b){
	return a>b	;
}

int main(){
	int array[10]={9,3,12,1,4,5,2,3,5,3};
	sort(array,array+10); 
	int i  = 0;
	int a[10];
	for(i = 0;i<10;i++){
		a[i] = i;
	}
	
	int rank[1000];
	
	for(int i= 0;i<10;i++){
		if(array[i-1] == array[i] && i!=0){
			rank[i] = rank[i-1];//记录排名 	
		} 
		else
			rank[i] = i;		
		printf("%d ",array[i]);		
	} printf("\n");
	
	printf("排名是：\n");
	for(int i = 0;i<10;i++ ){
		printf("%d ",rank[i]);
	} 
}
