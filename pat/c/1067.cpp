#include <stdio.h>
#include <algorithm>
using namespace std;
/*
1.������⣬ֻ׼ʹ��0���������ֽ��� 
*/
#define maxSize 100010
int array[maxSize] ,temp[maxSize];
void swap(int a,int b){//��ʾ����������±� 
	int c;
	c = temp[b];
	temp[b] = temp[a];
	temp[a] = c;
}
int main(){
	int N ;
	scanf("%d",&N);
	int i ,lo;//lo��ʾΪ����0���±� 
	for(i = 0;i< N;i++){
		scanf("%d",&array[i]);
		temp[i] = array[i];//��Ϊ���� 
		if(temp[i] == 0){
			lo = i;//��¼��ʼ�±� 
		}
	}	
	sort(array,array+N);//---->�õ���ȷ������
		
	int  count = 0 , count1 = 0; //��¼�������� 		
	//1.������λ����
	while(count1 < N){//count1��ʾ�����ʹ������� 		
		for(i = 0;i<N;i++){
			//���ж�lo�Ƿ���λ��0��	
			if(lo == 0){
				for(int j = 1;j < N;j++){
					if(temp[j] != array[j]){//������߲���� 
						lo = j;//���������һ��ֵ
						count ++; 
						break;//����ѭ��				
					}
				} 
			}
			//���������û�г�������ȷ��λ���� --->����Ѱ�Һͽ������� 		
			if(temp[i] == array[lo] ){
				swap(lo,i);//�������ߵ�ֵ 
				lo = i; 
				count++;
			}
		}
		count1++;
	}
	printf("%d",count);
} 
/*
4 4 0 2 1 3
10 3 5 7 2 6 4 9 0 8 1

8 3 0 5 6 2 1 4 7
*/
