#include<cstdio>
#include<set>
#include<vector>
#include<cmath>
#include<iostream>
#define maxn 100005

using namespace std;

vector<int> imp[maxn];

int main(){
	int i,j,k;
	int N,M;//N是不兼容的货物对； M是待放的商品 
	cin >> N >> M;
	
	int a,b;//代表不兼容的两个货物 
	for(i = 0;i< N ;i++){	
		cin >> a >> b; //输入a,b两个数 
		//cout << min(a,b);		
		imp[min(a,b)].push_back(max(a,b)); 
	} 
	
	set<int> goods;
	int goodNum;
	for(i = 0;i< M;i++){
		cin >> goodNum;
		goods.clear();
		for(j = 0;j< goodNum;j++){
			cin >> a;
			goods.insert(a);
		}
		
		//开始判断这些商品是否能够放在一起
		int curGoods;
		int flag = 0;
		for(set<int>::iterator it=goods.begin();it!=goods.end();it++){
			curGoods = *it;//表示的当前的商品 
			for(k = 0;k < imp[curGoods].size();k++){
				if(goods.find( imp[curGoods][k] ) != goods.end()) {//如果找到了，说明有冲突 
					cout <<"No" << "\n"; 
					flag = 1;
					break;
				}				
			}
			if(flag == 1) break;
		}
		if(flag == 0) cout << "Yes" << "\n";
		
	}
}
/*
6 3
20001 20002
20003 20004
20005 20006
20003 20001
20005 20004
20004 20006
4 00001 20004 00002 20003
5 98823 20002 20003 20006 10010
3 12345 67890 23333

*/
