#include<cstdio>
#include<functional>
#include<algorithm>
#include<iostream>
#define maxn 100 
using namespace std;

//��ȡ����ֵm��n
//����Ĺ�ϵʽ��m>=n ,�� (m-n) ��ֵȡ����С 
int getLeft(int number){
	int i,j;
	//cout <<"sqrt(number) = "<<sqrt(number)<<"\n";
	if(number == 1 ) return 1;
	for(i = sqrt(number) ; i <= number ;i++ ){		
		if(number % i == 0) {			
			return max(i,number/i);	
		}
	}
} 

//���ڴ洢��������� 
int input[maxn];
 
int main(){
	int N;
	cin >> N;
	int i,j;
	int m,n;
	m = getLeft(N);
	n = N / m;
	//cout << "m = "<<m<<",n = "<<n<<"\n";
	int res[m][n]; 
	
	for(i = 0;i< N;i++){
		cin >> input[i];
	}
	
	for(i = 0;i<m;i++){
		for(j = 0;j<n;j++){
			res[i][j] = 0;//Ϊ�������ֵ 
		} 
	}
	sort(input,input+N,greater<int>());	
	
//	for(i = 0;i< N;i++) cout <<input[i]<<" ";	
//	cout <<"\n";
	
	int index = 0;//��ʾ����Ԫ������Ŀ 
	i = 0;j = -1;//reset to 0	
	while( index < N ){
		//���ҷ��� 
		while(res[i][j+1]==0 && i<m && (j+1)<n){			
			j++;
			res[i][j] = input[index];
//			j++;	
			index ++;
		}
		//cout<<"i = "<<i<<",j = "<<j<<"\n";
		//���·���
		while(res[i+1][j]==0 && (i+1)<m && j<n){ //������ж�����Ӧ���� (i+1) < m
			i++;
			res[i][j] = input[index];			
			index ++;
		}
		
		//������
		while(res[i][j-1]==0 && i<m && j<n && (j-1)>=0 && i>=0){
			j--;
			res[i][j] = input[index];			
			index ++;
		}
		
		//���Ϸ���
		while(res[i-1][j]==0 && i<m && j<n && j>=0 && (i-1)>0){//��i�仯��ʱ�����j=0Ҳ����ȷ�� 
			i--;
			res[i][j] = input[index];			
			index ++;
		}
	} 
	
	for(i = 0;i< m;i++){
		for(j = 0;j< n;j++){
			cout << res[i][j];
			if(j!=n-1) cout <<" ";
		}cout<<"\n";
	}
}
/*
12
37 76 20 98 76 42 53 95 60 81 58 93

9 
1 2 3 4 5 6 7 8 9

8
1 2 3 4 5 6 7 8

1
1

2 
1 2
*/
