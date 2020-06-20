// Created by lawson on 20-6-19.
#include<iostream>
#include<cmath>
using namespace std;
const int maxN = 16005;
int n,ans = 0 ;
int beau[maxN];//美丽指数
int dp[maxN];//dp[i]表示以i为根且包含i可得的最大权联通块
int head[maxN],nex[maxN],to[maxN];//
int tot = 1;//辺的个数


//建数组邻接表
void add(int a,int b ){
    nex[tot] = head[a];//更新上一条辺的序号
    head[a] = tot; //结点a的第一条辺是head[a]
    to[tot] = b;//第tot条辺的终点
    tot++;
}

//深搜找辺 => cur 表示当前的顶点，fa 表示是顶点cur的父节点
void dfs(int cur,int fa){
    dp[cur] = beau[cur];
    for(int i = head[cur];i;i=nex[i]){ //递归找辺
        int y = to[i];//这条边所在的顶点
        //if(y!=cur){ //如果不是当前顶点 => 无环可以直接搞完
        if(y!=fa){//从哪个父节点过来，就不能再回去了
           dfs(y,cur);
           dp[cur] += max(dp[y],0); //取较大值
        }
    }
    ans = max(ans,dp[cur]);
}

int main(){
    cin >> n  ;
    int a,b;
    for(int i = 1; i <= n;i++){
        cin >> beau[i]; //输入花的美丽指数
    }

    //更新一下
    for(int i = 1;i<n;i++){
        cin >> a >> b;
        add(a,b);//建双向边
        add(b,a);
    }

    dfs(1,0);
    cout << ans <<"\n";
}
