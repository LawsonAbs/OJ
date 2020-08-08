//help qixiang 
#include<cstdio>

int n,m,king;//n行 m列 k国王 
int array[13][13];//记录哪个下标上已经有记录
int count = 0;//计数

bool isRight(int row,int line){//判断row line上的国王是否符合条件
	int flag = 0;
	for(int k= -1;k<=1 ;k++ ){
		for(int j = -1;j <=1 ;j++){
			if(k==0 && j==0)
				continue; 
			else{
				if(row+k >=0 && row+k <n && line+j >=0 && line+j<m ){
					if(array[row+k][line+j] == 1)
						flag = 1;		
				}	
			}
		}
	}
	if(flag ==1 ){ 
		return false;
	}	
	else return true;
}

void dfs(int currentId,int completedNumber){//当前处理的id  已完成的数 
	if(completedNumber == king){//如果k个国王都已经安排好了 
		count++;//计数
		return ; 
	}
	if(currentId == n*m ){//如果当前处理的数的下标已经超过已有的范围--则返回 
		return ;
	}
	for(int i = currentId;i< n*m ;i++){
		int row ,line;//行列
		row = i / m;//求出行 row 
		line = i % m;//求出列  line
		if(isRight(row,line))//如果当前放置满足情况
		{ 
			array[row][line] = 1;//赋值 
			dfs(i+1,completedNumber+1);//继续往下深搜 
			array[row][line] = 0;//回溯--->将之前的值清0	
		} 
	}
} 

int main(){
	scanf("%d %d %d",&n,&m,&king);
	dfs(0,0);//深搜 
	printf("%d",count); 
}  
/**
2 3 2
坑点：
1.去重
2.在判断是否受到攻击时，可以使用两点间的距离[数学公式]来做，这样会很简洁 
*/
