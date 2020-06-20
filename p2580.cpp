// Created by lawson on 20-6-19.
/*
 * 01.在trie树中，即使是相同的字符可能其p值都不一定相同，原因是：p值的取决于是紧跟在什么后的字符
 */
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxN = 5e6+5;//最长的名字长度，字符数
const int NUM = 30;//小写字母的个数

char name[maxN];//姓名
int trie[maxN][NUM]; // 第一维的大小怎么决定？
int End[maxN],vis[maxN];//结束标记
int tot = 0,p = 0; //tot表示节点个数;p 表示开始节点【p的含义是什么？ =》 当前正在判断的节点序号？】
int cNum;//char 对应的字符-'a'得到的值

//使用trie 结构处理这个name
void build(){
    p = 0;//重置
    for(int i = 0;i<strlen(name);i++){//依次遍历每个字符
        cNum = name[i]-'a';
        if(!trie[p][cNum]){//说明为空 -> 需要新增一个节点
            tot++;
            trie[p][cNum] = tot;
        }
        p = trie[p][cNum]; // 无论什么时候都得更新p的值
    }
    End[p] = 1;//这个时候在p处为一个结束标记
    return ;
}


void search(char test[]){
    p = 0;//重置为0
    for(int i = 0;i<strlen(test);i++){
        cNum = test[i] - 'a';
        if(trie[p][cNum]){
            p = trie[p][cNum];
        }
        else{
            printf("WRONG\n");
            return;
        }
    }
    if(End[p]){
        if(!vis[p])
            printf("OK\n"), vis[p]++;
        else
            printf("REPEAT\n");
    }
    else
        printf("WRONG\n");

}

int main(){
    int n,m;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        scanf("%s",name);
        build(); //处理这个name 信息
    }
    scanf("%d",&m);
    char test[maxN];//点名
    for(int i = 1;i<=m;i++){
        scanf("%s",test);
        search(test);//去trie树中判断这个test是否已经存在了
    }
    return 0;
}
/*
5
a
b
c
ad
acd
3
a
a
e



3
wuzuofan
luo
wangleping
4
wangleping
wangleping
wuyaoxuan
chengjunyang




 */