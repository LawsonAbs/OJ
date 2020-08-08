#include<cstdio>
#include<iostream>
#include<algorithm>
#include<functional>

#define maxn 10005
using namespace std;

int N , M;
int coins[maxn];
int rec[maxn]; 
int COUNT = 0;//��ĸ��� 
int res[maxn];//�������н� 
int num = 0;
int flag = 0;//��ʾ�Ƿ���ڽ� 

//ʹ�������㷨������������ 
//����ÿöӲ�ң����зŻ��߲���������ѡ����dfs������ʵ��������ѡ�񼴿� 
void dfs(int root,int index,int sum){//root��ʾ��0 			
	if( sum > M){//���������M 
		return ;
	} 
	else if(sum == M){		
		if(COUNT == 0){	
			num = index;		
			for(int i = 0;i< index;i++){
				res[i] = rec[i];//���浽res�� 
			}
		}
		COUNT ++;//����+1 
		flag = 1;
	} 	
	if(flag == 1) return ; 
	
	//�������µݹ� 	=> ��Ӳ�� 	
	rec[index] = root;	
	dfs(root+1,index+1,sum + coins[root]);
	rec[index] = 0;//��Ϊ�����Ѿ��޸���ֵ����������Ҫ����Ϊ0 
		
	//�������µݹ� 	=> ����Ӳ�� 			
	if(root + 1 < N) dfs(root+1,index,sum);	
}

int main(){	
	cin >> N >> M;
	int i,j;
	
	for(i = 0;i< N;i++){
		cin >> coins[i];
	}
	sort(coins,coins+N,less<int>());	
	
	int index = 0;//�±� 
	int sum = 0;//�ܺ� 
	for(i = 0;i< N;i++){
		index = 0;//����Ϊ0 
		sum = 0;//����Ϊ0 
		dfs(i,index,sum);//��i��ʼ 			
	} 
	
	if(COUNT == 0 ){
		cout << "No Solution\n";
		return 0; 	
	}
	for(j = 0;j < num;j++){
		if(j!=num-1) cout << coins[res[j]]<<" " ;
		if(j == num-1) cout << coins[res[j]] ;
	}	
}
