#include<cstdio>
#include<algorithm>
#include<cstring> 
#include<iostream> 

#define maxn 1005 

using namespace std;

int info[maxn][maxn];

int main(){
	int verNum,edgeNum;	
	cin >> verNum >> edgeNum;
	int i ,j ,k;
	
	int ver1,ver2;
	int deg[maxn];//表示每个节点的度
	memset(deg,0,sizeof(deg));
	
	for(i = 0;i< edgeNum;i++){
		cin >> ver1 >> ver2;//输入的是有向边 
		info[ver1][ver2] = 1;
		deg[ver2]++;//ver2的度数+1 
	}
	
	int query[maxn];
	int queryNum;
	cin >> queryNum;
	int res[maxn];
	int index = 0;
	for(i = 0;i< queryNum;i++ ){
		for(j = 0;j< verNum;j++){
			cin >> query[j];	
		}
		
		//开始处理各个序列 
		int degBak[maxn];
		for(j = 0;j < verNum + 1; j++){
			degBak[j] = deg[j];
		}
		
		for( j = 0; j< verNum; j++){
			if(degBak[ query[j] ]!=0){//如果入度不为0，则说明不是拓扑排序 
				res[index++] = i;				
				break; 
			}			
			for(k = 1; k <= verNum;k++){
				if(info[query[j]][k] == 1 )//说明顶点 k -> query[j] 之间有边
				{					
					degBak[k]--;//入度减一 
				}
			}
		}
	}
	
	for(i = 0;i< index;i++){
		if (i!=index -1) cout << res[i]<<" ";
		else cout << res[i];
	}	
}
/*

*/
