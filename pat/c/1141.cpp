#include<cstdio>
#include<cstring>
#include<string> 
#include<iostream>
#include<algorithm>
#include<cmath>
#define maxn 100005
using namespace std;

//ID Score School
struct testees{
	string id;
	int sco;
	string sch;	
};

struct result{
	int rank;
	string school;
	int score;
	int totalStu;
}; 

testees te[maxn];
result res[maxn];

void lower(string &s){
	int len = s.size();
	for(int i = 0;i< len;i++){
		if(s[i] >='A' && s[i]<='Z'){
			s[i] = s[i] + 32;
		}
	}
}

int cmp_testees(testees t1,testees t2){
	if (t1.sch == t2.sch){
		return t1.id < t2.id;	
	}
	return t1.sch < t2.sch;
}

int cmp_res(result r1,result r2){
	if(r1.score == r2.score){
		if(r1.totalStu == r2.totalStu) return r1.school < r2.school;
		return r1.totalStu < r2.totalStu; 
	} 
	return r1.score > r2.score;
} 

int main(){
	int N;
	cin >> N;
	int i ,j;
	string school;
	for(i = 0;i< N ;i++){
		cin >> te[i].id >> te[i].sco;
		cin >> school;
		lower(school);
		te[i].sch = school;
		//cout << "school = " << school;
	}
	
	//按照学校进行排序 
	sort(te,te+N,cmp_testees);
	//进行归类 
	string curSch;//学校的名字 
	int num ;//参加考试的该学校的人数 
	int index  = 0;
	double grade ;
	for(i = 0;i< N ;i++){
		curSch = te[i].sch;
		num = 0;//初始时num = 0 
		grade = 0;
		while(curSch == te[i].sch && i < N){
			if(te[i].id[0] == 'B'){
				grade = grade + (te[i].sco / 1.5);
			}
			if(te[i].id[0] == 'A'){
				grade = grade + te[i].sco ;
			}
			if(te[i].id[0] == 'T'){
				grade = grade + (te[i].sco * 1.5);
			}
			i++;
			num ++;
		}
		i--;
		res[index].school = curSch;
		res[index].score = floor(grade);
		res[index].totalStu = num;	
		index ++;	
	} 
	
	sort(res,res+index,cmp_res); 
	cout << index << "\n";
	int rank = 1;
	int totalRank = 1;
	for(i = 0;i< index;i++){
		if(res[i].score == res[i-1].score && i>=1){
			cout << rank << " " 
			<< res[i].school << " " 
			<< res[i].score << " " 
			<< res[i].totalStu<<"\n";				
		}
		else{
			cout << totalRank << " " 
			<< res[i].school << " " 
			<< res[i].score << " " 
			<< res[i].totalStu<<"\n";
			rank = totalRank;
		}
		totalRank++;	
	}
} 
/*
1
B57908 53 LanX
*/
