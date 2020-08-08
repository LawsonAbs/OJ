#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
using namespace std;
 
#define maxn 100000

char res[maxn];
char ori[maxn];
 
//针对 ori[maxn] 这个字符串得到新的字符串 
int getRes(char ori[],int seq){
	int i,count,time = 1,index =1 ;
	int length ;
	char curChar;
	char tempStr[maxn];
	
	while(time < seq){
		index = 0;
		length = strlen(ori);
		for(i = 0;i < length; i++){			
			curChar = ori[i];
			count = 0;
			while(curChar == ori[i] && i < length){
				count ++;
				i++;		
			}
			i--;
			tempStr[index++] = curChar;
			tempStr[index++] = count+48;			
			//cout << curChar << count ;
		}
		time ++;
		//将tempStr 的值赋给 ori 
		for(i = 0;i < index;i++){
			ori[i] = tempStr[i];						
		}
	}
	
	for(i = 0;i < index;i++){		
		cout <<  ori[i];
	}cout<<"\n";
}

int main(){
	int digit,seq;
	scanf("%d%d",&digit,&seq);
	ori[0] = digit + 48;
	//cout << ori[0] <<endl;
	getRes(ori,seq);
	
} 
