#include <stdio.h>
#include <algorithm>
using namespace std;

#define size 101
int array[size];//ԭ����ͱȽ����� 
int n ;

//ʹ�ò�������
void insertSort(){
	int i ,j ,k=1;//kΪ����a���±�	
	int a[size];//��ʱ��ŵ�����
	bool flag = true;
	a[k] = array[1];//��һ�ֵ	
	
	for(i = 2;i<= n;i++){
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
		//��ֵ���� 
		for(int c = 1;c <= k;c++){
			array[c] = a[c];
		}			
							
		for(int b = 1;b <= n;b++){
			if(b!=n){
				printf("%d ",array[b]);
			}
			else{
				printf("%d",array[b]);	
			}
		}printf("\n");						
	}
} 

 
int main(){	
	scanf("%d",&n);
	int i ;
	for(i = 1;i<= n;i++){
		scanf("%d",&array[i]);
	}
	
	printf("Isertion Sort\n");
	insertSort();	 
}
/**
10
3 1 2 8 7 5 9 4 6 0
*/
