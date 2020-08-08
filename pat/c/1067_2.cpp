#include <cstdio>
#define maxn 100010


int n;
int disorder = 0;//无序的数据数目
int array[maxn];
int indexZero;//0的下标 
int count = 0;//交换次数

//交换程序 
void swap(int array[]){
	int tempIndex = 0;//暂存下标 
	int i;
	int firstIndex;//第一个不相等的数的下标
	int startSearch = 0;//起始寻找位 
	
	while(disorder){//当没有无序数时 
		for(i = startSearch;i< n;i ++){			
			if(array[i] == indexZero){
				tempIndex = i;//记录数字indexZero所在的下标 
				startSearch = i+1;//记为i+1; 
				break;
			}
		}
		 
		if(i<n && indexZero!=0){//交换indexZero 与 tempIndex上的两个数 			 				
			array[indexZero] = array[tempIndex];
			array[tempIndex] = 0; 
			indexZero = tempIndex;//更新0的下标 					
			count++; 
		} 
		else {//0就在0号位 
			for( i = startSearch;i< n;i ++){
				if(array[i] != i){
					tempIndex = i;//记录数字indexZero所在的下标 
					break;
				}
			}
			array[indexZero] = array[tempIndex];
			array[tempIndex] = 0; 
			indexZero = tempIndex; 
			disorder += 2;
			count++; 
		} 
		
		if(disorder == 2){
			disorder = 0;//最后会使两个无序一起变为有序 
		}
		else if(tempIndex == 0)	disorder -= 2; 
		else disorder--;
	}
	printf("%d",count);
}


int main(){
	int i ;
	scanf("%d",&n);
	for(i = 0;i < n;i++){
		scanf("%d",&array[i]);	
		if(array[i]!=i)	disorder++; 
		if(array[i] == 0)	indexZero = i;
	} 
	swap(array);	
}
/**
10 3 5 7 2 6 4 9 0 8 1
*/
