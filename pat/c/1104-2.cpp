#include <cstdio>

int main(){
	int n;
	double v,ans = 0;
	scanf("%d",&n);
	
	for(int i = 1;i<= n;i++){
		scanf("%lf",&v);
		ans += v*i*(n-i+1);
	}
	printf("%.2lf\n",ans); 
}
/***
4
0.1 0.2 0.3 0.4
**/
