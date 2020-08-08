#include<cstdio>
#include<algorithm>
using namespace std;

int cmp(int a,int b){
	return a > b;
}

int main(){
	int n ;
	scanf("%d",&n);
	int array[n+1];
	
	int i = 0;
	int dis;
		
	for(i = 0;i< n ;i++){
		scanf("%d",&array[i]);		
	}
	sort(array,array+n,cmp);
	
	int count = 0;	
	int continuous = 0;//表示的是连续未变化的数字 
 	for(i = 0;i <= n ;i++){
	 	if(count-continuous >= array[i] ){
			printf("%d",array[i]);
			break;	
		}
		printf("num = %d, rank = %d\n",array[i],count-continuous);
		count ++;
		if(array[i] == array[i+1] && i!=n-1 ){
			continuous ++;
		}
		else{
			continuous = 0;
		}		
	}
}
/*
5
3 3 4 4 2

10
6 7 6 9 3 10 8 2 7 8

2
1 2

2
3 3

2
4 4

3
5 5 5

3
4 5 6

3
9 9 9

3
100 100 100

3
1 3 10 

2
0 0

2 
0 2

5
3 3 4 4 4

5
3 3 4 4 2
*/
