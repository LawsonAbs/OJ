//help qi xiang 
#include<cstdio>
#define maxn 1000
 
double array[maxn];//全局变量  保存皇后的位置 
int n, count = 0;//必要可输出计数 

bool isRight(int currentRow){//是否是符合条件的点  currentRow当前行 
	int i ; 
	for(i = 1;i< currentRow;i++){
		if( array[i] == -1) break;//不符合条件的数 
		if(array[currentRow] == array[i])		break;//列相同 
		if( ( (array[currentRow]- array[i])/(currentRow - i) == -1 ) )	break;//在斜对脚线上
		if( ((array[currentRow]- array[i])/(currentRow - i) == 1 ) )	break;//在斜对脚线上
	}//用abs函数来判断是否符合条件会更好 
	if(i == currentRow)	return true;
	else return false;
}

void dfs(int currentRow){
	if(currentRow == n+1){//如果已经到了最后一行的下一行 
		for(int j = 1;j <= n;j++){
			printf("%.0lf ",array[j]);//输出 
		}printf("\n");
		count++;
		return ;//返回 
	} 
	for(int i = 1;i<= n;i++){
		array[currentRow] = i;//currentRow是定值，随着递归改变 
		if(isRight(currentRow)){//如果符合条件--->则继续 
			dfs(currentRow+1);//往下一行搜索 --> ++则不能回溯 
		}
	}
} 
  
int main(){	
	scanf("%d",&n);
	dfs(1); 
}

/**
坑点： 
4/3 == 1 
*/


