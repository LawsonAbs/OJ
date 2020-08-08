#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;


typedef struct{
	char name[10];//����
	int age;//����
	int worth;//�ʲ� 
}Rich;

Rich rich[100002];
Rich temp[10000];

//������������ 
bool cmpA(Rich r1,Rich r2){
	return r1.age < r2.age;
}

//�����ʲ����� 
bool cmpW(Rich r1,Rich r2){
	if(r1.worth != r2.worth ){
		return r1.worth > r2.worth;	
	}
	else if(r1.age != r2.age ){
		return r1.age < r2.age;
	}
	else{		
		return (strcmp(r1.name ,r2.name) < 0);
	}		
} 

int main(){
	int  number ,query;//����	 
	scanf("%d %d",&number,&query);
	
	int i ;
	for(i = 0;i< number;i++){
		scanf("%s %d %d",rich[i].name,&rich[i].age,&rich[i].worth);
	}	 
	
	int queryNumber,minAge,maxAge;
	int count  = 0;
	for(i = 0;i<query;i++){
		count++;
		scanf("%d %d %d",&queryNumber,&minAge,&maxAge);
	
		//��������������ʱ 
		int j = 0;
		for(int k = 0;k<number;k++){
			if ( rich[k].age >= minAge && rich[k].age <= maxAge ){			
				temp[j++] = rich[k];//�ݴ�Ϊһ���µĽṹ�� 				
			}			
		}
	
		if(j == 0){//û�з�����������
			printf("Case #%d:\n",count); 
			printf("None\n");
		}
		else{
			//�����ʲ����� 
			sort(temp,temp+j,cmpW);	
			printf("Case #%d:\n",count);
			if(j<queryNumber){
				queryNumber = j;
			}		
			for(int m = 0;m<queryNumber;m++){
				printf("%s %d %d\n",temp[m].name,temp[m].age,temp[m].worth);
			} 
		}
	}
}
/**
12 4
Zoe_Bill 35 2333
Bob_Volk 24 5888
Anny_Cin 95 999999
Williams 30 -22
Cindy 76 76000
Alice 18 88888
Joe_Mike 32 3222
Michael 5 300000
Rosemary 40 5888
Dobby 24 5888
Billy 24 5888
Nobody 5 0
4 15 45
4 30 35
4 5 95
1 45 50
*/ 
