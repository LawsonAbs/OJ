#include <cstdio> 
#include <cstring>
#include <algorithm>
using namespace std;

/*
1.本题难点在于怎么知道有多少个考场，然后分别对其考场中的人进行排名 
2.我们可以使用sort对结构体的某一部分进行排序 
*/ 

typedef struct{
	char name[20];
	int grade;//分数 
	int flag ; //考场号 
	int localRank;//考场排名 
	int finalRank;//最终排名 
}Student;

Student stu[10000];

bool cmp(Student s1,Student s2){
	return s1.grade>s2.grade;		
}

int main(){
	int number , j = 0 ,i = 0 , k;
	scanf("%d",&number);
	
	while(j < number){ 
		scanf("%d",&k);//表示某一考场有多少人
		for(int m = 0;m<k;m++){
			scanf("%s %d",stu[i].name,&stu[i].grade);//输入考生信息
			stu[i++].flag = j+1;//确认考场号						
		}		
		//sort(stu[i-k],stu[i]);--->这么写是不正确的 ， 
		sort(stu + i - k,stu + i,cmp);//进行部分排序
		
		//进行的是当地排名 
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
		
	int total = i;//表示总共的人数 
	sort(stu,stu+total,cmp);//对所有的人进行排序 

	for(int l = 0;l<total;l++){
		if(stu[l].grade == stu[l-1].grade && l != 0){
				stu[l].finalRank = stu[l-1].finalRank;
			}
		else 
			stu[l].finalRank = l+1;	
	} 

	printf("%d\n",total);
	//printf("---排序后的结果：---\n");
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


