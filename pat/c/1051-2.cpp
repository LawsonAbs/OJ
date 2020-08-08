#include <cstdio>
#include <stack>

#define maxn 1000
using namespace std;


int main(){	
	int m,n,k;
	int array[maxn];
	stack<int> sta;//定义栈
	
	scanf("%d%d%d",&m,&n,&k);//输入m,n,k	 
	int  i;
	while(k--){
		int current = 1;//当前栈指针 + 重置为1 
		int j = 1; //重置为1 
		
		//当栈sta不为空的时候，退栈直为空 
		while(!sta.empty()){
			sta.pop();
		} 
		
		for(i = 1;i <= n;i++){ 
			scanf("%d",&array[i]);		 
		}		
		
		//入栈  + 需要清楚为什么需要使用while()循环 
		while(j <= n){
			sta.push(j);
			if( sta.size() > m){//栈的容积大于m的话 				
				break;//跳出循环
			}
			
			//如果栈顶数和序列相同，则出栈 ---> 注意这里使用while的原因 
			while(!sta.empty()  && sta.top() == array[current] ){
				sta.pop();//出栈一个数 
				current ++;//当前指针加1 
			}
			j++;
		}
		
		if(j < n || current < n){//如果没有输入完全或者没有判断完全 
			printf("NO\n"); 
		}		
		else if(j == n+1 && current == n+1){
			printf("YES\n");
		}
	}		
}
/*
5 7 5
1 2 3 4 5 6 7
3 2 1 7 5 6 4
7 6 5 4 3 2 1
5 6 4 3 7 2 1
1 7 6 5 4 3 2
*/
