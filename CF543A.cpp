// Created by lawson on 20-6-15.
//可AC
#include<iostream>
using namespace std;

const int maxN = 505;
int dp[maxN][maxN];//dp[j][k]表示前i名工程师，写j行代码，产生k个bug的方案数
int bug[maxN];//bug[i]表示第i 位工程师写一行代码产生的bug数

int main(){
    int n,m,b,mod;
    cin >> n >> m >> b >> mod;
    for(int i = 1;i<=n;i++){
        cin >> bug[i];
    }
    //for(int i = 0;i<=n;i++)
    dp[0][0] = 1;//初始化
    for(int i = 1;i<= n;i++){//前i个人
        for(int j = 1;j <=m ;j++ ){//写了j行代码
            for(int k = bug[i];k<= b;k++){//已知有k个bug
               dp[j][k] = (dp[j][k]//第i个人不写代码，直接用上个人的代码
                        + dp[j - 1][k - bug[i]]);//在自己写的基础上继续写
               dp[j][k] %= mod;
            }
        }
    }
    int res= 0;
    for(int k = 0;k<=b;k++){
        res += dp[m][k];
        res %= mod;
    }
    cout << res <<"\n";
}