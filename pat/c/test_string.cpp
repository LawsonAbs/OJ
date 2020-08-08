#include<cstdio>
#include<iostream>
#include<string>
#include<map>
#include<cmath>

using namespace std;

struct result{
	string id;	
	int proAss = 0;
	int midScore = -1;
	int finalScore = -1;	
	int grade = 0;
};

int main(){
	map<string,result> res;
	res["asd"].proAss = 200;
	res["asd"].midScore = 100;
	res["asd"].finalScore = 99;	
	
	//Ö±½ÓÊä³ö
	cout<<"======print directly======"<<endl; 
	cout << res["asd"].proAss<<endl;	
	 
	cout<<"=====use for to iterate map ======"<<endl;
	for(map<string,result>::iterator it = res.begin();it!=res.end();it++){
		cout <<"id = "<< it->first <<endl;	
		cout << "proAss = "<< it->second.proAss <<endl; 
		cout << "midScore = "<<it->second.midScore <<endl;
		cout << "finalScore = "<<it->second.finalScore <<endl;
	}
	
} 
