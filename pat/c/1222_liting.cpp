//help qixiang 
#include <iostream>
#include <cmath> 
using namespace std;
#define M 100 

int L[M], count = 0; 

bool isOK(int n, int m, int a, int l) {
	int row = (l-1) / m + 1;
	int col = (l-1) % m + 1;
	for(int i = 1; i < a; i++) {
		int cr = (L[i] - 1) / m + 1;
		int cc = (L[i] - 1) % m + 1;
		if((row-cr)*(row-cr) + (col-cc)*(col-cc) <= 2)
			return false; 
	}
	return true;
}

void DFS(int n, int m, int k, int a) {
	if(a == k+1) {
		count++;
	}
	else {
		for(int i = 1; i <= m*n; i++) {
			if(i > L[a-1]) {
				L[a] = i;
				if(isOK(n, m, a, i))
					DFS(n, m, k, a+1);
			}
		}
	}
}

int main() {
	int n, m, k, i;
	cin >> n >> m >> k;
	DFS(n, m, k, 1);
	cout << count << endl;
	return 0;
} 

