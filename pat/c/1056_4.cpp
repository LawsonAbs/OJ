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
        int curank = gamecount + 1;//这一轮比赛失败者的排名
        queue<int> tmp;
        for (int i = 0; i < gamecount; i++)
        {
            int max = -1;
            int maxindex = -1;
            
            //每次只放m个入队。 如果不满m个，则需要判断order.size()!=0
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
            tmp.push(maxindex);//一小组比赛结束后，把胜利者的下标号放入队列
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

