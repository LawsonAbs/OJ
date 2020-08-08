/**˼·����
1.�½��û��ṹ�壬�洢�ܷ����������������ĸ����� 
2.
*/ 
#include <cstdio>
#include <algorithm>
#define maxn 100010
using namespace std;

struct User{
	int id;//�û�id 
	int total_score ;//�ܷ��� ��ʼ��Ϊ0 
	int perfectNum ;//����ͨ�������� 
	int pro[6];//ÿ���û��Լ�����Ŀ��� 
}; 

User user[maxn];
int n,k,m;//���û� ������ ���ύ�� 

void init(){
	for(int i = 0;i< n;i++)	{
		for(int j = 1;j<= k;j++){
			user[i].pro[j] = -1;
		} 
		user[i].total_score = 0;
		user[i].perfectNum = 0; 
	}
}

bool cmp(User u1,User u2){
	if(u1.total_score == u2.total_score){
		if(u1.perfectNum == u2.perfectNum){
			return u1.id < u2.id;
		}
		else	return u1.perfectNum>u2.perfectNum;
	}
	else	return u1.total_score > u2.total_score; 
} 

int main(){	
	int i ,j;
	int project[6];//��Ŀ�� 
	scanf("%d %d %d",&n,&k,&m);
	 
	for(i = 1;i <= k;i++){
		scanf("%d",&project[i]);//����ÿ��ķ��� 
	}
	init();
	
	int tempId,tempPro,tempScore; 
	for(i = 0;i< m;i++){
		scanf("%d %d %d",&tempId,&tempPro,&tempScore);
		user[i].id = tempId;		
		user[i].pro[tempPro] = tempScore;
		if(tempScore == project[tempPro] ){//���������� 
			user[i].perfectNum++;//�Լ� 
		} 
	} 
	

	for(i = 0;i<n;i++){
		for(j = 1;j < k+1;j++){
			if(user[i].pro[j]!=-1)	user[i].total_score += user[i].pro[j];
		}
	}
	
	sort(user,user+n,cmp);
	for(i = 0;i< n;i++){
		printf("%05d %d ",user[i].id,user[i].total_score); 
		for(j = 1;j < k+1;j++ ){
			if(user[i].pro[j]!=-1){//������ύ 
				printf("%d",user[i].pro[j]); 
			}
			else	printf("-");
			if(j!=k)	printf(" ");
		}printf("\n");
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
