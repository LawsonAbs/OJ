#include<cstdio>
#include<iostream>

using namespace std;

//计算这个num中包含1的个数 
int sum(int num){
	int sum = 0;
	int temp;
	while(num!=0) {
		temp = num % 10;
		if(temp == 1){
			sum ++;
		}
		num /= 10;//除以10 
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
