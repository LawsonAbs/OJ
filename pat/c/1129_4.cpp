#include <iostream>
#include <cstdio>
#include <cstring>
#include <set> 
using namespace std;
 
struct node
{
    int cnt;
    int val;
    
    //���������  < 
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

//set �д�ŵ���node�ͱ��� 
//��Ϊnode���Զ�������ͣ�����set �е�Ԫ�ؾͲ����ٰ���֮ǰ��<�Ž��������ˣ�����ʹ���Զ����
//<�� 
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
            //�õ�һ��set<node> �ı����� 
            set<node>::iterator it;
            int cnt=0;//cnt �����ڿ���������� 
            for(it=s.begin(); it!=s.end()&&cnt<k; it++)
            {
                cnt++;
                printf(" %d",it->val);
            }
            printf("\n");
        }
        p.cnt=b[x];
        b[x]++;//����x�����Ʒ���ֵ�Ƶ�� 
        p.val=x;
        if(s.find(p)!=s.end())//ÿ���ж��Ƿ��Ѿ����ֹ��ˣ�����У���ɾ�����ٸ��£���û�У���ֱ�Ӹ���
            s.erase(p);
        p.cnt++;
        s.insert(p);
    }
    return 0;
}

