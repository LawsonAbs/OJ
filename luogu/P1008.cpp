#include<iostream>
using namespace std;

bool visit[10] ;
 
//判断是否所有的数字都取到了 
bool judge(){
	for (int i = 1;i<10;i++){
		if (!visit[i])
			return false;
	}
	return true;
}

int main(){	
	for (int i = 101;i<329;i++){		
		//每次重置 
		for (int k = 1;k<10;k++){
			visit[k] = 0;
		}
		int m,n;
		for (int j = 1;j<4;j++){
			m = i*j;
			while(m){
				n = m%10;
				visit[n] = 1;
				m=m/10;
			}
		}
		//注意这里的judge()需要带括号，否则会直接按照return true处理 
		if (judge())
			cout << i <<" "<< i*2 <<" " <<i *3 <<"\n";	
	}	
}
