#include<cstdio>
#include<map>
#include<set> 
#include<string>
#include<iostream>
using namespace std; 

int main(){
	int forward,skip,first;
	scanf("%d %d %d",&forward,&skip,&first);
	char post[1003][30]; 
		
	for(int i = 0;i< forward;i++){
		scanf("%s",post[i]);		
	}
	
	int count = 0;
	set<string> winner;
	int index = 1; 
	string curName;
	//printf("==================\n");
	int i = first-1;//the first people get award
	if(first > forward) {
		printf("Keep going...");
		return 0;
	}
	else{//�������Ҫ�� 
		printf("%s\n",post[i]);
		winner.insert(post[i]);
		for(i = first; i< forward; i++ ){
			count ++;			
			if(count % skip == 0){
				curName = post[i];
				if(winner.find(curName) == winner.end())//���set�� û�� curName
				{
					cout << curName << endl;
					winner.insert(curName);//���뵽winner�� 
					count = 0;// reset to 0 
				}else{
					count --;//��Ϊ���ʱ��Ӧ����count��������Ҫ-- 
				}			
			}		
		}	
	}			
} 
/*
2 3 5
Imgonnawin!
PickMe

9 3 2
Imgonnawin!
PickMe
PickMeMeMeee
LookHere
Imgonnawin!
TryAgainAgain
TryAgainAgain
Imgonnawin!
TryAgainAgain


9 3 2
Imgonnawin!
PickMe
PickMeMeMeee
LookHere
TryAgainAgain
TryAgainAgain
TryAgainAgain
TryAgainAgain
lawson


12 3 2
Imgonnawin!
PickMe
PickMeMeMeee
LookHere
TryAgainAgain
TryAgainAgain
TryAgainAgain
TryAgainAgain
lawson
a
b
c


*/
