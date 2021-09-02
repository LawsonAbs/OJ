#include<iostream>
const int maxN = 5005;
using namespace std;

int fam[maxN];//节点i的家庭
 
//返回节点a 的根节点 
int find(int a){
	while(a!=fam[a]){
		a = fam[a];
	}
	return a;
}
 
//将节点a,b合并 成一个 
void union_(int a, int b ){
	int ra = find(a), rb = find(b);
	if( ra!=rb){
		fam[max(ra,rb)] = min(ra,rb); 
	}
}


int main(){
	int n,m,p;
	cin >> n >> m >> p;
	//初始化 
	for(int i = 1;i< n+1;i++){
		fam[i] = i;
	}
	int a,b;
	for (int i = 0;i< m ;i++){
		cin >> a >> b;
		union_(a,b); 
	}
//	for(int i = 1;i<= n;i++){
//		cout <<i<<","<< find(i)<<"\n";
//	}
	for (int i = 0;i<p;i++){
		cin >> a >> b;
		int ra = find(a) , rb = find(b); 
		if (ra== rb){
			cout << "Yes\n";
		}
		else{
			//cout <<ra<<" "<<rb<<", No\n";'
			cout << "No\n";
		}   
	}
}
/*
6 5 3
2 2
6 6
1 4
5 5
3 3
1 4
2 3
5 6

6 5 3
1 2
1 5
3 4
5 2
1 3
1 4
2 3
5 6
*/
