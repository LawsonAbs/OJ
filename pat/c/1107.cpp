#include <stdio.h>
#include <algorithm> 
using namespace std;

#define maxSize 1001

bool cmp(int a,int b){
	return a > b;
}

int people[maxSize];//ͳ������ 
int arr[maxSize][maxSize];//���� 
 
int main(){
	int n,hobby,i,j,k; 
	scanf("%d",&n);//����������
	int record = 0;//��¼Ա 
	for(i = 1;i<= n;i++){ 
		people[i] = 0;//��ʼ��Ϊ0
		scanf("%d:",&arr[i][0]);//���밮����Ŀ----->��������Ŀ�洢���� 
		for( j = 1;j <= arr[i][0] ; j++){//ע���±� 
			scanf("%d",&hobby);//���밮��
			arr[i][j] = hobby;
						
			for( k = 1; k< i;k++) {//���ÿ�����������Ƿ�֮ǰ����� 
				for(int m = 1;m <= arr[k][0];m++ ) {
					if(arr[k][m] == hobby){
						record = k;
						break;//����ѭ�� 
					}					 
				}
				if(record) break;	//����ѭ��			
			}
			if(record)	break;//����ѭ��						
		}
		if(record == 0 )//���û����ͬ�� 
		{							
			people[i]++;
		}
		else{
			 
			people[record]++;//������ͬ���������� 
			record = 0;
		}
	}
	sort(people,people+n+1,cmp);//ע���������Ϊn+1   ��������֮���±��0��ʼ�� 
	int count = 0;
	for(i = 0;i <= n;i++){
		if(people[i]!=0){
			count++;
		}
	}
	printf("%d\n",count);
	for( i = 0;i <= n;i++){		
		if(count>1 && people[i]>0)	printf("%d ",people[i]);
		else if(count == 1 && people[i]>0) 	printf("%d",people[i]);
		count--;
	}	
} 

/**
8
3: 2 7 10
1: 4
2: 5 3
1: 4
1: 3
1: 4
4: 6 8 1 5
1: 4

8
1: 2
1: 4
1: 3
1: 1
1: 5
1: 7
1: 6
1: 8

4
4: 4 2 3 11
2: 4 5
2: 6 5
3: 8 5 10
*/

/**
1.�����ڶ�̬�ı仯�����Ǳ���Ĺؼ� 
*/
