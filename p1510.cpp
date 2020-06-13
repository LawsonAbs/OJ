/*
1.数组定义
01.dp[i] 表示到达体积i时需耗费的最小体力
02.need 表示东海填平需要的木石体积
03.v[i],cos[i] 每块石头的体积以及消耗的体力
04.n:西山的木石
05.rest:精卫剩余的体力

2.0/1背包
3.本题需要注意：
题目说至少需要体积为v(代码里对应为need)的木石才可以填平。也就是说，我们可以在>=need 的结果集
中选择一个最小的体力消耗的就OK了。
*/
#include<iostream>
#include<algorithm>

using namespace std;

const int INF = 0x3f7f7f7f;
const int maxN = 20005;
const int step = 10000;//即使多一块也无妨，多出来的一部分最长是step
int need,n,rest;
int dp[maxN],v[maxN],cost[maxN];

int main(){
	cin >> need >> n >> rest;	
	for(int i = 0;i< n;i++){
		cin >> v[i] >> cost[i];			
	}
	fill(dp,dp+maxN,INF);
	dp[0] = 0;
	for(int i = 0;i< n;i++){
		for(int j = need+step ; j >= v[i];j--){
			if(dp[j-v[i]]!=INF){//如果dp[j-v[i]]可达
				dp[j] = min(dp[j],dp[j-v[i]]+cost[i]);
			}
		}
	}
	int res = INF;
	for(int i = need;i<=need+step;i++){ //这里任何一个i都是满足条件的
		if(dp[i]!=INF)
			res = min(dp[i],res);
	}
	if(res > rest)
		cout << "Impossible\n";
	else
		cout << rest - res<<"\n";
}