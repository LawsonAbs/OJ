/**
1.��ϸ�������⣬�۲���еĴ�С�Ӷ�����������һ�������� 
2.��Ŀ������ǣ���Ҫ���з�����˶�����ǰ����ģ������˵ȴ��ڣ����Ǵ��ڵ��� 
3.�˿��봰�ڵ��±궼�Ǵ�1��ʼ���� 
*/
#include<cstdio>
#include<queue>
using namespace std;
#define maxn 1002

struct Window{
	queue<int> q;//���д洢�˵����
	int endTime,popTime;//��β ���� 
}; 

int convertToMinute(int h,int m){
	return h* 60 + m;//��ʱ��ת��Ϊ���� 
} 

Window win[20]//���ֻ��20������
int winNum, lineContain,customerNum,queryNum;
int startTime = 8 * 60;//�����ϰ��ʱ�� 
int ans[maxn] , needTime[maxn];//���������ʱ�䣨�±��1��ʼ��  ������Ҫ��ʱ�䣨�±��1��ʼ�� 

int main(){
	scanf("%d %d %d %d",&winNum,&lineContain,&customerNum,&queryNum);
	int i;
	for(i = 0;i< customerNum;i++){//�˿��±��1��ʼ 
		scanf("%d",needTime[i]);//��Ҫ�����ʱ��
	} 
	for(i = 0;i< queryNum;i++){
		scanf("%d",&query[i]);//�����ѯ�����	
	}
	
	int index = i;//��indexλ�˿���δ��� 
	for(i = 0;i < customerNum && i < (lineContain * winNum) ;i++){//����ѭ�����  ����ͬʱ����������ʱ�� 
		win[i%winNum].q.push(i);
		win[i%winNum].endTime += needTime[i];//���´��ڵķ������ʱ��
		ans[i] = win[i%n].endTime;		
	}
	
	
	int j; 
	int count = 1; 
	for(;i <= customerNum ;i++){//����ʣ��δ��ӵ��� 
		for(j = 0;j < winNum;j++){//�����еĴ�������һ����������Ĵ��� 
			win[j].popTime = win[j].q.front()
			ans[count++] = win[j].endTime; 
		}
	} 
}
/*
2 2 7 5
1 2 6 4 3 534 2
3 4 5 6 7
***/
  
