#include <stdio.h>
#include <algorithm>
using namespace std;

#define maxSize 10000

//1.ϵͳ�ĳ�ʼ�����ݻ�ܹ� 

typedef struct{
	double price,dis;//��ʾ�ͼۣ������ݵľ��� 
}Station;

bool cmp(Station s1,Station s2){
	return s1.dis < s2.dis;//�����ݾ����С���� 
}

int main(){
	int cMax,D,dAvg,N;//������������·�̣���λ��ʻ���룬��վ��
	scanf("%d %d %d %d",&cMax,&D,&dAvg,&N); 
	
	Station sta[maxSize];
	int i ;
	for(i = 0;i<N;i++){
		scanf("%lf %lf",&sta[i].price,&sta[i].dis);
	} 
	
	sta[i].price = 0,sta[i++].dis = D; 
	sort(sta,sta+N,cmp);
	
	//Ѱ�ҵ�ǰվ����ĵ�һ�������ͼ۱ȵ�ǰվ���б��˵�վ
	double priceNow = sta[0].price;//��ʾ��ǰվ���ͼ� 
	double total = 0;//�ܹ����ѵ���Ǯ 
	double maxDis = cMax * dAvg;//���������ߵ���Զ����
	double tank = 0;//��ʾ��ǰ�������������	 
	int now = 0;//��ǰ��λ�� 
	
	if(sta[0].dis!=0){
		printf("The maximum travel distance = 0.00\n");
		return 0;
	} 
	
	while(now < N){					
		//�۲��Ƿ��ܹ������յ� ��������ܣ�������ѭ�� 
		if(sta[now+1].dis - sta[now].dis > maxDis)		break;
		
		//1.������û�������ܹ��������ͼ۱ȵ�ǰ�͵�վ 
		int flag = 1;
		//need Ϊ������һվ��Ҫ������
		double need = 0; 
		for(i = now+1 ;i<=N ;i++){						
			//���˵������ڣ��ȵ�ǰվ���ͼۻ����˵�վ
			//Խ�緢��Խ�ã���Ǳ��˼���ҵ������С�ڵ�ǰ���ͼ�վ������ 
			if(sta[i].price < sta[now].price && maxDis >= (sta[i].dis - sta[now].dis) ){								
				need = (sta[i].dis - sta[now].dis) / dAvg;
				if(tank < need){//������� 
					total += ( ( (sta[i].dis - sta[now].dis) / dAvg - tank) * sta[now].price );
					tank = 0;//�����ͼ۵͵�վ����Ϊ0 
				}
				else{//������Ļ�����ֱ����� 
					tank -=need;
				}							
				now = i;//����iվ��Ϊ��ǰվ
				flag = 0;//�򲻽�������2 
				break;//����ѭ�� 				
			}
		}
		
		//2.���û���ҵ��ȵ�ǰվ�ͼ۵͵�վ���������ܵ���վ���ͼ۾����ܵ͵�վ 
		if(flag){
			//���δ����վ����͵��ͼ�--->��֤�Ƚ������ĵ�һ��վ��Ҫ��һ�� 
			double minPrice = sta[now+1].price + 1 ; 
			int k;//�洢����ͼ۵��Ǹ�վ���±� 
				 
			for(i = now+1;i<N;i++){
				//����վ���ͼ�С��minPriceʱ���ҿɵ��������͵��ͼ� 
				if( minPrice > sta[i].price && maxDis >= (sta[i].dis - sta[now].dis)){
					minPrice = sta[i].price;										
					//��Ҫ������ 
					need = (sta[i].dis - sta[now].dis) / dAvg; 	
					k = i;				
				}
			}
			//���������Ҫ��Ǯ 
			total += (cMax - tank)	 * sta[now].price ;	
			
			//������� 
			tank = cMax; 
			
			//���ʣ���� 
			tank -=need;					
			now = k;//�仯��ǰվ 
		}			
	} 
	if(now == N){
		printf("%.2lf",total); 
	} 
	//������ܵ��������ܹ��������Զ���� 
	else{
		printf("The maximum travel distance = %.2lf\n",sta[now].dis + maxDis);
	}
}

/**
50 1300 12 8
6.00 1250
7.00 600
7.00 150
7.10 0
7.20 200
7.50 400
7.30 1000
6.85 300

50 1300 12 2
7.10 0
7.00 600

50 1300 12 2
7.10 1
7.00 600
*/ 
