#include <stdio.h>
#include <string.h>
#include <map>
#include <set>
using namespace std;

int G[210][210];
int A[210];
int vis[210];
set<int> vertex;
int N,M,K,numv;

int main()
{
    scanf("%d%d",&N,&M);
    for(int i=0;i<M;i++)
    {
        int v1,v2;
        scanf("%d%d",&v1,&v2);
        G[v1][v2]=1;
        G[v2][v1]=1;
    }
    scanf("%d",&K);
    for(int i=0;i<K;i++)
    {
        bool flag=true;
        memset(vis,0,sizeof(vis));
        scanf("%d",&numv);
        for(int j=0;j<numv;j++)
        {
            scanf("%d",&A[j]);
            vertex.insert(A[j]);
        }
        if( vertex.size()!=N || numv!=N+1 || A[numv-1]!=A[0] )
        {
            flag=false;
        }
        else
        {
            for(int j=1;j<numv;j++)
            {
                int v1=A[j-1];
                int v2=A[j];
                if(G[v1][v2]==0)
                {
                    flag=false;
                }
                vis[v2]=1;
            }
        }
        if(flag)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}

