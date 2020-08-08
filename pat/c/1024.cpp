#include <stdio.h>
#include <string.h>
 
#define size 10000
/*
1.之所以会越界，是因为数字是成指数倍增加的，2-->4-->8-->16 
*/ 

char string[size];//使用20位字符串
int array[size];//保存数组 
int length = 0;//为当前数字的长度 
 
//执行加法操作 
void operate(){
	int flag = 0; //进位标志	 
	int i,j ;//临时变量 
	int tempArray[size];//暂存 
	for(i = 0;i < length ;i++){
		tempArray[i] = array[i];
	}
	
	for(i = 0 ,j = length -1;i < length,j>=0 ; i++,j--){		
		array[i] += tempArray[j] ;
		array[i] += flag;//加进位 
		flag = array[i] /10;//产生进位 
		if(array[i] >= 10){			
			array[i] %= 10;//更新 
		}
	}
	if(flag>0)
	{
		array[length++] = flag;
	}
}

//判断一个数是否是回文数 
bool isPalindromicNumber() {
	int i = 0 ;//注意这里的i需要初始化，否则会得到段错误【重要！！】 
	if(length == 1 ){//只有一位数 
		return true;
	}
		
	int index ;//从后往前遍历 
	for(int j = 0,index = length-1;j < length/2 ;j++,index--){
		if(array[j] != array[index]){
			return false;
		} 
	} 
	return true;
}

int main(){
	scanf("%s",&string);//输入数字 	 		
	int k ;//给定的步骤 
	scanf("%d",&k);
		
	int i , step = 0; //步数
	length = strlen(string);
	
	int index = 0;//这里使用index作为下标【重要！！！】 
	for(i = length - 1 ;i >= 0 ;i--){
		array[index++] = string[i]-'0';//将各位存储到int型array[]中 
	}

	//如果是回文数 
	if(isPalindromicNumber()){
		for(int m  = 0;m<index;m++){
			printf("%d",array[m]);//直接输出即可 			
		}printf("\n0");		
	}
	else{//如果不是		 
		do{ 			
			operate();//操作	
			step ++; 
		}while(!isPalindromicNumber() && (--k)>0);
		
		for(i = length - 1;i >= 0 ;i--){
			printf("%d",array[i]);
		}printf("\n");
		printf("%d\n",step);	
	}
}

/*
121 2
10000001 1
67 2
69 3
10000000000 100
90000000008 100
3 3
0 1
**/
