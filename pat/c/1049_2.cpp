#include<cstdio>
#include<iostream>
#include<climits> 
#define maxn 100
using namespace std;

//�������num�а���1�ĸ��� 
int sum(int num){
	int sum = 0;
	int temp;
	while(num!=0) {
		temp = num % 10;
		if(temp == 1){
			sum ++;
		}
		num /= 10;//����10 
	}
	return sum; 
}

int main(){
	int N;
	cin >> N;
	int totalNum = 1;	
	int i = 1;
	int arr[maxn];
	arr[0] = 1;//10���µ�����1�� 
	long long startNum = 10;//��ʾ���ǻ�׼�� 
	int count = 0; 
	while(startNum * 10 < N){	//��10��ʼ�Ƚ� 		 
		count ++; //count ��1 
		int tempSum = 0;
		for(i = 0;i < count;i++) {
			tempSum += arr[i];
		}
		arr[count] = tempSum * 9 + startNum;
		totalNum += arr[count];//��ʼ���� 
		startNum *= 10;//��ʼ10������
		//cout << arr[count] << endl;
	}
	
	//����ʼλ�ÿ�ʼ���㼴��
	//cout <<"startNum = "<< startNum <<"\n";
	for(i = startNum;i<= N;i++){
		totalNum += sum(i);
	}
	cout << totalNum;	
}
/*
1.�ֳ������������㼴��
 
*/
