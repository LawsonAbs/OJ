#include<cstdio>
#include<iostream>

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
	int totalNum = 0;	
	int i;
	for(i = 1;i<= N;i++){
		totalNum += sum(i);
	}
	cout << totalNum;
}
