#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>

using namespace std;
const int maxn=1000+5;

struct Mice{
    int weight;
    int ranks;
}mice[maxn];

int order1[maxn];
int cnt1=0;
int order2[maxn];
int cnt2=0;
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",&mice[i].weight);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&order1[i]);
    }
    cnt1=n;
    int rRanks=0;
    int groups;
    while(1){
        rRanks++;
        cnt2=0;
        int maxw,maxid;
        groups=cnt1/m;
        if(cnt1%m!=0)
            groups++;
        for(int i=0;i<cnt1;i+=m){
            maxw=0;
            int v;
            for(int j=i;j<i+m&&j<cnt1;j++){
               v=order1[j];
                if(mice[v].weight>maxw){
                    maxw=mice[v].weight;
                    maxid=v;
                }
            }
            for(int j=i;j<i+m&&j<cnt1;j++){
                v=order1[j];
                if(v!=maxid)
                    mice[v].ranks=groups+1;//有groups个组，那么晋级下一轮的就有groups个人，所有没晋级的并列第groups+1名。
            }
            order2[cnt2++]=maxid;
        }
        if(cnt1<=m){
            mice[maxid].ranks=1;
            break;
        }
        for(int i=0;i<cnt2;i++){
            order1[i]=order2[i];
        }
        cnt1=cnt2;
    }
    printf("%d",mice[0].ranks);
    for(int i=1;i<n;i++){
        printf(" %d",mice[i].ranks);
    }
    return 0;
}
