#include <iostream>
#include <string>
using namespace std;

int n; 
string deal(string s,int &e){
	int k = 0;//s的下标 
	while(s.length()>0&&s[0] == '0'){
		s.erase(s.begin());//去掉前导0 
	} 
	if(s[0] == '.'){
		s.erase(s.begin());
		while(s.length()>0&&s[0] == '0'){
			s.erase(s.begin());
			e--;//指数减一 
		}
	} 
	else{
		while(k< s.length() && s[k] !='.'){
			k++;
			e++;
		}
		if(k<s.length()){
			s.erase(s.begin() + k);
		}
	} 
	if(s.length() == 0){
		e = 0;
	}
	int num = 0;
	k = 0;
	string res;
	while(num < n){
		if(k<s.length())	res +=s[k++];
		else res += '0';
		num ++;
	}
	return res;//返回可以直接输出的字符串 
}

int main(){
	string s1,s2,s3,s4;
	cin >> n>> s1>>s2;
	int e1 = 0 ,e2 = 0;
	s3 = deal(s1,e1); 
	s4 = deal(s2,e2);
	if(s3 == s4 && e1 == e2){
		cout<< "YES 0."<<s3<<"*10^"<<e1<<endl;
	}
	else{
		cout<< "NO 0."<<s3<<"*10^"<<e1<<" 0."<<s4<<"*10^"<<e2<<endl;
		
	}
	return 0;
}

/**
3 0012.123 12.234
2 1.111 1.112
4 1.111 1.112
3 12300 12358.9
3 120 128
1 0.11 0.12
2 0.11 0.12
2 1.12 1.21
4 0 0000.00
4 000.00 00
**/
