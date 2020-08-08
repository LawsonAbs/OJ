#include <stdio.h>

const int size = 100;
int result[size] ,n;


//比较两个数组是否相同 
bool isSame(int a[],int b[],int n){
	int i ;
	for(i = 0;i<n;i++){
		if(a[i]!=b[i])
			return false;
	} 
	return true;
}

void merge(int A[],int L1,int R1,int L2,int R2){
	int i = L1,j = L2;//i指向A[L1],j指向A[L2]
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
	for(i = 0;i<index;i++){
		A[L1 + i] = temp[i];//将合并后的序列赋值回数组A   L1保证了数组原来的顺序 
	}
	for(i = 0;i<n;i++){
		printf("%d ",A[i]);
	}
}

//使用递归算法将array[]数组当前区间[left,right]进行排序 
void mergeSort(int A[],int left,int right){
	if(left < right){
		int mid = (left + right) / 2;
		mergeSort(A,left,mid);
		mergeSort(A,mid+1,right);
		merge(A,left,mid,mid+1,right);
		if(isSame(A,result,n)){//如果相等
			printf("Merge Sort\n"); 
		}
		else{
			printf("Insertion Sort\n");
		}
	}
} 


int main(){
	int array[size];
	
	scanf("%d",&n);
	int i = 0;
	for(i = 0;i<n;i++){
		scanf("%d",&array[i]);
	}
	for(i = 0;i<n;i++){
		scanf("%d",&result[i]);
	}
	printf("--------\n");
	mergeSort(array,0,n-1);//调用这个函数 
	for(int i = 0;i < n;i++){
		printf("%d ",array[i]);
	}
}

/**
10
3 1 2 8 7 5 9 4 6 0
1 2 3 7 8 5 9 4 6 0

10
3 1 2 8 7 5 9 4 0 6
1 3 2 8 5 7 4 9 0 6
*/
