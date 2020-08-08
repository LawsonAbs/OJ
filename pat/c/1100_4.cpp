#include<cstdio>
#include<cstring>
#include<stack>
#include<string>
#include<iostream>
using namespace std;

char first [13][5]={"tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
char secon [13][5]={"","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};


stack<string> sta;


//operate number 
int opeNum(char str[] ){
	int index = 0;
	int length = strlen(str);
	
//	printf("str = %s, length = %d\n",str,length);
	int res=0;
	while(index < length){
		res = res* 10 + str[index] - '0';
		index ++;
	}
	//printf("res = %d\n",res);
	return res;
}

void numToChar(int num){		
	int bit_1;
	int bit_2;		
	bit_1 = num % 13; //使用13 进制 
	//printf("bit_1 = %d,mars = %s\n",bit_1,first[bit_1]);	
	int count = 0;
	if(bit_1!=0) {
		sta.push(first[bit_1]);
		count++;	
	}
	if(num == 0){
		sta.push("tret");
	}	
	if(num/13 != 0) {
		num /= 13;		
		//printf("bit_1 = %d,mars = %s\n",num,secon[num]);	
		sta.push(secon[num]);
		count++;
	}
	//printf("count = %d\n",count);
	while(!sta.empty()){
		cout << sta.top();
		sta.pop();
		if(--count > 0){
			cout << " ";
		}
	}
	printf("\n"); 
}


int opeStr(char str[]){	
	int index = 0;
	int length = strlen(str);
//	printf("str = %s, length = %d\n",str,length);	
	int res = 0;
	char part1[10];
	char part2[10]; 
	if(length == 7){
		while(str[index]!=' '){
			part1[index] = str[index];
		//	printf("%c++ ",str[index]);
			index++;
		}
		part1[index]='\0';	
		
		index ++;
		//cout <<"index = "<<index<<endl;
		while(str[index]!=' ' && str[index]!='\0'){
			part2[index-4] = str[index];
			index++;
		}
		part2[index-4]='\0';			
		//printf("length = 7, part1 = %s, part2 = %s\n",part1,part2);		
	}
	else{
		while(str[index]!=' ' && str[index]!='\0'){
			part1[index] = str[index];
			//printf("@@@%c ",str[index]);
			index++;
		}
		part1[index]='\0';
		//printf("length = 3,part1 = %s\n",part1);
	}	

	if(length == 7){//如果是两位数 【13进制】 
		for(int j = 0;j< 13;j++){
			if(strcmp(part1,secon[j]) == 0){
				res = (j)* 13;
				break;
			}			
		}			
		for(int j = 0;j< 13;j++){
			if(strcmp(part2,first[j]) == 0){
				res = res + j;
				break;
			}		
		}
	}
	else{//如果是一位数 
		for(int j = 0;j< 13;j++){
			if(strcmp(part1,first[j]) == 0){
				res = res + j;
				break;
			}
			if(strcmp(part1,secon[j]) == 0){
				res = j * 13;
				break;
			}			
		}
	}
	cout << res << endl;
}



int main(){
	//printf("%s",secon[1]);
	int N;
	scanf("%d",&N);
	getchar();//吃掉后面的那个回车 
	int i ;
	char str[101][10];
	
	for(i = 0;i< N;i++){
		//scanf("%s",&str[i]);	
		cin.getline(str[i],10);
	}
	
//	for(i = 0;i< N;i++){
//		printf("i = %d, str = %s\n",i,str[i]);
//	}printf("\n");
//		
	int num;
//	printf("====================\n");
	for(i = 0;i< N ;i++){
		if(str[i][0] >='0' && str[i][0] <='9'){//如果处理的是数字 
			//printf("你输入的是数字   ：%s \n",str[i]);
			num = opeNum(str[i]);
			numToChar(num);
		}else{
		//	printf("你输入的是字符串 :%s \n",str[i]);
			opeStr(str[i]);
		} 
	}	
}
/*
4
29
5
elo nov
tam


4
hel mar
may
115
13

3
13
39
maa


10
0
1
2
jou dec
maa
tret
jan
feb
168
15


*/
