#include <cstdio>
#define maxn 100010


int n;
int disorder = 0;//�����������Ŀ
int array[maxn];
int indexZero;//0���±� 
int count = 0;//��������

//�������� 
void swap(int array[]){
	int tempIndex = 0;//�ݴ��±� 
	int i;
	int firstIndex;//��һ������ȵ������±�
	int startSearch = 0;//��ʼѰ��λ 
	
	while(disorder){//��û��������ʱ 
		for(i = startSearch;i< n;i ++){			
			if(array[i] == indexZero){
				tempIndex = i;//��¼����indexZero���ڵ��±� 
				startSearch = i+1;//��Ϊi+1; 
				break;
			}
		}
		 
		if(i<n && indexZero!=0){//����indexZero �� tempIndex�ϵ������� 			 				
			array[indexZero] = array[tempIndex];
			array[tempIndex] = 0; 
			indexZero = tempIndex;//����0���±� 					
			count++; 
		} 
		else {//0����0��λ 
			for( i = startSearch;i< n;i ++){
				if(array[i] != i){
					tempIndex = i;//��¼����indexZero���ڵ��±� 
					break;
				}
			}
			array[indexZero] = array[tempIndex];
			array[tempIndex] = 0; 
			indexZero = tempIndex; 
			disorder += 2;
			count++; 
		} 
		
		if(disorder == 2){
			disorder = 0;//����ʹ��������һ���Ϊ���� 
		}
		else if(tempIndex == 0)	disorder -= 2; 
		else disorder--;
	}
	printf("%d",count);
}


int main(){
	int i ;
	scanf("%d",&n);
	for(i = 0;i < n;i++){
		scanf("%d",&array[i]);	
		if(array[i]!=i)	disorder++; 
		if(array[i] == 0)	indexZero = i;
	} 
	swap(array);	
}
/**
10 3 5 7 2 6 4 9 0 8 1
*/
