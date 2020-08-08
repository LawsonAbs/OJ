#include<cstdio>
#include<iostream>
#include<cstring>
#include<set>
#include<cmath>

#define maxn 100

using namespace std;


int main(){
	double res = 3 /2.0;
	cout << res<<"\n"; 
	
	double a = 2.36;
	printf("a = %.1f\n",a);
	
	int b = round(a);
	printf("b = %d\n",b);
	
	set<int> s;
	s.insert(-b);
	for(set<int>::iterator it=s.begin();it!=s.end();it++){
		cout << *it;
	}
	cout<<endl;
	
}
