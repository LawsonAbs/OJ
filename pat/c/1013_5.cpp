//会运行超时 
#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<queue>
#include<vector>
#include<unordered_map>
#include<cstring>

using namespace std;

const int maxn = 1005;
int visit[maxn];
int link[maxn][maxn];
int n, m, k;

void dfs(int x)
{
    visit[x] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (visit[i] != 1 && link[i][x] == 1)
            dfs(i);
    }
}

int main()
{
    cin >> n >> m >> k;
    int city1, city2;
    memset(link, 0, sizeof(link));
    for (int i = 0; i < m; i++)
    {
        cin >> city1 >> city2;
        link[city1][city2] = 1;
        link[city2][city1] = 1;
    }

    int misscity;
    int count;
    for (int i = 0; i < k; i++)
    {
        cin >> misscity;
        count = 0;
        memset(visit, 0, sizeof(visit));
        visit[misscity] = 1;
        for (int i = 1; i <= n; i++)
        {
            if (visit[i] != 1)
            {
                dfs(i);
                count++;
            }
        }
        cout << count - 1 << endl;
    }
    return 0;
}
