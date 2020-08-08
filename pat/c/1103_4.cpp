#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int n,k,p;
int maxFacSum = -1;//最大底数之和
vector<int> fac,ans,temp;

int power(int x){
	int ans = 1;
	for(int i = 0;i< p;i++){
		ans *= x;
	}
	return ans;
}

void init(){
	int i = 0, temp = 0;
	while(temp<= n){
		fac.push_back(temp);
		temp = power(++i);
	}
}

void DFS(int index,int nowK,int sum,int facSum){
	if(sum == n && nowK == k){
		if(facSum > maxFacSum){
			ans = temp;//更新最优底数序列
			maxFacSum = facSum; 
		}
		return;
	}
	if(sum > n || nowK > k)	return;
	if(index - 1 >= 0){
		temp.push_back(index);//加入底数index到temp中
		DFS(index,nowK+1,sum+fac[index],facSum+index);//选 
		temp.pop_back();
		DFS(index-1,nowK,sum,facSum);//不选 		
	}
}

int main(){
	scanf("%d%d%d",&n,&k,&p);
	init();
	DFS(fac.size()-1,0,0,0);
	if(maxFacSum == -1)	printf("Impossible\n");
	else{
		printf("%d = %d^%d",n,ans[0],p);
		for(int i = 1;i<ans.size();i++){
			printf(" + %d^%d",ans[i],p);
		}
	}
} 
/**
169 5 2
169 167 3
50 50 2
60 60 2
50 25 2
100 100 2
400 400 2
300 300 2
**/
