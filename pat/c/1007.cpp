#include<cstdio>
#define maxn 10001

int array[maxn];
int dp[maxn];//��¼���ֵ
int origin[maxn];//��¼��ʼ�±�
int n;

void init(){
	int i;
	for(i = 0;i< n;i++){
		origin[i] = 0;
		dp[i] = -1;
	}
}

//cal���� 
int cal(int i){
	if(i == 0){
		dp[i] = array[i];
		return dp[i];
	}
	if(dp[i]!=-1){
		return dp[i];
	} 
	else{
		if(cal(i-1) > 0){
			dp[i] = cal(i-1) + array[i];//����֮ǰ�����ĺ�	
		}
		else {
			dp[i] = array[i];//ֱ�ӵ���ԭ������
		}
		return dp[i]; 
	}
} 


int main(){
	int i;
	scanf("%d",&n);
	
	init();
	int count = 0;
	for(i = 0;i< n;i++){
		scanf("%d",&array[i]);
		if(array[i] >= 0)	count++;
	}
	
	if(count == 0){
		printf("0 %d %d",array[0],array[n-1]);//ֱ�����0 
		return 0; 
	}
	cal(n-1);
	
//	printf("dp��������----------------\n");
//	for(i = 0;i< n;i++){
//		printf("%d ",dp[i]);
//	}
	
	//origin���� 
	int temp = 0;
	origin[0] = 0;//0����ʼ�����0 
	for(i = 1;i< n;i++){
		if(dp[i-1] > 0){
			origin[i] = origin[i-1];
		}
		else{
			origin[i] = i;//�������� 
		}
	} 
	
//	printf("origin��������----------\n");
//	for(i = 0;i< n;i++){
//		printf("%d ",origin[i]);
//	}
	
	int max = -99999;
	int tempIndex ;//�ݴ��¼�±� 
	for(i = 0;i< n;i++){
		if(dp[i] > max){
			max = dp[i];
			tempIndex = i; 
		}
	}
	printf("%d %d %d",max,array[origin[tempIndex]],array[tempIndex]);
}
/**
10
-10 1 2 3 4 -5 -23 3 7 -21

10
-10 1 -2 3 -4 -5 -23 3 7 -21

6
-2 11 -4 13 -5 -2

6
-2 -11 -4 -13 -5 -2

3
-1 2 -3

3
-1 0 -2
*/
