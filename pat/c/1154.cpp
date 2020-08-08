#include<cstdio>
#include<cstring>
#include<set>
#include<iostream>
#define maxn 10005

 
using namespace std;

int edge[maxn][maxn];//���ڴ洢�ߵ���Ϣ
 
int main(){
	int N,M,K;
	cin >> N >> M;
	int i,j,k;
	int ver1,ver2; 
	for(i = 0;i<M;i++){
		cin >> ver1 >> ver2;
		edge[ver1][ver2] = 1;
		edge[ver2][ver1] = 1;
	}
	
	cin >> K;
	int query[maxn];
	//int color[maxn];//ע�������color��ȡֵ��Χ��maxn��֮������maxn����ԭ����N���ڵ㣬������N����ɫ 
	//����ʹ�����鲢�����ʣ���Ϊ����ɫ���ܳ����±�洢�������ֶδ������Խ���ʹ�� set �洢���ǳ�ֱ�ӡ���Ϊset�������ȥ�ء� 
	set<int> color;
	int flag ;
	for(i = 0 ;i< K;i++){
		//��ʼ����Ϣ 
		flag = 0;
		color.clear();
		//memset(color,0,sizeof(color));
				
		//������������ Ⱦɫ ��� 
		for(j = 0;j< N;j++){
			cin >> query[j];
			color.insert(query[j]) ;
		}
		
		//���д���
		//��Ϊ�Ǳ����ڵ㣬���ԱȽ�����Ӧ�ñ�����ɫ��Ϣ 
		for(j = 0;j< N ;j++){
			for(k= j+1 ; k < N; k++){
				if(edge[j][k] == 1 && query[j] == query[k] ){//˵����������֮���б� 			
						flag =1 ;
						break; 					
				}
			}
			if(flag == 1) {
				cout << "No" << "\n";
				break;	
			}
		}
		if(j == N){			
			cout << color.size() << "-coloring"<<"\n";
		}
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
4
0 1 0 1 4 1 0 1 3 0
0 1 0 1 4 1 0 1 0 0
8 1 0 1 4 1 0 5 3 0
1 2 3 4 5 6 7 8 10 9

*/
