#include <stdio.h>

#define size 100000000
long long array[size];

int main(){
	int m,n;//æÿ’Ûµƒm¡–£¨n–– 
	long long number;
	long long max = 0;
	scanf("%d %d", &m,&n); 
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			scanf("%lld",&number);
			array[number]++;
			if(max < number){
				max = number;
			}
		}
	}
	
	long long maxCount = 0;
	for(int i = 0;i <= max;i++){
		if(array[maxCount] < array[i])
			maxCount = i;
	}
	printf("%d\n",maxCount);
}
/*
5 3
0 0 255 16777215 24
24 24 0 0 24
24 0 24 24 24
1 1
1
*/
