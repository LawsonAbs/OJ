#include<cstdio>
#include<cstring> 
#include<stack>
#include<iostream>

using namespace std;

int main(){
	char input[15];
	char info[11][5]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu","shi"};
	char smaUnit[5][5]={"","Shi","Bai","Qian"};
	char bigUnit[5][5]={"","Wan","Yi"};
	
	cin >> input;
	int i,j;
	int strLen = strlen(input);//�ַ������� 
	int zeroCount;//ĩβ����0�ĳ��� 
	char revInput[15];
	int index  = 0;
	int end = 0 ;//���ڱ����ֹ�� 	
	int count = 0;//���˶��ٴε�4λ��
	stack<string> output;//�������Ϣ��ջ
	
	if(input[0] == '-'){//����Ǹ����Ļ� 
		end = 1; 		
	}
	
	if(strLen == 1 && input[0] == '0' )
	{
		cout <<"ling"<<"\n";
		return 0;
	}
	
	for(i = strLen - 1;i>=end ;i--){
		revInput[index++] = input[i]; 
	}
	revInput[index] = '\0';//���һ���ַ���	
			
	strLen = strlen(revInput);//���»�ȡ��ת���ַ����ĳ��� 
	index = 0;
			
	//��ʱrevInput[i]!='0'
	// -1234 -> 4321
	//�����Ϣ
	for(i= 0;i < strLen; i++){
		if(i%4==0){//�������4λ 
			while(revInput[i] == '0'){//������һλ������ĸ0 ������ 
				i++;
				index ++;//ͬʱindex Ҳ��1
				index %=4;//ȡ������ 
				count ++; 			
				if((count) % 4 == 0 && (i+1) <= strLen) {//˵���Ѿ��ﵽ��4λ�� 	
					//cout <<"count = "<<count <<",count/4 = " <<	(count) / 4 << "\n";
					output.push(bigUnit[(count) / 4]);
				}
			}
		}
		
		if(( index % 4)  !=0  ){ //����Ǹ�λ������ջ 
			if( (revInput[i]-'0') != 0)//�����ֵ����0�������뵥λ 
			output.push(smaUnit[index%4]); //ȡ��λ��ʱ����Ҫע��ȡ�� ��
		}
				 
		output.push(info[revInput[i]-'0']);		
		
		index ++;
		count ++;
		if((count) % 4 == 0 && (i+1) < strLen) {//˵���Ѿ��ﵽ��4λ�� 			
			output.push(bigUnit[(count) / 4]);
		}
	}
	
	if(input[0] == '-'){//����Ǹ����Ļ� 
		output.push("Fu");
	}
		
	//cout <<"stack.size = "<< output.size()<<"\n";
	while(!output.empty()){		
		cout << output.top();//ȡջ��		
		if( output.size() != 1 ) cout <<" ";		
		output.pop();//ɾ��ջ��
	}	
} 
/*
100000

-123

12345

-12345

1234567

100800

110800

1010800

1000800
*/
