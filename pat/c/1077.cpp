//AC
#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
#define maxn 1010

int main(){
	string s[maxn];
	int num;
	scanf("%d",&num);
	getchar();
	int i ,j;
	for(i = 0;i< num;i++){
		getline(cin,s[i]);//�����ַ��������ո�		
	}
	
	//����ַ���1 2���Ĺ�����׺ 
	string maxPub;
	string tempPub;
	i = s[0].length() - 1;
	j = s[1].length() - 1;
	//while(s[0][i] == s[1][j] && i>=0 && j>=0){//Ϊʲô�������i>=0 && j>=0֮��Ͷԣ� 
	printf("%c",s[0][-1]); 
	while(s[0][i] == s[1][j]){
		tempPub += s[0][i];
		i--; 
		j--;
	}
	
	if(tempPub.length() !=0 ){			
		for(i = tempPub.length() - 1; i >= 0;i--){
			maxPub += tempPub[i];
		}
		if(num == 2){
			cout<<maxPub;
			return 0;
		} 
	}
	else{
		printf("nai");
		return 0; 
	}
	i = 2;

	while(i < num){
		if(s[i].find(maxPub) == -1){//����в���ȵ�ʱ�� 
			maxPub.erase(maxPub.begin());//ɾ����һԪ�� 
			i--;//���ж�һ�� 			
		}
		i++;
		if(maxPub.length() == 0 || i < 0){//���û�й����ַ��� 
			printf("nai"); 
			return 0;
		} 
	}
	cout<<maxPub;	
}
/**
pat 1077 ����Ӻ�׺���� 
ע��
1.ע����������±�����⣬����˵
1���ڷ��ʴ������ַ�����ʱ���籾��������Ҫ���������ַ���������Ҫ֪��ÿ���ַ����ĳ��ȣ�
Ȼ���������С�Ĺ������ȡ�
2�������ڱ������У�ʹ��whileѭ�����ǰ�����ַ����Ĺ�������ʱ�����i��j��ֵ��һ�������-1��
��ᵼ�¶δ���ķ�����
2.�δ���ķ������ܵ�ԭ�������¿���:
1���������Խ�磻
2���ݹ���ò�������
 
3
Itai nyan~
~~~~~~~~~~
~~~~~~~~~~

3
Itai!
Ninjinnwaiyada T_T
T_T

5
uhhh nyan~
uhhh nyan~
Itai nyan~
Ninjin wa iyadanyan~
Ninjin wa iyadancan~


5
Itai nyan~
Ninjin wa iyadanyan~
uhhh nyan~
yan~
Ninjin wa iyadancan~

2
fsdof
sfdsoi 
*/
