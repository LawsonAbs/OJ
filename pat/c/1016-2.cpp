/*
1.һ��Ҫע�⴦���˳�򣬱���˵����while()ѭ���У��ȼ������Ʒѣ�Ȼ���ٵ�����˳�����Ҫ�� 
*/ 

#include  <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

double rateStructure[24];//����һ��24Сʱ�ķ���

typedef struct{
	char name[21];
	int month, day, hour, minute;//�£��գ�ʱ���� 
	char line[10];
	int flag ; 
}record; 

record re[100];

bool cmp(record a,record b){
	int s = strcmp(a.name,b.name);
	if(s!=0) return s<0;
	else if(a.month!=b.month) return a.month<b.month;
	else if(a.day!=b.day) return a.day<b.day;
	else if(a.hour!=b.hour) return a.hour<b.hour;
	else return a.minute<b.minute;
}

int main(){
	int number;	 
	
	int i ;
	for(i = 0;i<24;i++){
		scanf("%lf",&rateStructure[i]);//����˰�ʽṹ --->ʹ��double�洢 
	}
	
	scanf("%d",&number);
	for(i = 0;i<number;i++){
		scanf("%s %d:%d:%d:%d %s",re[i].name,&re[i].month,&re[i].day,&re[i].hour,&re[i].minute,&re[i].line);
		re[i].flag = 1;//ȫ����Ϊ1 
	}
	
	sort(re,re+number,cmp);
//	for(i = 0;i<number;i++){
//		printf("%s %d:%d:%d:%d %s\n",re[i].name,re[i].month,re[i].day,re[i].hour,re[i].minute,re[i].line);
//	}
	
	i = 0;
	char on[10] ="on-line",off[10] = "off-line";
	
	record temp;
	strcpy(temp.name,"");	temp.month = 0;//����Ĭ�ϳ�ʼֵ 
	
	double total = 0;
	int k = 0;	
	double sum[10000];//��¼�ܻ���
	while(i < number){				
		//����������������绰��¼������� 		 
		if(strcmp(re[i].line,on) == 0 && strcmp(re[i+1].line,off) == 0 && strcmp(re[i].name,re[i+1].name) == 0 ){						 			
			//�����һ�ε�total 
			if(strcmp(temp.name,re[i].name)!=0 || temp.month!=re[i].month){
				int j = 0;
				k = 0;//���������� 
				for(j =0;j<k;j++){
					total += sum[j];		
				}
				
				if(total!=0){					
					printf("Total amount: %lf\n",total); 
					total = 0;
					
				}
				printf("%s %02d\n",re[i].name,re[i].month);//���customer��month		
			}									
			
			temp = re[i];//�ݴ����ֵ 
			printf("%s %02d\n",temp.name,temp.month);
			printf("%02d:%02d:%02d %02d:%02d:%02d ",re[i].day,re[i].hour,re[i].minute,re[i+1].day,re[i+1].hour,re[i+1].minute);//���һ��ͨ����¼�ľ���ʱ��
						
			int count = 0; 
			//ע��ѭ�������� 
			while(re[i].day < re[i+1].day || re[i].hour < re[i+1].hour || re[i].minute < re[i+1].minute){				
				count ++;//�ۼƷ����� 								
				sum[k] += rateStructure[re[i].hour];//��cents								
				//printf("%d %lf \n",re[i].hour,total);
				re[i].minute ++;//���������ϵ��� 
				
				if(re[i].minute == 60){
					re[i].hour++;
					re[i].minute =0;//����Ϊ0 
				}
				if(re[i].hour == 24){
					re[i].day++;
					re[i].hour = 0;//����Ϊ1
				}				
			}						
			printf("%d %lf\n",count,sum[k]); 
			k++;
			i++;//����������λ 			
		}					
		i++;
	}
	if(k!=0){
		for(int j = 0;j<k;j++){
			total +=sum[j];
		}
		printf("Total amount: %lf\n",total);
	} 
}


/***�������� 
10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10
10
CYLL 01:01:06:01 on-line
CYLL 01:28:16:05 off-line
CYJJ 01:01:07:00 off-line
CYLL 01:01:08:03 off-line
CYJJ 01:01:05:59 on-line
aaa 01:01:01:03 on-line
aaa 01:02:00:01 on-line
CYLL 01:28:15:41 on-line
aaa 01:05:02:24 on-line
aaa 01:04:23:59 off-line


10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10
6
CYLL 01:01:06:01 on-line
CYLL 01:28:16:05 off-line
CYJJ 01:01:07:00 off-line
CYLL 01:01:08:03 off-line
CYJJ 01:01:05:59 on-line
CYLL 01:28:15:41 on-line

*/
