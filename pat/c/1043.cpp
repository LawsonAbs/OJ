#include <stdio.h>
#define null NULL
typedef struct BiTree{
	struct BiTree *lChild,*rChild;//������ָ��
	int data;//������ 
}BiTree;


//��������---����һ�ö��������� 
//Ҫ���������temp(��ʵ����bt)��Ϊʲôʹ����&temp��������ܹ�������������ԭ���ǣ�
//ʹ�õݹ���������temp�ĳ�ʼֵû�б仯�����ڵݹ�Ĺ����н�����һ�ö������� 
void insertBiTree_1(BiTree *&temp,int da){
	//������ڵ�Ϊ�� 
	if(temp == NULL){
		temp = new BiTree;//ָ��һ���½ڵ� 
		temp->data = da; 
		temp->lChild = null;
		temp->rChild = null; 
		return;
	}	
	if(da < temp->data) insertBiTree_1(temp->lChild,da);//���ʱ��temp->lChild���Ѿ�������ָ���ϵ 
	else insertBiTree_1(temp->rChild,da);
} 

/**
//��������-->����һ�ö�����
//�����ӲҪʹ�����ַ�ʽ������һ�ö���������ô����Ҫһ��ͷ��� 
void insertBiTree_2(BiTree *&temp,int da){	
	//BiTree *temp;
	//temp = bt;
		
	//���ҵ����ʵ�λ��--->���˵temp��Ϊnull 
	//������һ��while(temp!=null)ѭ����ԭ�򣺿���������������Ҳ������������ 
	while(temp!=NULL){	
		if(temp->data < da ) {//��Ҫѭ�������Ƿ�Ϊnull
			temp = temp->rChild;
		}
		else if( temp != null && temp->data > da ){//��Ҫѭ�������Ƿ�Ϊnull 
			temp = temp->lChild;
		}		
	}
	if(temp == null){
		temp = new BiTree; 
		temp->data = da;//��������
		temp->lChild = null;
		temp->rChild = null;	
	}	
} 
**/ 


//�������������
void preOrderBiTree(BiTree *T){
	if(T!=null){
		printf("%d ",T->data);	
	}
	else	return ;//������ֹ�ݹ�--->�ݹ�����߽� 
	preOrderBiTree(T->lChild);//�ݹ������� 
	preOrderBiTree(T->rChild);//�ݹ������� 
}

void insertBiTree_2(BiTree *&bt,int da){	
	//���ж����Ƿ�Ϊ��-->���Ϊ�գ�������ֱ�ӷ��� 
	if(bt==null){	
		bt = new BiTree;//��Ϊ��main�����У�bt��null��������Ҫ������ָ��һ���ڵ㣬�����ڸýڵ��ϸ�ֵ������ 
		bt->data = da;
		bt->lChild = null;
		bt->rChild = null;
		return ;
	} 	
	BiTree *pre;//̽��ָ��
	pre = bt;
	
	BiTree *follow;//����ָ��
	follow = bt;
			
	int flag = -1; 
	while(pre!=NULL){	
		if(pre->data <= da ) {//��Ҫѭ�������Ƿ�Ϊnull
			follow = pre;//�ݴ�ֵ 
			pre = pre->rChild; //�仯����follow!!
			flag = 1;
		}
		else if( pre != null && pre->data > da ){//��Ҫѭ�������Ƿ�Ϊnull 
			follow = pre;//�ݴ�ֵ 
			pre = pre->lChild;//�仯����follow!!
			flag = -1;
		}		
	}
	//ע�⣡�����˵�Ǹ���ָ�뷢�ֺ���Ϊnull,����ӽڵ㣬�ҽ���ǰָ�루pre���ĺ������temp 
	if(pre == null){
		//�������½�һ��BiTree�ڵ㣬�������޸ĳɱ�־�Ķ������ڵ㣨������������Ϊ�գ� 
		BiTree *temp;	
		temp = new BiTree; 
		temp->data = da;//��������
		temp->lChild = null;
		temp->rChild = null;
		
		if(flag == 1){
			follow->rChild = temp;	
			flag = -1; 
		}
		else if(flag == -1){
			follow->lChild = temp;
			flag = -1;
		}
	}	
} 

int main(){ 
	BiTree *bt;//�½�һ��BiTree��ͷָ�� 
	bt = null;//��ʼ��Ϊnull 
	
	int number;//��ʾ�ڵ���
	scanf("%d",&number);//����number
	int i;
	int da;
	for(i = 0;i< number;i++){
		scanf("%d",&da);		
		insertBiTree_2(bt,da);//��bt���������в���ֵ������ 
	} 	
	//������������� 
	preOrderBiTree(bt);
}
/**
7
8 6 5 7 10 8 11

7
8 6 5 7 10 9 11
*/
