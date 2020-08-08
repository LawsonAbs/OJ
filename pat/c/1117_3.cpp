#include<iostream>
#include<algorithm>
#include<functional>
#define maxn 200005
using namespace std;

int main(){
	int N;
	cin >> N;
	int i,j;
	int array[maxn];
	for(i = 0;i< N;i++){
		cin >> array[i];
	}
		
	sort(array,array+N,greater<int>());
	int anw[maxn];
	int rank = 0;
	anw[array[0]] = 0;
	for(i = 1;i< N;i++){
		if(array[i] == array[i-1]){//如果当前值和之前的值相等 
			anw[array[i]] = rank;
		}else{
			rank = i;
			anw[array[i]] = rank;
		}
	}
		
	for(j = 0;j < N ;j++){		
//		cout <<anw[array[j]]<<" "; 
		if(anw[array[j]] >= array[j]){
			cout << array[j-1] - 1;
			break;
		}
	}
	
	if(j == N){//说明没有值大于 
		cout << array[N-1]-1; 
	}
}
/*
10
6 7 6 9 3 10 8 2 7 8

10
7 7 7 9 3 10 8 2 7 8

5 
4 3 3 3 3

5 
4 3 3 2 2

*/
