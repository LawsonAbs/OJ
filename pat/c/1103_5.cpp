#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#define maxn  500
using namespace std;

int limitNum;
int n,k,p;
int path[maxn];
int maxSum = 0;//因子之和 
int outcome[maxn];//用数组记录分解record 
int result[maxn];//pow函数计算的结果--预处理 

//分解数n 次数count 指数p 和sum 路径part[]  
void factorization(int n ,int count,int sum,int path[],int pre,int inSum){
	int temp = 0;
	if(sum > n || count > k) return;//如果已经不满足条件，则直接退出 
	else if(sum == n && count == k){				
		if(inSum > maxSum){ 
			for(int j = count-1;j >=0 ;j--){			 
				outcome[j] = path[j]; 			
				maxSum = inSum;				
			}			
		}		
		return;
	}
	else {		
		if(pre >= 1){
			temp = result[pre];
			path[count] = pre;//加入路径 			
			factorization(n,count+1,sum+temp,path,pre,inSum+pre);					
		}
		path[count] = 0;//删除路径 
		if(pre > 1){
			pre--;
			factorization(n,count,sum,path,pre,inSum); 		
		}					
	}
}

//找出最大限制的数
void getLimitNum (int n,int p){	
	for(int i = 0;i <= n;i++ ) {
		result[i] = (int)pow(i,p) ;//将结果放在result中 
		if(pow(i,p) >= n){
			limitNum = i; 
			break;
		}	
	}	
}

int main(){	
	scanf("%d %d %d",&n,&k,&p);
	getLimitNum(n,p);	
	factorization(n,0,0,path,limitNum,0);	//present值设为1 

	sort(outcome,outcome+k); 
	if(maxSum){
		printf("%d =",n);
		for(int i = k-1;i >=0 ; i--){
			if(i!=0)	printf(" %d^%d +",outcome[i],p);
			else	printf(" %d^%d",outcome[i],p);
		}	
	}
	else{
		printf("Impossible");
	}	
}
/**
169 5 2
169 167 3
50 50 2
60 60 2
50 25 2
100 100 2
400 400 2
300 300 2
注：
1.程序容易运行超时，这时候就得使用小技巧避免情况发生。
1>比如在程序中需要使用到pow函数，我们可以预处理之后，直接使用，而不是每次都计算
2>输出要求是和最大；如果和最大有不同的数据，则按照字典序输出。可以不用sort排序，直接从高往低计算即可。 

*/
