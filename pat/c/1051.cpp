#include <cstdio>
#include <stack>
using namespace std;

const int maxn = 1000;

int arr[maxn];//������Ŀ�����ĳ�ջ���� 
stack<int> st;//����ջst,���Դ��int��Ԫ�� 

int main(){
	int m,n,t;
	scanf("%d%d%d",&m,&n,&t);
	
	while(t--){		
		while(!st.empty()){//��ջ����ʱ�����ջ 
			st.pop();
		}
		for(int i  = 1;i <= n;i++){//�������� 
			scnaf("%d",&arr[i]);
		} 
		 
		int current = 1;//ָ���ջ�����еĴ���ջԪ��
		bool flag = true;
		for(int i = 1;i <= n;i++){
			st.push(i);//ѹi��ջ 
			if(st.size() > m ){//�����ʱջ��Ԫ�ظ�����������m,�����зǷ� 
				flag = false;
				break;
			}
			
			//ջ��Ԫ�����ջ���е�ǰλ����ͬʱ
			while(!st.empty()  && st.top() == arr[current]){
				st.pop(); //��ջ 
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
