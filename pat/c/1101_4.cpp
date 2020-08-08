#include <cstdio>
#include <queue>
#include <algorithm>
// pta 1101
using namespace std;
//priority_queue<int, vector<int>, greater<> > mq;
queue<int> mq;
int nn, digit[100010];
int l_max[100010], r_min[100010];

int main() {
    scanf("%d%d", &nn, &digit[0]);
    l_max[0] = digit[0];
    int i = 1;
    for (; i < nn; ++i) {
        scanf("%d", &digit[i]);
        l_max[i] = max(l_max[i - 1], digit[i]);
    }
    r_min[nn - 1] = digit[nn - 1];
    i = nn - 2;
    while (i >= 0) {
        r_min[i] = min(r_min[i + 1], digit[i]);
        i--;
    }
    for (int j = 0; j < nn; ++j) {
        if (digit[j] >= l_max[j] && digit[j] <= r_min[j])
            mq.push(digit[j]);
    }
    printf("%lu\n", mq.size());
    while (mq.size() > 1) {
        printf("%d ", mq.front());
        mq.pop();
    }
    if(mq.size() == 0){
    	printf("\n");
	}
	else{
		 printf("%d\n", mq.front());
    	mq.pop();
	}   
    return 0;
}
/*
2
2 1
*/
