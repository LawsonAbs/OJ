#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;

int pos[maxn];//��Ÿ����ֵ�ǰ������λ�ñ��
int main(){
	int n,ans = 0;
	scanf("%d",&n);
	int left = n-1,num;//left��ʾ��0���ⲻ�ڱ�λ�ϵĸ���
	for(int i = 0;i<n;i++){
		scanf("%d",&num);
		pos[num] = i;//��num������λ��
		if(num == i && num!=0)	left--; 
	} 
	int k = 1;//k ��������ʼ�±� 
	while(left > 0){
		//���0�ڱ�λ�ϣ���Ѱ��һ����ǰ���ڱ�λ�ϵ�����0����
		if(pos[0] == 0){
			while(k< n){
				if(pos[k] != k){
					swap(pos[0],pos[k]);
					ans++;
					break;
				}
				k++;//���� 
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
ע 
1.������0�Ƿ�ʧ�򣨴Ӷ�ͳһÿ��while��������left--�� 
2.����pos[num] = i;����������ֱ��array[i] = num;�кܴ�ͬ
3.�����k��1��ʼ����ʾ��һ��ʧ����±ꡣ�Ӷ���������ݴ�����ʱ��ķѣ� 
4.����swap()����������룻�������˶�swap(pos[0],pos[pos[0]])������⡣�����ֶ�ģ�⡣ 
*/
