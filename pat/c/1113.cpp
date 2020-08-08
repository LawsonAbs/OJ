#include<cstdio>
#include<algorithm>
using namespace std; 

int cmp(int a,int b){
	return a < b;
}

int main(){
	int N ;
	scanf("%d",&N);
	//printf("N = %d\n",N);
	int i;
	int array[N]; //定义一个N个数的序列 
	for(i = 0;i<N;i++){
		scanf("%d",&array[i]);			
	}
	
	sort(array,array+N,cmp);
//	for(i = 0;i < N;i++){
//		//printf("%d ",array[i]);
//	}
	
	int sum1 = 0;
	int sum2 = 0; 
	int sumDiff = 0;
	int numDiff = 0;
	int mid = N/2;
	
	for(i = 0;i < mid;i++){
	//	printf("%d ",array[i]);
		sum1 +=  array[i];
	}//printf("\n");
	
	for(i = N -1;i >= mid ;i--){
	//	printf("%d ",array[i]);
		sum2 +=  array[i];
	}//printf("\n");
	if(N%2 == 0) {
		printf("0 %d",sum2-sum1);
	}else{
		printf("1 %d",sum2-sum1);
	}
	return 0;
}
/**
10
23 8 10 99 46 2333 46 1 666 555

3
1 8 10

**/
