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
	str += str; // ����ƴ��
	//��ʼ����Ϊ1 
	fill(dpl,dpl+maxN,1);
	fill(dpr,dpr+maxN,1);
	char cur_color;
	int len = str.length();	
	//dpl[i]��ʾ�ӵ�i���ڵ�ǰ�ֿ� 
	for (int i = 0;i< len-1;i++){
		cur_color = str[i];
		for(int j = i+1;j<len;j++){//ֱ��ȡģ 			
			if(cur_color == str[j] || str[j] == 'w'){
				dpl[i]++;				
			}
			else if(cur_color == 'w' && str[j]!='w'){
				cur_color = str[j] ;  //�޸ĵ�ǰɫ 
				dpl[i]++;
			}				
			else //����ѭ�������� 
				break;			
		}
	}
	//�������� dpr[i] ��������Լ� ��dpr[i]��ʾ�ӵ�i���ڵ�ǰ�ֿ� 
	for (int i = len-1;i >=1 ;i--){
		cur_color = str[i-1]; 
		for(int j = i-2;j>=0;j--){			
			if(cur_color == str[j] || str[j] == 'w' ){
				dpr[i]++;				
			}
			else if(cur_color == 'w' && str[j]!='w'){
				cur_color = str[j] ;  //�޸ĵ�ǰɫ 
				dpr[i]++;	
			}				
			else //����ѭ�������� 
				break;  
		}
	}
	
	
	int res = 0;
	for (int i = 0;i< len;i++){
		//cout <<"i="<<i<<" "<< dpl[i] <<" "<< dpr[i]<<"\n";
		res = max(dpl[i]+dpr[i],res);
	}
	//��Ҫע�������ԭʼstr ����ĳ��� 
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
