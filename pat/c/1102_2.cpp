#include<cstdio>
#include<queue> 
#define maxn 100
using namespace std;

struct Node{
	int left,right;	
	int root_flag = 1 ;//����־ 
};

int num;//������� 
Node node[maxn];//�������ڵ� 
vector<int> result;//�洢�������
 
//���ַ�ת�������� 
int charToNum(char a,int i){
	if(a == '-'){		
		return -1;//û�к��ӽ�� 
	}
	else{
		node[a-'0'].root_flag = 0;
		return a-'0';
	}
}

//�ҵ����ڵ� 
int findRoot(){
	for(int i = 0;i < num;i++){
		if(node[i].root_flag != 0){
			return i;
		}
	}
}

//��α��� -->�Ӹ���ʼ 
void level(int root){
	int left,right; 
	int count = 0;
	queue<int> qu;//�½����� 
	qu.push(root);
	while(!qu.empty()){//���зǿ� 
		if(count!=num-1)	printf("%d ",qu.front());//������� 
		else printf("%d",qu.front());
		count++;
		right = node[qu.front()].right;
		left = node[qu.front()].left;
		if(right!=-1)	qu.push(right);
		if(left!=-1)	qu.push(left);
		qu.pop();//���� 
	}
	printf("\n");
}

//������� 
void inOrder(int root){
	if(node[root].left!=-1)	inOrder(node[root].left);
	result.push_back(root);//���浽result��
	if(node[root].right!=-1)	inOrder(node[root].right); 
}

int main(){	
	scanf("%d",&num);//�ܽ����
	getchar(); 
	int i ;
	char a,b; 
	
	for(i = 0;i< num;i++){//�������� 
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
ע��
1.Ҫѧ�����������ʱ�Ϳ�ʼ�������ݡ����籾���Ҹ��ڵ�
2.������ʵ������ʵ����ת�����ڸ���ֱ�Ӳ�α�������������������������ɡ� 
*/
