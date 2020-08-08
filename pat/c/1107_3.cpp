#include <cstdio>
#include <algorithm>

using namespace std;
const int N = 1010;
int father[N];//��Ÿ��׽ڵ�
int isRoot[N] = {0};//��¼ÿ���ڵ��Ƿ���Ϊĳ�����ϵĸ��ڵ�
int course[N] = {0};//��ʼ��Ϊ0 
int findFather(int x){
	int a = x;
	while(x != father[x]){
		x = father[x];
	}
	while(a != father[a]){
		int z = a;
		a = father[a];
		father[z] = x;
	}
	return x;
} 

//�ϲ�a �� b���ڵļ��� 
void Union(int a ,int b){
	int faA = findFather(a);
	int faB = findFather(b);
	if(faA != faB){
		father[faA] = faB;
	} 
}

//��ʼ��father[i]Ϊi,��flag[i]Ϊfalse 
void init(int n){
	for(int i = 1;i <= n;i++){
		father[i] = i;//��ʼʱÿ���ڵ�ĸ��ڵ㶼���Լ� 
		isRoot[i] = false;
	}
}

bool cmp(int a,int b){
	return a> b;
}

int main(){
	int n,k,h;
	scanf("%d",&n);
	init(n);
	for(int i = 1;i<= n;i++){
		scanf("%d:",&k);
		for(int j = 0;j<k;j++){
			scanf("%d",&h);
			if(course[h] == 0){
				course[h] = i;
			}
			Union(i,findFather(course[h]));//�ϲ� 
		}
	}
	for(int i = 1;i <= n;i++){
		isRoot[findFather(i)]++;//i�ĸ��ڵ���findFather(i)��������1 
	} 
	int ans = 0;
	for(int i = 1;i<=n;i++){
		if(isRoot[i] != 0){
			ans++;//ֻͳ��isRoot[i]��Ϊ0 
		}
	} 
	printf("%d\n",ans);
	sort(isRoot+1,isRoot+n+1,cmp);
	for(int i = 1;i<= ans;i++){
		printf("%d",isRoot[i]);
		if(i<ans)	printf(" ");
	}
	return 0;
}

/*
8
3: 2 7 10
1: 4
2: 5 3
1: 4
1: 3
1: 4
4: 6 8 1 5
1: 4
**/

