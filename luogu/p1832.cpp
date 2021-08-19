// Created by lawson on 20-6-16.
/*
 01.完全背包
 02.
 */
#include<iostream>
#include<cmath>
using namespace std;
const int maxN = 1005;
typedef  long long ll;
int prime[maxN];//素数表
int cnt = 0;//素数个数
ll dp[maxN] ;//dp[i]表示数字i由素数构成的方案个数
int  n;


void getPrime(){
    for(int i = 2;i<1005;i++){
        int j = 2;
        for( j= 2;j<=sqrt(i);j++){
            if(i% j == 0)
                break;
        }
        if(j > sqrt(i))
            prime[cnt++] = i;//是素数
    }
}

int main(){
    getPrime();
//    for(int i = 0;i < cnt;i++)
//        cout << prime[i]<<" ";

    //dp开始
    //完全背包
    cin >> n;
    dp[0] = 1;
    for(int i = 0 ;i< cnt && prime[i]<=n;i++){//有cnt 个物品，放前i 个物品
        for(int j = prime[i];j<= n;j++){//从prime[i]开始放东西
            if(dp[j-prime[i]])
                dp[j]+= dp[j-prime[i]];
        }
    }
    cout << dp[n]<<"\n";
}