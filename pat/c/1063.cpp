#include <cstdio>
#include <set>
using namespace std;

const int N = 51;
set<int> st[N];//N������

void compare(int x,int y){//�Ƚ�set[x]��set[y] 
	int totalNum = st[y].size(),sameNum = 0;
	
	//��������st[x]
	for(set<int>::iterator it = st[x].begin();it !=st[x].end();it++){
		if(st[y].find(*it) != st[y].end())
			sameNum++;
		else
			totalNum++;//��st[y]�в����ҵ���Ԫ�� 			
	} 
	printf("%.1f%\n",sameNum * 100.0 / totalNum) ;//������� 
} 

int main(){
	int n,k,q,v,st1,st2;
	
	scanf("%d",&n);//���ϸ��� 
	for(int i = 1;i <= n;i++){
		scanf("%d",&k);//����Ԫ���еĸ��� 
		for(int j = 0;j<k;j++){
			scanf("%d",&v);
			st[i].insert(v); //��Ԫ�ز��뵽������	
		}		
	} 
	
	//q����ѯ 
	scanf("%d",&q);
	for(int i = 0;i<q;i++){
		scanf("%d%d",&st1,&st2);
		compare(st1,st2);
	}
	return 0;
} 
/*
3
3 99 87 101
4 87 101 5 87
7 99 101 18 5 135 18 99
2
1 2
1 3
*/ 
