#include<cstdio>
#define maxn 1005
int main(){
	int num,n;//num ������ǲ���������  n������������εķ�����
	scanf("%d",&num);
	double array[maxn];
	int i,j,k;
	double value;//�ж�ÿ����������б�� 
	int flag  = 0;
	for(i = 0;i< num;i++){
		scanf("%d",&n);
		for(j = 0;j< n;j++)
		{
			scanf("%lf",&array[j]);//��ÿ���ʺ�˳�����
		}
		
//		for(j = 0;j< n;j++){
//			printf("%f ",array[j]);
//		}
		double curValue = 0;
		for(j = 0;j< n;j++){
			flag = 0;
			curValue = array[j]; 
			//printf("curValue = %f\n",curValue);
			for(k = j+1;k< n ;k++){
				//printf("k = %d,array[k]= %d ",k,array[k]);
				value = (array[k] - array[j])/(k-j);				
				if(value == -1 || value == 1 || value == 0)	 
				{
					printf("NO\n");
					//printf("j = %d,k = %d\n",j,k);
					flag = 1; 
					break;
				}
			}			
			if(flag == 1){
				break;
			}
		//	printf("\n");
		}
		if(j == n){
			printf("YES\n");
		}
	} 
}

/*
4
8 4 6 8 2 7 1 3 5
9 4 6 7 2 8 1 9 5 3
6 1 5 2 6 4 3
5 1 3 5 2 4

1
5 1 1 1 1 1
*/
