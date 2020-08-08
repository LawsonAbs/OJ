#include <iostream>
#include <string>
#include <map>

using namespace std;

//检查字符c是否是【0-9，A-Z，a-z】 
bool check(char c){
	if(c >= '0' && c <= '9') return true;
	if(c >= 'A' && c <= 'Z') return true;
	if(c >= 'a' && c <= 'z') return true;
	return false;
} 

int main(){
	map<string ,int > count;//count计算字符串出现的次数
	string str;
	getline(cin,str);//读入整串字符串
	int i = 0;
	while(i < str.length()){
		string word;
		while(i<str.length() && check(str[i]) == true){
			if(str[i] >= 'A' && str[i] <= 'Z'){
				str[i] +=32;
			}
			word += str[i];
			i++;
		}
		if(word != ""){//单词次数非空，令次数加1 
			if(count.find(word) == count.end()) count[word] = 1;
			else count[word]++;
		}
		while(i < str.length() && check(str[i]) == false){
			i++;//跳过非单词字符 
		} 
	} 
	
	string ans;
	int max = 0;
	for(map<string,int>::iterator it = count.begin();it!=count.end();it++){
		if(it->second > max){
			max = it->second;
			ans = it->first;
		}
	} 
	cout << ans << " "<<max<<endl;
	return 0;
} 
/*
Can1: "Can a can can a can?  It can!"
*/



