#include<cstdio>
#include<set>
#include<cstring>
#include<iostream>

#define maxn 205
using namespace std;

int main(){
	set<int> ver[maxn];
	set<int> bak[maxn];
	int verNum,edgeNum;
	int M;	
	cin >> verNum >> edgeNum;
	
	int i,j;
	int left,right;
	for(i = 0;i< edgeNum;i++){
		cin >>left >> right;//�������������ڵ�
		 
		ver[left].insert(right);
		ver[right].insert(left); 
	}

	int query[maxn];//�����飬��Ҫ��set 
	int vertex;
	int queNum;
	cin >>M ;
	for (i = 0;i< M ;i++){
		cin >> queNum;
		//cout <<"queNum = "<< queNum <<endl;
		memset(query,0,sizeof(query));
		for(j = 0;j< queNum;j++){
			cout<< query[j]<<" ";
		}cout<<"\n";
		for(j = 0;j< queNum;j++){
			cin >> query[j];	
		}
							
		int flag  = 0;		
		for(j = 0; j < queNum ; j++){
			int curVer = query[j];
			//cout << "curVer = "<< curVer<<"\n";
			for(int k = 0;k< queNum ;k++){
				if(k != j){
					//��query[k] �����жϣ�������е� query[k] k!=j �ܹ���ver���ҵ���
					//��˵����һ�� clique 
					if(ver[curVer].find(query[k]) == ver[curVer].end()){//˵������һ��Clique 			
						flag = 1;
						break;
					}	
				}					
			} 
			if(flag == 1){
				break;
			}
		}
		if(flag == 1)	cout << "Not a Clique"<< "\n";
		if(flag == 0){	
		    //�ж��Ƿ���һ��Maximal Clique��			
			for(set<int>::iterator it = ver[curVer].begin();it!=ver[curVer].end();it++){								
				cout << "curVer = "<< curVer<<"\n";
				for(int k = 0;k< queNum ;k++){
					if(k != j){
						//��query[k] �����жϣ�������е� query[k] k!=j �ܹ���ver���ҵ���
						//��˵����һ�� clique 
						if(ver[curVer].find(query[k]) == ver[curVer].end()){//˵������һ��Clique 			
							flag = 1;
							break;
						}	
					}					
				} 
				if(flag == 1){
					break;
				}
			}			
			cout << "Yes"<< "\n";
		}	
	}
} 
