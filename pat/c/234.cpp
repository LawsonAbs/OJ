#include<stdio.h>
#include<string>
#include<cctype>
#include<iostream>
using namespace std;

int main()
{
	string a;
	cin >> a;
	string res;
	res = tolower(a);
	cout <<"res = "<< res<<"\n";
	return 0;
} 
