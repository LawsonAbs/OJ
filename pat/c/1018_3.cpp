#include <iostream>
#include <vector>
 
using namespace std;
 
const int SIZE = 501;
int map[SIZE][SIZE];
 
struct Node{
	Node(){
	    num =0;
	    dis =-1;
	    cnt = 0;
	    visited = false;
	}
	int num;
	unsigned int dis;
	int cnt;
	bool visited;
};
 
Node stations[SIZE]; 
vector <int> v;
vector <int> s;
int lastacc=0;
int lastsize = 1;
unsigned int lastdis = -1;
int Cmax;
float lastdiff;
void findpath(int cur,int d,int dis,int n,vector<int > &v){
	if(dis > lastdis)
	    return;
	if(cur == d ){
		if(dis <= lastdis){
			lastdis = dis;
			int acc=0,size=1;
			vector<int>::iterator iter=v.begin();
			while(iter != v.end()){
				acc += stations[*iter].num;
				iter++;
			}
			size = iter - v.begin();
			float diff = acc*1.0/size - Cmax/2;
			diff = diff >0 ? diff:-diff;
			if(diff < lastdiff){
				s=v;
				lastacc=acc;
				lastsize = size;
				lastdiff = diff;
			}
		}
		return;
	}
 
	for(int j=1;j<=n;j++){
		if(map[cur][j] != -1 && !stations[j].visited){
			stations[j].visited = true;
			v.push_back(j);
//			dis += map[cur][j];
			findpath(j,d,dis+map[cur][j],n,v);
//			dis -= map[cur][j];
			stations[j].visited = false;
			v.pop_back();
		}
	}
}
 
void display(int r,vector<int> s,int r2){
	printf("%d 0",r);
	vector <int>::iterator iter = s.begin();
	while(iter != s.end()){
		printf("->%d",*iter);
		iter++;
	}
	printf(" %d\n",r2);
}
 
int main()
{
	int N,Sp,M;
//	freopen("test.txt","r",stdin);
	scanf("%d%d%d%d",&Cmax,&N,&Sp,&M);
	lastdiff = Cmax/2;
	for(int i=1;i<=N;i++){
		scanf("%d",&stations[i].num);
	}
	for(int i=0;i<=N;i++)
	    for(int j=0;j<=N;j++){
	    	map[i][j] = -1;
	    	map[j][i] = -1;
		}
	for(int i=0;i<=N;i++)
	    map[i][i] = 0;
	    
	for(int i=0;i<M;i++){
		int c1,c2,t;
		scanf("%d%d%d",&c1,&c2,&t);
		map[c1][c2] = t;
		map[c2][c1] = t;
	}
//	Dijkstra(map,stations,N);         //calculate the shortest path	
 
	findpath(0,Sp,0,N,v);
//    cout <<lastdiff <<' ' <<lastacc <<' ' <<endl;
    int remain;
    if(lastdiff <=Cmax/2){
    	remain = lastsize *Cmax/2 - lastacc;
    	display(remain,s,0);
	}else{
		remain = lastacc - lastsize *Cmax/2;
		display(0,s,remain);
	}
        
	return 0;
}
/*
10 3 3 5
16 17 0
0 1 1
0 2 1
0 3 3
1 3 1
2 3 1

10 3 3 5
6 7 0
0 1 1
0 2 1
0 3 3
1 3 1
2 3 1

*/
