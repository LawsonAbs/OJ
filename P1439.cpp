#include<iostream>

using namespace std;
const int maxN = 1e3+5;
int dp[maxN][maxN];
int n;
int a[maxN], b[maxN]; //输入两个数组的值

int main(){
    cin >> n;
    for(int i = 1;i<= n;i++)
        cin >> a[i];
    for(int i = 1;i<= n;i++)
        cin >> b[i];

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<= n ;j++){
            if(a[i] == b[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else//不等的情况下
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout << dp[n][n]<<"\n";
}
