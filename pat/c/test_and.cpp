#include<cstdio>
#include<iostream>

using namespace std;

int main(){
	int t1 = 1289;
	int t2 = t1 & 0xffffffff;
	int t3 = t1 + 0xffffffff;
	cout << "t1= "<<t1<<"\n";
	//printf("%x\n",t1);
	cout << "t2= "<<t2<<"\n";
	cout << "t3= "<<t3<<"\n";
	cout << "1+0xffffffff="<<1+0xffffffff<<endl; 
}
