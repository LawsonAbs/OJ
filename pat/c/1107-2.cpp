#include <stdio.h>
#include <algorithm> 
using namespace std;

#define maxSize 10010

bool cmp(int a,int b){
	return a > b;
}

int people[maxSize];//ͳ������ 
int arr[maxSize][maxSize];//���� 
int temp[maxSize];//�ݴ�hobby 

int main(){
	int n,hobby,i,j,k; 
	scanf("%d",&n);//����������
	int record = 0;//��¼Ա 
	for(i = 1;i<= n;i++){ 
		people[i] = 0;//��ʼ��Ϊ0
		scanf("%d:",&arr[i][0]);//���밮����Ŀ----->��������Ŀ�洢���� 
		for( j = 1;j <= arr[i][0] ; j++){//ע���±� 
			scanf("%d",&hobby);//���밮��
			temp[j] = hobby;//�ŵ�temp������
			arr[i][j] = hobby;	
		}	
		
		//���ÿ�����������Ƿ�֮ǰ����� 
		for(j = 1;j <= arr[i][0] ;j++ ){
			for( k = 1; k< i; k++) {
				for(int m = 1;m <= arr[k][0]; m++ ) {			
					if(arr[k][m] == temp[j]){
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
			int y;//����ǰ�����������֮ǰ�±�Ϊrecord�ļ��ϵ��� 
			for(y = 1;y <= arr[i][0];y++ ){
				arr[record][arr[record][0]+y] = arr[i][y]; 
			}
			arr[record][0] += arr[i][0];//��̬�ı䰮�ø��� 
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
1: 3
1: 3
3: 3 1 8
1: 5
1: 7
1: 1
1: 8

1.�����ڶ�̬�ı仯�����Ǳ���Ĺؼ� 
*/
