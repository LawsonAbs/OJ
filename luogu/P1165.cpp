#include<iostream>
using namespace std;
const int maxN = 200005;
int max_val[maxN]; //���嵱ǰλ�õ����ֵ
int len = 0; 

int main(){
	int n;
	cin >> n;
	int a,in; //in ��ʾ��������� 
	max_val[0] = 0;
	for (int i = 0;i < n;i++){
		cin >> a;
		if (a ==0){
			cin >> in;
			if (len){
				max_val[len] = max(in,max_val[len-1]);
			}
			else{
				max_val[len] = max(in,0);
			}
			len++;
		}
		else if(a == 1){ // �������
			if(len==0){
				continue;
			}
			else{
				max_val[len] = 0; //��Ϊ0 
				len--;
			}			
		}
		else if(a == 2){
			if(len > 0){
				cout << max_val[len-1] <<"\n";	
			}
			else{
				cout << 0 <<"\n";
			}			
		} 
	}
}
/*
6
0 1
0 2
2
0 4
1
2
*/
