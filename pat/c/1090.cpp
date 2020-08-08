#include <stdio.h>
#include <algorithm>
#include <vector>

#define maxSize 100
using namespace std;

//定义树结点 
typedef struct {
	int data;//存放的数据
}TreeNode;

int main(){
	vector<int> a;//声明一个变长数组a 
	int i;
	for(i = 0;i< 15;i++){
		a.push_back(i) ;
	} 
	
	//1.第一种遍历方式 
	for(i = 0;i<a.size();i++){
		printf("%d ",a[i]);
	}printf("\n");
	
	//2.第二种遍历方式 
	for( vector<int>::const_iterator it = a.begin();it<a.end();it++){
		printf("%d ",it);
	}
	
	printf("\na.size = %d\n",a.size());	
}
