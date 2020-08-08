#include<cstdio>
#include<iostream>
#include<map>
using namespace std;

int main(){
	map<int,int> ma;
	
	ma[1]=11;
	ma[2]=22;
	ma[3]=33;
	
	map<int,int> ::iterator it = ma.begin();
	printf("before advance----*it = %d\n",*it); 
	advance(it,1);//使用advance()函数可以向后移一个指针 
	printf("after advance----*it = %d\n",*it); 
	
	if(ma.find(1)!=ma.end()){
		printf("%d",ma[1]);
	}
	printf("\n=============\n");
	
	for(int i = 1;i< 4;i++){
		printf("%d ",ma[i]);
	}printf("\n");
	
	
	for(map<int,int> ::iterator it = ma.begin();it!=ma.end();it++){
		cout << it->first <<" " << it->second;
	} 
}
