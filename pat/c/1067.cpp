#include <stdio.h>
#include <algorithm>
using namespace std;
/*
1.理解题意，只准使用0和其他数字交换 
*/
#define maxSize 100010
int array[maxSize] ,temp[maxSize];
void swap(int a,int b){//表示数组的两个下标 
	int c;
	c = temp[b];
	temp[b] = temp[a];
	temp[a] = c;
}
int main(){
	int N ;
	scanf("%d",&N);
	int i ,lo;//lo表示为数字0的下标 
	for(i = 0;i< N;i++){
		scanf("%d",&array[i]);
		temp[i] = array[i];//作为备份 
		if(temp[i] == 0){
			lo = i;//记录起始下标 
		}
	}	
	sort(array,array+N);//---->得到正确的排序
		
	int  count = 0 , count1 = 0; //记录交换次数 		
	//1.进行移位操作
	while(count1 < N){//count1表示被访问过的数字 		
		for(i = 0;i<N;i++){
			//先判断lo是否在位置0处	
			if(lo == 0){
				for(int j = 1;j < N;j++){
					if(temp[j] != array[j]){//如果两者不相等 
						lo = j;//则随机交换一个值
						count ++; 
						break;//跳出循环				
					}
				} 
			}
			//如果该数字没有出现在正确的位置上 --->进行寻找和交换操作 		
			if(temp[i] == array[lo] ){
				swap(lo,i);//交换两者的值 
				lo = i; 
				count++;
			}
		}
		count1++;
	}
	printf("%d",count);
} 
/*
4 4 0 2 1 3
10 3 5 7 2 6 4 9 0 8 1

8 3 0 5 6 2 1 4 7
*/
