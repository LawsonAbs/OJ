#include<cstdio>
#include<cstring>
#include<queue>
#include<iostream>

using namespace std;

int main(){
	priority_queue<int> pq;
	pq.push(1);
	pq.push(2);
	
	int size = pq.size() ;
	for(int i = 0;i< size;i++){
		cout << pq.top() << " ";
		pq.pop();
	}
}
