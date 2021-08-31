#include<iostream>
#include<string>
using namespace std;

void process(string s){	
	if (s.find("1")!=s.npos && s.find("0")!=s.npos){ //那说明要 
		cout <<"C"; 
		string left = s.substr(0,s.length()/2);
		string right = s.substr(s.length()/2);
		
		process(left);
		process(right);
	}
	else if (s.find("0") == s.npos){
		cout <<  "B";
	}	
	else if (s.find("1") == s.npos){
		cout <<  "A";
	}
} 

int main(){
	string s;
	cin >> s;
	
	string left,right;
//	left = s.substr(0,s.length()/2);
//	right = s.substr(s.length()/2);
//	cout <<left <<"\n" << right;
	//对字符串递归进行处理 	
	process(s);	
}
