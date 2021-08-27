#include<iostream>
#include<stack>
#include<string>
using namespace std; 

bool judge(char cur_op,char pre_op){
	if(cur_op == '+' ){
		if(pre_op == '+') return true;// ��ʾ��Ҫ���� 
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
	int left,right,value; //���ұ��ʽ������ֵ 
	char top_op; 
	for (int i = 0;i< str.length();i++){
		if (str[i] >= '0' && str[i] <='9'){
			num.push(str[i]-'0'); 
		}
		else{
			if(!op.empty()){ //���������ջΪ�� 							
				top_op = op.top();
				if(judge(str[i],top_op)){ 
					right = num.top();
					num.pop();
					left = num.top();
					num.pop();//������ջ����
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
					num.push(value);//������Ľ������ջ�� 
					op.pop();
				}				
			}			
			op.push(str[i]); //������Σ�����Ҫ�Ѳ�������ջ 
		}
	}
	while(!op.empty()){
		right = num.top();
		num.pop();
		left = num.top();
		num.pop();//������ջ����
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
