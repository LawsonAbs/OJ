#include<cstdio>
#include<iostream>
#define maxn 50005;

using namespace std;

int preord[maxn];//����������� 
int inord[maxn];//�����������
 
int main(){
	int N;
	scanf("%d",&N);
	
	int i,j;
	//��������������е�ֵ 
	for(i = 0;i< N;i++){
		scanf("%d",preord[i]);
	}	
	
	//�������������е�ֵ 
	for(i = 0;i< N;i++){
		scanf("%d",inord[i]);
	}
	
	
}
