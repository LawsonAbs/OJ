#include<iostream>
#include<string>
#include<map>
using namespace std;
const int maxn = 2010;//×ÜÈËÊý

map<int,string> intToString;
map<string,int> stringToInt;
map<string,int> Gang;
int G[maxn][maxn] = {0},weight[maxn] = {0};
int n ,k ,numPerson = 0;
bool vis[maxn] = {false};

void dfs(int nowVisit,int& head,int& numMember,int& totalValue){
	numMember++;
	vis[nowVisit] = true;
	if()
} 
