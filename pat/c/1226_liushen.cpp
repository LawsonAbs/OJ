//help qixiang 
#include<cstdio>
#define maxn 30
int array[maxn];//ԭ����
int record[maxn];//��¼�������Ƿ��ȥ��  record[i] =0��ʾ���±�Ϊi����û�в�ȥ 
int maxLen = 0;//������� 
int n;

void deal(int currentIndex){//ȥ���߲�ȥ������� 
	if(currentIndex == n+1){//����Ѿ������һ�����ֵ���һ�������� 
		int count = 1;//��ʾ��ȷ������ 
		int tempLen = 0;
		for(int i = 1;i <= n;i++ ){
			if(record[i] == 0){//������λû�в�ȥ 
				if(array[i] == count){//�����λ�ϵ����ֵ���count 
					tempLen++;
				}
				count++; 
			}
		}
		if(tempLen > maxLen){//������󳤶� 
			maxLen = tempLen; 
		}
		return ;
	} 
	deal(currentIndex+1);//����ȥ��λ 
	record[currentIndex] = 1;//��ȥ��λ 
	deal(currentIndex+1);//��ȥ��λ 
	record[currentIndex] = 0;//��λ 
}

int main(){
	scanf("%d",&n);
	for(int i = 1;i<= n;i++){ //��1��ʼ�洢 
		scanf("%d",&array[i]);
	}
	deal(1);
	printf("%d",maxLen);
}
/**
5
1 1 2 5 4
*/
