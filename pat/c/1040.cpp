#include<cstdio>
#include<string>
#define maxn 1002
#include<iostream>
using namespace std;

int main(){
	int i,j,k;
	string str;//�ַ��� 
	getline(cin,str);
	int longCom = 1;//������ַ����ĳ��� 
	int len = str.length();
	int tempLen;
	int tempLoc;
	int location;
	
	//��λ���Գ� 
	for(i = 1;i< len;i++){
		j = i;
		k = i;
		tempLen = 1;
		while(str[k-1] == str[j+1] && j < len - 1 && k > 0){
			k--;
			j++;
			tempLen+=2;
		}
		if(tempLen > longCom){
			longCom = tempLen;
		}
	}
	
	//żλ���Գ� 
	for(i = 0;i< len;i++){
		j = i + 1;//��λ 
		k = i;//��λ 
		tempLen = 0;
		while(str[k] == str[j] && j < len  && k >= 0){
			k--;
			j++;
			tempLen+=2;
		}
		if(tempLen > longCom){
			longCom = tempLen;
		}
	}
		
	printf("%d",longCom);
}
/*
ABCDDCBA
ASDFA
AFDFAFDFA
s? PAT&TAP ?
**/
