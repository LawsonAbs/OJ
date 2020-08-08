#include <stdio.h>
#include <algorithm>
using namespace std;

#define maxSize 100010 

//正数从大到小排序 
bool cmp1(int a ,int b){
	return a > b;
}


//负数从小到大排序 
bool cmp2(int a ,int b){
	return a < b;
}



int main(){
	int NC, NP;//number of coupon,products
	int cous1[maxSize] ,cous2[maxSize],pro1[maxSize],pro2[maxSize];//分别用来存储正数，负数 
	scanf("%d",&NC);
	int i ,temp;
	
	//输入优惠券
	int a = 0, b= 0;//下标 
	for(i = 0;i<NC;i++){
		scanf("%d",&temp);
		if(temp >= 0){
			cous1[a++] = temp; 
		}
		else{
			cous2[b++] = temp;
		}
	}
	
	scanf("%d",&NP);
	//输入产品价格 
	int c= 0, d =0;//重置为0 
	for(i = 0;i<NP;i++){
		scanf("%d",&temp);
		if(temp >= 0){
			pro1[c++] = temp; 
		}
		else{
			pro2[d++] = temp;
		}
	}
	
	//全部从高到低排序 
	sort(cous1,cous1+a,cmp1);//正数	
	sort(cous2,cous2+b,cmp2);//负数 
	
	sort(pro1,pro1+c,cmp1);		//正数 
	sort(pro2,pro2+d,cmp2);//负数 
	
	int total = 0;//代表总数
	for(i = 0;i<a && i < c;i++){//同时取正数 
		total +=(cous1[i] * pro1[i]); 
	} 
	for(i = 0;i<b && i<d ;i++){
		total += (cous2[i] * pro2[i]);
	}
	printf("%d",total);
}

/**
4
1 2 4 -1
4
7 6 -2 -3

4
1 2 0 -3 
4
7 6 -2 -3

4
1 2 0 -3 
4
0 0 0 0


*/
