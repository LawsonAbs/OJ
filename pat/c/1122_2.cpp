#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int e[205][205];
int n, m, t, k, a[205], x, y,flag = 1;
int main(){
	scanf("%d%d",&n,&m);
	memset(e,0,sizeof(e));
	// �������� 
	for(int i = 0; i < m; i++){
		scanf("%d%d",&x, &y);
		e[x][y] = e[y][x] = 1;
	}
	scanf("%d",&t);
	while(t--){
		flag = 1;
		scanf("%d",&k);
		 
		if(k != n+1){ // �ж�Ԫ�ظ��� 
			for(int i = 0; i < k; i++){
				scanf("%d",&a[0]);
			}
			flag = 0;
		}else{
			for(int i = 0; i < k; i++){
				scanf("%d", &a[i]);
			}
			if(a[0] != a[k-1]){ // ��βԪ�رȽ� 
					flag = 0;
			}else{
				for(int i = 0; i < k-1; i++){ // �Ƿ�ͨ·�ж� 
					if(!e[a[i]][a[i+1]]){
						flag = 0;
						break;
					}
				}
				sort(a,a+n-1);
				for(int i = 0; i < k-1; i++){ // �ж��ظ�Ԫ�� 
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
