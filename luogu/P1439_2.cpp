/*
 1.这是一个加强版的 最长公共子序列
 */
#include<iostream>
#include<algorithm>
#include<map>

using namespace std;
const int maxN = 1e3+5;
int n;
int a[maxN], b[maxN]; //输入两个数组的值
int tail[maxN];//tail[i]表示长度为i 的最长不下降子序列结尾中的最小值
map<int,int> tran;//做一个映射

void proc(){
    int cnt = 1;
    for(int i = 1;i<=n;i++){
        tran[a[i]] = cnt;
        cnt ++;
    }
    for(int i = 1;i<=n;i++){
        b[i] = tran[b[i]];
    }
}

int main(){
    cin >> n;
    for(int i = 1;i<= n;i++)
        cin >> a[i];
    for(int i = 1;i<= n;i++)
        cin >> b[i];

    //step1.先做一个映射与转换
    proc();

    //step2.求出数组b的最长不下降子序列
    int cnt = 1;//最长不下降子序列的长度
    tail[cnt] = b[1];
    for(int i = 2; i<=n; i++){
        if(b[i] >= tail[cnt])//比最大的都要大，那么就直接往后添加
            tail[++cnt] = b[i];
        else{
            int idx = lower_bound(tail+1,tail+cnt+1,b[i]) - tail;//找出第一个大于且等于b[i]的值
            tail[idx] = b[i];
        }
    }
    cout << cnt <<"\n";
}

/*
5
1 2 3 4 5
3 2 1 4 5

5
3 2 1 4 5
1 2 3 4 5

 */