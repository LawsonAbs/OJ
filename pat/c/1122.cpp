#include<cstdio>
#include<iostream>
#include<cstring> 
#include<set>
#define maxn 2005
//��Ϊmaxn����������ѯ����ģ������䷶Χ���ܻ�Ƚϴ󣬿��ܻᳬ��200 

using namespace std;

int edge[maxn][maxn];//ʹ���ڽӾ����ߵ���Ϣ 
//��Ҫע����ǣ�������������Ǵ� 0 -> (N-1) ����ô���ǿ���ʹ��edge[N][N]��Ϊ�洢
//����������������Ǵ� 1 -> N ����ô�ͱ����� edge[N+1][N+1]���������ֶδ���
//�������ʹ�õ��� maxn ��Ϊ�洢 
 
int main(){
	int  N,M,K;
	cin >> N>>M;
	int i,j,z;	
	int ver1,ver2; 
	set<int> vertex;
	for(i = 0;i< M;i++){
		cin >> ver1 >> ver2;
		edge[ver1][ver2] = 1;//�б� 
		edge[ver2][ver1] = 1;//�б� 
	}
	
	cin >> K;
	int verNum;
	int query[maxn];
	for(i = 0;i< K;i++){
		cin >> verNum;		 
		memset(query,0,sizeof(query));//����Ϊ0 
		vertex.clear();		
		for(j = 0;j < verNum;j++){
			cin >> query[j];
			vertex.insert(query[j]);
		}
		if(verNum != (N+1) || query[0] != query[N] || vertex.size()!=N) {//�Ƿ� simple || ��������յ㲻ͬ������cycle ||������漰�����еĽڵ� 
			cout <<"NO\n";
		}
		else{//���ʱ��Ž����ж�
			for(z = 0; z < verNum -1; z++) {
				//cout <<  query[z]<<" ";
				if(edge[query[z]][query[z+1]] != 1){				
					cout <<"NO\n";
					break;
				}				
			}
			if(z == verNum - 1){
				cout <<"YES\n";
			}
		}
	}
}
/*
6 10
6 2
3 4
1 5
2 5
3 1
4 1
1 6
6 3
1 2
4 5
6
7 5 1 4 3 6 2 5
6 5 1 4 3 6 2
9 6 2 1 6 3 4 5 2 6
4 1 2 5 1
7 6 1 3 4 5 2 6
7 6 1 2 5 4 3 1

6 10
6 2
3 4
1 5
2 5
3 1
4 1
1 6
6 3
1 2
4 5
1
7 1 2 1 2 1 2 1

6 10
6 2
3 4
1 5
2 5
3 1
4 1
1 6
6 3
1 2
4 5
1
7 1 6 1 2 1 2 1


6 10
6 2
3 4
1 5
2 5
3 1
4 1
1 6
6 3
1 2
4 5
1
7 1 1 1 1 1 1 1

3 1
1 2
1
4 1 2 3 1

3 2
1 2
2 3
1
4 1 2 3 1


3 3
1 2
2 3
1 3
1
4 1 2 3 1


6 10
6 2
3 4
1 5
2 5
3 1
4 1
1 6
6 3
1 2
4 5
1
7 1 2 5 1 2 5 1
*/ 
