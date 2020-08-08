/**
1.�ѵ�������ȴ���ʱ��ȫ��ʹ���������㡣 
*/ 
#include<cstdio>
#include<algorithm>
#include<vector> 
using namespace std;
#define maxn 10001

struct People{
	int arriveTime;
	int process;//��Ҫ�����ʱ��
};

vector<People> qu;//���˼��뵽������ 

bool cmp(People p1,People p2){
	return p1.arriveTime < p2.arriveTime;
}

int main(){
	int num,winNum;//������  �ܴ����� 
	int i;
	People tempPeo;//�ݴ��˵���Ϣ
	scanf("%d %d",&num,&winNum);
	int hour,minute,second,process;//ʱ �� �� 
	int boundary = 17 * 60 * 60 ;//17:00:00
	int count = 0;
	int window[maxn] ;//��ŵ��ǵ�ǰ���ڵ�ʱ�� 
	int startTime = 8 * 60 * 60;//��ʼʱ��
	
	for(i = 0;i<num;i++){
		scanf("%d:%d:%d %d",&hour,&minute,&second,&process);//����ÿ���˵���Ϣ
		tempPeo.arriveTime = hour*60*60 + minute * 60 + second;		
		tempPeo.process = process * 60;
		if(tempPeo.arriveTime <= boundary){
			qu.push_back(tempPeo);//��ÿ���˵���Ϣ��� 
			count ++; 
		} 
	}
	sort(qu.begin(),qu.end(),cmp);	
	for(i = 0;i < winNum;i++ ){//���մ�����  ���г�ʼ�� 
		window[i] = startTime; 
	} 

	double wait = 0; 
	int minStart;//��һ����С��ʼʱ�� ȥ����
	int index ;//��С��ʼʱ����±� 
	//��ʼ�������� 
	while(!qu.empty()){//���軹��ʣ������δ���� 
		minStart = 9999999;
		for(i = 0;i < winNum ;i++){//�ҵ�һ�����Է���Ĵ��� 
			if(window[i] < minStart){
				minStart = window[i];
				index = i;
			}
		}
		tempPeo = qu[0];
		qu.erase(qu.begin());//ɾ��ͷ 
		if(tempPeo.arriveTime < window[index]){//����ȵ�  ���ڻ�δ���� 
			wait += (window[index] - tempPeo.arriveTime); 
			window[index] += tempPeo.process;
		}	
		else{
			window[index] = tempPeo.arriveTime + tempPeo.process;
		} 
		//����ʱ�� ---> ��Ӧ�ý���ֻ�ǵ����ļ� ����ȡ���߽ϴ�ֵ�ټ��ϴ����ʱ�� 
	}
	double avg = ( wait / 60) / count; 
	printf("%.1lf",avg);
}
/**
7 3
07:55:00 16
17:00:01 2
07:59:59 15
08:01:00 60
08:00:00 30
08:00:02 2
08:03:00 10

2 1
07:55:00 16
17:00:01 2

2 2
08:00:00 16
07:58:00 2
*/
