#include<cstdio>
#include<algorithm>
#include<string.h>
#include<iostream>

#define N 10001
using namespace std;

//新建一个student 结构体，用于保存student的信息 
struct student
{
	int height;
	char name[10]; //no more than 8 English letters without space
};

student stu[10001];

//比较函数，对结构体进行排序 
int cmp(student s1,student s2){
	if(s1.height!=s2.height){
		return s1.height > s2.height;
	}	
	else if(s1.height == s2.height){
		return strcmp(s1.name,s2.name) < 0;	
	}	
}

//输出该result中的内容
int printResult(student result[],int bundary){	 
	for(int i = 0;i < bundary;i++){
		if(i != bundary - 1) {
			printf("%s ",result[i].name);
		} 
		else{ 
			printf("%s\n",result[i].name);			 
		} 
	}
} 

//result 是结果集 ； mid是中间位置【最高个】；offset是到中间位置的距离；cur是stu中的下标 
void leftAdd(student result[],int mid,int bundary,int cur){
	int offset =1; 
	for(int i = 1;i < bundary ; i += 2){//添加左边的人 		
		result[mid - offset ] = stu[cur+i];
		offset ++;
	}
}

void rightAdd(student result[],int mid,int bundary,int cur){
	int offset =1; 
	for(int i = 2;i < bundary ;i += 2){//添加右边的人 
		result[mid + offset] = stu[cur+i];
		offset ++;
	}
}

int main(){
	int number;//the total number of people
	int k;//the total number of rows		
	scanf("%d%d",&number,&k);
			
	int i = 0,j = 0;	
	for(i = 0;i < number ;i++){		
		scanf("%s %d",&stu[i].name,&stu[i].height);	
	}
	
	sort(stu,stu+number,cmp);

	int rest ;//表示最后一排站的人 
	//输出队尾
	int mid ;	
	int num;
	if( k > 1) {	
		num = number / k; //计算 每行站多少人 
		rest = number % k + num; //求出最后一排的人数 		
	}
	else{
		rest = number;//最后一排 = 第一排 
	} 	
	student result[rest];//定义一个输出数组，用于盛放排队后的人 	
	
	//=================计算最后一排 =====================
	mid = rest / 2;	
	int cur = 0; //用于标识student结构体中的下标 
	result[mid] = stu[0];//最高个是第一一个人 	
	leftAdd(result,mid,rest,cur);		
	rightAdd(result,mid,rest,cur);	
	//输出该result中的内容
	printResult(result,rest);	
		
	if(k > 1){ // 如果不止一排，则计算除第一排的任一排 ----------			
		mid = num /2;	
		cur = rest ;//表示stu 当前的下标 		
		for(i = 0;i < k -1 ;i++){			
			//给最高个赋值
			result[mid]	 = stu[cur];		 
			//轮流给两边赋值 			
			leftAdd(result,mid,num,cur);			
			rightAdd(result,mid,num,cur);
			cur += num;//往后移k位 			
			//输出 
			printResult(result,num);		
		}	
	}				
	return 0;
}
