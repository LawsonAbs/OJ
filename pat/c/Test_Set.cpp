#include<cstdio>
#include<set>
#include<iostream>
using namespace std;

int main(){
	set<int> s;
	
	s.insert(3);
	s.insert(1);
	s.insert(20);
	s.insert(2);
	
	//int temp = s.erase(1);
	
	for(set<int> ::iterator it = s.begin(); it!=s.end();){			
		printf("*it = %d\n",*it);
		it++;			
	}printf("\n");

}
