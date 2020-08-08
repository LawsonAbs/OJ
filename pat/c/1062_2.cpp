#include <cstdio>
#include <algorithm>
#define maxn 100010
using namespace std;

struct Student{
	int id;
	int de,cai,sum;
}tempStu[maxn];

Student sage[maxn],	nobl[maxn], fool[maxn],smal[maxn];//圣人 君子 愚民 小人 
bool cmp(Student s1,Student s2){
	if(s1.sum == s2.sum){
		if(s1.de == s2.de)	
			return s1.id < s2.id;//小的在前 
		else
			return s1.de > s2.de;
	}
	else	return s1.sum > s2.sum;//大的在前 	
} 

//输出函数 
void outPut(int n,Student stu[]){
	int i;
	for (i = 0;i< n;i++){
		printf("%d %d %d\n",stu[i].id,stu[i].de,stu[i].cai); 
	}
}

int main(){
	int n,l,h;
	int count = 0;
	int sageCo = 0,noblCo =0,foolCo = 0,smalCo = 0;
	scanf("%d %d %d",&n,&l,&h);

	for(int i = 0;i < n;i++){
		scanf("%d %d %d",&tempStu[i].id,&tempStu[i].de,&tempStu[i].cai);
		tempStu[i].sum = tempStu[i].de + tempStu[i].cai;
		if(tempStu[i].cai < l || tempStu[i].de < l)  count++;//计数 不及格者
		else if(tempStu[i].cai >= h && tempStu[i].de >= h){
			sage[sageCo].sum = tempStu[i].sum;
			sage[sageCo++] = tempStu[i];//结构体赋值 	
		}
		else if(tempStu[i].cai < h && tempStu[i].de >= h){
			nobl[noblCo].sum = tempStu[i].sum;
			nobl[noblCo++] = tempStu[i];//结构体赋值 			
		}
		else if(tempStu[i].cai <= tempStu[i].de && tempStu[i].de < h ){
			fool[foolCo].sum = tempStu[i].sum;
			fool[foolCo++] = tempStu[i];//结构体赋值 			
		} 
		else {
			smal[smalCo].sum = tempStu[i].sum; 
			smal[smalCo++] = tempStu[i];					
		}			
	}
	sort(sage,sage+sageCo,cmp);
	sort(nobl,nobl+noblCo,cmp);
	sort(fool,fool+foolCo,cmp);
	sort(smal,smal+smalCo,cmp);
	
	printf("%d\n",n-count);
	outPut(sageCo,sage);
	outPut(noblCo,nobl);
	outPut(foolCo,fool);
	outPut(smalCo,smal);
	return 0;
}
/**
14 60 80
10000001 64 90
10000002 90 60
10000011 85 80
10000003 85 80
10000004 80 85
10000005 82 77
10000006 83 76
10000007 90 78
10000008 75 79
10000009 59 90
10000010 88 45
10000012 80 100
10000013 90 99
10000014 66 60
*/


