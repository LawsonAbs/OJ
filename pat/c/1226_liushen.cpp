//help qixiang 
#include<cstdio>
#define maxn 30
int array[maxn];//原数组
int record[maxn];//记录该数字是否擦去了  record[i] =0表示该下标为i的数没有擦去 
int maxLen = 0;//最长的序列 
int n;

void deal(int currentIndex){//去或者不去这个数字 
	if(currentIndex == n+1){//如果已经到最后一个数字的下一个数字了 
		int count = 1;//表示正确的序列 
		int tempLen = 0;
		for(int i = 1;i <= n;i++ ){
			if(record[i] == 0){//表明该位没有擦去 
				if(array[i] == count){//如果该位上的数字等于count 
					tempLen++;
				}
				count++; 
			}
		}
		if(tempLen > maxLen){//更新最大长度 
			maxLen = tempLen; 
		}
		return ;
	} 
	deal(currentIndex+1);//不擦去该位 
	record[currentIndex] = 1;//擦去该位 
	deal(currentIndex+1);//擦去该位 
	record[currentIndex] = 0;//复位 
}

int main(){
	scanf("%d",&n);
	for(int i = 1;i<= n;i++){ //从1开始存储 
		scanf("%d",&array[i]);
	}
	deal(1);
	printf("%d",maxLen);
}
/**
5
1 1 2 5 4
*/
