#include<cstdio>
#include<set> 
#include<algorithm>
#include<climits>
#include<iostream>
#define maxn 105
using namespace std;

int N;
set<int> a;

struct result{
	int a;
	int b;
};

result res[maxn];

//判断数组array是否是一个标准的结果 
bool judge(){	
	//判断是否有前后矛盾的答案 
	for(set<int>::iterator it1=a.begin();it1!=a.end();it1++){
		for(set<int>::iterator it2=a.begin();it2!=a.end();it2++){ 
			if((*it1) == (-1)* (*it2)) return false;
		}
	}
	
	int count = 0; 
	for(set<int>::iterator it = a.begin();it!=a.end();it++){
		if(*it < 0) count++;
	} 
	if(count != 2) return false;//说明狼人数超标		
	return true;	 
}


bool cmp(result r1,result r2){
	if(r1.a == r2.a) return r1.b < r2.b;
	return r1.a < r2.a;	
}

int main(){	
	cout << INT_MAX; 
}
/*
6
+6
+3
+1
-5
-2
+4


6
+6
+3
+1
+5
+2
+4

*/
