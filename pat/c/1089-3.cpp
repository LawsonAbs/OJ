#include <stdio.h>
#include <algorithm>
using namespace std; 

const int size = 100;

//定义两个局部变量，方便访问 
int n , result[size];
int flag = 1;//是否再进行排序的控制变量 


//比较两个数组是否相同 
bool isSame(int a[],int b[],int n){
	int i ;
	for(i = 1;i <= n;i++){
		if(a[i]!=b[i])
			return false;
	} 
	return true;
}

//使用归并排序时将两个数组合并 
void merge(int A[],int L1,int R1,int L2,int R2){
	int i = L1,j = L2;
	//i指向A[L1],j指向A[L2]
	//同时也为了保持L1,L2值不变 --->非常重要 
	
	int temp[size],index = 0;	//temp临时存放合并后的数组，index为其下标
	
	while(i<=R1 && j<=R2){//使用two pointer的方法来将二者归并 
		if(A[i] <= A[j]){
			temp[index++] = A[i++];
		}
		else
		{
			temp[index++] = A[j++];
		}		
	} 
	//补齐数 
	while(i<=R1){
		temp[index++] = A[i++];
	} 
	while(j<=R2){
		temp[index++] = A[j++];
	} 
	
	//这一点为two pointer方法来实现两个数组的合并的核心！！ --->局部更新的方法 
	for(i = 0;i<index;i++){
		A[L1 + i] = temp[i];//将合并后的序列赋值回数组A   L1保证了数组原来的顺序 
	}
	
	//判断两个数组是否相等	
	if(isSame(A,result,n) == true){
		printf("Merge Sort\n");				
	}
	
	for(i = 1;i <= n;i++){
		printf("%d ",A[i]);
	}
	printf("\n");
}

//使用非递归算法将array[]数组当前区间[left,right]进行排序 
void mergeSort(int A[]){
	for(int step = 2;step/2  <= n;step *=2 ){
		for(int i = 1 ;i <= n ; i += step){
			int mid = i + step / 2 -1;
			if(mid + 1 <= n){			
				merge(A, i, mid, mid+1, min(i+step -1 ,n));				 				
			}
		}
	}
} 


int main(){
	int array[size];	
	scanf("%d",&n);
	int i ;
	 
	for(i = 1;i <= n;i++){//注意程序中所有数组下标均是从i = 1开始 
		scanf("%d",&array[i]);
	}
	for(i = 1;i <= n;i++){
		scanf("%d",&result[i]);
	}
	printf("--------\n");
	mergeSort(array);
}

/**
10
3 1 2 8 7 5 9 4 6 0
1 2 3 7 8 5 9 4 6 0

10
3 1 2 8 7 5 9 4 0 6
1 3 2 8 5 7 4 9 0 6
*/
