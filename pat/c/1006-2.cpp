#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct pNode{
	char id[20];
	int hh ,mm,ss;//ans1�������ǩ��ʱ�䣬ans2�������ǩ��ʱ��	 
}temp,ans1,ans2; 

bool great (pNode node1,pNode node2){
	if(node1.hh!=node2.hh){
		return node1.hh > node2.hh; 
	}
	if(node1.mm != node2.mm){
		return node1.mm >node2.mm;
	}
	return  node1.ss > node2.ss;
}

int main(){
	int n ;
	scanf("%d",&n);
	ans1.hh = 24,ans1.mm = 60,ans1.ss = 60;//�ѳ�ʼǩ��ʱ������Ϊ��� 
	ans2.hh = 0,ans2.mm = 0,ans2.ss = 0;//�����ǩ��ʱ������Ϊ��С 
	for(int i = 0;i<n;i++){
		scanf("%s %d:%d:%d",temp.id,temp.hh,temp.mm,temp)
	} 
}
/*** 
3
CS301111 07:30:28 17:00:10
SC3021234 07:30:27 11:25:25
CS301133 21:45:00 21:58:40

1
CS301133 21:45:00 21:58:40
*/ 
