#include <cstdio> 
#include <string>
#include <iostream>
#include <map>
using namespace std;


//寻找相等的字符 
char deal(string& str1,string& str2){
	int i = 0; 
	while(i<str1.length()){			
		if(str1[i] == str2[i] && (str1[i]>='A' && str1[i]<='G'))
		break;
		else{
			str1.erase(str1.begin());
			str2.erase(str2.begin());
		}
	}
	char same = str1[0];//返回 
	str1.erase(str1.begin());
	str2.erase(str2.begin());
	return same;
}

int main(){
	string str1,str2,str3,str4;
	char same;
	map<char,string> week;//星期
	week['A'] = "MON"; 
	week['B'] = "TUE";
	week['C'] = "WED";
	week['D'] = "THU";
	week['E'] = "FRI";
	week['F'] = "SAT";
	week['G'] = "SUN";
	
	getline(cin,str1);
	getline(cin,str2);
	getline(cin,str3);
	getline(cin,str4);
		 
	same = deal(str1,str2);
	cout<<week[same]<<" ";//输出星期几 
	
	//输出小时
	int i;
	for( i = 0;i<str1.length();i++){
		if(str1[i] == str2[i] && (str1[i] >= '0' && str1[i] <= '9'))
		break;
		if(str1[i] == str2[i] && (str1[i] >= 'A' && str1[i] <= 'N'))
		break;
	}  
	if(str1[i]-'0'>=0 && str1[i] -'0'<=9){//如果是数字 
		printf("%02d:",str1[i]-'0');
	}
	else{
		printf("%2d:",str1[i]-'A'+10);
	}
	
	//输出分钟 	
	for( i = 0;i<str3.length();i++){
		if(str3[i] == str4[i] && (str3[i] >= 'a' && str3[i] <= 'z'))
		break;
		if(str3[i] == str4[i] && (str3[i] >= 'A' && str3[i] <= 'Z'))
		break;
	}
	printf("%02d",i);
}


/*
3485&Ajdkxh4hhGE 
2984&AkdfkkkkggEdsb 
s&hgsfdk 
d&Hyscvnm

3485djDkxh4hhGA 
2984akDfkkkkggAdsb 
1s&hgsfdk 
1sd&Hyscvnm


3485djDkxh4hhG0 
2984akDfkkkkgg0dsb 
s&hgsfdk 
d&Hyscvnm
**/
