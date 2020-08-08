#include<cstdio>
#include<iostream>
#include<algorithm>
#include<functional>

#define maxn 10005
using namespace std;

int N , M;
int coins[maxn];
int rec[maxn]; 
int COUNT = 0;//解的个数 
int res[maxn];//存下所有解 
int num = 0;
int flag = 0;//表示是否存在解 

//使用深搜算法解决这个和问题 
//对于每枚硬币，都有放或者不放这两种选择，在dfs代码中实现这两种选择即可 
void dfs(int root,int index,int sum){//root表示是0 			
	if( sum > M){//如果超过了M 
		return ;
	} 
	else if(sum == M){		
		if(COUNT == 0){	
			num = index;		
			for(int i = 0;i< index;i++){
				res[i] = rec[i];//保存到res中 
			}
		}
		COUNT ++;//解数+1 
		flag = 1;
	} 	
	if(flag == 1) return ; 
	
	//继续往下递归 	=> 放硬币 	
	rec[index] = root;	
	dfs(root+1,index+1,sum + coins[root]);
	rec[index] = 0;//因为上面已经修改了值，所以这里要重置为0 
		
	//继续往下递归 	=> 不放硬币 			
	if(root + 1 < N) dfs(root+1,index,sum);	
}

int main(){	
	cin >> N >> M;
	int i,j;
	
	for(i = 0;i< N;i++){
		cin >> coins[i];
	}
	sort(coins,coins+N,less<int>());	
	
	int index = 0;//下标 
	int sum = 0;//总和 
	for(i = 0;i< N;i++){
		index = 0;//重置为0 
		sum = 0;//重置为0 
		dfs(i,index,sum);//从i开始 			
	} 
	
	if(COUNT == 0 ){
		cout << "No Solution\n";
		return 0; 	
	}
	for(j = 0;j < num;j++){
		if(j!=num-1) cout << coins[res[j]]<<" " ;
		if(j == num-1) cout << coins[res[j]] ;
	}	
}
