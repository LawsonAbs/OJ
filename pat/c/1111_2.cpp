#include<cstdio> 
#include<iostream>
#include<algorithm>

#define maxn 510  
#define INF 0x3fffffff 
using namespace std;

int N,M;
int L[maxn][maxn];//用一个邻接矩阵存储地图节点之间的距离 
int T[maxn][maxn];//存储的是两者的时间 
int d[maxn];//表示的是源点到其它点的距离
int dd[maxn];//表示的是该点的上一个节点 
int t[maxn];//表示的是源点到其它点的时间
int td[maxn];//表示的是该点的上一个节点
int w[maxn];//点权
bool isVisit[maxn];//表示的是这些节点是否已经访问过 

//使用dijkstra 算法求出最短距离 
//传入的参数是 源点的下标 
void dijkstraPath(int s){		
	//先找出源点到节点最短的节点u
	int u = -1; //初始时为-1 
	int minValue = INF; 		
	for(int i = 0;i < N;i ++ ){
		if(d[i] < minValue && isVisit[i] == false){
			minValue = d[i];
			u = i;//记录最小距离的这个城市的id 
		}
	}
	
	if(u == -1) return ;//说明所有的节点都已经访问过了 	
	d[u] = minValue;
	isVisit[u] = true;//标记已访问
	//用节点u更新最短距离 
	for(int j = 0;j< N;j++){
		if(isVisit[j] == false && d[u] + L[u][j] < d[j]){
			d[j] = d[u] + L[u][j];//更新最短距离
			t[j] = t[u] + T[u][j];//更新时间  !!!! 十分重要，一定要更新！ 
			dd[j] = u;//更新上一个节点 
		}
		else if(isVisit[j] == false && d[u] + L[u][j] == d[j]){//如果距离相等 
			if(t[j] > t[u] + T[u][j]) {//如果t[j]  
			//	cout <<"I'm here' "<<"\n"; 
				t[j] = t[u] + T[u][j];//更新时间
				dd[j] = u;//取时间最短 
			}
		}
	}  
}
  
  
void dijkstraTime(int s){		
	//先找出源点到节点最短的节点u
	int u = -1; //初始时为-1 
	int minValue = INF; 		
	for(int i = 0;i < N;i ++ ){
		if(t[i] < minValue && isVisit[i] == false){
			minValue = t[i];
			u = i;//记录最小距离的这个城市的id 
		}
	}
	
	if(u == -1) return ;//说明所有的节点都已经访问过了 
	//cout << u <<"\n";
	t[u] = minValue;
	isVisit[u] = true;//标记已访问
	//用节点u更新最短距离 
	for(int j = 0;j< N;j++){
		if(isVisit[j] == false && t[u] + T[u][j] < t[j]){
			t[j] = t[u] + T[u][j];//更新最短距离
			w[j] = w[u] + 1;//更新权重 
			td[j] = u;//更新上一个节点 
		}
		else if(isVisit[j] == false && t[u] + T[u][j] == t[j]){//如果时间相等 
			if(w[j] > w[u] + 1) {//取过路数最少 
				w[j] = w[u] + 1;
				td[j] = u;
			}
		}		
	}  
}



void init(){
	fill(L[0],L[0]+maxn * maxn,INF);//初始化L 
	fill(T[0],T[0]+maxn * maxn,INF);//初始化T
	fill(d,d+maxn,INF);//初始化单点距离 
	fill(t,t+maxn,INF);//初始化单点时间 	
	fill(w,w+maxn,INF);//点权
	fill(isVisit,isVisit+maxn,false);// 将isVisit数组初始化为false 
}

int main() {	
	init(); 
	int sour,des;//sour是源点 ,des是终点 
	cin >> N >> M ;
	int i,j;
	int v1,v2, isOneWay, length,time;
	for(i = 0;i< M;i++){
		cin >> v1 >> v2 >> isOneWay >> length >> time;
		L[v1][v2] = length;//两者之间的距离		
		L[v2][v1] = length;		
		T[v1][v2] = time;//两者之间的时间 
		T[v2][v1] = time;				
	}
	
	cin >> sour >> des;//输入源点，终点 	
	d[sour] = 0;//初始化，让源点到源点自身的距离为0	
	dd[sour] = sour;//初始化前节点 
	
	t[sour] = 0;//初始化，让源点到源点自身的距离为0	
	td[sour] = sour;//初始化前节点 
	w[sour] = 1;
	//这个for循环也可以写在dijkstra里面 
	for(i = 0;i< N;i++){ 			
		dijkstraPath(sour); 			
	}	
	
	fill(isVisit,isVisit+maxn,false);
	for(i = 0;i< N;i++){ 				
		dijkstraTime(sour); 
	}

	//============== 输出距离 ==============		
	int res[maxn] ;//用于保存结果路径的值 
	int index1 = 0;
	int tempDes = des;
	res[index1++] = tempDes; //加入终点 
	while(dd[tempDes]!=tempDes){				
		tempDes = dd[tempDes];//更新des的值 
		res[index1++] = tempDes; 	
	}		
	
	// ============ 输出时间 ============	
	int res2[maxn] ;//用于保存结果路径的值 
	int index2 = 0;
	tempDes = des;
	res2[index2++] = tempDes; //加入终点 
	while(dd[tempDes]!=tempDes){				
		tempDes = td[tempDes];//更新des的值 
		res2[index2++] = tempDes; 	
	}		
	
	if(index1 == index2){//如果两个下标相等  ，判断内容是否相等 
		for(i = 0;i < index1 ;i++){
			if(res[i] != res2[i] ) break;
		} 
	}
	
	if(i == index1){//说明是相同的路径 
		cout <<"Distance = "<< d[des]<<"; " << "Time = " << t[des]<<": ";
		for(i = index1-1;i >=0 ;i--){
			if(i != 0)	cout << res[i] <<" -> ";
			else cout << res[i] ;
		} cout <<"\n";		
	}
	else {
		cout <<"Distance = "<< d[des]<<": ";
		for(i = index1-1;i >=0 ;i--){
			if(i != 0)	cout << res[i] <<" -> ";
			else cout << res[i] ;
		} cout <<"\n";
		
		cout <<"Time = " << t[des]<<": ";
		for(i = index2-1;i >=0 ;i--){
			if(i != 0)	cout << res2[i] <<" -> ";
			else cout << res2[i] ;
		} cout <<"\n";
	} 	
}
/*
4 4
0 1 0 1 1
2 3 0 2 2
2 1 1 1 1
1 3 0 3 1
0 3

5 5
0 1 0 1 1
2 3 0 2 2
2 1 1 1 1
1 3 0 3 1
3 4 0 2 2
0 4


5 5
0 1 0 1 1
2 3 0 2 2
2 1 1 1 1
1 3 0 3 5
3 4 0 2 2
0 4
*/
