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
	int deg[maxn];//��ʾÿ���ڵ�Ķ�
	memset(deg,0,sizeof(deg));
	
	for(i = 0;i< edgeNum;i++){
		cin >> ver1 >> ver2;//������������ 
		info[ver1][ver2] = 1;
		deg[ver2]++;//ver2�Ķ���+1 
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
		
		//��ʼ����������� 
		int degBak[maxn];
		for(j = 0;j < verNum + 1; j++){
			degBak[j] = deg[j];
		}
		
		for( j = 0; j< verNum; j++){
			if(degBak[ query[j] ]!=0){//�����Ȳ�Ϊ0����˵�������������� 
				res[index++] = i;				
				break; 
			}			
			for(k = 1; k <= verNum;k++){
				if(info[query[j]][k] == 1 )//˵������ k -> query[j] ֮���б�
				{					
					degBak[k]--;//��ȼ�һ 
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
