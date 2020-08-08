#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<iomanip>
#include<iostream>

using namespace std;

struct student{
	char regId[15];
	int score;
};

struct result3{
	int site;
	int num;
};

student stu[10005];
student res[10005];
result3 res3[10005];

int cmp(student s1,student s2){
	if(s1.score == s2.score) return strcmp(s1.regId,s2.regId) < 0;
 	return s1.score > s2.score;
}

int cmp2(result3 r1,result3 r2){
	if(r1.num == r2.num) return r1.site< r2.site;
	return r1.num > r2.num;
}

int main(){
	int N,M;
	cin >> N>> M;
	int i ,j;
	for(i = 0;i< N;i++){
		cin >> stu[i].regId >> stu[i].score;
	}
	
	int type;
	char level;//如果type是1的时候，则输入level 
	int term;//如果tupe是2/3 ，则输入term 
	int flag ;
	string temp;//暂存字符串 
	int site = 0;
	for(i = 0;i< M;i++){
		flag = 0;
		cin >> type;
		if(type == 1){
			cin >> level;//开始处理
			int index = 0;
			cout << "Case "<< i+1 <<": "<<type << " " << level<< "\n";						
			for(j = 0;j< N;j++){
				if(stu[j].regId[0] == level){
					flag = 1;//说明有 
					strcpy(res[index].regId,stu[j].regId);
					res[index].score = stu[j].score;
					index ++;					
				}
			}
			if(flag == 0){
				cout << "NA" << "\n";
			}else{
				sort(res,res+index,cmp);
				for(int k = 0;k< index;k++){
					cout << res[k].regId << " "<< res[k].score<<"\n";
				}
			}
		}
		else if(type == 2){
			cin >> term;
			int testees = 0;
			int sum = 0;
			for(j = 1;j < N;j++){				
				temp = stu[j].regId;				
				site = stoi(temp.substr(1,3));				
				if(site == term){
					flag = 1;
					testees ++;
					sum += stu[j].score;					
				}
			}
			cout << "Case "<< i+1 <<": "<<type << " "<<setfill('0')<<setw(3)<<term<<"\n";
			if(flag == 1) cout << testees << " "<< sum << "\n";
			else cout << "NA" << "\n";
		}
		else if(type == 3){
			cin >> term;
			int array[1000];
			memset(array,0,sizeof(array));
			int date = 0;			
			int index = 0;
			for(j = 0;j< N;j++){				
				temp = stu[j].regId;				
				date = stoi(temp.substr(4,6));					
				if(date == term){
					flag = 1;
					temp = stu[j].regId;
					site = stoi(temp.substr(1,3));
					array[site]++;
				}
			}			
			cout << "Case "<< i+1 <<": "<< type << " " << setfill('0') << setw(6) << term <<"\n";						
			if(flag == 1){			
				for(j = 0;j< 1000;j++){
					if(array[j]!=0){
						res3[index].num = array[j];
						res3[index].site = j;
						index++; 						
					}
				}
				sort(res3,res3+index,cmp2);
				for(j = 0;j < index;j++){
					cout << res3[j].site  <<" "<< res3[j].num << "\n";
				}
			}
			else cout << "NA" << "\n";			
		}
	}
}
/*
8 4
B123180908127 99
B102180908003 86
A112180318002 98
T107150310127 62
A107180908108 100
T123180908010 78
B112160918035 88
A107180908021 98
1 A
2 107
3 180908
2 002

8 4
B123180908127 99
B102180908003 86
A112180318002 98
T107150310127 62
A107180908108 100
T123180908010 78
B112160918035 88
A107180908021 98
1 A
2 107
3 080908
2 002

*/
