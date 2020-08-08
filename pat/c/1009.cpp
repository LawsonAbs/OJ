#include <stdio.h>
#include <algorithm>
using namespace std;
//1.double数据用lf 
//2.这里需要注意没有最后一个数据后面没有多余的空格！！需要考虑的很全面
//比如说，我们需要确定哪一个是最后一个数据；以及当多项式全为0时该怎么输出！ 

typedef struct {
	int exponent;
	double coeffcient;		
}Ploy;


bool cmp(Ploy a,Ploy b){
	return a.exponent>b.exponent;
}

int main(){
	Ploy p1[20],p2[20], p3; //p3用来暂存存储相乘的结果
	Ploy p4[1000];//p4用来存储最终的结果
	 
	int A,B,i = 0 ,j = 0;
	scanf("%d",&A);	
		
	for(i = 0;i<A;i++){
		scanf("%d %lf",&p1[i].exponent,&p1[i].coeffcient);		
	}	
	 
	scanf("%d",&B);
	for(j = 0;j<B;j++){
		scanf("%d %lf",&p2[j].exponent,&p2[j].coeffcient);		
	}
	int lengthP1 = i,lenghtP2 = j;//保存两个的原长	 
		
	/*进行多项式的乘法操作 */
	int k  = 0,l = 0;//用来遍历p1和p2
	int countOfP4 = 0;//计数 
	int a ;//作为循环变量 
	while(l<lenghtP2){		
		for(k = 0;k<lengthP1;k++){
			p3.coeffcient = p1[k].coeffcient * p2[l].coeffcient;//系数相乘
			p3.exponent = p1[k].exponent + p2[l].exponent;//指数相加 
			
			for(a = 0;a<countOfP4;a++){
				if(p3.exponent == p4[a].exponent){				
					p4[a].coeffcient +=p3.coeffcient;				
					break;//并且跳出循环 
				}
			}
			
			//如果说没有找到相同项 
			if(a == countOfP4){
				p4[countOfP4++] = p3;//则直接进行赋值 
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
		printf("%d ",count);//非零指数项共有count 
	}
	else{
		printf("%d",count);//非零指数项共有count 
	}	
	
	//使用count2的目的是为了控制最后一次输出时没有多余的空格 
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

