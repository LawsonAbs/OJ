#include <cstdio>
#include <algorithm>
using namespace std;
//#define maxSize 100001
const int maxSize = 100003;

typedef struct{
	int data;//ֵ��
	int next;//ָ����ֵ 
	int location;//�Լ���λ�� 		
}Lnode;//����ڵ� 

//����ȽϺ��� 
bool cmp(Lnode a,Lnode b){
	return	a.data < b.data;
}

int main(){
	int number;//����������
	int startLocation; //��ʼλ��
	Lnode node[maxSize];//����һ��LNode������
	Lnode trueNode[maxSize];//��������������
	 
	scanf("%d %d",&number,&startLocation);	
	int i,j=-1;//ѭ�� 
	int count = 0;//��ʾ�������������Ŀ 	
	for(i = 0;i<number;i++){
		scanf("%d%d%d",&node[i].location,&node[i].data,&node[i].next);//��������ֵ 			
		if(node[i].location == startLocation){
			j = i;//�ҳ�ͷ�ڵ���±�			
		}
	} 
	if(j == -1){//˵��û����startLocation��ʼ�Ľڵ� 
		printf("0 -1");
		return 0;//ֱ�ӽ��� 
	} 
	
	//��ͷ�ڵ㿪ʼ�������ҳ����в���������Ľڵ�		
	while(node[j].next !=-1 ){		
		int k ;//�������� 
		for(k = 0;k< i;k++){
			if(node[k].location == node[j].next){
				trueNode[count++] = node[j]; //�ƶ����µĽṹ���� 
				j = k;//��ֵ 
			}							
		}
	}	
	trueNode[count] = node[j];//�����һ�ֵ 
	
	
	sort(trueNode,trueNode+count+1,cmp);//ʹ��sort���� 	
	printf("%d %05d\n",count+1,trueNode[0].location);
	//����������һ���Ҫ�ж��Ƿ���ѭ��������һ�д���Ƿ���ȷ�� 
	for(int j = 0;j < count + 1;j++){
		if(j != count){
			printf("%05d %d %05d\n",trueNode[j].location,trueNode[j].data,trueNode[j+1].location);	
		}
		else
		{
			printf("%05d %d -1\n",trueNode[j].location,trueNode[j].data);
		}		
	}			
}
/**
5 00001
11111 100 -1
00002 0 -1
33333 100000 11111
12345 -1 33333
22222 1000 12345

2 00001
00001 0 22222
22222 1000 12345
**/
