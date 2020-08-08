#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

struct node{
	int child[10000];
	int curIndex = 0;//表示当前孩子数 
	int isVisit = 0;//初始化未访问 
};

node n[501]; 
int count = 0;//联通的节点数 

//判断图是否联通 
void isConnect(int root){
	if(n[root].isVisit == 1) return; 
	else {
		n[root].isVisit = 1;//设置为1
		count++;
	}
	for(int i = 0;i< n[root].curIndex;i++ ){//取所有的孩子 
		isConnect(n[root].child[i]);	 
	}
} 

int main(){
	int ver,edge;//the number of vertex ; the number of edge
	scanf("%d %d",&ver,&edge);
	int i ;
	int res[ver+1];
	int v1,v2;
	memset(res,0,sizeof(res));
		
	for(i = 0;i< edge;i++){
		scanf("%d %d",&v1,&v2);
		n[v1].child[n[v1].curIndex] = v2;
		n[v2].child[n[v2].curIndex] = v1;
		
		n[v1].curIndex++;
		n[v2].curIndex++;
		res[v1]++;
		res[v2]++;
	} 
	
	isConnect(1); 
	//cout << "count = "<< count<<endl;
	if(count != ver){
		cout << "Non-Eulerian" <<endl;		
	}
	else{
		//输出边的度数	
		int oddNum = 0;//度数为奇数的数目	 
		for(i = 1;i< ver+1;i++){
			if(res[i] % 2 != 0) oddNum++;
			cout << res[i];
			if(i != ver) cout << " ";
		}
		cout << endl;
		
		if(oddNum == 0){
			cout<< "Eulerian" << endl;
		}
		else if(oddNum == 2){
			cout<<"Semi-Eulerian"<< endl;
		}else{
			cout << "Non-Eulerian" << endl;
		}	
	}	
}
/*
1 0
1

7 12
5 7
1 2
1 3
2 3
2 4
3 4
5 2
7 6
6 3
4 5
6 4
5 6

1 0
1 

2 1
1 2

6 4
1 2
2 3
3 4
5 6

6 4
1 2
3 4
5 6
4 6
*/
 
