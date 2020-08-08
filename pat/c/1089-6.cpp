#include <stdio.h>
#include <algorithm>
using namespace std;

#define size 101
int array[size];//原数组和比较数组 
int n ;

//使用插入排序
void insertSort(){
	int i ,j ,k=1;//k为数组a的下标	
	int a[size];//暂时存放的数组
	bool flag = true;
	a[k] = array[1];//第一项赋值	
	
	for(i = 2;i<= n;i++){
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
		//赋值操作 
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
