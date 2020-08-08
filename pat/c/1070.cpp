#include <stdio.h>
#include <algorithm>
using namespace std;

#define N 1001
typedef struct{
	double inventory;//����
	double money;//�ܼ� 
	double price;//���� 
}MoonCake;


bool cmp(MoonCake a,MoonCake b){
	return a.price > b.price; 
}

int main(){	
	int n ,d;
	scanf("%d %d",&n,&d);
	int i ;
	MoonCake moonCake[N];
	for(i = 0;i<n;i++){
		scanf("%lf",&moonCake[i].inventory); 
	}
	for(i = 0;i<n;i++){
		scanf("%lf",&moonCake[i].money);
		moonCake[i].price = moonCake[i].money /moonCake[i].inventory;
	}
		
	sort(moonCake,moonCake+n,cmp);
	
	double profit = 0;
	i = 0;
	while(d>0){		
		if(d > moonCake[i].inventory){
			profit += moonCake[i].money;//ֱ�ӵ�����money 
			d -= moonCake[i].inventory;
		}
		else{
			profit += d * moonCake[i].price;
			d = 0; 
		} 
		i++;	
	}
	printf("%.2lf",profit);
} 
/*
3 200
180 150 100
7.5 7.2 4.5
*/
