#include<cstdio>
#include<map>
using namespace std;
#define maxn 10002
#define likeMaxn 202

int fav[likeMaxn];//最爱的颜色
int stripe[maxn];//给出的色彩带 

int main(){
	int n;
	scanf("%d",&n);
	int favNum;
	scanf("%d",&favNum);//total number of colors
	map<int,int> mp;//建立int -> int 型的映射 
	int i,j;
	int count = 0;
	for(i = 0;i< favNum;i++){
		scanf("%d",&fav[i]);
		mp[fav[i]] = count++; 
	}	
//	printf("-----------mp中的元素\n");
//	for(map<int ,int>::iterator it = mp.begin();it!=mp.end();it++){
//		printf("%d %d\n",it->first,it->second);
//	}
//	printf("-----------------------结束\n"); 
	int total;
	scanf("%d",&total);
	for(i = 0;i< total;i++){
		scanf("%d",&stripe[i]);
		if( mp.find(stripe[i]) != mp.end()){//出现在map中 
			stripe[i] = mp[stripe[i]];//替换 
		}
		else{
			stripe[i] = -1;
		}
	} 
	
	int origin[maxn];
	j = 0;
	for(i = 0;i< total;i++){
		if(stripe[i]!=-1)	origin[j++] = stripe[i];
	}
	
//	for(i = 0;i< j;i++){
//		printf("%d ",origin[i]);
//	}printf("\n");
	
	count = j;//实际有效的色彩 	
	int dp[maxn];
	int max ;
	dp[0] = 1;//第一位 
	for(i = 1;i< count;i++){
		dp[i] = 1;//先初始化 只有自己一人
		max = 0; 
		for(j = 0;j< i;j++){
			if(origin[i] >= origin[j]){//
				if(dp[j] + 1 > max){
					max = dp[j] + 1;
					dp[i] = max;
				}
			}
		}
	}
//	for(i = 0;i< count;i++){
//		printf("%d ",dp[i]); 
//	}printf("\n");
		max = 0;
	for(i = 0;i< count;i++){
		if(dp[i] > max){
			max = dp[i];
		}
	}	printf("%d",max);
} 
/**
6
5 2 3 1 5 6
12 2 2 4 1 5 5 6 3 1 1 5 6
**/
 
