/*
1.P1176 路径计数2
典型：
01.计数dp 
02.带有 ”显式的横纵坐标轴“ 的dp
03.状态转移公式：
dp[i][j] += (dp[i-1][j]+dp[i][j-1]);
同时，需要注意对阻碍点的过滤。
*/


#include<iostream>
using namespace std;
const int maxN= 1005;
const int maxM = 100005;

int dp[maxN][maxN]; //N*N 的网格
int n,m;
int main(){
	cin >> n >> m;
	int a, b;
	for(int i = 0;i<m;i++){ //输入m个阻碍坐标
		cin >> a >> b;
		dp[a][b] = -1;//阻碍
	}

	int left,down;//left 表示从左侧过来； down 表示从上面过来
	dp[1][1] = 1;
	for(int i = 1; i<= n;i++){
		for(int j = 1;j<=n;j++){
			if(dp[i][j]!=-1)
			{
				left = (dp[i-1][j] == -1)? 0: dp[i-1][j]; //三元运算符 
				down = (dp[i][j-1] == -1)? 0: dp[i][j-1];
				dp[i][j] += (left+down);
				dp[i][j] %= 100003;
			}
		}
	}
	cout << dp[n][n]<<"\n";
}

