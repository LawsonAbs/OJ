//help qi xiang 
#include<cstdio>
#define maxn 1000
 
double array[maxn];//ȫ�ֱ���  ����ʺ��λ�� 
int n, count = 0;//��Ҫ��������� 

bool isRight(int currentRow){//�Ƿ��Ƿ��������ĵ�  currentRow��ǰ�� 
	int i ; 
	for(i = 1;i< currentRow;i++){
		if( array[i] == -1) break;//�������������� 
		if(array[currentRow] == array[i])		break;//����ͬ 
		if( ( (array[currentRow]- array[i])/(currentRow - i) == -1 ) )	break;//��б�Խ�����
		if( ((array[currentRow]- array[i])/(currentRow - i) == 1 ) )	break;//��б�Խ�����
	}//��abs�������ж��Ƿ������������� 
	if(i == currentRow)	return true;
	else return false;
}

void dfs(int currentRow){
	if(currentRow == n+1){//����Ѿ��������һ�е���һ�� 
		for(int j = 1;j <= n;j++){
			printf("%.0lf ",array[j]);//��� 
		}printf("\n");
		count++;
		return ;//���� 
	} 
	for(int i = 1;i<= n;i++){
		array[currentRow] = i;//currentRow�Ƕ�ֵ�����ŵݹ�ı� 
		if(isRight(currentRow)){//�����������--->����� 
			dfs(currentRow+1);//����һ������ --> ++���ܻ��� 
		}
	}
} 
  
int main(){	
	scanf("%d",&n);
	dfs(1); 
}

/**
�ӵ㣺 
4/3 == 1 
*/


