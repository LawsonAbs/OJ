#include<cstdio>
#include<iostream>
#define max(a,b) ((a)>(b)? (a): (b))
using namespace std;

int main(){
	int a = 2;	
	int b = 2;
	int n = max(a,b);
	printf("n = %d\n",n);	
	int m = max((++a),b);
	printf("a= %d ,b = %d, m = %d",a,b,m);
	return 0;
} 
