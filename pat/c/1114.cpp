#include<cstdio> 
#include<algorithm>
#include<cstring>

#define N 10
using namespace std;

//��Ա�Լ���id���±���� 
struct people{	
	int fatherId = 0;//��ʼ��ֵΪ 0
	int montherId = 0;
	int childNum;
	int child[N];//�洢���� id������ 
	int estNum;//estate number
	int area;//the estate area 
	int isVisit = 0;//�Ƿ���ʹ�  & ��ʼ��Ϊδ���� 
};
//�����isVisit �������ڱ����Ƿ���һ���˵�ѡ�� 

people peo[10001];
int node[N];//���ڴ洢�ڵ���±�  

int minChild = 9999;
int traverseCount = 0;//��ʾ�ѱ������ڵ������ 
int familyCount = 0;//��ʾ��ͥ��Ա 
double estTotal = 0;//��ʾ���������� 
double areaTotal = 0;//�������ܶ� 

//���ڼ������Ľ�� 
struct result{
	int id;//��Сid 
	double avgSet;//ƽ���ʲ��� 
	double avgArea;//ƽ����С 
	int familyNum;//�� family ���� 
};

result res[1000] ;

//��ȱ��� -> �������������estTotal �� areaTotal 
void dfs(int root){
	if(peo[node[root]].isVisit == 1)//����Ѿ����ʹ�����ֱ�ӷ��� 
		return ;
	familyCount ++;
	int father = -1,mother = -1;//����&��ʼ����������	
	
	//���root����Ӧ�Ľڵ㲻���� =>  ��ʼ����ֵ0
	if(peo[root].fatherId == 0 ) return ;
	if(peo[root].montherId == 0 ) return ;
		
	father = peo[root].fatherId;
	mother = peo[root].montherId;
	
	//�����С��id ����С��father,  mother ���� -1 
	if(father < minChild){
		if(father != -1)
		minChild = father;
	}
	if(mother < minChild){
		if(mother != -1)
		minChild = mother;
	}
	if(root < minChild){
		minChild = root;
	}

	for(int i = 0;i< peo[root].childNum;i++){
		if (peo[root].child[i] < minChild){
			minChild = peo[root].child[i];
		}
	}
	peo[root].isVisit = 1;
	estTotal += peo[root].estNum ;//����������� 
	areaTotal += peo[root].area;//���area���� 

	//�ȱ�����ĸ 
	if(father!=-1 && peo[father].isVisit != 1) 	dfs(father);
	if(mother!=-1 && peo[mother].isVisit != 1)	dfs(mother);	
	
	//�ٱ�������
	int child;
	for(int i = 0;i< peo[root].childNum;i++) {
		child = peo[root].child[i];
		if(peo[child].isVisit != 1) 	dfs(child);
	}	
}

//compare rule
int cmp(result r1,result r2){
	if(r1.avgArea == r2.avgArea)
		return r1.id < r2.id;
	return r1.avgArea > r2.avgArea;		
}

int main(){
	int n ;
	scanf("%d",&n);	
	int i,j;
	int curId;
	for(i = 0;i< n;i++){
		scanf("%d",&curId);	
		node[i]	= curId;
		scanf("%d %d %d",&peo[curId].fatherId,&peo[curId].montherId,&peo[curId].childNum);
		for(j = 0; j< peo[curId].childNum; j++){
			scanf("%d",&peo[curId].child[j]);
		}
		scanf("%d %d",&peo[curId].estNum,&peo[curId].area);
		peo[curId].isVisit = 0;//assign to 0 to denote don't access
	}
	
	//������� 
	printf("====test printf======\n");
	for(i = 0;i< n;i++){						
		curId = node[i];
		printf("%d %d %d %d ",curId,peo[curId].fatherId,peo[curId].montherId,peo[curId].childNum);
		for(j = 0; j< peo[curId].childNum; j++){
			printf("%d ",peo[curId].child[j]);
		}
		printf("%d %d %d\n",peo[curId].estNum,peo[curId].area,peo[curId].isVisit);	
	}
		
	int index = 0;	
	//while(true){ // �����for ѭ��������ʹ��whileѭ���ĵ��� 
	for(i = 0; i< n;i++){		
		minChild = 9999;		
		traverseCount += familyCount;	
		familyCount = 0;//һ����ͥ�ж�����Ա 
		if(traverseCount >= n) {//���С���ܵýڵ��� 
			break;
		}
		dfs(node[i]);
		//����Ϊֹ�����е�һ�� family �Ľڵ㶼�Ѿ����������� 	
		res[index].id = minChild;
		res[index].avgSet = estTotal / familyCount;
		res[index].avgArea = areaTotal / familyCount; 
		res[index].familyNum =  familyCount;
		index ++;
	}
	
	sort(res,res+index,cmp);
	printf("%d\n",index);
	for(i = 0;i< index;i++ ){
		printf("%d %d %.3f %.3f",res[i].id,res[i].familyNum,res[i].avgSet,res[i].avgArea);		
	}	
}
/*
10
6666 5551 5552 1 7777 1 100
1234 5678 9012 1 0002 2 300
8888 -1 -1 0 1 1000
2468 0001 0004 1 2222 1 500
7777 6666 -1 0 2 300
3721 -1 -1 1 2333 2 150
9012 -1 -1 3 1236 1235 1234 1 100
1235 5678 9012 0 1 50
2222 1236 2468 2 6661 6662 1 300
2333 -1 3721 3 6661 6662 6663 1 100

7
1234 5678 9012 1 0002 2 300
1235 5678 9012 0 1 50
9012 -1 -1 3 1236 1235 1234 1 100
2222 1236 2468 2 6661 6662 1 300
2468 0001 0004 1 2222 1 500
2333 -1 3721 3 6661 6662 6663 1 100
3721 -1 -1 1 2333 2 150


3
1234 5678 9012 1 0002 2 300
9012 -1 -1 3 1236 1235 1234 1 100
1235 5678 9012 0 1 50
*/
