#include <stdio.h>
#include <stack>
using namespace std;
#define maxn 1000 //����ʹ������е�ͬ���ؼ��� 

int main(){
	stack<int> st;//����һ��ջ	 
	int m,n,k;//mΪstack���ݻ���nΪ���ķ�Χ��kΪ���ѡ��
	
	scanf("%d %d %d",&m,&n,&k);
	int i ;
	while(k--){		
		int number = 1;//��numberѹ��ջ(number��һ���仯��������ʼ��Ϊ0)				
		int flag = 0;
		int array[maxn];//�洢��ѯֵ						 
		int current = 0 ;//��ʾ��ǰ�����±�
		 
		for(i = 0;i< n ;i++){			
			scanf("%d",&array[i]);//�������� 
		}
			
		//���ջΪ�� 
		if(st.empty()){
			st.push(number++);//��number��ջ 
		}			
		
		while(!st.empty() && current < n){			
			//�����������С��n����ѭ��ѹջ��ֱ������ 
			while(array[current] != st.top()) { 
				st.push(number++);//��tempѹջ 
				if(st.size() > m) //�������ջ�ݻ�
				{	
					flag = 1;					
					break;										
				}		
			}
			if(flag == 1){
				break;
			}
			
			//������ 
			while(!st.empty() && array[current] == st.top()){
				st.pop(); //����ջ��Ԫ�� 
				current ++;//�����±��һ 
			}
			//���ջΪ�գ���δ�����龡ͷ 
			if(st.empty() && current < n - 1){
				st.push(number++);//��number��ջ 
			}				
		}
				
		if(st.empty()){
			printf("YES\n");
		}
		else{
			printf("NO\n");
			//���ջ�Ƿ�Ϊ�� �������Ϊ�գ���ʹ��Ϊnull 
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

