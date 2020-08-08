#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
ll Map[256];
ll inf = (1ll<<63) -1;//long long �����ֵ2^63-1

void init(){
	for(char c ='0';c<='9';c++){
		Map[c] = c-'0';//��'0'-'9'ӳ�䵽0~9 
	}
	for(char c ='a';c<='z';c++){
		Map[c] = c-'a' + 10;//ͬ�� 
	} 
} 

//����tֻ����Ϊһ���Ƚ�ֵ�� 
ll convertNum10(char a[] ,ll radix,ll t){
	ll ans = 0;
	int len = strlen(a);
	for(int i = 0;i<len;i++){
		ans = ans*radix + Map[a[i]];
		if(ans < 0 || ans > t)//������߳���N1��ʮ���� 
		return -1;
	}
	//printf("ans = %lld\n",ans); 
	return ans;
} 

//N2��ʮ������t�Ƚ� 
int cmp(char N2[],ll radix,ll t){
	int len = strlen(N2);
	ll num = convertNum10(N2,radix,t);
	if(num < 0) return 1;
	if(t>num) return -1;//t�ϴ󣬷���-1 
	
	else if(t == num){//��ȣ�����0 
		return 0;
	}
	else return 1;//tС,����1 
} 

ll binarySearch(char N2[],ll left,ll right,ll t){
	ll mid;
	while(left <= right){
		mid = (left + right) / 2;
		int flag = cmp(N2,mid,t);
		if(flag == 0){
			return mid;//�ҵ��⣬���ظ�ֵ����Ϊ�����ڶ�����⡿ 
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
	
	if(tag == 2){//Ϊ��ʹ��������������е�radix����N1�Ľ��ƣ� 
		char tempStr[11];
		strcpy(tempStr,N1);//�ݴ�N1�ַ�����ֵ 
		strcpy(N1,N2);
		strcpy(N2,tempStr); 
	}	
	ll t = convertNum10(N1,radix,inf);
	//printf("t = %lld\n",t);
	
	//Ѱ��N2�����Ľ���λ��Ϊ��С�Ľ��� 
	ll low = findLargestDigit(N2);
	
	//�߽���Ϊlow��t֮��Ľϴ�ֵ+1 
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
