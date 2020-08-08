#include<cstdio>
#include<vector>
#include<iostream>

using namespace std;

int main(){
	vector<vector<int> > vec(10);
	for(int i = 0;i< 10;i++){		
		vec[i].push_back(i);
	}
	
	
	for(int i= 0;i< 10;i++){
		for(int j = 0;j< vec[i].size();j++){
			cout << vec[i][j] <<"\n";	
		}
	}
}

