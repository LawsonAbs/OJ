#include<iostream>
#include<stack>
#include<string>
using namespace std; 

bool judge(char cur_op,char pre_op){
	if(cur_op == '+' ){
		if(pre_op == '+') return true;// 表示需要计算 
		if(pre_op == '-') return true;
		if(pre_op == '*') return false;
		if(pre_op == '/') return false;		
	}
	else if(cur_op == '-' ){
		if(pre_op == '+') return true;
		if(pre_op == '-') return true;
		if(pre_op == '*') return false;
		if(pre_op == '/') return false;		
	}
	else if(cur_op == '*' ){
		if(pre_op == '+') return false;
		if(pre_op == '-') return false;
		if(pre_op == '*') return true;
		if(pre_op == '/') return true;		
	}
	else if(cur_op == '/' ){
		if(pre_op == '+') return false;
		if(pre_op == '-') return false;
		if(pre_op == '*') return true;
		if(pre_op == '/') return true;		
	}	
}


int main(){
	string str;
	cin  >> str;
	stack<int> num;
	stack<char> op;
	int left,right,value; //左右表达式，最终值 
	char top_op; 
	for (int i = 0;i< str.length();i++){
		if (str[i] >= '0' && str[i] <='9'){
			num.push(str[i]-'0'); 
		}
		else{
			if(!op.empty()){ //如果操作符栈为空 							
				top_op = op.top();
				if(judge(str[i],top_op)){ 
					right = num.top();
					num.pop();
					left = num.top();
					num.pop();//接连出栈两次
					if (top_op == '-'){
						value = left - right;
					} 
					else if (top_op == '+'){
						value = left + right;
					} 
					else if (top_op == '*'){
						value = left * right;
					} 
					else if (top_op == '/'){
						value = left / right;
					}
					num.push(value);//将运算的结果放入栈中 
					op.pop();
				}				
			}			
			op.push(str[i]); //无论如何，都需要把操作符入栈 
		}
	}
	while(!op.empty()){
		right = num.top();
		num.pop();
		left = num.top();
		num.pop();//接连出栈两次
		top_op = op.top();
		op.pop();
		if (top_op == '-'){
			value = left - right;
		} 
		else if (top_op == '+'){
			value = left + right;
		} 
		else if (top_op == '*'){
			value = left * right;
		} 
		else if (top_op == '/'){
			value = left / right;
		}
		num.push(value);		
//		cout <<"size = "<< op.size() <<"\n";
	}
	cout << value;
}
/*
1+2-3*4
1+2-3*4/5
*/ 
