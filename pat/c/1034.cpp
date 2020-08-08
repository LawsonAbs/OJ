#include<cstdio>
#include<set>
#include<map>
#include<cstring>
#include<set>
#include<algorithm>
#include<iostream>

#define maxn 10005
using namespace std;

struct People{	
	string name;
	int callTime;//ͨ��ʱ�� 	
	int totalNum  = 0;//����֯�µ������� 
	int totalRel = 0;//����֯����Ȩ�� 
	int maxCallId;//������ͨ��ʱ����˵�id 
}; 

struct Result{	
	string name;//���� 
	int num;//��Ŀ 
}; 

map<string,int> sstoi;//�ַ�����Ӧint 
People peo[maxn]; 
int N,K; 
int father[maxn];//��ʾ��������ĸ��ڵ� 

//������� 
int cmp(Result p1,Result p2){
	return p1.name < p2.name;
}

//�ַ���ת����
int PEO_NUM = 0; 
void convert(string name){
	if(sstoi.find(name) == sstoi.end()){//���δ�ҵ�����ַ��� 
		sstoi[name] = PEO_NUM;		
		PEO_NUM ++; //��������һ��
	}
}

//��ʼ������ 
void init(){	
	for(int i = 0; i< maxn;i++){
		father[i] = i;//��ÿ�������ó��Լ��� father 
	} 
	for(int i = 0;i < PEO_NUM ;i++){// ֻ��PEO_NUM ���� 
		peo[i].maxCallId = i;//�Լ������ֵ��id = �Լ� 
	}
} 

//���Ҹ�����
//����ĸ����󣬰���ͨ��ʱ������ж� 
int findFather(int a){
	while(father[a] != a){//������ڵ㲻���Լ� 
		a =	father[a];//���¸��ڵ� 
	}
	return a;//����a 
} 

//�ϲ������ڵ� 
void unionTwo(int a,int b){
	int fa = findFather(a);
	int fb = findFather(b);
	if(fa < fb){//���¸��ڵ� 
		father[fb] = fa;
	}
	else{
		father[fa] = fb;
	}
} 

int main(){	
	cin >> N >> K;
	string call1,call2;//ͨ����������
	int time;//ͨ��ʱ�� 
	int i;		
	init();
	 
	for (i = 0;i < N;i++ ){
		cin >> call1 >> call2 >> time; 		
		convert(call1);
		convert(call2);//�Ȱ������˵�����д�뵽map��
		peo[sstoi[call1]].name = call1; 
		peo[sstoi[call1]].callTime += time;//ͨ��ʱ���ۼ�		 		
		
		peo[sstoi[call2]].name = call2; 
		peo[sstoi[call2]].callTime += time;//ͨ��ʱ���ۼ�	
		
		//�������û��ϲ���һ������ 
		//�ϲ��Ĺ���ȡ��С��id��Ϊ��id  
		unionTwo(sstoi[call1],sstoi[call2]);
	}
	
//	//cout << "PEO_NUM = "<< PEO_NUM<<"\n"; 
//	for(i = 0;i< PEO_NUM;i++){
//		cout << peo[i].name << " "<< peo[i].callTime << "\n"; 
//	}
//	
//	//���father��Ϣ 
//	for(i = 0;i< PEO_NUM;i++){
//		cout <<i<<" "<< father[i]<<"\n";
//	}
		 
	set<int> gangNum ;//gang number 
	
	//��ʼ������Щ gang 
	for(i = 0;i< PEO_NUM;i++){	
		int maxTime = 0;
		int fa = findFather(i);
		peo[fa].totalNum += 1;//���������� 
		peo[fa].totalRel += peo[i].callTime;// ������Ȩ�� 
		gangNum.insert(findFather(i));//���ҽڵ�i��father,���ŵ�set�� 		
		
		//�ҳ��ʱ��ͨ������ 
		if( peo[peo[fa].maxCallId].callTime < peo[i].callTime){
			peo[fa].maxCallId = i;//����i��ֵ 
		}
	}
	//cout <<"gangNum = " << gangNum.size()<<"\n"; 
	
	//ɾ��һЩ����������������
	//���� <= 2; ����ϵȨ�ش���K 	
	for(set<int> :: iterator it = gangNum.begin(); it!=gangNum.end();it++){		
		if(peo[*it].totalNum <= 2 || (peo[*it].totalRel / 2) <= K ){
			gangNum.erase(*it);	
			//cout << *it << " ";
		}		
	//	cout << peo[*it].name << " "<< peo[*it].maxCallId <<" "<< peo[*it].callTime<<" "<<peo[*it].totalRel <<" "<<peo[*it].totalNum <<"\n"; 
	}
	
	cout <<gangNum.size()<<"\n"; 
	
	Result res[maxn];//������  �������� 
	int index = 0;
	for(set<int> :: iterator it = gangNum.begin(); it!=gangNum.end();it++){	
		res[index].name = peo[peo[*it].maxCallId].name;//��ֵ���� 
		res[index].num = peo[*it].totalNum;//��ֵ���� 		
		index++;
	}
	
	sort(res,res+index,cmp) ;
	for(i = 0;i< index;i++ ){
		cout << res[i].name <<" "<< res[i].num<<"\n"	;
	}
}
/*
8 59
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10
AAA BBB 10
BBB AAA 20
AAA CCC 40
*/

 
