#include<cstdio>
#include<algorithm>
#include<iostream>

using namespace std;
struct item{
	int index = -1;//��ʾ��ǰ�������Ʒ������ 
	int accNum = 0 ;//ÿ����Ʒ�ķ�����
	int order ;//���ʵ�˳�� 
	int isVisit =0;//��ʾ�Ƿ���ʹ� 
};

int cmp(item i1,item i2){
	if(i1.accNum == i2.accNum) return i1.index < i2.index ;
	return i1.accNum > i2.accNum;
}

int main(){
	int num,limit;	 
	scanf("%d %d",&num,&limit);
	item it[num];
	int i,j;
	int accItem;
	int k;
	for(i = 0;i< num;i++){//�����iֻ�������������룬�����±��� 
		scanf("%d",&accItem);				
		if(i != 0){
			k = min(limit,i);
			sort(it,it+i,cmp);
			printf("%d: ",accItem);
			for(j = 0;j< k;j++){
				if(j != k - 1) 	{									
					printf("%d ",it[j].index);
				}
				else{
					printf("%d",it[j].index);
				}
 			}printf("\n");			
		}
		
		for(j = 0;j< i;j++){
			if(it[j].index == accItem){				
				it[j].accNum++;
				it[j].order = i;//����order��ֵ 
				//cout << "index = " << it[j].index << ",accNum = "<<it[j].accNum << endl; 
				break;
			}
		}
		if(j == i){
			it[i].accNum++;
			it[i].index = accItem;//��ʾ����ṹ���з��ʵľ���accItem��һ��
			it[i].order = i;				
		}		
	}	
}
/*
12 3
3 5 7 5 5 3 2 1 8 3 8 12

*/
