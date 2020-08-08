#include<cstdio>
#include<map>
#include<string>
#include<iostream>
#include<cmath>
using namespace std;

bool isPrime(int number){
	if(number == 1)	return false;
	if(number == 2) return true;
	for(int i = 2;i <= sqrt(number); i++){
		if(number % i == 0){
			return false; // is not a prime
		}
	}
	return true;//is a prime 
}

int main(){
	map<int,string> awardList;
	int N;
	scanf("%d",&N);
	int i;
	int id;//表示每个人的id 
	
	for(i = 1;i<= N ;i++){
		scanf("%d",&id);//输入id			
		if(i == 1){
			awardList[id] = "Mystery Award";
		}
		else if(isPrime(i)){
			awardList[id] = "Minion";
		}
		else
			awardList[id] = "Chocolate";				
	}
	
	int queryNum ;
	scanf("%d",&queryNum);
	int queryId; 		
	for(i = 0;i< queryNum;i++){
		scanf("%d",&queryId);
		map<int,string> :: iterator it = awardList.find(queryId);
		if(it != awardList.end()){
			printf("%04d: ",it->first);
			cout << it->second << endl;
			awardList[queryId] = "Checked";
		}
		else {
			printf("%04d: Are you kidding?\n",queryId);			
		}		
	}
}
/*
6
1111
6666
8888
1234
5555
0001
6
8888
0001
1111
2222
8888
2222


6
1111
6666
8888
1234
5555
0001
1
8888


6
1111
6666
8888
1234
5555
0001
3
1111
1111
1111



*/
