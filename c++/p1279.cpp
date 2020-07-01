#include <cstring>
#include<iostream>
using namespace std;
const int maxN = 2e3+5;
int dp[maxN][maxN];//dp[i][j]表示子串a[i]与b[j]可达到的最小值
char a[maxN], b[maxN];//两个字符串
int k; //空格和字符之间的固定差值

int getMin(int a,int b ,int c){
    if(a >= b )
        if(b >= c) return c;
        else return b;
    else
        if(a >= c) return c;
        else return a;
}

int main(){
    scanf("%s",a+1);
    scanf("%s",b+1);
    cin >> k;
    int lA = strlen(a+1), lB = strlen(b+1);

    //step1:初始化
    for(int i = 1;i<=lA;i++){
        dp[i][0] = dp[i-1][0] + k;//a串与空串进行匹配
        dp[0][i] = dp[0][i-1] + k;//空串与b串进行匹配
    }

    //step2: 开始递推就算最优解
    for(int i = 1;i<= lA ;i++){
        for(int j = 1;j<= lB;j++){
            int val = abs(int(a[i]) - int(b[j]));
            dp[i][j] = getMin(dp[i-1][j]+k,//a[i]和空格匹配
                              dp[i][j-1]+k,//空格和b[j]匹配
                              dp[i-1][j-1]+val);//二者直接匹配加上差值
        }
    }
    cout << dp[lA][lB] <<"\n";
}
/*
cmc
snmn
2

c
c
2

c
s
2

cmc
cmcs
2

*/