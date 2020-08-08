#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100010;
int main(){
	int n ,p,a[maxn];
	scanf("%d%d",&n,&p);
	for(int i = 0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	sort(a,a+n);
	int i = 0,j = 0,count = 1;
	while(i<n && j< n){//高明之处在于j值保持不变，然后i值却往后推了一个 
		while(j < n && a[j] <= (long long)a[i]*p){
			count = max(count,j-i+1);
			j++;
		}
		i++;
	}
	printf("%d",count);
	return 0;
} 
