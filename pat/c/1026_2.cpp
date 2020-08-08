#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<set>
#define maxn 10005
 
using namespace std;

struct User{
	int start_hour;//�����ʱ�� 
	int start_min;
	int start_sec;
	int playTime;
	int startTime;//�û������ʱ�䣨sec�� 
	int endTime;//�û������ʱ�䣨minΪ��λ�� 
	int isVip;//��־�Ƿ���vip
	int end_hour; 
	int end_min;
	int end_sec;
	int flag = 0 ;//��־�Ƿ��Ѿ������  ��ʼ��Ϊ0 
};

User user[maxn];
queue<int> que[maxn];//que �Ķ�ά����  	//������е��±�����Ӻ�һ�£����Ǵ�1��ʼ 
set<int> vip ;//��ʾ����vip���ӵ��±�� 
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
	
	//ѭ���������ǣ� i<N  
	for(i = 0;i < N ;i++ ){//��ʼ�� N��Ա���뵽���ӣ����У��� 
		if(user[i].isVip == 0){//����Ƿ�vip 			 
			for(j = 0;j< K;j++){//�ҳ�һ�ź��ʵ����� 
				if(vip.find(j) == vip.end() && que[j].empty()){//���δ�ҵ������ӣ�˵������vip���� //����������û����					
					que[j].push(i);//��i����û� ���뵽����j��	
					user[i].flag = 1; 
					break;//������û�֮��Ӧ���˳�						
				}								
			}			
		}	
		else if(user[i].isVip == 1){//�����vip�û� 
			for(j = 0;j< K;j++){//�ҳ�һ�ź��ʵ����� 
				if(vip.find(j) != vip.end() && que[j].empty()){//����ҵ������ӣ�˵����vip����			//����������û���� 
					que[j].push(i);//��i����û� ���뵽����j��
					user[i].flag = 1; 
					break;				
				}
			}			
		}				
	}
}

int main(){
	cin >> N;
	int i,j;
	for(i = 0;i<N;i++){//�����û�����Ϣ 		
		scanf("%d:%d:%d %d %d",&user[i].start_hour, &user[i].start_min,&user[i].start_sec,&user[i].playTime,&user[i].isVip);		
	}		
	
	cin >> K >> M;	
	int vipTable = 0;
	for(i= 0;i< M;i++){
		cin >> vipTable;
		vip.insert(vipTable) ; //��ʾ��������� vipTable 
	}
	
	sort(user,user+N,cmp);//���û��������� 	
	
	cout <<"�Ŷӵ��û��У�\n"; 
	for(i = 0;i< N;i++){
		printf("i=%d,%02d:%02d:%02d\n",i,user[i].start_hour ,user[i].start_min ,user[i].start_sec );
	}
	
	init();//��ʼ������
	for(i = 0;i< K;i++){
		printf("i=%d,����=%d\n",i,que[i].front() );// 
	} 
	
	//��ʵ����ʡ�Ե�һ���ĳ�ʼ������
	int curTable[maxn]={0};//��ʾÿ�����ӵĵ�ǰʱ��  ,��ʼ����ֵΪ0 
		
	//��ʼ�� N ���˽��з��� 
	for(i = 0;i< N;i++){		
		if(user[i].flag == 1){// ����Ѿ�������ˣ����ж���һ�� 
			continue;
		} 
				
		int minTime = 0x3fffffff ;//��С��ʱ�� 
		int minTable = -1;//��С�Ĵ��ں� 			
				
		if(user[i].isVip == 1) {//���жϵ�ǰ�û��Ƿ���vip 
			for(j = 0;j< K;j++){//�����ж��Ƿ������� 				
				int tempTime = curTable[j] + user[que[j].front()].playTime ;//�������ӺŴ� 1 ��ʼ 
				if(minTime > tempTime){//���minTime ���ڵ�ǰ�� tempTime 
					minTime = tempTime;
					minTable = j ;//��ǰ������ 
				}					 				 
			}
		}
				
		else{//������Ϊһ����ͨ�û������ж� 
			for(j = 0;j < K;j++ ){ //�ҳ�һ����Ч������ �����ӺŴ�1��ʼ 		
				if(vip.find(j) == vip.end()){//�� vip ���� 
					int tempTime = curTable[j] + user[que[j].front()].playTime ;//�������ӺŴ� 0 ��ʼ 
					if(minTime > tempTime){//���minTime ���ڵ�ǰ�� tempTime 
						minTime = tempTime;
						minTable = j ;//��ǰ������ 
					} 
				}					
			}
		}		
						
		curTable[minTable] +=  user[que[minTable].front()].playTime;	//�������ŵ�ʱ�� 
		user[que[minTable].front()].endTime = curTable[minTable];//�����û������ʱ�� 	
		que[minTable].pop();//�����׳���
		que[minTable].push(i); //��ӵ�ǰ���û� 		 				
	}  
	
	//����ʣ��� table ��ʱ�� 
	for(i= 0 ;i< K;i++){
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
