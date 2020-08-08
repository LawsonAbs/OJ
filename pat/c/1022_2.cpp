#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <string>
using namespace std;

//5个变量分别建立书名，作者，关键词，出版社以及出版年份与ID的映射关系 
map<string,set<int> >mpTitle,mpAuthor,mpKey,mpPub,mpYear; 

void query(map<string ,set<int> >& mp,string& str){
	if(mp.find(str) == mp.end()) printf("Not Found\n");
	else{		
		for(set<int> :: iterator it = mp[str].begin() ;it!=mp[str].end();it++){
			printf("%07d\n",*it);
		}
	} 
} 

int main(){
	int n ,m,id,type;
	string title,author,key,pub,year;
	
	scanf("%d",&n);
	for(int i = 0;i< n;i++){
		scanf("%d",&id);
		char c = getchar();
		getline(cin,title);
		mpTitle[title].insert(id);
		getline(cin,author);
		mpAuthor[author].insert(id);
		while(cin >> key){
			mpKey[key].insert(id);
			c = getchar();
			if(c == '\n')	break;
		}
		getline(cin,pub);
		mpPub[pub].insert(id);
		getline(cin,year);
		mpYear[year].insert(id); 
	}
	string temp;
	scanf("%d",&m);
	for(int i = 0;i< m;i++){
		scanf("%d: ",&type);
		getline(cin,temp);
		cout<<type << ": "<< temp<<endl;
		if(type == 1) query(mpTitle,temp); 
		else if(type == 2) query(mpAuthor,temp);
		else if(type == 3) query(mpKey,temp);
		else if(type == 4) query(mpPub,temp);
		else query(mpYear,temp);
	}
	return 0 ;
} 
/**
3
1111111
The Testing Book
Yue Chen
test code debug sort keywords
ZUCS Print
2011
3333333
Another Testing Book
Yue Chen
test code sort keywords
ZUCS Print2
2012
2222222
The Testing Book
CYLL
keywords debug book
ZUCS Print2
2011
6
1: The Testing Book
2: Yue Chen
3: keywords
4: ZUCS Print
5: 2011
3: blablabla
*/ 
