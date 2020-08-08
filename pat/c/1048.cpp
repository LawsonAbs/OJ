#include <stdio.h>
#include <algorithm>
using namespace std;
 
#define N 100010
int array[N];

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	int i ,j = n - 1;
	for (i = 0;i<n;i++){
		scanf("%d",&array[i]);
	}
	
	sort(array,array+n);//´ÓµÍµ½¸ßÅÅÐò
	i = 0;
	while(i < j){
		if(array[i] + array[j] > m){
			j--;
		}
		else if(array[i] + array[j] < m){
			i++;
		}
		else{
			printf("%d %d",array[i],array[j]);
			break;
		}
	}
	if(i == j){
		printf("No Solution");
	} 
} 

/*
8 15
1 2 8 7 2 4 11 15

7 14
1 8 7 2 4 11 15
*/
