#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#define maxn  500
using namespace std;

int limitNum;
int n,k,p;
int path[maxn];
int maxSum = 0;//����֮�� 
int outcome[maxn];//�������¼�ֽ�record 
int result[maxn];//pow��������Ľ��--Ԥ���� 

//�ֽ���n ����count ָ��p ��sum ·��part[]  
void factorization(int n ,int count,int sum,int path[],int pre,int inSum){
	int temp = 0;
	if(sum > n || count > k) return;//����Ѿ���������������ֱ���˳� 
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
			path[count] = pre;//����·�� 			
			factorization(n,count+1,sum+temp,path,pre,inSum+pre);					
		}
		path[count] = 0;//ɾ��·�� 
		if(pre > 1){
			pre--;
			factorization(n,count,sum,path,pre,inSum); 		
		}					
	}
}

//�ҳ�������Ƶ���
void getLimitNum (int n,int p){	
	for(int i = 0;i <= n;i++ ) {
		result[i] = (int)pow(i,p) ;//���������result�� 
		if(pow(i,p) >= n){
			limitNum = i; 
			break;
		}	
	}	
}

int main(){	
	scanf("%d %d %d",&n,&k,&p);
	getLimitNum(n,p);	
	factorization(n,0,0,path,limitNum,0);	//presentֵ��Ϊ1 

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
ע��
1.�����������г�ʱ����ʱ��͵�ʹ��С���ɱ������������
1>�����ڳ�������Ҫʹ�õ�pow���������ǿ���Ԥ����֮��ֱ��ʹ�ã�������ÿ�ζ�����
2>���Ҫ���Ǻ�������������в�ͬ�����ݣ������ֵ�����������Բ���sort����ֱ�ӴӸ����ͼ��㼴�ɡ� 

*/
