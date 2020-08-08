#include<cstdio>
#include<iostream>
using namespace std;

struct edge{
	int left,right;//һ���ߵ�������������
	int visit = 0 ;//��ʶ�������Ƿ���ʹ�����ʼֵΪ0 
};

edge e[10005]; 

int main(){
	int N,M;
	scanf("%d %d",&N,&M);
	int i,j,x;
	for(i = 0;i< M;i++){
		scanf("%d%d",&e[i].left,&e[i].right);
	}
	int K;//����ѯ�� 
	scanf("%d",&K);
	int verNum;//��ʾ����ѯ�Ķ��㼯���� 
	int verSet[10005]; 
	for(i = 0;i< K;i++){
		scanf("%d",&verNum);	
		for(j = 0;j< verNum;j++){
			scanf("%d",&verSet[j]);//�������ѯ��ÿ��vertex 			
		}
		
		//��ʼ���д���
		//���ѭ��������� 
		for( x = 0; x < M; x++ ){
			for(j = 0;j < verNum;j++){
				if(e[x].left == verSet[j] || e[x].right == verSet[j]) {
					e[x].visit = 1;//��Ϊ1 
				}
			}
		}
		
		for( x = 0;x < M ;x++){
			if(e[x].visit == 0){//������Ȼ�в��������� 
				break;
			}
			e[x].visit = 0;//reset 
		}
		if(x == M) cout <<"Yes"<<endl;
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
