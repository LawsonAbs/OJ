#include<cstdio>
#include<iostream>
#include<set>
using namespace std;

struct edge{
	int left,right;//һ���ߵ������������� 
	int isVisit = 0;//��ʾ�Ƿ���ʹ� 
};
 
edge e[10005];  

int main(){
	int N,M;
	scanf("%d %d",&N,&M);
	int i,j,x;
	int left,right; 
	for(i = 0;i< M;i++){
		scanf("%d%d",&e[i].left,&e[i].right);	
	}
	int K;//����ѯ�� 
	scanf("%d",&K);
	int verNum;//��ʾ����ѯ�Ķ��㼯���� 
	set<int> verSet; //����ѯ���㼯 
	int vertex;//ÿ������ 
	for(i = 0;i< K;i++){
		scanf("%d",&verNum);	
		for(j = 0;j< verNum;j++){
			scanf("%d",&vertex);//�������ѯ��ÿ��vertex
			verSet.insert(vertex);//���뵽set�� 
		}

//		for(set<int>::iterator it= verSet.begin();it!=verSet.end();it++){
//			cout<<*it<<" ";
//		}						
		//��ʼ���д���
		for( x= 0; x<M;x++ ){
			if(verSet.find(e[x].left)==verSet.end() 
			&& verSet.find(e[x].right)==verSet.end() ){				
				break;
			}
		}
		
		if(x == M) cout <<"Yes"<<endl;
		else cout<<"No"<<endl;
		
		verSet.clear();//clear set		
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
