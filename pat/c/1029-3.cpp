#include <stdio.h>
#include <algorithm>

using namespace std;

/*
1.使用全局变量可以扩大数组范围 
*/
#define size  2000002
	
long long  array[size]; //两个数组存放数据
int main(){

 int n1,n2, i, j =0 ;;	
	scanf("%d",&n1);	
	for(i = 0;i<n1;i++){
		scanf("%ld",&array[i]);
	} 
	
	scanf("%d",&n2);
	for(j = i;j < n2 + i;j++){
		scanf("%ld",&array[j]);
	} 	 
	sort(array,array+(n1+n2));
	printf("%d",array[(n1+n2-1)/2]);
}

/*
4 11 12 13 14
5 9 10 15 16 17

2
11 12
2
13 14
**/
