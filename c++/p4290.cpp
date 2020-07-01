#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int maxN = 205;
const int maxK = 20;//每个字母可以由多少种两个字符代替
const int maxM = 5;//4个字符
int n;
int tran[maxM][maxM][maxM]; //tran[i][j][k] 表示两个字符i,j可以得到单个字符k
int dp[maxN][maxN][maxM];//dp[len][i][j] 表示
char in[maxN];//玩具名


//根据字符返回数字
int transChar(char c) {
    if (c == 'W') return 1;
    if (c == 'I') return 2;
    if (c == 'N') return 3;
    if (c == 'G') return 4;
}

void printChar(int num) {
    if (num == 1) printf("W");
    if (num == 2) printf("I");
    if (num == 3) printf("N");
    if (num == 4) printf("G");
}


//进行预处理操作
//当前处理的字符cur , 当前需要输入的两个字母的个数 num
void read(int cur, int num) {
    char c1, c2;
    char str[2];//输入的字符串
    for (int i = 0; i < num; i++) {
        scanf("%s", str);
        c1 = transChar(str[0]);
        c2 = transChar(str[1]);
        tran[c1][c2][cur] = 1;// c1c2 => w
    }
}


int main() {
    int a[5]; //a[1]代表字母W 可由多少种两个字母替换,....
    //读取数据
    for (int i = 1; i < 5; i++)//读取每个字符可被替换的种数
        cin >> a[i];

    for (int i = 1; i < 5; i++)//继续读取数据，并处理
        read(i, a[i]);

    /*
    for (int i = 1; i < 5; i++) {
        for (int j = 1; j < 5; j++) {
            for (int k = 1; k < 5; k++)
                if (tran[i][j][k])
                    cout << i << j << "->" << k << "\n";
        }
    }*/
    scanf("%s", in+1 );//从下标1开始输入
    //cout <<"in[0]="<< in[0]<<"\n";
    //预处理dp[][][]
    //如果写成 scanf("%s",in+1) ,那么 执行strlen(in) 时得到的结果为0;
    int n = strlen(in+1);
    //cout << "strlen(in) = "<< n <<"\n";
    for (int i = 1; i <= n; i++) {
        dp[1][i][transChar(in[i])] = 1;//自己能转到自己
    }

    for (int len = 2; len <= n; len++) {
        for (int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;//右侧区间端点
            for (int sp = l; sp <= r; sp++) {//分割点
                int ll = sp - l + 1;//左区间长度
                int lr = r - sp; //右区间长度
                //下面两个循环是用于遍历所有的排列情况
                for (int i = 1; i <= 4; i++) { //本次dp[len][l][i] 是否可达
                    for (int j = 1; j <= 4; j++) {
                        //依次检测如下两个区间是否符合能够缩小成一个字符
                        int v1 = dp[ll][l][i];
                        int v2 = dp[lr][sp + 1][j];
                        if (v1 && v2) {//如果二者均可转换，那么继续往下走
                            for (int k = 1; k <= 4; k++) {//判断可以转换成什么字符
                                if (tran[i][j][k]) {//如果数字（其实是字母）i,j可转换为k
                                    dp[len][l][k] = 1;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    int flag = 0;//是否有输出
    for (int i = 1; i <= 4; i++) {
        if (dp[n][1][i]) {
            flag = 1;
            printChar(i);
        }
    }
    if (!flag)
        cout << "The name is wrong!\n" << "\n";
}

//}
/*
1 1 1 1
II
WW
WW
IG
IIII


1 1 1 1
II
WW
WW
IG
IIIG


1 1 1 1
II
WW
WW
IG
IIIG
*/
