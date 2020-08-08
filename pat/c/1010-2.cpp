#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
ll Map[256];
ll inf = (1ll<<63) -1;//long long 的最大值2^63-1

void init(){
	for(char c ='0';c<='9';c++){
		Map[c] = c-'0';//将'0'-'9'映射到0~9 
	}
	for(char c ='a';c<='z';c++){
		Map[c] = c-'a' + 10;//同理 
	} 
} 

//参数t只是作为一个比较值用 
ll convertNum10(char a[] ,ll radix,ll t){
	ll ans = 0;
	int len = strlen(a);
	for(int i = 0;i<len;i++){
		ans = ans*radix + Map[a[i]];
		if(ans < 0 || ans > t)//溢出或者超过N1的十进制 
		return -1;
	}
	//printf("ans = %lld\n",ans); 
	return ans;
} 

//N2的十进制与t比较 
int cmp(char N2[],ll radix,ll t){
	int len = strlen(N2);
	ll num = convertNum10(N2,radix,t);
	if(num < 0) return 1;
	if(t>num) return -1;//t较大，返回-1 
	
	else if(t == num){//相等，返回0 
		return 0;
	}
	else return 1;//t小,返回1 
} 

ll binarySearch(char N2[],ll left,ll right,ll t){
	ll mid;
	while(left <= right){
		mid = (left + right) / 2;
		int flag = cmp(N2,mid,t);
		if(flag == 0){
			return mid;//找到解，返回该值【因为不存在多解问题】 
		}
		else if(flag == -1)
			left = mid+1; 
		else
			right = mid-1;
	}
	return -1;
}

int findLargestDigit(char N2[]){
	int ans = -1,len = strlen (N2);
	for(int i = 0;i<len;i++){
		if(Map[N2[i]] > ans){
			ans = Map[N2[i]];
		}
	}
	return ans + 1; 
}

char N1[20],N2[20],temp[20];
int tag ,radix;
int main(){
	init();
	scanf("%s %s %d %d",N1,N2,&tag,&radix);
	
	if(tag == 2){//为了使方便操作（将所有的radix都是N1的进制） 
		char tempStr[11];
		strcpy(tempStr,N1);//暂存N1字符串的值 
		strcpy(N1,N2);
		strcpy(N2,tempStr); 
	}	
	ll t = convertNum10(N1,radix,inf);
	//printf("t = %lld\n",t);
	
	//寻找N2中最大的进制位作为最小的进制 
	ll low = findLargestDigit(N2);
	
	//高进制为low和t之间的较大值+1 
	ll high = max(low,t) + 1;
	
	ll ans = binarySearch(N2,low,high,t);
	
	if(ans == -1 )
	printf("Impossible\n");
	else
	printf("%lld\n",ans );
	return 0;
}
/**
1 ab 1 2
32 20 1 10
0 0 1 2
0 0 1 34
5 5 1 10
**/
