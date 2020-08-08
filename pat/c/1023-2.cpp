#include <stdio.h>
#include <string.h>

#define size 30//数字共有20位 

int main(){
	int array1[10]={0},array2[10] = {0};//比较两个数的个数，大小 
	int array[size];
	int i,j ;
	 
	char string[size];//使用20位字符串
	scanf("%s",&string);//输入数字 	 
	
	int length = strlen(string);
		
	//12312378  ----> 87321321式存储，方便后面计算 
	int index = 0;//这里使用index作为下标【重要！！！】 
	for(i = length - 1 ;i >= 0 ;i--){
		array[index++] = string[i]-'0';//将各位存储到int型array[]中 
	}
	
	int flag = 0; //进位标志	 
	for(i = 0 ;i < length ; i++){
		array1[array[i]]++;//记录数字，个数 
		
		array[i] *= 2;
		array[i] += flag;//加进位 
		flag = array[i] /10;//产生进位 
		if(array[i] >= 10){			
			array[i] %= 10;//更新 
		}
	}
	if(flag>0)
	{
		array[length++] = flag;
		flag = 0;//重置 
	}
		
	for(i = 0;i < length;i++ ) {
		array2[array[i]] ++;//出现次数 	
	}
	
	//比较两个数组 ----> 要清楚虽然数字是从1—9,但是我们为啥也要比较0的原因 
	for(i = 0;i<=9;i++){
		if(array1[i] != array2[i]){
			break;
		}
	}
	
	
	if(i > 9){//如果没有遍历完--->不完全相等 
		printf("Yes\n");		 
	}
	else{
		printf("No\n");
	}
	for(i = length - 1;i >= 0 ;i--){
		printf("%d",array[i]);	
	} 	 	
}
/*
1234567899
5634567899
9999
9000000000000000000009
99999999
5
10122448866
325
300
*/

