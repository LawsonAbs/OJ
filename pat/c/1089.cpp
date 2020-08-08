#include <stdio.h>

bool compare(int a[],int b[],int n){
	int i = 0;
	for(i = 0;i<n;i++){
		if(a[i]!=b[i]){
			return true;
		}
	}
	return false;
}


int main(){
	int n ;
	scanf("%d",&n);//n<100
	int i = 0;
	int array[102];//用来存储
	int result[102];
	
	for(i = 0;i < n;i++){
		scanf("%d",&array[i]);	
	}
	
	//先使用归并排序	
	for(){
		
	} 
}
/**
10
3 1 2 8 7 5 9 4 6 0
1 2 3 7 8 5 9 4 6 0

*/
