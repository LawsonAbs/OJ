#include <stdio.h>
#include <string.h>

/**
1.确定寻找的边界
2.数据不能越界 
3.参阅博客http://www.cnblogs.com/549294286/p/3571604.html 
**/

int hashMap [36] ={false};//用来存储0-9和a-z之间的数 
char N1[11],N2[11];
int tag;
long long radix;//radix表示的是进制
long long result ;
//typedef long long LL;
//LL inf = (1LL<<63 - 1); 

long long inf = ((long long)1<<63)-1;//long long的最大值2^63-1，注意括号 


//遍历整个数组确定进制最小边界  ----> 为保险，还是设置为long long类型 
long long solveLowestBoundary(char str[]){
	int i ,length ;
	long long lowestBoundary = 1;//lowestBoundary表示的是最小的边界 
	length = strlen(str);
	for (i = 0;i<length;i++){
		if(str[i] <='9' && str[i] >='0'){
			hashMap[(str[i]-'0')] = true;//需要注意这里是str[i]-'0' 
		}
		else if(str[i] <= 'z' && str[i] >= 'a'){
			hashMap[(str[i]-'a'+10)] = true;
		}
	}

	for(i = 0;i<35;i++){
		if(lowestBoundary <= i && hashMap[i] == true){		
			lowestBoundary = i + 1;//+1之后才表示最小的进制 （相当于二分法中的left） 
		}
	}
	return lowestBoundary;
} 


//将字符串转换成十进制 
long long convertTo10(char str[],long long radix,long long inf){
	int length = strlen(str);//求出字符串的长度
	int i ;
	long long sum = 0;//表示转换进制后的和---->每次运算后都得清零【放在正确的位置】 
	for	(i = 0;i<length;i++){
		if(str[i]<='9' && str[i]>=0){
			sum = ( sum * radix ) + str[i]-'0';
		}
		else if(str[i] <='z' && str[i]>='a'){
			sum = (sum * radix) + (str[i] - 'a' + 10) ;
		}
		
		//很为关键的一步 
		if(sum <0 || sum > inf){//溢出或者超过N1的十进制 		
			return -1;
		}		
	}
	//printf("sumOf10 = %lld\n",sum);
	return sum;//返回最后的操作值 
} 

int cmp(char N2[],long long radix, long long t){
	int len = strlen(N2);
	long long num = convertTo10(N2,radix,t);
	if(num < 0)	return 1;//溢出 
	//printf("t = %d\n",t); 
	if(t > num ) return -1;
	else if(t == num) return 0;//相等，返回0 
	else return 1;
}


//使用二分法找到第一个小于result的合适进制 
long long selectRadix (long long left,long long right,long long t){	
	long long mid;		
	//printf("发的t = %d\n",t);
	while(left <= right){
		mid = (left + right) / 2;
		int flag = cmp(N2,mid,t); 
	//	printf("flag = %d\n",flag); 
	//	printf("left = %lld,mid = %lld,right = %lld\n",left,mid,right); 				
		if(flag == 0){//如果该进制的数找到了，则返回该进制 
			return mid;
		}				
		else if(flag == -1 ){//将N1这个数按照mid这个进制转换 
			left = mid + 1 ;
		}
		else{
			right = mid - 1;
		}	
	}	
	return -1 ;
}


int main(){
	
	scanf("%s %s %d %lld",N1,N2,&tag,&radix);	
	if(tag == 2){//为了使方便操作（将所有的radix都是N1的进制） 
		char tempStr[11];
		strcpy(tempStr,N1);//暂存N1字符串的值 
		strcpy(N1,N2);
		strcpy(N2,tempStr); 
	}
	
	long long temp ;//temp用来存储二分法的上界 
	 
	result = convertTo10(N1,radix,inf);
	temp = result;
	
	//printf("result = %lld\n",temp );
	
	long long lowestBoundary = solveLowestBoundary(N2);//确定进制的最小边界 
	
	//确保二分法的上界是一个最小的准确值 
	if(temp < lowestBoundary){
		temp = lowestBoundary;
	}
	
	if(selectRadix (lowestBoundary,temp,result) == -1){
		printf("Impossible\n");		
	}		
	else {
		printf("%lld\n",selectRadix (lowestBoundary,temp,result));		
	}
} 

/** 
s9jix hj 1 36

oj scb8j 2 36

10 aaaaaaaaaa 2 15

6 110 1 10

1 ab 1 2
 
32 20 1 10

0 0 1 34
5 5 1 10
*/
