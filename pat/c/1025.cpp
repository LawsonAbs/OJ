#include <stdio.h> 
#include <string.h>
#include <algorithm>
using namespace std;

/*
1.�����ѵ�������ô֪���ж��ٸ�������Ȼ��ֱ���俼���е��˽������� 
*/ 

typedef struct{
	char name[20];
	int grade;//��ʾ���� 
	int flag ; //��־������ 
	int localrank;//�������� 
	int finalRank;//�������� 
}Student;

Student stu[30010];

//�Ȱ���������-->�ٰ����������� 
bool cmp(Student s1,Student s2){
	if(s1.flag!=s2.flag)
		return s1.flag<s2.flag; 
	else if(s1.grade == s2.grade){
		int s = strcmp(s1.name,s2.name);		
		return s<0;
	}
	else
	return s1.grade > s2.grade;	
}

bool cmp2(Student s1,Student s2){
	if(s1.grade == s2.grade){
		int s = strcmp(s1.name,s2.name);
		
		return s<0;
	}
	else
	return s1.grade > s2.grade;
}

int main(){
	int number , j = 0 , i= 0 , k;
	scanf("%d",&number);
	
	int record[30001] ;
	while(j < number){		
		scanf("%d",&k);
		record[j] = k;//��ʾĳһ�����ж�����
		
		while(k--){
			scanf("%s %d",stu[i].name,&stu[i].grade);//���뿼����Ϣ
			stu[i++].flag = j+1;//ȷ�Ͽ�����			
		}
		j++; 
	}		
	sort(stu,stu+i,cmp);	
	
	
	int sum = 0;
	for(int m = 0;m < j;m++){
		int a = 0;
		for(int l = sum;l < sum + record[m];l++){
			if(stu[l].grade == stu[l-1].grade && l != sum){
				stu[l].localrank = stu[l-1].localrank;
			}
			else
				stu[l].localrank = a+1;
			//printf("%d ",stu[l].localrank);
			a++;
		}
		sum += record[m] ;//��sum��ֵ�����ۼ� 		
	}
	
	printf("%d\n",i);
	sort(stu,stu+i,cmp2);
	for(int m = 0;m<i;m++){
		if(stu[m].grade == stu[m-1].grade && m!=0){
			stu[m].finalRank  = stu[m-1].finalRank;
		}
		else
			stu[m].finalRank = m+1;
		printf("%s %d %d %d\n",stu[m].name,stu[m].finalRank,stu[m].flag,stu[m].localrank);
	}
}

/**
2
5
1234567890001 95
1234567890005 100
1234567890003 95
1234567890002 77
1234567890004 85
4
1234567890013 65
1234567890011 25
1234567890014 100
1234567890012 85
**/
