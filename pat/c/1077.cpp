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
		getline(cin,s[i]);//输入字符串，带空格		
	}
	
	//求出字符串1 2最大的公共后缀 
	string maxPub;
	string tempPub;
	i = s[0].length() - 1;
	j = s[1].length() - 1;
	//while(s[0][i] == s[1][j] && i>=0 && j>=0){//为什么这里添加i>=0 && j>=0之后就对？ 
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
		if(s[i].find(maxPub) == -1){//如果有不相等的时候 
			maxPub.erase(maxPub.begin());//删除第一元素 
			i--;//再判断一次 			
		}
		i++;
		if(maxPub.length() == 0 || i < 0){//如果没有公共字符串 
			printf("nai"); 
			return 0;
		} 
	}
	cout<<maxPub;	
}
/**
pat 1077 求最长子后缀问题 
注：
1.注意数组访问下标的问题，比如说
1）在访问大量的字符串的时候，如本题这样需要求出最长公共字符串，则需要知道每个字符串的长度，
然后求出其最小的公共长度。
2）例如在本代码中，使用while循环求出前两个字符串的公共长度时，如果i和j的值有一个变成了-1，
则会导致段错误的发生。
2.段错误的发生可能的原因有以下可能:
1）数组访问越界；
2）递归调用层数过多
 
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
