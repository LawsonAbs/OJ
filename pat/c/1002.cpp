#include <stdio.h>
#include <algorithm>
using namespace std;
//1.double������lf 
//2.������Ҫע��û�����һ�����ݺ���û�ж���Ŀո񣡣���Ҫ���ǵĺ�ȫ��
//����˵��������Ҫȷ����һ�������һ�����ݣ��Լ�������ʽȫΪ0ʱ����ô����� 

typedef struct {
	int exponent;
	double coeffcient;		
}Ploy;


bool cmp(Ploy a,Ploy b){
	return a.exponent>b.exponent;
}

int main(){
	Ploy p1[20],p2[20];	
	int A,B;
	scanf("%d",&A);
	int i = 0 ,j = 0;
	int k  = 0,l = 0;//��������p1��p2 
	
	for(i = 0;i<A;i++){
		scanf("%d %lf",&p1[i].exponent,&p1[i].coeffcient);		
	}	
	 
	scanf("%d",&B);
	for(j = 0;j<B;j++){
		scanf("%d %lf",&p2[j].exponent,&p2[j].coeffcient);		
	}

	int lengthP1 = i,lenghtP2 = j;//����������ԭ��	 
	
	while(l<lenghtP2){		
		for(k = 0;k<lengthP1;k++){
			if(p1[k].exponent == p2[l].exponent){				
				p1[k].coeffcient +=p2[l].coeffcient;				
				break;//��������ѭ�� 
			}
		} 
		
		if(k == lengthP1){//˵��û���ҵ���ͬ�� 
			p1[lengthP1++] = p2[l]; 
		} 
		l++;
	}
	
	sort(p1,p1+lengthP1,cmp);
	
	int count = 0;
	for(i = 0;i<lengthP1;i++){		
		if(p1[i].coeffcient != 0){
			count++;
		}
	}
	if(count !=0){
		printf("%d ",count);//����ָ�����count 
	}
	else{
		printf("%d",count);//����ָ�����count 
	}
	
	
	
	//ʹ��count2��Ŀ����Ϊ�˿������һ�����ʱû�ж���Ŀո� 
	int count2= 0;
	for(i = 0;i<lengthP1;i++){
		if(p1[i].coeffcient == 0){
			continue;
		}
		else{
			if(count2 != count -1){
				count2++;
				printf("%d %.1lf ",p1[i].exponent,p1[i].coeffcient);	
			}
			else{
				printf("%d %.1lf",p1[i].exponent,p1[i].coeffcient);
			}		
		}
	}		
} 

/***
3 2 1.5 1 0.5 0 3
1 100 2.3
4 3 2.4 2 1.5 1 0.5 0 3


2 2 -1.5 1 2.4
2 2 1.5 1 -2.4
**/

