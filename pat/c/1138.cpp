#include<cstdio>
#include<iostream>
#define maxn 50005;

using namespace std;

int preord[maxn];//先序遍历序列 
int inord[maxn];//中序遍历序列
 
int main(){
	int N;
	scanf("%d",&N);
	
	int i,j;
	//输入先序遍历序列的值 
	for(i = 0;i< N;i++){
		scanf("%d",preord[i]);
	}	
	
	//输入后序遍历序列的值 
	for(i = 0;i< N;i++){
		scanf("%d",inord[i]);
	}
	
	
}
