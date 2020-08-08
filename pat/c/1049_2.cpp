#include<cstdio>
#include<iostream>
#include<climits> 
#define maxn 100
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
	int totalNum = 1;	
	int i = 1;
	int arr[maxn];
	arr[0] = 1;//10以下的数有1个 
	long long startNum = 10;//表示的是基准数 
	int count = 0; 
	while(startNum * 10 < N){	//从10开始比较 		 
		count ++; //count 增1 
		int tempSum = 0;
		for(i = 0;i < count;i++) {
			tempSum += arr[i];
		}
		arr[count] = tempSum * 9 + startNum;
		totalNum += arr[count];//开始计数 
		startNum *= 10;//开始10倍扩大
		//cout << arr[count] << endl;
	}
	
	//从起始位置开始计算即可
	//cout <<"startNum = "<< startNum <<"\n";
	for(i = startNum;i<= N;i++){
		totalNum += sum(i);
	}
	cout << totalNum;	
}
/*
1.分成两部分来计算即可
 
*/
