#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int M = 40010;//ѧ���Ͻ�
const int N = 2510;//�γ����Ͻ�


vector < vector<string> > studentOfCourse[M];
//char studentOfCourse[M][5];//ÿ�ſζ�Ӧ��ѧ�� 

int main(){
	int studentNum,totalCourse;//ѧ���������γ��� 
	char name[5] ;
	
	scanf("%d%d",&studentNum,&totalCourse);
	for(int i = 0;i < studentNum;i++){ 		
		scanf("%s",name);//����ѧ������ 
		int  courseNum;//��ʾĳѧ���Ŀγ���
		scanf("%d",&courseNum);
		for(int j = 0;j < totalCourse ;j++){
			int course;//�γ̺� 
			scanf("%d",&course);
			studentOfCourse[course][ ];			
		}		
	}
	
	
	for(int i = 0;i<totalCourse;i++){
		printf("%d %d\n",i,studentOfCourse[i].size);
		for(int j = 0;j < studentOfCourse[i].size();j++){
			printf("%s\n",studentOfCourse[i].[j]);
		}		
	}
	return 0 ;
}
