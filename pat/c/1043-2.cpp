#include <stdio.h>
#define null NULL
#define maxSize 1003

typedef struct BiTree{
	struct BiTree *lChild,*rChild;//������ָ��
	int data;//������ 
}BiTree;



int  start[maxSize];//��ʼ���� 
int  result1[maxSize];//�������������� 
int  result2[maxSize];//�������������� 
int  result3[maxSize];//DRL����������� 
int  result4[maxSize];//DRL�����������

int count1 = 0;//����һ��ȫ�ֱ����������洢LDR����������� 
int count2 = 0;//�����洢LRD����������� 
int count3 = 0;//�����洢DRL��δ������������ 
int count4 = 0;//�����洢RLD��δ������������ 
 
void insertBiTree(BiTree *&bt,int da){	
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

//�����������������
void preOrderBiTree(BiTree *T){	 
	if(T!=null){
		result1[count1++] = T->data;	
		//printf("%d ",T->data);	
	}
	else	return ;//������ֹ�ݹ�--->�ݹ�����߽� 
	preOrderBiTree(T->lChild);//�ݹ������� 
	preOrderBiTree(T->rChild);//�ݹ������� 
}

//�����������������
void postOrderBiTree(BiTree *T){
	if(T!=null){
		postOrderBiTree(T->lChild);//�ݹ������� 
		postOrderBiTree(T->rChild);//�ݹ������� 		
		result2[count2++] = T->data;	
	}	  
	else	return ;//������ֹ�ݹ�--->�ݹ�����߽�
}

//DRL��������������--->�õ�������������� 
void DRLOrderBiTree(BiTree *T){	 
	if(T!=null){
		result3[count3++] = T->data;
		DRLOrderBiTree(T->rChild);//�ݹ������� 
		DRLOrderBiTree(T->lChild);//�ݹ������� 	
	}
	else	return ;//������ֹ�ݹ�--->�ݹ�����߽� 	
}

//RLD�������������
void RLDOrderBiTree(BiTree *T){	 		
	if(T!=null){
		RLDOrderBiTree(T->rChild);//�ݹ������� 
		RLDOrderBiTree(T->lChild);//�ݹ������� 
		result4[count4++] = T->data;	
		//printf("%d ",T->data);	
	}
	else	return ;//������ֹ�ݹ�--->�ݹ�����߽� 	
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
		start[i] = da;//��ŵ�start��		
		insertBiTree(bt,da);//��bt���������в���ֵ������ 
	} 		
	//���������������� 
	preOrderBiTree(bt);
	postOrderBiTree(bt);
	DRLOrderBiTree(bt);
	RLDOrderBiTree(bt);
	
	//�Ƚ����������Ƿ���ͬ
	for(i = 0;i< number;i++){
		if(start[i]!=result1[i]){
			break;
		}
	} 
	if(i == number ){
		printf("YES\n");
		for(int j = 0;j < number ;j++){//�������������� 
			if(j < number-1) {
				printf("%d ",result2[j]);
			}
			else
				printf("%d\n",result2[j]);
		}
		return 0; 
	} 
	
	for(i = 0;i< number;i++){
		if(start[i]!=result3[i]){
			break;
		}
	} 
	if(i< number ){
		printf("NO\n");	
	}
	else{
		printf("YES\n");
		for(int j = 0;j < number ;j++){//����������� 
			if(j < number-1) {
				printf("%d ",result4[j]);
			}
			else
				printf("%d\n",result4[j]);
		}
	}
}
/**
7
8 6 5 7 10 8 11

7
8 10 11 8 6 7 5

7
8 6 8 5 10 9 11

*/
