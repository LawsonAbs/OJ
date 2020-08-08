#include<cstdio>
#include<string>
#include<set>
#include<map>
#include<cmath>
#include<algorithm> 
#include<iostream>
#define maxn 10005

using namespace std;

struct mid{
	string id;
	int midScore;	
};

struct final{
	string id;	
	int finalScore;	
};


struct result{
	string id;	
	int proAss = 0;
	int midSco = -1;
	int finalSco = -1;
	int grade = 0;
};


//���������ṹ�� 
mid midTerm[maxn];
final finalTerm[maxn];
result res[maxn];

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
	set<string> quaId;
	map<string,int> program;
	for(i = 0;i < P;i++){
		//scanf("%s %d",&id,&score);
		cin >> id >> score;
		if(score >= 200){
			quaId.insert(id);
			program[id] = score;
		}
	}
	
	for(i = 0;i< M ;i++){
		cin >> midTerm[i].id >> midTerm[i].midScore;//����id �Լ����п��� �ɼ�		
	}
	
	for(i = 0;i< N ;i++){
		cin >> finalTerm[i].id >> finalTerm[i].finalScore;//����id �Լ���ĩ���� �ɼ�		
	}
	
	double grade = 0;
	int count  = 0;//���е����� 
	for(i = 0;i< M ;i++){
		if(quaId.find(midTerm[i].id) != quaId.end()){//����ҵ��ˣ���˵�����ܻ��֤�� 
			for(j = 0;j < N ;j++){
				if(midTerm[i].id == finalTerm[j].id){
					break; 
				}
			}
			//��ʼ�������ĳɼ� 
			if(j < N){//˵���Ȳμ������п��ԣ�Ҳ�μ�����ĩ���� 
				if(midTerm[i].midScore > finalTerm[i].finalScore){
					grade = ( midTerm[i].midScore * 0.4 ) + (finalTerm[j].finalScore * 0.6);
					grade = round(grade);					
				}
				else{
					grade = finalTerm[j].finalScore;
				}
			}
			if(grade >= 60){
				res[count].id =  midTerm[i].id;
				res[count].proAss = program[midTerm[i].id];
				res[count].midSco = midTerm[i].midScore;
				res[count].finalSco = finalTerm[j].finalScore;
				res[count].grade = grade;
				count ++;
			}			
		}		
	} 
	sort(res,res+count,cmp);
	for(i = 0;i< count;i++){
		cout << res[i].id <<" "
		<< res[i].proAss <<" "
		<< res[i].midSco <<" "
		<< res[i].finalSco <<" "
		<< res[i].grade <<" "
		<< endl;
	}
}
