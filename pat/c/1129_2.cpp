#include<cstdio>
#include<algorithm>
#include<iostream>

using namespace std;
struct item{
	int index = -1;//��ʾ��ǰ�������Ʒ������ 
	int accNum = 0 ;//ÿ����Ʒ�ķ�����
};

int cmp(item i1,item i2){
	if(i1.accNum == i2.accNum) return i1.index < i2.index ;
	return i1.accNum > i2.accNum;
}

int cmp_index(item i1,item i2){
	return i1.index < i2.index ;	
}

int main(){
	int num,limit;	 
	scanf("%d %d",&num,&limit);
	item it[num];
	int i,j;
	int accItem;
	int k;
	
	//ʹ�ö��ַ�Ѱ�Һ��ʵ����� 
	int high ,low ,mid ;
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
		
		//�����µĴ����޸ĳ�ʹ��2�ַ� 
		//���Ǵ��ڵ������ǣ����ʹ�ö��ַ�����ôǰ����ǣ�it[i].index ��һ�������״̬��
		//���������������У���ô���޷�ʹ�ö��ַ� 
		sort(it,it+i,cmp_index);
		high = i-1;
		low = 0;		
		while(low <= high){
			mid = (high + low)/2; //���mid��ֵ
			//printf("mid = %d\n",mid);
			if(it[mid].index < accItem){
				low = mid + 1; 				
			}
			else if(it[mid].index > accItem){
				high = mid - 1;	
			}
			else break;
		}
		
		if(it[mid].index == accItem){//�����ǰ�����ֵ�Ѿ�������			
				it[mid].accNum++;			
		}
		else{
			it[i].accNum++;
			it[i].index = accItem;//��ʾ����ṹ���з��ʵľ���accItem��һ��							
		}		
	}	
}
/*
12 3
3 5 7 5 5 3 2 1 8 3 8 12

*/
