#include <cstdio>
#define maxn 1000

int n,m;//������ ����������
int father[maxn];

//��ʼ������ 
void init(){
	int i;
	for(i = 0;i <= n; i++){
		father[i] = i;//��ʼ��---ÿ���ڵ�ĸ��ڵ�Ϊ�ýڵ㱾�� 
	}
}

int findFather(int x){
	//���������ѭ���ҳ����ĸ��� 
	while(x != father[x]){
		x = father[x];
	}
	return x;
}

void Union(int a,int b){
	int faA = findFather(a);
	int faB = findFather(b);	
	//�ǲ���ͬһ�����ȣ�����ǣ���faA ����������ΪB 
	if(faA != faB){		
		father[faA] = faB;
	}
} 

int main(){		
	int i,j;
	scanf("%d %d",&n,&m); 
	init(); 
	int a,b;//a��b�����ѹ�ϵ 
	for(i = 0;i < m;i++){
		scanf("%d %d",&a,&b);
		Union(a,b);
	} 
	
	int group = n; 
	for(i = 1;i<= n;i++){
		printf("father[%d] = %d\n",i,father[i]);
		if(father[i]!=i)
			group --;
	}
	printf("\ngroup = %d",group);	
}
/*
3 2
1 3 
3 4

5 3
1 4
3 5
4 2 


5 3
4 2
1 4
3 5


6 4
1 4
3 5
4 2
5 6
*/
