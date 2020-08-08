#include<cstdio>
#include<set>
#include<iostream>

using namespace std;
struct node{
	int address;
	int next = -1;
	int data;
	int order;
	bool operator<(const node &n)const{
		return n.order > order;
	}
};

node n[100005];
int main(){
	int root,N,K;//N���ܽ������ K�Ƿ�Χֵ
	scanf("%d %d %d",&root,&N,&K);
	int i ,j;	
	int address;
	for(i = 0;i< N ;i++){
		scanf("%d",&address);
		scanf("%d %d",&n[address].data,&n[address].next);
		n[address].address = address;
	} 
	int tempRoot = root;
	
	set<node> res; 
	node tempNode;
	int index = 0;
	while(tempRoot!=-1){//=-1��ʾ��ͷ 
		if(n[tempRoot].data < 0){
			tempNode.address = tempRoot;
			tempNode.data = n[tempRoot].data;			
			tempNode.order = index;
			index ++;
			res.insert(tempNode);//����set�� 
		}
		tempRoot = n[tempRoot].next; 
	}
	
	tempRoot = root;
	while(tempRoot != -1){//���� ֵ <= K��Ԫ��
		if(n[tempRoot].data <= K && n[tempRoot].data >= 0){
			tempNode.address = tempRoot;
			tempNode.data = n[tempRoot].data;	
			tempNode.order = index;
			index++;		
			res.insert(tempNode);//����set�� 
		}
		tempRoot = n[tempRoot].next; 	
	}
	
	tempRoot = root;
	while(tempRoot != -1){//���� ֵ <= K��Ԫ��
			if(n[tempRoot].data > K){
			tempNode.address = tempRoot;
			tempNode.data = n[tempRoot].data;
			tempNode.order = index;
			tempNode.next = -1;
			index++;			
			res.insert(tempNode);//����set�� 
		}
		tempRoot = n[tempRoot].next; 	
	}
	
	set<node>::iterator nextIt;
	set<node>::iterator backIt;
	for(set<node>::iterator it = res.begin();it!=res.end();it++){
		backIt=it;
		nextIt=++it;
		if(nextIt!=res.end())	printf("%05d %d %05d\n",backIt->address,backIt->data,nextIt->address);		
		else 	printf("%05d %d -1\n",backIt->address,backIt->data);
		//printf("backIt.data = %05d,nextIt.data = %05d\n",backIt->data,nextIt->data);		
		it=backIt;
	}
} 
