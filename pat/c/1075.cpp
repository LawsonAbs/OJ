/**思路分析
1.新建用户结构体，存储总分数，完美解决问题的个数。 
2.同一道题的完美解答不累计。 
3.若某用户全部提交的都没有通过编译，则不输出；若有编译通过的，但是得分为0的需输出。 
4.注意排名
5.sort排序出现问题。【建议以后若有对sort排序的情况，老老实实从开始排到结束，不包含其它元素】 
*/ 
#include <cstdio>
#include <algorithm>
#define maxn 100010
using namespace std;

struct User{
	int id;//与下标相同---只做排序使用 
	int total_score ;//总分数 初始化为0 
	int perfectNum ;//完美通过的题数 
	int pro[6];//每个用户自己的题目情况 
	int flag ;
}; 

User user[maxn];
int n,k,m;//总用户 总题数 总提交数 

void init(){
	for(int i = 0;i<= n;i++)	{
		for(int j = 1;j<= k;j++){
			user[i].pro[j] = -2;
		} 
		user[i].total_score = 0;
		user[i].perfectNum = 0; 
		user[i].flag = 0;
	}
}

bool cmp(User u1,User u2){
	if(u1.total_score == u2.total_score){
		if(u1.perfectNum == u2.perfectNum){
			return u1.id < u2.id;
		}
		else	return u1.perfectNum > u2.perfectNum;
	}
	else	return u1.total_score > u2.total_score; 
} 

int main(){	
	int i ,j; 
	int project[6];//题目数 
	scanf("%d %d %d",&n,&k,&m);
	 
	for(i = 1;i <= k;i++){
		scanf("%d",&project[i]);//输入每题的分数 
	}
	init();
	
	int tempId,tempPro,tempScore; //用数组下标作为id
	for(i = 0;i< m;i++){
		scanf("%d %d %d",&tempId,&tempPro,&tempScore);
		user[tempId].id = tempId; //重复执行不必要的动作 ----->若执行此处代码，则无法通过第三个测试用例 
		if(tempScore>=0)	user[tempId].flag = 1; 		
		if(tempScore == project[tempPro] && user[tempId].pro[tempPro] < project[tempPro]){//如果第一次完美解决 
			user[tempId].perfectNum++;//自加 
		} 
		if(user[tempId].pro[tempPro] < tempScore){
			if(tempScore == -1)	user[tempId].pro[tempPro] = 0;
			else user[tempId].pro[tempPro] = tempScore;			
		}
	} 	

	for(i = 1;i<= n;i++){
		for(j = 1;j <= k;j++){
			if(user[i].pro[j] > 0)	user[i].total_score += user[i].pro[j];
		}
	}
	
	//sort(user ,user + n +1,cmp);//user的id从1开始    所以从user开始排  直到user+n+1 
	sort(user+1,user + n +1,cmp);
	int rank = 0;//输出排名 
	int tempTotal = maxn;//总分数
	int count= 0;//相同分数的人数 
	//for(i = 0;i< n;i++){
	for(i = 1;i<=n;i++){
		if(user[i].flag==1){						
			if(user[i].total_score == tempTotal){				
				count ++;				
				printf("%d ",rank);//输出rank				
			}
			else if(user[i].total_score != tempTotal){//如果相等 
				rank++; 
				rank += count;				
				tempTotal = user[i].total_score;
				printf("%d ",rank); 			
				count =0;
			}
			
			printf("%05d %d ",user[i].id,user[i].total_score); 
			for(j = 1;j < k+1;j++ ){
				if(user[i].pro[j]!=-2){//如果有提交 
					if(user[i].pro[j]!=-1)	printf("%d",user[i].pro[j]); 
					else	printf("0");
				}
				else	printf("-");
				if(j!=k)	printf(" ");
			}printf("\n");
		} 
	}
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
*/
