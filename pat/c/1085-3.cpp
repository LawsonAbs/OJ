#include <stdio.h>
#include <algorithm>
using namespace std;

#define size 100002
/*
1.使用two pointer
*/

int main(){
	long long n,p;
	scanf("%ld %ld",&n,&p);
	int i ;
	long long array[size];
	for(i = 0;i<n;i++){
		scanf("%ld",&array[i]);
	}		
	sort(array,array+n);
	
	int number  = 0;//用来记录两者之间相差的数目
	int j  = 0;
	for(i = 0 ; i < n ; i++){		
		while(j < n){//高明之处在于j值保持不变，然后i值却往后推了一个 		
			if(array[j] <= array[i] * p){//如果满足条件
				number = max(number,(j - i + 1));			
			}
			else if(array[j] > array[i] * p){
				break;//如果是这种情况则跳出循环 
			}
			j++;				
		}
	} 
	printf("%d",number);
}
/*测试点 
10 8
2 3 20 4 5 1 6 7 8 9

10 8
2 3 25 4 5 10 6 7 8 9

2 5
6 40
*/
