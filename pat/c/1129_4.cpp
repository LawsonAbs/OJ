#include <iostream>
#include <cstdio>
#include <cstring>
#include <set> 
using namespace std;
 
struct node
{
    int cnt;
    int val;
    
    //重载运算符  < 
    bool operator<(const node &a)const
    {
        if(cnt==a.cnt)
            return val<a.val;
        else
            return cnt>a.cnt;
    }
};
 
int n,k;
int b[50005];

//set 中存放的是node型变量 
//因为node是自定义的类型，所以set 中的元素就不会再按照之前的<号进行排序了，而是使用自定义的
//<号 
set <node> s;
 
int main()
{
    int i,j,x;
    node p;
    scanf("%d%d",&n,&k);
    for(i=0; i<n; i++)
    {
        scanf("%d",&x);
        if(i>0)
        {
            printf("%d:",x);
            //得到一个set<node> 的遍历器 
            set<node>::iterator it;
            int cnt=0;//cnt 是用于控制输出项数 
            for(it=s.begin(); it!=s.end()&&cnt<k; it++)
            {
                cnt++;
                printf(" %d",it->val);
            }
            printf("\n");
        }
        p.cnt=b[x];
        b[x]++;//更新x这个商品出现的频率 
        p.val=x;
        if(s.find(p)!=s.end())//每次判断是否已经出现过了，如果有，则删除后再更新，若没有，则直接更新
            s.erase(p);
        p.cnt++;
        s.insert(p);
    }
    return 0;
}

