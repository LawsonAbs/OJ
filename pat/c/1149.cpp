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
	int N,M;//N�ǲ����ݵĻ���ԣ� M�Ǵ��ŵ���Ʒ 
	cin >> N >> M;
	
	int a,b;//�������ݵ��������� 
	for(i = 0;i< N ;i++){	
		cin >> a >> b; //����a,b������ 
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
		
		//��ʼ�ж���Щ��Ʒ�Ƿ��ܹ�����һ��
		int curGoods;
		int flag = 0;
		for(set<int>::iterator it=goods.begin();it!=goods.end();it++){
			curGoods = *it;//��ʾ�ĵ�ǰ����Ʒ 
			for(k = 0;k < imp[curGoods].size();k++){
				if(goods.find( imp[curGoods][k] ) != goods.end()) {//����ҵ��ˣ�˵���г�ͻ 
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
