#include<cstdio>
#include<iostream>
#define maxn 205
using namespace std;

//�洢����Ϣ 
int edge[maxn][maxn];

int main(){
	int Nv,Ne;
	cin >> Nv >> Ne;
	int i,j,k;
	int ver1,ver2;
	for(i = 0;i< Ne;i++){
		cin>> ver1 >> ver2;
		edge[ver1][ver2] = 1;
		edge[ver2][ver1] = 1;
	}
	int M,K;
	int query[maxn];
	int flag;
	cin >> M;
	for(i = 0; i< M;i++){
		cin >>K;
		flag = 0;//init value
		 
		for(j = 0;j< K;j++){
			cin >> query[j];
		}
		
		//˫��������鿴���еĶ����Ƿ�����ͨ�� 
		for(j = 0; j< K; j++){
			for(k = j+1; k< K; k++){
				if(edge[query[j]][query[k]] != 1){//˵������������֮��û�б� 
					flag = 1;
					break;
				} 
			}
			if(flag == 1){
				cout << "Not a Clique"<<"\n";	 
				break;	
			}
		}		
		
		if(j == K){//˵�����еĽڵ㶼�Ѿ����������ˣ���ʱ�����ж��Ƿ���Maximal 
			for(j = 1; j <= Nv; j++){ //ע��j���±��1��ʼ�������Ǵ�0 ��ʼ 
				for(k = 0;k < K;k++){
					if(edge[j][query[k]] != 1)	break;				
				}
				if(k == K){
					cout <<"Not Maximal"<<"\n";
					break;
				}
			}
			if(j > Nv){//˵����һ��Maximal Clique 
				cout <<"Yes"<<"\n";
			}
		}
	}
}
/*
8 10
5 6
7 8
6 4
3 6
4 5
2 3
8 2
2 7
5 3
3 4
6
4 5 4 3 6
3 2 8 7
2 2 3
1 1
3 4 3 6
3 3 2 1

*/
