#include <cstdio>

long long inf1 =  ((long long)1<<63)-1;//���ֵ 
long long inf2 = (-1)*inf1- 1;//��Сֵ 
  
void function(long long result ,long long a,long long b,long long c,int count){
	result = a+b;	
	if(result <= c){			
		printf("Case #%d: false\n",count);	
	}
	else
	{
		printf("Case #%d: true\n",count);
	}
	count++;	
} 

int main(){	
	int number;
	scanf("%d",&number);
	int count = 1;
	while(number--){		
		long long a ,b ,c;
		long long result ;
		scanf("%lld %lld %lld",&a,&b,&c);
		
		//�������ͬʱС��0�����п��ܳ����½�
		if(a<0 && b<0){
			if(inf2 - a > b){			
				printf("Case #%d: false\n",count);//a+b�϶�С��c 
			}
			else{
				function(result,a,b,c,count);			
			}			
		}
		
		//�������ͬʱ����0�����п��ܳ����Ͻ� 
		else if(a >0 && b>0){
			if(inf1 - a < b){			
				printf("Case #%d: true\n",count);//a+b�϶�����c 
			}
			else{
				function(result,a,b,c,count);			
			}
		}
		
		else{
			function(result,a,b,c,count);		
		}		
		count++;		
	}	
} 



/**
3
0 0 0
2 3 4
-9223372036854775807 -9223372036854775808 0
**/
