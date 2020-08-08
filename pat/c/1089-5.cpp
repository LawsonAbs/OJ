#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 111;
int origin[N],tempOri[N],changed[N];//原始数组，原始数组备份，目标数组
int n ;//元素个数

bool isSame(int A[],int B[]){
	for(int i = 1;i <= n;i++){
		if(A[i]!=B[i])
			return false;
	} 
	return true;
} 

//输出数组 
bool showArray(int A[]){
	for(int i = 0;i<n;i++){
		printf("%d",A[i]);
		if(i< n-1)
			printf(" ");
	}
	printf("\n");
}

//插入排序 
bool insertSort(){
	bool flag = false;//比较记录
	for(int i = 1 ;i< n;i++){
		if(i !=1 && isSame(tempOri,changed)){
			flag = true;
		}
		
		//以下为插入部分
		int temp = tempOri[i],j = i;
		while(j>0 && tempOri[j-1] > temp){
			tempOri[j]  = tempOri[j-1];
			j--;
		} 
		tempOri[j] = temp;
		if(flag = true){
			return true;//如果flag为true，则说明已达到目标数组 
		}
	} 
	return false;//无法达到目标数组，返回false 
}

void mergeSort(){
	bool flag = false;
	for(int step  = 2;step /2 <= n;step *=2){
		if(step!=2 && isSame(tempOri,changed)){
			flag = true;
		}
		for(int i = 0;i<n;i+=step){
			sort(tempOri+i,tempOri + min(i+step,n));
		}
		if(flag == true){
			showArray(tempOri);
			return ;
		}
	}
} 

int main(){
	scanf("%d",&n);
	for(int i = 0;i<n;i++){
		scanf("%d",&origin[i]);
		tempOri[i] = origin[i];
	}
	for(int i = 0;i<n;i++){
		scanf("%d",&changed[i]);
	}
	if(insertSort()){
		printf("Insertion Sort\n");
		showArray(tempOri);
	}
	else{
		printf("Merge Sort\n");
		for(int i = 0;i<n;i++){
			tempOri[i] = origin[i];
		}
		mergeSort();
	}
	return 0;
}
/*
10
3 1 2 8 7 5 9 4 0 6
1 3 2 8 5 7 4 9 0 6
*/
