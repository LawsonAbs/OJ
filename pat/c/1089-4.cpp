#include <stdio.h>
#include <algorithm>
using namespace std;

#define size 101
int array[size],result[size];//ԭ����ͱȽ����� 

int n ,array1[size];
bool mergeFlag = false;//��ʼ��Ϊfalse

//�Ƚ����������Ƿ���ͬ 
bool isSame(int a[],int b[],int n){
	int i ;
	for(i = 1;i <= n;i++){
		if(a[i]!=b[i])
			return false;
	} 
	return true;
}


//ʹ�ò�������
void insertSort(){
	int i ,j ,k=1;//kΪ����a���±�	
	int a[size];//��ʱ��ŵ�����
	bool flag = true;
	a[k] = array[1];//��һ�ֵ	
	
	int count = 0;
	for(i = 2;i<= n;i++){
		if(count != 2)
		{
			if(array[i] >= a[k]){//���˵�������һλ 
				k++;
				a[k]  = array[i]; 			
			}
			else{
				for(j = 1;j <= k && flag; j++){//���ҳ�ǡ����λ�ã�Ȼ������ȥ�����ǲ�һ����Ҫ������ 
					if(array[i] < a[j]){//С�� 
						int m ;
						for(m = k; m >= j;m--){//������һλ 
							a[m+1] = a[m];
						}					
						a[j] = array[i];
						flag = false;					 
					}
				}	
				k++;//k��һ
				flag = true;
			}
			
			if(count == 1){
				count ++;
			} 
			//��ֵ���� 
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
	
	if(mergeFlag == true){	//���		
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
	
	//�ж����������Ƿ����	
	if(isSame(A,result,n) == true){
		printf("Merge Sort\n");
		mergeFlag = true; 
	}
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
