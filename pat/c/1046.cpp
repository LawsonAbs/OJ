#include <cstdio> 


//1.ÿһ�Գ��ڶ������ַ�����Ѱ�Ҿ��� 
int N;
int array[100002];
int sum1 = 0,sum2 = 0;
int sum= 0;//��ʾ�ܵ�һ������·������ 

int positive(int a,int b){
	int i ;
	sum1 = 0 ;
	for(i = a-1;i<b-1;i++){
		sum1 += array[i]; 
	}
	return sum1;
} 

//b�Ǵ�ֵ��a��Сֵ 
int reverse(int a,int b){
	int i ;
	sum2 = 0 ;
	for(i = b-1;i<N;i++){
		sum2 += array[i]; 
		if(sum2 > sum1){			
			return sum2;
		}
	}
	
	for(i = 0;i<a-1;i++){
		sum2 += array[i];
		if(sum2 > sum1){			
			return sum2;
		}
	}
	return sum2;
} 

int main(){
	scanf("%d",&N);	
	int i = 0;
	//arrray[0]�ǳ���1������2�ľ��룬������n,��array[n-1]Ϊ��n�����ڵ���һ�����ڵľ��� 
	for(i = 0;i<N;i++){
		scanf("%d",&array[i]);
	}
	
	
	
	int M;
	int temp[2];
	scanf("%d",&M);
	while(M--){
		scanf("%d %d",&temp[0],&temp[1]);
		
		//������ֵ����������˳�� 
		int a = 0;
		if(temp[0]>temp[1]){
			a = temp[0];
			temp[0] = temp[1];
			temp[1] = a;
		}
		
		//printf("temp[0] = %d,temp[1]=%d\n",temp[0],temp[1]);
		
		sum1 = positive(temp[0],temp[1]);
		sum2 = reverse(temp[0],temp[1]);
		
		if(sum1 < sum2){
			printf("%d\n",sum1);
		}
		else{
			printf("%d\n",sum2);
		}
	} 	
}
/**
5 1 2 4 14 9
3
4 1
1 3
2 5
**/
