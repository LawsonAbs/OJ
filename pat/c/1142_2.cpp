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
		cin >>left >> right;//输入左右两个节点
		 
		ver[left].insert(right);
		ver[right].insert(left); 
	}

	int query[maxn];//用数组，不要用set 
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
					//对query[k] 进行判断，如果所有的 query[k] k!=j 能够在ver中找到，
					//则说明是一个 clique 
					if(ver[curVer].find(query[k]) == ver[curVer].end()){//说明不是一个Clique 			
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
		    //判断是否是一个Maximal Clique？			
			for(set<int>::iterator it = ver[curVer].begin();it!=ver[curVer].end();it++){								
				cout << "curVer = "<< curVer<<"\n";
				for(int k = 0;k< queNum ;k++){
					if(k != j){
						//对query[k] 进行判断，如果所有的 query[k] k!=j 能够在ver中找到，
						//则说明是一个 clique 
						if(ver[curVer].find(query[k]) == ver[curVer].end()){//说明不是一个Clique 			
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
