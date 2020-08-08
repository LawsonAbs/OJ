#include<cstdio>
#include<set>
#include<iostream>

using namespace std;

int main(){
	set<int> a;
	a.insert(1);
	a.insert(2);
	
	a.insert(-3);
	a.insert(-5); 
	for(set<int>::iterator it1=a.begin();it1!=a.end();it1++){
		cout  << *it1<<", ";
	}
} 
