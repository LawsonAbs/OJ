#include<cstdio>
#include<iostream>
#define maxn 205
using namespace std;

//存储边信息 
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
		
		//双层遍历，查看所有的顶点是否都是联通的 
		for(j = 0; j< K; j++){
			for(k = j+1; k< K; k++){
				if(edge[query[j]][query[k]] != 1){//说明这两个顶点之间没有边 
					flag = 1;
					break;
				} 
			}
			if(flag == 1){
				cout << "Not a Clique"<<"\n";	 
				break;	
			}
		}		
		
		if(j == K){//说明所有的节点都已经遍历结束了，这时候再判断是否是Maximal 
			for(j = 1; j <= Nv; j++){ //注意j的下标从1开始，而不是从0 开始 
				for(k = 0;k < K;k++){
					if(edge[j][query[k]] != 1)	break;				
				}
				if(k == K){
					cout <<"Not Maximal"<<"\n";
					break;
				}
			}
			if(j > Nv){//说明是一个Maximal Clique 
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
