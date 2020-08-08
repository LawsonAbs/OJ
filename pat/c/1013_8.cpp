#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
int v[1001][1001];//记录连通路线 默认为0 不连通
int visit[1001];//记录是否遍历过
int n;//n个城市

void dfs(int node){
    visit[node] = 1;
    for(int i=1; i<=n; i++){
        if(visit[i]== 0 && v[node][i] == 1){
            dfs(i);
        }
    }
}

int main()
{
    int m, k, a, b;//m条路 k个要检查的城市 ab为路线起点终点
    scanf("%d%d%d", &n, &m, &k);
    for(int i=0; i<m; i++){
        scanf("%d%d", &a, &b);
        v[a][b] = 1;
        v[b][a] = 1;
    }
    
    for(int i=0; i<k; i++){
        memset(visit, 0, sizeof(visit));//重置visit 所有城市未被遍历
        int temp = 0;
        scanf("%d", &temp);
        visit[temp] = 1;//被攻占的城市，标记为true
        int cnt = 0;//记录连通分量
        for(int j=1; j<=n; j++){
            if(visit[j] == false){
                dfs(j);
                cnt++;//连通分量+1
            }
        }
        printf("%d\n", cnt-1);//思路第二条
    }
    return 0;
}

