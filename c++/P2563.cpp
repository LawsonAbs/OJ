#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

const int maxN = 205;//
int dp[maxN];//dp[i]表示i可以由几个素数的和表示出来
int prime[maxN];//求出200 以内的素数
int tot = 0;//素数的个数

//预处理得到素数表
void getPrime(){
    for(int i = 2;i<=200;i++){
        int j ;
        for( j = 2;j <= sqrt(i);j++){
            if(i % j == 0) break;
        }
        if(j > sqrt(i)){
            prime[tot++] = i;//i 是素数
            //dp[i] = 1;//自己到自己可达
        }
    }
}

void getNum(){
    //类似于 完全背包问题
    for(int i = 0;i< tot;i++){ //放前i个素数
        for(int j = prime[i];j<=200;j++){//依次计算出
            if(dp[j-prime[i]]){//如果 j-prime[i] 可达
                dp[j] += dp[j-prime[i]];//累计数目
            }
        }
    }
}

int main(){
    int num;
    dp[0] = 1,prime[0] = 2; //第一个素数是2
    getPrime();
    getNum();
    while(scanf("%d",&num)!=EOF){
        cout << dp[num]<<"\n";
    }
}

