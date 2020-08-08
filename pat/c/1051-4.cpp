#include <stdio.h>
#include <stack>
using namespace std;
#define maxn 1000 //避免使用与库中的同名关键字 

int main(){
	stack<int> st;//定义一个栈	 
	int m,n,k;//m为stack的容积，n为数的范围，k为检查选项
	
	scanf("%d %d %d",&m,&n,&k);
	int i ;
	while(k--){		
		int number = 1;//将number压入栈(number是一个变化的数，初始化为0)				
		int flag = 0;
		int array[maxn];//存储查询值						 
		int current = 0 ;//表示当前数组下标
		 
		for(i = 0;i< n ;i++){			
			scanf("%d",&array[i]);//输入数据 
		}
			
		//如果栈为空 
		if(st.empty()){
			st.push(number++);//将number入栈 
		}			
		
		while(!st.empty() && current < n){			
			//如果不等于且小于n，则循环压栈，直到等于 
			while(array[current] != st.top()) { 
				st.push(number++);//将temp压栈 
				if(st.size() > m) //如果超出栈容积
				{	
					flag = 1;					
					break;										
				}		
			}
			if(flag == 1){
				break;
			}
			
			//如果相等 
			while(!st.empty() && array[current] == st.top()){
				st.pop(); //弹出栈顶元素 
				current ++;//数组下标加一 
			}
			//如果栈为空，且未到数组尽头 
			if(st.empty() && current < n - 1){
				st.push(number++);//将number入栈 
			}				
		}
				
		if(st.empty()){
			printf("YES\n");
		}
		else{
			printf("NO\n");
			//检查栈是否为空 ，如果不为空，则使其为null 
			while(!st.empty()){
				st.pop();
			} 	
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

