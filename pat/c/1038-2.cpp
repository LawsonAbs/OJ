/*
1.所有的事实只证明一件事情，如果能够思考的越多，那么处理问题就会越简单 
2.sort()函数中的比较函数到底该怎么使用 
*/ 

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

const int maxn = 10010 ;
string str[maxn];

bool cmp(string a,string b){
	return a + b < b + a;//如果a+b小于b+a，则把a排在前面 
} 

int main(){
	int n ;
	cin>>n;
	for(int i = 0;i<n;i++){
		cin>>str[i];
	}
	
	sort(str,str+n,cmp);
	
	string ans;//结果字符串
	for(int i = 0;i<n;i++){
		ans +=str[i];
	} 
	 
	while(ans.size()!=0 && ans[0] == '0'){
		ans.erase(ans.begin());//去除前导0 
	}
	if(ans.size() == 0) cout <<0;
	else cout << ans;
	return 0; 
} 

/*
5 32 321 3214 0229 87

5 32 321 3210 0229 87
5 0 000 00 00 0000
*/

