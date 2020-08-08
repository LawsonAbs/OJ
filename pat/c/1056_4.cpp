#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
int mice[1000];
int r[1000];

int main(){
    int n(0), m(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> mice[i];
    }
    queue<int> order;
    int t(0);
    for (int i = 0; i < n; i++){
        cin >> t;
        order.push(t);
    }
    while(order.size() != 1){
        int gamecount = order.size() / m + (order.size() % m == 0 ? 0 : 1);
        int curank = gamecount + 1;//��һ�ֱ���ʧ���ߵ�����
        queue<int> tmp;
        for (int i = 0; i < gamecount; i++)
        {
            int max = -1;
            int maxindex = -1;
            
            //ÿ��ֻ��m����ӡ� �������m��������Ҫ�ж�order.size()!=0
            for (int j = i*m; j < i*m + m&&order.size()!=0; j++)
            {
                int index = order.front();
                order.pop();
                if (mice[index]>max)
                {
                    max = mice[index];
                    if (maxindex != -1)
                    {
                        r[maxindex] = curank;
                    }
                    maxindex = index;
                }
                else
                {
                    r[index] = curank;
                }
            }
            tmp.push(maxindex);//һС����������󣬰�ʤ���ߵ��±�ŷ������
        }
        order = tmp;
    }
    r[order.front()] = 1;
    cout << r[0];
    for (int i = 1; i < n; i++)
    {
        cout << " " << r[i];
    }
    cout << endl;
    return 0;
}

