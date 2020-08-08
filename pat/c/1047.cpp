#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int M = 40010;//学生上界
const int N = 2510;//课程数上界


vector < vector<string> > studentOfCourse[M];
//char studentOfCourse[M][5];//每门课对应的学生 

int main(){
	int studentNum,totalCourse;//学生人数，课程数 
	char name[5] ;
	
	scanf("%d%d",&studentNum,&totalCourse);
	for(int i = 0;i < studentNum;i++){ 		
		scanf("%s",name);//输入学生姓名 
		int  courseNum;//表示某学生的课程数
		scanf("%d",&courseNum);
		for(int j = 0;j < totalCourse ;j++){
			int course;//课程号 
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
