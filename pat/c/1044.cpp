#include <stdio.h> 
#define size 100002


/*
1.��ʹ�ö��ַ���ʱ�������left = mid + 1 ; right  = mid - 1;
��ѭ������������while(left <= right) {}
*/ 
int main(){
	int n,m;//n��ʾ������ʯ��,m��ʾ������Ҫ���ļ�Ǯ 
	int diamond[size];//��ʾһ�����ϵ���ʯ�� 
	int sum[size];
	sum[0] = 0;//��ʼ����һ��Ϊ0 
	scanf("%d %d",&n,&m); 
	
	int i ;
	for(i = 0;i<n;i++){
		scanf("%d",&diamond[i]);
		sum[i+1] = sum[i] + diamond[i]; 
	//	printf("%d\n",sum[i]);
	}
//	printf("%d\n",sum[i]);
	
	//��ʼ����Ѱ�Ҽ۸�պ�Ϊm���� 
	int count = 0;//������ʾ�Ƿ������ǡ����ȵ�����
	int min = m;//������ʾ���߽���
	 
	for(i = 1 ; i <= n ; i++){
		int left = i,right = n;//���ұ߽� 
		int mid;
		while(left <= right){//ע��ѭ���߽�		
			mid = (left + right) / 2;//����м�ֵ
			if(sum[mid] < sum[i-1] + m) {//���С�� 
				left = mid + 1;//��߽�ֵ�͵����м�ֵ��1				
			}
			else if(sum[mid] > sum[i-1] + m){//������� 
				right = mid - 1;//�ұ߽�ֵ�͵����м�ֵ��1
				if(min > sum[mid] -( sum[i-1] + m )){
					min = sum[mid] -( sum[i-1] + m );	
				}				
			}
			else{//������� 
				printf("%d-%d\n",i,mid); //���i,midֵ 
				min = 0;				
				break;							
			} 
		}
	}
	
	//���˵û���ҵ�ǡ����ȵĽ���ô���ҳ���ԱȽ�С�� 
	if(min != 0){
		//printf("min = %d\n",min);
		for(i = 1 ; i <= n ; i++){
			int left = i,right = n;//���ұ߽� 
			int mid;
			while(left <= right){//ע��ѭ���߽�		
				mid = (left + right) / 2;//����м�ֵ
				if(sum[mid] < sum[i-1] + m) {//����м�ֵС�ڵĻ� 
					left = mid + 1;//��߽�ֵ�͵����м�ֵ��1
				}
				else if(sum[mid] > sum[i-1] + m){//����м�ֵ���ڵĻ� 
					right = mid - 1;//�ұ߽�ֵ�͵����м�ֵ��1 
					//���˵�պò�ֵΪ min 
					if(min == sum[mid] -( sum[i-1] + m )){
						printf("%d-%d\n",i,mid); //���i,midֵ 
					}
				}
			}
		}
	} 
}
/**
16 15
3 2 1 5 4 6 8 7 16 10 15 11 9 12 14 13

8 15
3 2 1 5 4 6 8 7

5 13
2 4 5 7 9

3 3
1 2 3

3 5
2 2 2

1 10
18
**/
