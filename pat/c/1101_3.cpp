#include<cstdio>
#include<iostream>
#include<climits>
#define maxn 100005

using namespace std;

int main(){
	int N;
	cin >> N;
	int i,j,k;
	int array[N];
	int max[N];//��ߵ����ֵ�� �������˼�����±�iʱ���������ֵ 
	int min[N];//�ұߵ���Сֵ   �������˼�����±�iʱ���Ҳ����Сֵ 
	 
	int res[N];
	int maxValue = 0;
	int minValue = INT_MAX;
	//ע����������minValue ���ó�һ��99999999�����õ������ 
	for(i = 0;i< N;i++){
		scanf("%d",&array[i]);
		max[i] = maxValue;
		if(maxValue < array[i]){
			maxValue = array[i]; 
		}		
	}
	
	//�ҳ�min[] 
	for(i = N-1 ; i >=0 ;i--){	
		min[i] = minValue;
		if(minValue > array[i]){
			minValue = array[i]; 
		}	
	}
	
	int count = 0;
	int curValue;	
	for(i = 0;i < N;i++){
		curValue = array[i];//��ǰֵ 
		if(curValue > max[i] && curValue < min[i]) {			
			res[count] = curValue;
			count++;
		}
	}
	
	cout << count << "\n"; 
	if(count == 0) cout << "\n";	
	for(i = 0;i< count;i++){
		cout << res[i];
		if (i != count - 1) cout << " ";		
	}	

}
/*
5
5 4 3 2 1

5
1 3 2 4 5

5
1 3 2 5 4

5
1 2 3 4 5

*/
