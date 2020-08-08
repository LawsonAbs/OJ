#include <stdio.h>
#include <algorithm>
using namespace std;


typedef struct{
  int id;
  int c;//grade和sort
  int m;
  int e;
  int a;    
}Student;



bool cmpC(Student s1,Student s2){
  return s1.c > s2.c; 
}

bool cmpM(Student s1,Student s2){
  return s1.m > s2.m; 
}

bool cmpE(Student s1,Student s2){
  return s1.e > s2.e; 
}

bool cmpA(Student s1,Student s2){
  return s1.a > s2.a; 
}

int ran[1000000][4];
int name[100000];//用来存储学号
Student stu[1000000];

int main(){

  
  int n,m;
  scanf("%d %d",&n,&m);
  
  int i ;
  for(i = 0;i<n;i++){
    scanf("%d %d %d %d",&stu[i].id,&stu[i].c,&stu[i].m,&stu[i].e);
    stu[i].a = (stu[i].c + stu[i].m + stu[i].e) /3;
  }
    
  //按照平均成绩排名 
  sort(stu,stu+n,cmpA);
  for(i = 0;i<n;i++){
  	if(stu[i].a == stu[i-1].a && i!=0){
  		ran[stu[i].id][0] = ran[stu[i-1].id][0];
	  }
	  else    ran[stu[i].id][0] = i+1;
  } //printf("\n");
  
    
  //按照C语言成绩排名 
  sort(stu,stu+n,cmpC);
  for(i = 0;i<n;i++){
  	if(stu[i].c == stu[i-1].c && i!=0){
  		ran[stu[i].id][1] = ran[stu[i-1].id][1];
	  }
	  else 
    ran[stu[i].id][1] = i + 1;
  }// printf("\n");
  
  //按照数学M成绩排名 
  sort(stu,stu+n,cmpM);
  for(i = 0;i<n;i++){
  	if(stu[i].m == stu[i-1].m && i!=0){
  		ran[stu[i].id][2] = ran[stu[i-1].id][2];
	  }
	  else 
    ran[stu[i].id][2]= i + 1;    
  }
  
  //按照英语E成绩排名 
  sort(stu,stu+n,cmpE);
  for(i = 0;i<n;i++){
  	if(stu[i].e == stu[i-1].e && i!=0){
  		ran[stu[i].id][3] = ran[stu[i-1].id][3];
	  }
	  else 
    ran[stu[i].id][3] = i + 1;    
  }
    
	char course[4] = {'A','C','M','E'};
	
  //输入查询姓名 
  for(i = 0;i<m;i++){
    scanf("%d",&name[i]);
    int min = 1000000;//附上平均成绩值
    int k = 0; 
    for(int j = 0;j<4;j++){
      if(min > ran[name[i]][j] && ran[name[i]][j]!=0) {
        min = ran[name[i]][j];
        k = j;
      }
    }
    if(min == 1000000){
      printf("N/A\n");
      continue;
    }
    else{    
      printf("%d %c",min,course[k]);     
    }
  } 
} 


/***
5 6
310101 98 85 88
310102 70 95 88
310103 82 87 94
310104 91 91 91
310105 85 90 90
310101
310102
310103
310104
310105
999999
**/



