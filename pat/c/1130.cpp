#include<cstdio>
#include<cstring> 
#include<iostream>

using namespace std;

struct node{
	char data[15];//���ڵ��ֵ ����һ������ 
	int leftChi,rightChi;//���Һ��ӵĽڵ� 
};

int N;//�������Ľڵ��� 
int array[22];//����������ڵ� 
node n[22];	

//������� �õ���׺���ʽ 
void ldr(int root){
	if( strcmp(n[root].data,"+") == 0|| 
		strcmp(n[root].data,"-") == 0||
		strcmp(n[root].data,"*") == 0||
		strcmp(n[root].data,"/") == 0||
		strcmp(n[root].data,"%") == 0||
		strcmp(n[root].data,"&") == 0) 		
		cout << "(";
	if(n[root].leftChi!=-1){//����������� 
		ldr(n[root].leftChi);		
	}
	cout << n[root].data ;
	if(n[root].rightChi!=-1){
		ldr(n[root].rightChi);		
	}
	
	if( strcmp(n[root].data,"+") == 0|| 
		strcmp(n[root].data,"-") == 0||
		strcmp(n[root].data,"*") == 0||
		strcmp(n[root].data,"/") == 0||
		strcmp(n[root].data,"%") == 0||
		strcmp(n[root].data,"&") == 0)
		cout << ")"; 
} 

//�Ҹ��ڵ� 
int lookRoot(){
	int i ;
	for(i = 1;i<= N;i++){
		if(array[i] == 0) break;//˵���Ǹ��ڵ� 
	}	
	return i;
}

int main(){	
	scanf("%d",&N);
	int i ;		
	memset(array,0,sizeof(array));//��ʼ��Ϊ0 
	for(i = 1;i <= N;i++){	
		getchar();
		scanf("%s %d %d",&n[i].data, &n[i].leftChi, &n[i].rightChi);
		if(n[i].leftChi != -1)	array[n[i].leftChi] = 1; 
		if(n[i].rightChi != -1)	array[n[i].rightChi] = 1;
	} 
	int root;
	root = lookRoot();
	//cout<<"root = "<<root<<endl;
	int leftRoot ,rightRoot;
	leftRoot = n[root].leftChi;
	rightRoot = n[root].rightChi;
	
	//��Ҫ�������ж�һ��leftRoot �� rightRoot �Ƿ����-1������ᱨ�δ��� 
	//���ǲ������ǣ���ô�����������롣 ��Ȼ����leftRoot �� RightRoot =-1����� 
	//leftRoot = -1����������Ǵ��ڵġ�����˵ֻ��һ�����ʽ�� -1
	//rightRoot = -1 ������������ܲ��Ǵ��ڵġ� 
	if(leftRoot != -1) ldr(leftRoot);
	cout<<n[root].data;
	if(rightRoot !=-1) ldr(rightRoot);
}
/*
3
- 3 2
a -1 -1
b -1 -1

1
a -1 -1

3
- 2 3
a -1 -1
b -1 -1

8
* 8 7
a -1 -1
* 4 1
+ 2 5
b -1 -1
d -1 -1
- -1 6
c -1 -1
*/ 
