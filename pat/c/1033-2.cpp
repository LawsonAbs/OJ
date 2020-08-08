#include <stdio.h>
#include <algorithm>
using namespace std;

const int maxn = 510;
const int inf = 10000000;

struct station{
	double price,dis;
}st[maxn];

//���վ����С�������� 
bool cmp (station a,station b){
	return a.dis < b.dis;
}

int main(){
	int n;//��վ�� 
	double cMax,D,dAvg;//��������������յ���룬��λ������ʻ���� 
	scanf("%lf %lf %lf %d",&cMax,&D,&dAvg,&n);
	for(int i = 0;i<n;i++){
		scanf("%lf %lf",&st[i].price,&st[i].dis); 
	} 
	
	//Ϊ��ͳһ������ 
	st[n].price = 0,st[n].dis = D;
	
	//����������� 
	sort(st,st+n,cmp);
	
	//1.�����һ��վ�����ܵ����ֱ������ 
	if(st[0].dis!=0){
		printf("The maximun travel distance = 0.00\n");
	}
	//2.���򣬽��������ϵͳ 
	else{
		int now = 0;//���õ�ǰվ��Ϊnow 
		
		//ans���ܻ��ѣ�nowTank:������ǰ������Max:������ʻ���� 
		double ans = 0,nowTank = 0,Max = cMax * dAvg;
		
		//ÿ��ѭ����ѡ����һ����Ҫ�����վ 
		while(now < n){
			
			//3.ѡ��ӵ�ǰ����վ�ܴﵽ��Χ�ڵĵ�һ���ͼ۵��ڵ�ǰ�ͼ۵ļ���վ
			//���û�е��ڵ�ǰ�ͼ۵ļ���վ����ѡ����ͼ۸���Ǹ�			
			//-->ʹ�õķ����ǣ�priceMin���� !!��ʹ�Ҳ�����͵ģ�ҲҪ��һ���Ƚϵ͵ģ� 
			
			int k = -1;//k������ͼ۵ļ���վ��ţ���ʼ��Ϊ -1 
			double priceMin = inf;//����ͼۣ� ��ʼ��Ϊ�Ƚϴ��ֵ 
			for(int i = now + 1;i<=n && st[i].dis - st[now].dis <= Max ;i++){
				if(st[i].price < priceMin){//��������ͼ� ������һ���ȵ�ǰ��Ҫ�� 
					priceMin = st[i].price; 
					k = i;
								
					//����ҵ�һ���ȵ�ǰ�ͼۻ�Ҫ�͵ģ�ֱ���ж�ѭ��
					if(priceMin < st[now].price){
						break;
					} 										
				}
			}
			
			//����״̬�޷��ҵ�����վ���˳�ѭ�� 
			if(k == -1) break; 
			
			//����Ϊ���ҵ��ļ���վk,����ת�ƻ���
			//need Ϊ��now��k��Ҫ������			
			double need = (st[k].dis - st[now].dis) / dAvg;
			if(priceMin < st[now].price){//�������վk���ͼ۵��ڵ�ǰ�ͼ� 
				//ֻ���㹻�������վk����
				if(nowTank < need){//�����������need 
					ans += (need - nowTank) * st[now].price;//���㵽need��Ҫ�Ļ��� 
					nowTank = 0;//�������վk����������Ϊ0 
				} 
				else{
					nowTank -=need;//ֱ�ӵ��� 
				} 
			}
			else{
				ans +=(cMax - nowTank) * st[now].price;//���ͼ���
				nowTank = cMax - need;//���ʣ������ 
			} 
			now = k;//�������վk��������һ��ѭ�� 
		} 
		if(now == n){
			printf("%.2f\n",ans);
		} 
		else{
			printf("The maximum travel distance = %.2f\n",st[now].dis + Max);
		}
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
*/ 
