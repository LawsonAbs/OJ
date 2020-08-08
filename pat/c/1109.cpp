#include<cstdio>
#include<algorithm>
#include<string.h>
#include<iostream>

#define N 10001
using namespace std;

//�½�һ��student �ṹ�壬���ڱ���student����Ϣ 
struct student
{
	int height;
	char name[10]; //no more than 8 English letters without space
};

student stu[10001];

//�ȽϺ������Խṹ��������� 
int cmp(student s1,student s2){
	if(s1.height!=s2.height){
		return s1.height > s2.height;
	}	
	else if(s1.height == s2.height){
		return strcmp(s1.name,s2.name) < 0;	
	}	
}

//�����result�е�����
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

//result �ǽ���� �� mid���м�λ�á���߸�����offset�ǵ��м�λ�õľ��룻cur��stu�е��±� 
void leftAdd(student result[],int mid,int bundary,int cur){
	int offset =1; 
	for(int i = 1;i < bundary ; i += 2){//�����ߵ��� 		
		result[mid - offset ] = stu[cur+i];
		offset ++;
	}
}

void rightAdd(student result[],int mid,int bundary,int cur){
	int offset =1; 
	for(int i = 2;i < bundary ;i += 2){//����ұߵ��� 
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

	int rest ;//��ʾ���һ��վ���� 
	//�����β
	int mid ;	
	int num;
	if( k > 1) {	
		num = number / k; //���� ÿ��վ������ 
		rest = number % k + num; //������һ�ŵ����� 		
	}
	else{
		rest = number;//���һ�� = ��һ�� 
	} 	
	student result[rest];//����һ��������飬����ʢ���ŶӺ���� 	
	
	//=================�������һ�� =====================
	mid = rest / 2;	
	int cur = 0; //���ڱ�ʶstudent�ṹ���е��±� 
	result[mid] = stu[0];//��߸��ǵ�һһ���� 	
	leftAdd(result,mid,rest,cur);		
	rightAdd(result,mid,rest,cur);	
	//�����result�е�����
	printResult(result,rest);	
		
	if(k > 1){ // �����ֹһ�ţ���������һ�ŵ���һ�� ----------			
		mid = num /2;	
		cur = rest ;//��ʾstu ��ǰ���±� 		
		for(i = 0;i < k -1 ;i++){			
			//����߸���ֵ
			result[mid]	 = stu[cur];		 
			//���������߸�ֵ 			
			leftAdd(result,mid,num,cur);			
			rightAdd(result,mid,num,cur);
			cur += num;//������kλ 			
			//��� 
			printResult(result,num);		
		}	
	}				
	return 0;
}
