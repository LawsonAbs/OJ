#include <cstdio> 
#include <cstring>
#include <algorithm>
using namespace std;

/*
1.�����ѵ�������ô֪���ж��ٸ�������Ȼ��ֱ���俼���е��˽������� 
2.���ǿ���ʹ��sort�Խṹ���ĳһ���ֽ������� 
*/ 

typedef struct{
	char name[20];
	int grade;//���� 
	int flag ; //������ 
	int localRank;//�������� 
	int finalRank;//�������� 
}Student;

Student stu[10000];

bool cmp(Student s1,Student s2){
	return s1.grade>s2.grade;		
}

int main(){
	int number , j = 0 ,i = 0 , k;
	scanf("%d",&number);
	
	while(j < number){ 
		scanf("%d",&k);//��ʾĳһ�����ж�����
		for(int m = 0;m<k;m++){
			scanf("%s %d",stu[i].name,&stu[i].grade);//���뿼����Ϣ
			stu[i++].flag = j+1;//ȷ�Ͽ�����						
		}		
		//sort(stu[i-k],stu[i]);--->��ôд�ǲ���ȷ�� �� 
		sort(stu + i - k,stu + i,cmp);//���в�������
		
		//���е��ǵ������� 
		int l  = 0;
		for(int m = i-k;m < i;m++){
			if(stu[m].grade == stu[m-1].grade && m!=i - k){
				stu[m].localRank = stu[m-1].localRank;
			}
			else 
				stu[m].localRank = l+1;
			l++;
			//printf("%s %d %d\n",stu[m].name,stu[m].grade,stu[m].localRank);
		}		
		j++; 
	}
		
	int total = i;//��ʾ�ܹ������� 
	sort(stu,stu+total,cmp);//�����е��˽������� 

	for(int l = 0;l<total;l++){
		if(stu[l].grade == stu[l-1].grade && l != 0){
				stu[l].finalRank = stu[l-1].finalRank;
			}
		else 
			stu[l].finalRank = l+1;	
	} 

	printf("%d\n",total);
	//printf("---�����Ľ����---\n");
	for(i = 0;i<total;i++){
		printf("%s %d %d %d\n",stu[i].name,stu[i].finalRank,stu[i].flag,stu[i].localRank);
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


