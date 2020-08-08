//help qixiang 
#include<cstdio>

int n,m,king;//n�� m�� k���� 
int array[13][13];//��¼�ĸ��±����Ѿ��м�¼
int count = 0;//����

bool isRight(int row,int line){//�ж�row line�ϵĹ����Ƿ��������
	int flag = 0;
	for(int k= -1;k<=1 ;k++ ){
		for(int j = -1;j <=1 ;j++){
			if(k==0 && j==0)
				continue; 
			else{
				if(row+k >=0 && row+k <n && line+j >=0 && line+j<m ){
					if(array[row+k][line+j] == 1)
						flag = 1;		
				}	
			}
		}
	}
	if(flag ==1 ){ 
		return false;
	}	
	else return true;
}

void dfs(int currentId,int completedNumber){//��ǰ�����id  ����ɵ��� 
	if(completedNumber == king){//���k���������Ѿ����ź��� 
		count++;//����
		return ; 
	}
	if(currentId == n*m ){//�����ǰ����������±��Ѿ��������еķ�Χ--�򷵻� 
		return ;
	}
	for(int i = currentId;i< n*m ;i++){
		int row ,line;//����
		row = i / m;//����� row 
		line = i % m;//�����  line
		if(isRight(row,line))//�����ǰ�����������
		{ 
			array[row][line] = 1;//��ֵ 
			dfs(i+1,completedNumber+1);//������������ 
			array[row][line] = 0;//����--->��֮ǰ��ֵ��0	
		} 
	}
} 

int main(){
	scanf("%d %d %d",&n,&m,&king);
	dfs(0,0);//���� 
	printf("%d",count); 
}  
/**
2 3 2
�ӵ㣺
1.ȥ��
2.���ж��Ƿ��ܵ�����ʱ������ʹ�������ľ���[��ѧ��ʽ]������������ܼ�� 
*/
