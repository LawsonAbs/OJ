#include<cstdio>
#include<iostream>
using namespace std;

struct edge{
	int ver[10005];//һ����������ڶ���	���� 
	int index = 0;//��ʾ���ڵĶ����� 
};
 
edge e[10005];  

int main(){
	int N,M;
	scanf("%d %d",&N,&M);
	int i,j,x;
	int left,right; 
	for(i = 0;i< M;i++){
		scanf("%d%d",&left,&right);
		e[left].ver[e[left].index] = right;
		e[left].index++;
		
		e[right].ver[e[right].index] = left;
		e[right].index++;		
	}
	int K;//����ѯ�� 
	scanf("%d",&K);
	int verNum;//��ʾ����ѯ�Ķ��㼯���� 
	int verSet[10005]; //����ѯ���㼯 
	for(i = 0;i< K;i++){
		scanf("%d",&verNum);	
		for(j = 0;j< verNum;j++){
			scanf("%d",&verSet[j]);//�������ѯ��ÿ��vertex 						
		}
				
		int sumEdge = 0;//��ʾ���뼯�����ܵñ��� 		
		//�ҳ��ظ��ı���
		int repEdge = 0;
		
		//��ʼ���д���
		for( x = 0; x < verNum; x++ ){
			sumEdge += e[verSet[x]].index;//����û���ų��ظ������ 
			for(j = x+1;j< verNum;j++){				
				for(int z = 0;z < e[verSet[j]].index;z++){//��ʾ���� �ڵ��=j�����ڽڵ��� 
					if(e[verSet[j]].ver[z] == verSet[x]){						
						repEdge ++;
					} 
				}			
			} 
		}
		sumEdge -= repEdge;//�ų��ظ������ 
		if(sumEdge == M) cout <<"Yes"<<endl;
		else cout<<"No"<<endl;		
	} 
}
/*
10 11
8 7
6 8
4 5
8 4
8 1
1 2
1 4
9 8
9 1
1 0
2 4
5
4 0 3 8 4
6 6 1 7 5 4 9
3 1 8 4
2 2 8
7 9 8 7 6 5 4 2
*/
