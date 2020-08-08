#include<cstdio>
#include<functional>
#include<algorithm>
#include<iostream>
#define maxn 100 
using namespace std;

//获取两个值m和n
//满足的关系式：m>=n ,且 (m-n) 的值取到最小 
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

//用于存储结果的数组 
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
			res[i][j] = 0;//为结果集赋值 
		} 
	}
	sort(input,input+N,greater<int>());	
	
//	for(i = 0;i< N;i++) cout <<input[i]<<" ";	
//	cout <<"\n";
	
	int index = 0;//表示的是元素总数目 
	i = 0;j = -1;//reset to 0	
	while( index < N ){
		//向右方向 
		while(res[i][j+1]==0 && i<m && (j+1)<n){			
			j++;
			res[i][j] = input[index];
//			j++;	
			index ++;
		}
		//cout<<"i = "<<i<<",j = "<<j<<"\n";
		//向下方向
		while(res[i+1][j]==0 && (i+1)<m && j<n){ //这里的判断条件应该是 (i+1) < m
			i++;
			res[i][j] = input[index];			
			index ++;
		}
		
		//向左方向
		while(res[i][j-1]==0 && i<m && j<n && (j-1)>=0 && i>=0){
			j--;
			res[i][j] = input[index];			
			index ++;
		}
		
		//向上方向
		while(res[i-1][j]==0 && i<m && j<n && j>=0 && (i-1)>0){//在i变化的时候，如果j=0也是正确的 
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
