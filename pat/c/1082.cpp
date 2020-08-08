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
	int strLen = strlen(input);//字符串长度 
	int zeroCount;//末尾连续0的长度 
	char revInput[15];
	int index  = 0;
	int end = 0 ;//用于标记终止符 	
	int count = 0;//读了多少次的4位数
	stack<string> output;//将输出信息入栈
	
	if(input[0] == '-'){//如果是负数的话 
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
	revInput[index] = '\0';//最后一个字符串	
			
	strLen = strlen(revInput);//重新获取倒转后字符串的长度 
	index = 0;
			
	//此时revInput[i]!='0'
	// -1234 -> 4321
	//输出信息
	for(i= 0;i < strLen; i++){
		if(i%4==0){//如果到了4位 
			while(revInput[i] == '0'){//如果最后一位等于字母0 ，则处理 
				i++;
				index ++;//同时index 也加1
				index %=4;//取其余数 
				count ++; 			
				if((count) % 4 == 0 && (i+1) <= strLen) {//说明已经达到了4位数 	
					//cout <<"count = "<<count <<",count/4 = " <<	(count) / 4 << "\n";
					output.push(bigUnit[(count) / 4]);
				}
			}
		}
		
		if(( index % 4)  !=0  ){ //如果是个位，则不入栈 
			if( (revInput[i]-'0') != 0)//如果该值不是0，则输入单位 
			output.push(smaUnit[index%4]); //取单位的时候，需要注意取余 ，
		}
				 
		output.push(info[revInput[i]-'0']);		
		
		index ++;
		count ++;
		if((count) % 4 == 0 && (i+1) < strLen) {//说明已经达到了4位数 			
			output.push(bigUnit[(count) / 4]);
		}
	}
	
	if(input[0] == '-'){//如果是负数的话 
		output.push("Fu");
	}
		
	//cout <<"stack.size = "<< output.size()<<"\n";
	while(!output.empty()){		
		cout << output.top();//取栈顶		
		if( output.size() != 1 ) cout <<" ";		
		output.pop();//删除栈顶
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
