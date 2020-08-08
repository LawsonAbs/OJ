#include<cstdio>
#include<queue>
#include<iostream>
#define maxn 1005
#define winMaxn 25
 
using namespace std;

int N,M,K,Q;

//��N������ => ������N�� 
queue<int> que[winMaxn];

//�����Ӹ�ʽ�����Ϊ Сʱ������ 
void printRes(int totalMin){
	int min = totalMin % 60;
	int hour = totalMin / 60;		
	printf("%02d:%02d\n",hour+8,min);
} 

//��ʼ������ 
void initQue() {
	int i,j;
	int start = 1;	
	for(j = 1;j<= M;j++){ //�����ڵ����� 
		start = (j-1) * N + 1;
		for(i = 1;i<= N;i++ ){		
			que[i].push(start);
			start++;
		}
	}
} 

int main(){	
	cin >> N >> M >> K >> Q;
	int i,j;
	int time[maxn];//��ʾÿ���˵�����ʱ��	
	int comp[maxn];//��ʾ��K���˵Ĵ����� 
	int query[maxn];//��ʾ��ѯ������ 
	int curWindow[N+1] = {0};//��ʾ��ǰ���ڵ�ʱ�� 
	
	//����ÿ���˵Ĵ���ʱ�� 
	for(i=1;i<=K;i++){
		cin >> time[i];
	}
	
	for(i = 1;i<=Q;i++) { //������Ҫ��ѯ���� 
		cin >> query[i]; 
	}
	//���ȶԶ��н��г�ʼ������
	initQue(); 
	
	//��ʣ��δ��ӵ��˽����������� 
	//�±��1 ��ʼ �����Ǵ�1��ʼ����Ϊ�Ѿ���ʼ�����ˡ� ���ʿ�ʼ���±��� N*M+1	
	for(i = N*M+1 ; i <= K;i++){
		//cout <<"��ǰ�����жϵ����ǣ�"<<i<<"\n";		
		int minWindow = -1;//��Сʱ������Ӧ�Ĵ���
		int minTime = 0x3fffffff;//���д����У���С��ʱ��	
						
		for( j = 1; j <= N;j++){ //��1�Ŵ��ڿ�ʼ 
		//	cout <<"���׵����ǣ�"<< que[j].front()<<"\n"; 
			int tempTime = ( curWindow[j] + time[que[j].front()] );
			if(minTime > tempTime ){//�����ǰ���ڵ�ʱ��С��minTime,��ѡ�����minTime�����Ҹ���minWindow 
				minWindow = j;
				minTime = tempTime ;
			}
		//	cout <<"minTime = "<<minTime<<"\n";			
		}	
		//cout <<"��γ��ӵ��ǣ�"<< que[minWindow].front() <<"\n";		
		curWindow[minWindow] += time[que[minWindow].front()];
		comp[que[minWindow].front()] = curWindow[minWindow];//д����ɵ�ʱ�� 		
		que[minWindow].pop();//��minWindow�Ŵ��ڵĵ�һ���˳���		
		que[minWindow].push(i);//��i 			
	}
	
	//�Ի����ڵ�M ���˿�ʼ���� 
	for(i = 1;i<=N;i++){
		while(!que[i].empty()){
			curWindow[i] += time[que[i].front()];
			comp[que[i].front()] = curWindow[i];//д����ɵ�ʱ��
			que[i].pop();//������Ԫ�س��� 
		}
	}
	
	for(i = 1;i<=Q;i++){	
		int startTime = comp[query[i]] - time[query[i]];//��ʾ�˿͵Ŀ�ʼ����ʱ��
		if(startTime >= 540) cout <<"Sorry\n";
		else printRes(comp[query[i]]);			
	}
} 
/*
2 2 7 5
1 2 6 4 3 534 2
3 4 5 6 7

2 2 4 4
1 2 6 4
1 2 3 4


1 2 4 4
1 2 6 4
1 2 3 4

1 2 4 4
1 2 597 4
1 2 3 4

3 2 4 4
1 2 540 4
1 2 3 4
*/

/*
�����������������⣺
01.���N*M ������ڵ�ǰ������K��ô�죿 
02.�������һ�����⣬������ȫ������8:00���ͳһ���� 
*/
