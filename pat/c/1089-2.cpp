#include <stdio.h>

const int size = 100;
int result[size] ,n;


//�Ƚ����������Ƿ���ͬ 
bool isSame(int a[],int b[],int n){
	int i ;
	for(i = 0;i<n;i++){
		if(a[i]!=b[i])
			return false;
	} 
	return true;
}

void merge(int A[],int L1,int R1,int L2,int R2){
	int i = L1,j = L2;//iָ��A[L1],jָ��A[L2]
	int temp[size],index = 0;	//temp��ʱ��źϲ�������飬indexΪ���±�
	
	while(i<=R1 && j<=R2){//ʹ��two pointer�ķ����������߹鲢 
		if(A[i] <= A[j]){
			temp[index++] = A[i++];
		}
		else
		{
			temp[index++] = A[j++];
		}		
	} 
	//������ 
	while(i<=R1){
		temp[index++] = A[i++];
	} 
	while(j<=R2){
		temp[index++] = A[j++];
	} 
	for(i = 0;i<index;i++){
		A[L1 + i] = temp[i];//���ϲ�������и�ֵ������A   L1��֤������ԭ����˳�� 
	}
	for(i = 0;i<n;i++){
		printf("%d ",A[i]);
	}
}

//ʹ�õݹ��㷨��array[]���鵱ǰ����[left,right]�������� 
void mergeSort(int A[],int left,int right){
	if(left < right){
		int mid = (left + right) / 2;
		mergeSort(A,left,mid);
		mergeSort(A,mid+1,right);
		merge(A,left,mid,mid+1,right);
		if(isSame(A,result,n)){//������
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
	mergeSort(array,0,n-1);//����������� 
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
