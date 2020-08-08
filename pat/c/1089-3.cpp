#include <stdio.h>
#include <algorithm>
using namespace std; 

const int size = 100;

//���������ֲ�������������� 
int n , result[size];
int flag = 1;//�Ƿ��ٽ�������Ŀ��Ʊ��� 


//�Ƚ����������Ƿ���ͬ 
bool isSame(int a[],int b[],int n){
	int i ;
	for(i = 1;i <= n;i++){
		if(a[i]!=b[i])
			return false;
	} 
	return true;
}

//ʹ�ù鲢����ʱ����������ϲ� 
void merge(int A[],int L1,int R1,int L2,int R2){
	int i = L1,j = L2;
	//iָ��A[L1],jָ��A[L2]
	//ͬʱҲΪ�˱���L1,L2ֵ���� --->�ǳ���Ҫ 
	
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
	
	//��һ��Ϊtwo pointer������ʵ����������ĺϲ��ĺ��ģ��� --->�ֲ����µķ��� 
	for(i = 0;i<index;i++){
		A[L1 + i] = temp[i];//���ϲ�������и�ֵ������A   L1��֤������ԭ����˳�� 
	}
	
	//�ж����������Ƿ����	
	if(isSame(A,result,n) == true){
		printf("Merge Sort\n");				
	}
	
	for(i = 1;i <= n;i++){
		printf("%d ",A[i]);
	}
	printf("\n");
}

//ʹ�÷ǵݹ��㷨��array[]���鵱ǰ����[left,right]�������� 
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
	 
	for(i = 1;i <= n;i++){//ע����������������±���Ǵ�i = 1��ʼ 
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
