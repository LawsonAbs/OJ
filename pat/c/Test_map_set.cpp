#include<cstdio>
#include<map>
#include<set>

#include<iostream>

using namespace std;

int main(){
	map<int,set<int> > m;
	m[1].insert(2);	
	m[1].insert(3);
	
	for(map<int,set<int> >::iterator it = m.begin();it!=m.end();it++){
		cout << it->first<<"\n";
		
		set<int> temp  = it->second;
		for(set<int> ::iterator setIt = temp.begin();setIt!=temp.end();setIt++)
		{
			set<int> ::iterator bak = setIt;
			bak++;
			for(set<int>::iterator two = bak;two!=temp.end();bak++){
				if() 
			} 
			cout << *setIt<<" ";	
		}
	}
	
}
//map中 的value可以存放set 
