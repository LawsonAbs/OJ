#include <cstdio>
#include <stack>

#define maxn 1000
using namespace std;


int main(){	
	int m,n,k;
	int array[maxn];
	stack<int> sta;//����ջ
	
	scanf("%d%d%d",&m,&n,&k);//����m,n,k	 
	int  i;
	while(k--){
		int current = 1;//��ǰջָ�� + ����Ϊ1 
		int j = 1; //����Ϊ1 
		
		//��ջsta��Ϊ�յ�ʱ����ջֱΪ�� 
		while(!sta.empty()){
			sta.pop();
		} 
		
		for(i = 1;i <= n;i++){ 
			scanf("%d",&array[i]);		 
		}		
		
		//��ջ  + ��Ҫ���Ϊʲô��Ҫʹ��while()ѭ�� 
		while(j <= n){
			sta.push(j);
			if( sta.size() > m){//ջ���ݻ�����m�Ļ� 				
				break;//����ѭ��
			}
			
			//���ջ������������ͬ�����ջ ---> ע������ʹ��while��ԭ�� 
			while(!sta.empty()  && sta.top() == array[current] ){
				sta.pop();//��ջһ���� 
				current ++;//��ǰָ���1 
			}
			j++;
		}
		
		if(j < n || current < n){//���û��������ȫ����û���ж���ȫ 
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
