#include <stdio.h>
#include <algorithm>
using namespace std;

#define size 101
int array[size],result[size];//原数组和比较数组 

int n ,array1[size];
bool mergeFlag = false;//初始化为false

//比较两个数组是否相同 
bool isSame(int a[],int b[],int n){
	int i ;
	for(i = 1;i <= n;i++){
		if(a[i]!=b[i])
			return false;
	} 
	return true;
}


//使用插入排序
void insertSort(){
	int i ,j ,k=1;//k为数组a的下标	
	int a[size];//暂时存放的数组
	bool flag = true;
	a[k] = array[1];//第一项赋值	
	
	int count = 0;
	for(i = 2;i<= n;i++){
		if(count != 2)
		{
			if(array[i] >= a[k]){//如果说大于最后一位 
				k++;
				a[k]  = array[i]; 			
			}
			else{
				for(j = 1;j <= k && flag; j++){//先找出恰当的位置，然后插入进去，但是不一定需要遍历完 
					if(array[i] < a[j]){//小于 
						int m ;
						for(m = k; m >= j;m--){//往后移一位 
							a[m+1] = a[m];
						}					
						a[j] = array[i];
						flag = false;					 
					}
				}	
				k++;//k加一
				flag = true;
			}
			
			if(count == 1){
				count ++;
			} 
			//赋值操作 
			for(int c = 1;c <= k;c++){
				array[c] = a[c];
			}			
					
			if(isSame(array,result,n)){
				printf("Insertion Sort\n");
				count ++;
			}	
		}
		else if(count == 2){
			for(int b = 1;b <= n;b++){
				if(b!=n){
					printf("%d ",array[b]);
				}
				else{
					printf("%d",array[b]);	
				}
			}printf("\n");
			return ;
		}						
	}
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
	
	if(mergeFlag == true){	//输出		
		for(i = 1;i <= n;i++){
			if(i!=n){
				printf("%d ",A[i]);	
			}
			else{
				printf("%d",A[i]);
			} 
		}printf("\n");	
		mergeFlag = false; 
		return ;
	}
	
	//判断两个数组是否相等	
	if(isSame(A,result,n) == true){
		printf("Merge Sort\n");
		mergeFlag = true; 
	}
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
	scanf("%d",&n);
	int i ;
	for(i = 1;i<= n;i++){
		scanf("%d",&array[i]);
		array1[i] = array[i];
	}
	for(i = 1;i<= n;i++){
		scanf("%d",&result[i]);
	}
	mergeSort(array1);
	insertSort();
	 
}
/**
10
3 1 2 8 7 5 9 4 6 0
1 2 3 7 8 5 9 4 6 0

10
3 1 2 8 7 5 9 4 0 6
1 3 2 8 5 7 4 9 0 6

4
3 4 2 1
3 4 2 1

*/
