//���scanf����ԭ��--->�������Ϊʲô������д����� 

#include <stdio.h>
#include <stack>
using namespace std;

int main(){
	stack<int> st;//����һ��ջ	 
	int m,n,k;//mΪstack���ݻ���nΪ���ķ�Χ��kΪ���ѡ��
	
	scanf("%d%d%d",&m,&n,&k);
	int i ;
	while(k--){
		
		int temp;//�洢������ 
		int number = 1;//��numberѹ��ջ(number��һ���仯��������ʼ��Ϊ0)
		int flag = 0;		
						 
		for(i = 0;i< n ;i++){			
			scanf("%d",&temp);//�������� 
			
			//���ջΪ�� 
			if(st.empty()){
				st.push(number++);//��number��ջ 
			}			
			//������ڣ���ѭ��ѹջ��ֱ������ 
			while(temp > st.top() ) { 
				st.push(number++);//��tempѹջ 
				if(st.size() > m) //�������ջ�ݻ�
				{	
					printf("st.size = %d\n",st.size());			
					flag = 1;
					break;					
				}
			}
			if(flag){
				break;			
			} 
			if(temp == st.top()){//������ 			
				st.pop(); //����ջ��Ԫ�� 
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

