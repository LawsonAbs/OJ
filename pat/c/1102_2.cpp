#include<cstdio>
#include<queue> 
#define maxn 100
using namespace std;

struct Node{
	int left,right;	
	int root_flag = 1 ;//根标志 
};

int num;//结点总数 
Node node[maxn];//二叉树节点 
vector<int> result;//存储遍历结果
 
//从字符转换成数字 
int charToNum(char a,int i){
	if(a == '-'){		
		return -1;//没有孩子结点 
	}
	else{
		node[a-'0'].root_flag = 0;
		return a-'0';
	}
}

//找到根节点 
int findRoot(){
	for(int i = 0;i < num;i++){
		if(node[i].root_flag != 0){
			return i;
		}
	}
}

//层次遍历 -->从根开始 
void level(int root){
	int left,right; 
	int count = 0;
	queue<int> qu;//新建队列 
	qu.push(root);
	while(!qu.empty()){//队列非空 
		if(count!=num-1)	printf("%d ",qu.front());//输出队首 
		else printf("%d",qu.front());
		count++;
		right = node[qu.front()].right;
		left = node[qu.front()].left;
		if(right!=-1)	qu.push(right);
		if(left!=-1)	qu.push(left);
		qu.pop();//出队 
	}
	printf("\n");
}

//中序遍历 
void inOrder(int root){
	if(node[root].left!=-1)	inOrder(node[root].left);
	result.push_back(root);//保存到result中
	if(node[root].right!=-1)	inOrder(node[root].right); 
}

int main(){	
	scanf("%d",&num);//总结点数
	getchar(); 
	int i ;
	char a,b; 
	
	for(i = 0;i< num;i++){//输入数据 
		scanf("%c %c",&a,&b);
		getchar(); 
		node[i].left = charToNum(a,i);
		node[i].right = charToNum(b,i);			
	} 
	int root = findRoot();	
	
	level(root);
	inOrder(root);		
	
	for(i = result.size()-1;i >=0 ;i--){
		if(i!=0)	printf("%d ",result[i]);
		else printf("%d",result[i]);
	}
}
/*
8
1 -
- -
0 -
2 7
- -
- -
5 -
4 6
注：
1.要学会从输入数据时就开始处理数据。比如本题找根节点
2.本题其实不用真实的旋转，对于该树直接层次遍历，中序遍历，最后倒着输出即可。 
*/
