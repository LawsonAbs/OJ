#include<iostream>
using namespace std;

int res = 0;
const int maxN = 1005;

//ʹ�ü��仯�����������TLE
int record[maxN];  //��¼ÿ�����ֿ��Բ�ֵĸ���
 
//��������num���Եõ��ĸ��� 
void get_num(int num){
	if (num == 1) //�߽����� 
		return ; // �����һ�� 
	if (record[num]!= -1){
		res += record[num]; 
		return ; //ֱ�Ӽ��귵�� 
	}
	int start = res;
	for (int i = 1;i<= num/2;i++){ //�ݹ�ѭ�� 				
		res ++;
		get_num(i);
	}
	record[num] = res- start;//��¼��������ԵĴ��� 
}

int main(){
	int n;
	cin >> n;
	fill(record,record+maxN,-1); 
	get_num(n);
	cout << res + 1 <<"\n";
//	for (int i = 1;i<=6;i++){
//		cout << record[i] << " ";
//	}
} 
