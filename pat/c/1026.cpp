#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#define maxn 10005
 
using namespace std;

struct User{
	int start_hour;//�����ʱ�� 
	int start_min;
	int start_sec;
	int playTime;
	int isVip;//��־�Ƿ���vip
	int end_hour; 
	int end_min;
	int end_sec;
};

User user[maxn];
int N,K,M; //N ��������K����������M��VIP�������� 

//��user ���յ���ʱ��������� 
int cmp(User u1,User u2){
	if(u1.start_hour == u2.start_hour){
		if(u1.start_min == u2.start_min){
			return u1.start_sec < u2.start_sec;
		}
		else return u1.start_min < u2.start_min;
	}
	else return u1.start_hour < u2.start_hour;
}

int getSec(){
	int startSec = 0;	//��ʼ������ 
	
} 

//���ʼ��������뵽������ 
void init(){
	int i,j;
	for(i = 1;i <= K;i++ ){//��ʼ�� ��Ա���뵽���ӣ����У��� 
		
	} 
}

int main(){
	cin >> N;
	int i,j;
	for(i = 0;i<N;i++){//�����û�����Ϣ 		
		scanf("%d:%d:%d %d %d",&user[i].start_hour, &user[i].start_min,&user[i].start_sec,&user[i].playTime,&user[i].isVip);
		
	}		
	
	cin >> K >> M;
	int vip[maxn] ={0};//��ʾ����vip���ӵ��±�� 
	int vipTable = 0;
	for(i= 0;i< M;i++){
		cin >> vipTable;
		vip[i] = vipTable; //��ʾ��������� vipTable 
	}
	
	sort(user,user+N,cmp);//���û��������� 
	queue<int> que[maxn];//que �Ķ�ά����  
	//������е��±�����Ӻ�һ�£����Ǵ�1��ʼ 
	
	for(i = 0;i< N;i++){
		printf("%02d:%02d:%02d\n",user[i].start_hour ,user[i].start_min ,user[i].start_sec );
	}
	
	//��ʵ����ʡ�Ե�һ���ĳ�ʼ������
	int curTable[maxn]={0};//��ʾÿ�����ӵĵ�ǰʱ��  ,��ʼ����ֵΪ0 
		
	//��ʼ�� N ���˽��з��� 
	for(i = 0;i< N;i++){
		int minTime = 0x3fffffff ;//��С��ʱ�� 
		int minTable = -1;//��С�Ĵ��ں� 	
		j = M;//����Ϊ��ʼֵ 
		if(user[i].isVip == 1) {//���жϵ�ǰ�û��Ƿ���vip 
			for(j = 0;j< M;j++){//�����ж��Ƿ���vip���� 
				if(que[vip[j]].empty()) {//����ö���Ϊ�գ���Ž�ȥ 					
					que[vip[j]].push(i);//��i����û���ӵ������� 
					break; 
				} 
			}
		}
		if(j < M){//˵��vip������δ���꣬��ʱ��ֱ�ӽ�����һ���û� 
			continue;
		}
		
		for(j = 1;j <= K;j++ ){ //�ҳ�һ����Ч������ �����ӺŴ�1��ʼ 		
			if(!que[j].empty()) {//��������ӵĶ��зǿ� 
				int tempTime = curTable[j] + user[que[j].front()].playTime ;//�������ӺŴ� 1 ��ʼ 
				if(minTime > tempTime){//���minTime ���ڵ�ǰ�� tempTime 
					minTime = tempTime;
					minTable = j ;//��ǰ������ 
				} 
			}
			else {//����ֱ��ʹ�� 
				if(minTime > 0){//���minTime ���ڵ�ǰ�� tempTime 
					minTime = 0;//ֱ�ӽ���ǰ��ʱ����Ϊ0 				
					minTable = j ;//��ǰ������ 
				} 				
			}		
		}
		if(minTime != 0){//������ǵ�һ����� 
			curTable[minTable] +=  user[que[minTable].front()].playTime;	//�������ŵ�ʱ�� 
			user[que[minTable].front()].playTime = curTable[minTable];//�����û������ʱ�� 	
			que[minTable].pop();//�����׳���
			que[minTable].push(i); //��ӵ�ǰ���û� 
		} 
		else{
			que[minTable].push(i);//���򽫵�ǰ���û���� 			
		}		
	}  
	
	//����ʣ��� table ��ʱ�� 
	for(i= 1 ;i<= K;i++){
		while(!que[i].empty()){//������зǿ� 
			curTable[i] +=  user[que[i].front()].playTime;	//�������ŵ�ʱ�� 
			user[que[i].front()].playTime = curTable[i];//�����û������ʱ�� 
			que[i].pop();//����				
		}
	}	
} 
/*
9
20:52:00 10 0
08:00:00 20 0
08:02:00 30 0
20:51:00 10 0
08:10:00 5 0
08:12:00 10 1
20:50:00 10 0
08:01:30 15 1
20:53:00 10 1
3 1
2

*/
