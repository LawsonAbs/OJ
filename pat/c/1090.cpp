#include <stdio.h>
#include <algorithm>
#include <vector>

#define maxSize 100
using namespace std;

//��������� 
typedef struct {
	int data;//��ŵ�����
}TreeNode;

int main(){
	vector<int> a;//����һ���䳤����a 
	int i;
	for(i = 0;i< 15;i++){
		a.push_back(i) ;
	} 
	
	//1.��һ�ֱ�����ʽ 
	for(i = 0;i<a.size();i++){
		printf("%d ",a[i]);
	}printf("\n");
	
	//2.�ڶ��ֱ�����ʽ 
	for( vector<int>::const_iterator it = a.begin();it<a.end();it++){
		printf("%d ",it);
	}
	
	printf("\na.size = %d\n",a.size());	
}
