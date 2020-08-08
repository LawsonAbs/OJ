#include <cstdio>
#include <stack>
using namespace std;

const int maxn = 1000;

int arr[maxn];//保存题目给定的出栈序列 
stack<int> st;//定义栈st,用以存放int型元素 

int main(){
	int m,n,t;
	scanf("%d%d%d",&m,&n,&t);
	
	while(t--){		
		while(!st.empty()){//当栈不空时，清空栈 
			st.pop();
		}
		for(int i  = 1;i <= n;i++){//读入数据 
			scnaf("%d",&arr[i]);
		} 
		 
		int current = 1;//指向出栈序列中的待出栈元素
		bool flag = true;
		for(int i = 1;i <= n;i++){
			st.push(i);//压i入栈 
			if(st.size() > m ){//如果此时栈中元素个数大于容量m,则序列非法 
				flag = false;
				break;
			}
			
			//栈顶元素与出栈序列当前位置相同时
			while(!st.empty()  && st.top() == arr[current]){
				st.pop(); //出栈 
				current ++;
			} 			
		} 
		if(st.empty() == true && flag == true){
				printf("YES\n");
			}
		else{
			printf("NO\n");
		}
	}		
	return 0 ;
} 
/**
5 7 5
1 2 3 4 5 6 7
3 2 1 7 5 6 4
7 6 5 4 3 2 1
5 6 4 3 7 2 1
1 7 6 5 4 3 2
*/ 
