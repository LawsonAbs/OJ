#include<cstdio>
#include<string>
#include<set>
#include<map>
#include<cmath>
#include<algorithm> 
#include<iostream>
#define maxn 10005

using namespace std;

struct result{
	string id;	
	int proAss = 0;
	int midScore = -1;
	int finalScore = -1;	
	int grade = 0;
};

//定义三个结构体 
int cmp(result r1,result r2){
	if(r1.grade == r2.grade) return r1.id < r2.id;
	return r1.grade > r2.grade;
}


int main(){
	int P,M,N;
	scanf("%d%d%d",&P,&M,&N);
	int i,j,k;
	string id;
	int score;
	int index = 0;	
	map<string,int> program;
	map<string,result> stu;
	result res[maxn];
	for(i = 0;i < P;i++){		
		cin >> id >> score;
		if(score >= 200){
			stu[id].id = id; 
			stu[id].proAss = score;			
		}
	}
	
	for(i = 0;i< M ;i++){
		cin >> id;
		cin >> stu[id].midScore;//输入id 以及期中考试 成绩	
	}
	
	for(i = 0;i< N ;i++){
		cin >> id;
		cin >> stu[id].finalScore;//输入id 以及期末考试 成绩		
	}
	
	double grade = 0;
	int count  = 0;//所有的人数 	
	for(map<string,result>::iterator it = stu.begin();it!=stu.end();it++){
		//cout << it->first <<" " << it->second.proAss << endl;
		if(it->second.proAss >= 200){//如果成绩 >= 200 
			if(it->second.midScore > it->second.finalScore){//如果 midScore > finalScore 
				grade = (it->second.midScore * 0.4) + (it->second.finalScore * 0.6);
				grade = round(grade);
			}else{
				grade = it->second.finalScore;
			}			
			if(grade >= 60){
				res[count].id =  it->second.id;
				res[count].proAss = it->second.proAss;
				res[count].midScore = it->second.midScore;
				res[count].finalScore = it->second.finalScore;
				res[count].grade = grade;
				count ++;
			}			
		}
	} 
	sort(res,res+count,cmp);
	for(i = 0;i< count;i++){
		cout << res[i].id <<" "
		<< res[i].proAss <<" "
		<< res[i].midScore <<" "
		<< res[i].finalScore <<" "
		<< res[i].grade << endl;
	}
}
