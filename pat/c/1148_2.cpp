#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

int main()
{
    int n, s;
    scanf("%d", &n);
    int m[n + 1];
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &s);
        m[i] = s;
    }

    int real[n + 1] = {1};
    vector<int> lie;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            fill(real, real + n + 1, 1);
            lie.clear();
            real[i] = -1;
            real[j] = -1;
            for (int v = 1; v <= n; v++)
            {
                if (real[abs(m[v])] * m[v] < 0)
                    lie.push_back(v);
            }
            if (lie.size() == 2 && real[lie[0]] + real[lie[1]] == 0)
            {
                printf("%d %d", i, j);
                return 0;
            }
        }
    }
    printf("%s", "No Solution");
    return 0;
}

