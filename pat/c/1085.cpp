#include <stdio.h>
#include <algorithm>
using namespace std;

#define size 100002
/*
1.ʹ��two pointer
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
	
	int number  = 0;//������¼����֮��������Ŀ
	for(i = 0 ; i < n ; i++){
		int j = n - 1; 
		while(j >= i){
			if(number > (j - i +1)){//���˵number��ֵ�Ѿ��������ߵľ��룬���ٱȽ� 
				break;
			} 
			else{
				if(array[j] <= array[i] * p){//�����������
					if(number <(j - i + 1)){
						number = j - i + 1;				
					}
					break;//ֻҪ��������������break��						
				}
				else{
					j--;
				} 	
			}			
		}
	} 
	printf("%d",number);
}
/*���Ե� 
10 8
2 3 20 4 5 1 6 7 8 9

10 8
2 3 25 4 5 10 6 7 8 9

2 5
6 40
*/
