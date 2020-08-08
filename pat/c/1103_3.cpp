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
void factorization(int n ,int count, int p,int sum,int path[],int inSum){
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
	else{
		for(int i = limitNum ; i >= 0 ; i--){			
			temp = result[i];
			path[count] = i;//����·�� 
			factorization(n,count+1,p,sum+temp,path,inSum+i); 	
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
	factorization(n,0,p,0,path,0);	//presentֵ��Ϊ1 

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
