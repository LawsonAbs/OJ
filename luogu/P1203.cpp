#include<iostream>
#include<string>

using namespace std;
const  int maxN = 800;
/*
*/
int main(){
	int dpl[maxN],dpr[maxN];
	int n ;
	string str;
	//cin >> n ;
	cin >> str;
	str += str; // 两份拼凑
	//初始化都为1 
	fill(dpl,dpl+maxN,1);
	fill(dpr,dpr+maxN,1);
	char cur_color;
	int len = str.length();	
	//dpl[i]表示从第i个节点前分开 
	for (int i = 0;i< len-1;i++){
		cur_color = str[i];
		for(int j = i+1;j<len;j++){//直接取模 			
			if(cur_color == str[j] || str[j] == 'w'){
				dpl[i]++;				
			}
			else if(cur_color == 'w' && str[j]!='w'){
				cur_color = str[j] ;  //修改当前色 
				dpl[i]++;
			}				
			else //跳出循环，结束 
				break;			
		}
	}
	//从右往左 dpr[i] 必须包括自己 ，dpr[i]表示从第i个节点前分开 
	for (int i = len-1;i >=1 ;i--){
		cur_color = str[i-1]; 
		for(int j = i-2;j>=0;j--){			
			if(cur_color == str[j] || str[j] == 'w' ){
				dpr[i]++;				
			}
			else if(cur_color == 'w' && str[j]!='w'){
				cur_color = str[j] ;  //修改当前色 
				dpr[i]++;	
			}				
			else //跳出循环，结束 
				break;  
		}
	}
	
	
	int res = 0;
	for (int i = 0;i< len;i++){
		//cout <<"i="<<i<<" "<< dpl[i] <<" "<< dpr[i]<<"\n";
		res = max(dpl[i]+dpr[i],res);
	}
	//需要注意最长不过原始str 本身的长度 
	cout << min(res,len/2) ;
} 
/*
1
b 

3
rrr

5
wrwrr
 
29
brbrrrbbbrrrrrbrrbbrbbbbrrrrb

29 
wwwbbrwrbrbrrbrbrwrwwrbwrwrrb
*/
