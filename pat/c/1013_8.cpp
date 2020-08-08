#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
int v[1001][1001];//��¼��ͨ·�� Ĭ��Ϊ0 ����ͨ
int visit[1001];//��¼�Ƿ������
int n;//n������

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
    int m, k, a, b;//m��· k��Ҫ���ĳ��� abΪ·������յ�
    scanf("%d%d%d", &n, &m, &k);
    for(int i=0; i<m; i++){
        scanf("%d%d", &a, &b);
        v[a][b] = 1;
        v[b][a] = 1;
    }
    
    for(int i=0; i<k; i++){
        memset(visit, 0, sizeof(visit));//����visit ���г���δ������
        int temp = 0;
        scanf("%d", &temp);
        visit[temp] = 1;//����ռ�ĳ��У����Ϊtrue
        int cnt = 0;//��¼��ͨ����
        for(int j=1; j<=n; j++){
            if(visit[j] == false){
                dfs(j);
                cnt++;//��ͨ����+1
            }
        }
        printf("%d\n", cnt-1);//˼·�ڶ���
    }
    return 0;
}

