#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define maxN 100010
 
/*
1.ʹ��Ԥ���� 
*/

typedef struct{
	char name[10];//����
	int age;//����
	int worth;//�ʲ� 
}Rich;

Rich rich[maxN];
Rich temp[maxN];//�ݴ�ǰһ�ٵ��� 

//�Ը����������� 
bool cmp(Rich r1,Rich r2){
	if(r1.worth!=r2.worth)
		return r1.worth > r2.worth ;
	else if(r1.worth == r2.worth){
		if(r1.age!=r2.age){
			return r1.age < r2.age;
		}
		else
			return strcmp(r1.name,r2.name)< 0;		
	}
}

int main(){
	int  number ,query;//����	 
	scanf("%d %d",&number,&query);
	
	int i ;
	for(i = 0;i< number;i++){
		scanf("%s %d %d",rich[i].name,&rich[i].age,&rich[i].worth);
	}
	
	//��������ݼ����� 
	sort(rich,rich+number,cmp);	
	/*
	1.��Ϊ��ĿҪ����˵��M=100Ϊ����������������Լ���ÿ����������ֻ��100�ˣ���Age[maxN]����������洢
	ÿ�������ж����� 
	*/ 
	int Age[maxN] = {0};
	
	int tempNum = 0;
	for(int i = 0;i<number;i++){
		if(Age[rich[i].age]<100){//���˵����Ϊrich[i].age������С��100ʱ 
			Age[rich[i].age]++;
			temp[tempNum++] = rich[i]; 
		}
	} 
	 	
	int queryNumber,minAge,maxAge;
	
	for(i = 1;i <= query;i++){		
		scanf("%d %d %d",&queryNumber,&minAge,&maxAge);		
		int count  = 0;//ÿ��������Ҫ��ѯ�����ݣ���count���� 
		printf("Case #%d:\n",i);
		
		for(int i = 0;i<tempNum && count < queryNumber; i++){
			if(temp[i].age >= minAge && temp[i].age <= maxAge){
				printf("%s %d %d\n",temp[i].name,temp[i].age,temp[i].worth);
				count ++;
			}
		} 
		if(count == 0){
			printf("None\n");
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
