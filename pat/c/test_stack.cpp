#include<cstdio>
#include<stack>
#include<iostream>

using namespace std;

int main(){
	stack<string> out;
	out.push("1");
	out.push("2");
		
	while(!out.empty()){		
		cout << out.top();//ȡջ��		
		if( out.size() != 1) cout <<"+";
		out.pop();//ɾ��ջ��		
	}	
}
