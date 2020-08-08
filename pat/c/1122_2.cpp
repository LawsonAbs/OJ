#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int e[205][205];
int n, m, t, k, a[205], x, y,flag = 1;
int main(){
	scanf("%d%d",&n,&m);
	memset(e,0,sizeof(e));
	// 数据输入 
	for(int i = 0; i < m; i++){
		scanf("%d%d",&x, &y);
		e[x][y] = e[y][x] = 1;
	}
	scanf("%d",&t);
	while(t--){
		flag = 1;
		scanf("%d",&k);
		 
		if(k != n+1){ // 判断元素个数 
			for(int i = 0; i < k; i++){
				scanf("%d",&a[0]);
			}
			flag = 0;
		}else{
			for(int i = 0; i < k; i++){
				scanf("%d", &a[i]);
			}
			if(a[0] != a[k-1]){ // 首尾元素比较 
					flag = 0;
			}else{
				for(int i = 0; i < k-1; i++){ // 是否通路判断 
					if(!e[a[i]][a[i+1]]){
						flag = 0;
						break;
					}
				}
				sort(a,a+n-1);
				for(int i = 0; i < k-1; i++){ // 判断重复元素 
					if(a[i] == a[i+1]){
						flag = 0;
						break;
					}
				}
			}
		}
		if(flag)puts("YES");
		else puts("NO");
	}	
	return 0;
}
