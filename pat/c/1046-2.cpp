#include <cstdio> 
#include <algorithm>
using namespace std;


//ע��ʹ��Ԥ���������� 
//1.ÿһ�Գ��ڶ������ַ�����Ѱ�Ҿ��� ,��������̫��ᵼ�³�ʱ 
//2.��������˼����û��һ�ָ��Ӽ򵥵ķ�ʽ--->�������ɸ��������ӳɻ�������ÿһ�����ڵ���һ�����ڵľ��룬
//�����a,b����֮��ľ���ʱ������ֱ����������ɵõ����룬�������������С�ģ�������Ҫ�����sum-sum1�Ƚϡ�
//ȡ��Сֵ 
 

int N;
int array[100002];
int dis[100002];//��ʾ��ǰ��㵽��ʼ�ڵ��ֵ������right��left��ֵ��Ϊdis[right]-dis[left] 
 
int sum1 = 0,sum2 = 0;
int sum= 0;//��ʾ�ܵ�һ������·������ 


int main(){
	scanf("%d",&N);	
	int i = 0;
	
	dis[0] = 0;//��ʾ��һ����㵽�Լ��ľ��� 
	//arrray[0]�ǳ���1������2�ľ��룬������n,��array[n-1]Ϊ��n�����ڵ���һ�����ڵľ��� 
	for(i = 1;i<=N;i++){
		scanf("%d",&array[i]);
		sum += array[i];//����ܵ�·������
		dis[i] = sum; //��ʾ��i+1����㵽��һ���ڵ�ľ��� 
	}
	
	int M;
	int temp[2];
	scanf("%d",&M);
	while(M--){
		scanf("%d %d",&temp[0],&temp[1]);
		
		//������ֵ����������˳�� 
		int a = 0;
		if(temp[0]>temp[1]){
			a = temp[0];
			temp[0] = temp[1];
			temp[1] = a;
		}

		sum1 = dis[temp[1] - 1]-dis[temp[0]-1];
		sum2 = sum - sum1;
			
		printf("%d\n",min(sum1,sum2));
		
	} 	
}
/**
5 1 2 4 14 9
3
4 1
1 3
2 5
**/
