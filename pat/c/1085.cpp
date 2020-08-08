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
	for(i = 0 ; i < n ; i++){
		int j = n - 1; 
		while(j >= i){
			if(number > (j - i +1)){//如果说number的值已经大于两者的距离，则不再比较 
				break;
			} 
			else{
				if(array[j] <= array[i] * p){//如果满足条件
					if(number <(j - i + 1)){
						number = j - i + 1;				
					}
					break;//只要满足这个情况，就break掉						
				}
				else{
					j--;
				} 	
			}			
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
