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
	Ploy p1[20],p2[20], p3; //p3�����ݴ�洢��˵Ľ��
	Ploy p4[1000];//p4�����洢���յĽ��
	 
	int A,B,i = 0 ,j = 0;
	scanf("%d",&A);	
		
	for(i = 0;i<A;i++){
		scanf("%d %lf",&p1[i].exponent,&p1[i].coeffcient);		
	}	
	 
	scanf("%d",&B);
	for(j = 0;j<B;j++){
		scanf("%d %lf",&p2[j].exponent,&p2[j].coeffcient);		
	}
	int lengthP1 = i,lenghtP2 = j;//����������ԭ��	 
		
	/*���ж���ʽ�ĳ˷����� */
	int k  = 0,l = 0;//��������p1��p2
	int countOfP4 = 0;//���� 
	int a ;//��Ϊѭ������ 
	while(l<lenghtP2){		
		for(k = 0;k<lengthP1;k++){
			p3.coeffcient = p1[k].coeffcient * p2[l].coeffcient;//ϵ�����
			p3.exponent = p1[k].exponent + p2[l].exponent;//ָ����� 
			
			for(a = 0;a<countOfP4;a++){
				if(p3.exponent == p4[a].exponent){				
					p4[a].coeffcient +=p3.coeffcient;				
					break;//��������ѭ�� 
				}
			}
			
			//���˵û���ҵ���ͬ�� 
			if(a == countOfP4){
				p4[countOfP4++] = p3;//��ֱ�ӽ��и�ֵ 
			}					
		} 				
		l++;
	}
	
	sort(p4,p4+countOfP4,cmp);
	
	int count = 0;
	for(i = 0;i<countOfP4;i++){		
		if(p4[i].coeffcient != 0){
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
	for(i = 0;i<countOfP4;i++){
		if(p4[i].coeffcient == 0){
			continue;
		}
		else{
			if(count2 != count -1){
				count2++;
				printf("%d %.1lf ",p4[i].exponent,p4[i].coeffcient);	
			}
			else{
				printf("%d %.1lf",p4[i].exponent,p4[i].coeffcient);
			}		
		}
	}		
} 

/***
2 1 2.4 0 3.2
2 2 1.5 1 0.5
**/

