#include<cstdio> 
#include<cstring>
#include<cmath> 
#include<algorithm>
#include<map>
#define maxn 10002
using namespace std;

//所有节点的父节点 
int father[maxn];

//find the father node of a 
int findFather(int a){
	while(a != father[a]){
		a = father[a];
	}
	return a;
}

int unionFather(int a,int b){
	//分别找出节点a，b的父节点 
	int fa = findFather(a);
	int fb = findFather(b);
	father[max(fa,fb)] = min(fa,fb); 
}

int main(){
	int N;
	scanf("%d",&N);//the picture Num 
	int k;//the number of birds in this picture
	int i,j;
	int birdAll [maxn]; //all birds
	int birdNum = 0;//total birds number 
	int curBird;//the index of current bird
	int birdRow[maxn];// every input row of bird
	map<int,int> record;
	//init 
	for(i = 0;i< maxn;i++){
		father[i] = i;
	}
	//input
	for(i = 0;i< N ;i++){
		scanf("%d",&k);
		for(j = 0;j < k;j++){
			scanf("%d",&curBird);//输入鸟的下标 
			birdRow[j] = curBird;
			if(birdAll[curBird] == 0){
				birdNum ++;
				birdAll[curBird] = curBird;
			}
		}
		//将当前行的bird 合并到一起 
		for(j = 1;j < k;j++){
			unionFather(birdRow[0],birdRow[j]);
		}
	}
	
	int birdHerd = 0;//鸟群数 
	//是否需要遍历所有节点，才能得出鸟群数？ 	
	int tempRoot = 0; 
	for(i = 1;i <= maxn - 1 ;i++){		
		if(birdAll[i] == i)
		{
			tempRoot = findFather(birdAll[i]);
		}
		if(record.find(tempRoot) == record.end()){
			birdHerd ++;		
			record[tempRoot] = 1;			
		}
	}
	
	//printf("birdHerd = %d,birdNum = %d\n",birdHerd,birdNum);
	printf("%d %d\n",birdHerd,birdNum);
	int queryNum ;
	scanf("%d",&queryNum);
	int b1,b2;
	int fb1,fb2;	
	for(i = 1;i<= queryNum ;i++){
		scanf("%d %d",&b1,&b2);
		fb1 = findFather(b1);
		fb2 = findFather(b2);
		
		if(fb1 == fb2){
			printf("Yes\n");
		}
		else{
			printf("No\n");
		}		
	}			
}
/*
4
3 10 1 2
2 3 4
4 1 5 7 8
3 9 6 4
2
10 5
3 7


*/
