#include <stdio.h>
#include <algorithm>
using namespace std;

#define maxSize 100010 

//�����Ӵ�С���� 
bool cmp1(int a ,int b){
	return a > b;
}


//������С�������� 
bool cmp2(int a ,int b){
	return a < b;
}



int main(){
	int NC, NP;//number of coupon,products
	int cous1[maxSize] ,cous2[maxSize],pro1[maxSize],pro2[maxSize];//�ֱ������洢���������� 
	scanf("%d",&NC);
	int i ,temp;
	
	//�����Ż�ȯ
	int a = 0, b= 0;//�±� 
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
	//�����Ʒ�۸� 
	int c= 0, d =0;//����Ϊ0 
	for(i = 0;i<NP;i++){
		scanf("%d",&temp);
		if(temp >= 0){
			pro1[c++] = temp; 
		}
		else{
			pro2[d++] = temp;
		}
	}
	
	//ȫ���Ӹߵ������� 
	sort(cous1,cous1+a,cmp1);//����	
	sort(cous2,cous2+b,cmp2);//���� 
	
	sort(pro1,pro1+c,cmp1);		//���� 
	sort(pro2,pro2+d,cmp2);//���� 
	
	int total = 0;//��������
	for(i = 0;i<a && i < c;i++){//ͬʱȡ���� 
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
