#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 10010;

struct Student{
	int id;
	int score[6];
	int flag;
	int solve;
	int score_all;
}stu[maxn];

int n,k,m;
int full[6];
bool cmp(Student a,Student b){
	if(a.score_all!=b.score_all)	return a.score_all > b.score_all;
	else if(a.solve != b.solve)	return a.solve > b.solve;
	else return a.id < b.id;
}

void init(){
	for(int i = 1;i<= n;i++){
		stu[i].id = i;
		stu[i].score_all = 0;
		stu[i].flag = 0;		
		for(int j = 1; j<= k;j++){
			stu[i].score[j] = -2;
		}
	}
}

int main(){
	scanf("%d %d %d",&n,&k,&m);
	init();
	for(int i = 1;i<= k;i++){
		scanf("%d",&full[i]);
	}
	int u_id,p_id,score_obtained;
	for(int i = 0;i< m;i++){
		scanf("%d%d%d",&u_id,&p_id,&score_obtained);
		if(score_obtained!=-1){
			stu[u_id].flag = 1;
		}
		if(score_obtained == full[p_id] && stu[u_id].score[p_id] < full[p_id]){
			stu[u_id].solve++;
		}
		if(score_obtained > stu[u_id].score[p_id]){
			if(score_obtained == -1)	stu[u_id].score[p_id] = 0; 
			else	stu[u_id].score[p_id] = score_obtained;			
		}
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<= k;j++){
			if(stu[i].score[j] > 0){
				stu[i].score_all += stu[i].score[j];
			} 
		} 
	}
	sort(stu+1,stu+n+1,cmp);
	
	int rank = 0;//输出排名 
	int tempTotal = maxn;//总分数
	int count= 0;//相同分数的人数 
	for(int i = 1;i<= n ;i++){						
		if(stu[i].flag){
			if(stu[i].score_all == tempTotal){				
				count ++;				
				printf("%d ",rank);//输出rank				
			}
			else if(stu[i].score_all != tempTotal){//如果相等 
				rank++; 
				rank += count;				
				tempTotal = stu[i].score_all;
				printf("%d ",rank); 			
				count =0;
			}
			
			printf("%05d %d ",stu[i].id,stu[i].score_all); 
			for(int j = 1;j < k+1;j++ ){				
				if(stu[i].score[j]!=-2){//如果有提交 
					if(stu[i].score[j]!=-1)	printf("%d",stu[i].score[j]); 
					else	printf("0");
				}
				else	printf("-");
				if(j!=k)	printf(" ");
			}printf("\n");
		}
	}
	return 0;
}
/**
7 4 20
20 25 25 30
00002 2 12
00007 4 17
00005 1 19
00007 2 25
00005 1 20
00002 2 2
00005 1 15
00001 1 18
00004 3 25
00002 2 25
00005 3 22
00006 4 -1
00001 2 18
00002 1 20
00004 1 15
00002 4 18
00001 3 4
00001 4 2
00005 2 -1
00004 2 0
**/
