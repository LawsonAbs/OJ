// Created by lawson on 20-6-17.
#include<iostream>
#include<cstdio>
using namespace std;

const int maxN = 2005;
int dp[maxN][maxN];//dp[i][j]表示第j棵树，高度为i时获得的最大值
int fruit[maxN][maxN];//fruit[i][j]表示第i棵树，高度为j时有柿子
int rec[maxN];//rec[i]用于记录高度为i时的最大值

int n,h,delta;
int main(){
    scanf("%d%d%d",&n,&h,&delta);
    for(int i = 1;i<= n;i++){//树的下标
        int num,loc;//柿子数； 每个柿子所在的高度
        scanf("%d",&num);
        for(int j = 1;j<=num;j++)//柿子个数
        {
            scanf("%d",&loc);
            fruit[i][loc] ++;//高度为loc,第i棵树时有一个柿子
        }
    }

    for(int i = h;i>h-delta;i--){//高度为i
        for(int j = 1;j<=n;j++){//树的下标为j
            dp[i][j] = fruit[j][i] + dp[i+1][j]; //本高度+上面高度继承
        }
    }

    //dp计算
    for(int i = h-delta;i>0;i--){//i为高度
        for(int j = 1;j<=n;j++){//j为树的下标
            dp[i][j] = dp[i+1][j];//继承
            if(rec[i+delta]){ //如果之前高度为 i+delta 时的最大值已经找到过了
                dp[i][j] = max(dp[i][j],rec[i+delta]);
            }
            else{//没有记录，第一次需要寻找
                for(int k = 1;k<=n;k++) { //找中间跳一次
                    dp[i][j] = max(dp[i][j], dp[i + delta][k]);
                }
                rec[i+delta] = dp[i][j];
            }
            dp[i][j] += fruit[j][i]; //加上当前的果子
        }
    }
    int res = 0;
    for(int i = 1;i<= n;i++)
        res = max(res,dp[1][i]);
    printf("%d\n",res);
}
/*
3 10 2
3 1 4 10
6 3 5 9 7 8 9
5 4 5 3 6 9

01.如何降维？
02.

 */