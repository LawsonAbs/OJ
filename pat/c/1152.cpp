#include<cstdio>
#include<cmath>
#include<iomanip>
#include<iostream>

#define maxn 1005
using namespace std;

bool isPrime(long long num){
	if(num == 0) return false;
	if(num == 1) return false; 
	int i;
	for(i = 2;i<= sqrt(num);i++){
		if(num%i == 0) return false;
	}
	if(i > sqrt(num)) return true;
}

int main(){
	int L,M;
	char str[maxn];
	cin >>L >> M;
	int i;
	cin >> str;
	
	long long num = 0;//´ýÅÐ¶ÏµÄÊý 
	int count;
	for(i = 0; i <= L- M ;i++){
		count = 0;//reset to 0 
		num = 0;
		while(count < M){
			num = num*10 + str[i+count]-'0';
			count++;
		}
		//cout <<"num = "<<num<<"\n";			
		if( isPrime(num) ){			
			cout << setfill('0')<<setw(M)<<num<<"\n";
			break;
		}
	}
	if(i > L- M ){
		cout <<"404"<<"\n";
	}	
}
/*
20 5
23654987725541023819

20 5
23600007725541023819

20 6
23654987725541023819

20 7
23654987725541023819


18 9
516642742746639193

10 9
1100000007

6 4
211236

5 2
10234
*/
