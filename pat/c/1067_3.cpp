#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;

int pos[maxn];//存放各数字当前所处的位置编号
int main(){
	int n,ans = 0;
	scanf("%d",&n);
	int left = n-1,num;//left表示除0以外不在本位上的个数
	for(int i = 0;i<n;i++){
		scanf("%d",&num);
		pos[num] = i;//数num所处的位置
		if(num == i && num!=0)	left--; 
	} 
	int k = 1;//k 搜索的起始下标 
	while(left > 0){
		//如果0在本位上，则寻找一个当前不在本位上的数与0交换
		if(pos[0] == 0){
			while(k< n){
				if(pos[k] != k){
					swap(pos[0],pos[k]);
					ans++;
					break;
				}
				k++;//自增 
			}
		} 
		while(pos[0]!=0){
			swap(pos[0],pos[pos[0]]);
			ans++;
			left--;
		} 
	}
	printf("%d",ans);
	return 0;
}

/**
注 
1.不考虑0是否失序（从而统一每次while结束都是left--） 
2.采用pos[num] = i;的做法，与直接array[i] = num;有很大不同
3.这里的k从1开始，表示第一个失序的下标。从而避免大数据带来的时间耗费！ 
4.采用swap()函数精简代码；或许有人对swap(pos[0],pos[pos[0]])不大理解。建议手动模拟。 
*/
