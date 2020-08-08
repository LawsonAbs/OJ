#include <cstdio>
#include <string>
#include <iostream>
#define maxn 1000
using namespace std;

struct Node{
	string account;
	string password;
	int modify_flag = 0;//修改标志 
}; 

Node node[maxn];

int main(){
	int n;
	int i,j;
	int modify_count = 0;//修改的账户数
	
	scanf("%d",&n);
	getchar();
	for(i = 0;i< n;i++){
		cin>>node[i].account>>node[i].password;		
		
		for(j = 0;j< node[i].password.length();j++){//修改password 
			if(node[i].password[j]=='1'){
				node[i].password[j] = '@';
				node[i].modify_flag = 1;				
			}	
			else if(node[i].password[j]=='0'){
				node[i].password[j] = '%';
				node[i].modify_flag = 1;				
			}
			else if(node[i].password[j]=='l'){
				node[i].password[j] = 'L';
				node[i].modify_flag = 1;				
			}
			else if(node[i].password[j]=='O'){
				node[i].password[j] = 'o';			
				node[i].modify_flag = 1;
			}
		}
		if(node[i].modify_flag)	modify_count++;//如果有修改 		
	}
	if(modify_count == 0){//如果都没有修改 
		if(n==1)	printf("There is 1 account and no account is modified");
		else	printf("There are %d accounts and no account is modified",n);
	} 
	else {
		printf("%d\n",modify_count);
		for(i = 0;i< n;i++){
			if(node[i].modify_flag){
				modify_count--;
				if(modify_count!=0)	cout<<node[i].account<<" "<<node[i].password<<endl;
				else cout<<node[i].account<<" "<< node[i].password;
			}			
		}
	}
}
/*
3
Team000002 Rlsp0dfa
Team000003 perfectpwd
Team000001 R1spOdfa

1
team110 abcdefg332


2
team110 abcdefg222
team220 abcdefg333
replace 1 (one) by @, 0 (zero) by %, l by L, and O by o.
There are N accounts and no account is modified
There is 1 account and no account is modified
**/
