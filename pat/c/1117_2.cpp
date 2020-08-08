#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
#define INF 0x3f3f3f3f
using namespace std;
/*
求满足下面的最大的E：
恰好有E个天的行程都大于E miles

从小到大排序，倒着循环一遍，直到最小值<=天数为止，此时的天数-1即为答案。
*/
const int maxn=100000+5;
int a[maxn];
int main()
{
    int n;
    int b;
    memset(a,0,sizeof(a));
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int minvalue=INF;
    sort(a+1,a+n+1);
    int E=0,ans;
    for(int i=n;i>=1;i--){
        E++;
        minvalue=min(a[i],minvalue);
        if(minvalue>E){
            ans=E;
        }
        else{
            break;
        }
    }
    printf("%d\n",ans);
    return 0;
}
