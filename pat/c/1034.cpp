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
	int callTime;//通话时长 	
	int totalNum  = 0;//该组织下的总人数 
	int totalRel = 0;//该组织的总权重 
	int maxCallId;//该组中通话时长最长人的id 
}; 

struct Result{	
	string name;//姓名 
	int num;//数目 
}; 

map<string,int> sstoi;//字符串对应int 
People peo[maxn]; 
int N,K; 
int father[maxn];//表示各个对象的父节点 

//排序操作 
int cmp(Result p1,Result p2){
	return p1.name < p2.name;
}

//字符串转数字
int PEO_NUM = 0; 
void convert(string name){
	if(sstoi.find(name) == sstoi.end()){//如果未找到这个字符串 
		sstoi[name] = PEO_NUM;		
		PEO_NUM ++; //自增处理一下
	}
}

//初始化操作 
void init(){	
	for(int i = 0; i< maxn;i++){
		father[i] = i;//将每个人设置成自己的 father 
	} 
	for(int i = 0;i < PEO_NUM ;i++){// 只有PEO_NUM 个人 
		peo[i].maxCallId = i;//自己的最大值的id = 自己 
	}
} 

//查找父对象
//这里的父对象，按照通话时长大的判断 
int findFather(int a){
	while(father[a] != a){//如果父节点不是自己 
		a =	father[a];//更新父节点 
	}
	return a;//返回a 
} 

//合并两个节点 
void unionTwo(int a,int b){
	int fa = findFather(a);
	int fb = findFather(b);
	if(fa < fb){//更新父节点 
		father[fb] = fa;
	}
	else{
		father[fa] = fb;
	}
} 

int main(){	
	cin >> N >> K;
	string call1,call2;//通话的两个人
	int time;//通话时间 
	int i;		
	init();
	 
	for (i = 0;i < N;i++ ){
		cin >> call1 >> call2 >> time; 		
		convert(call1);
		convert(call2);//先把两个人的姓名写入到map中
		peo[sstoi[call1]].name = call1; 
		peo[sstoi[call1]].callTime += time;//通话时间累加		 		
		
		peo[sstoi[call2]].name = call2; 
		peo[sstoi[call2]].callTime += time;//通话时间累加	
		
		//将两个用户合并成一个家族 
		//合并的规则：取较小的id作为父id  
		unionTwo(sstoi[call1],sstoi[call2]);
	}
	
//	//cout << "PEO_NUM = "<< PEO_NUM<<"\n"; 
//	for(i = 0;i< PEO_NUM;i++){
//		cout << peo[i].name << " "<< peo[i].callTime << "\n"; 
//	}
//	
//	//输出father信息 
//	for(i = 0;i< PEO_NUM;i++){
//		cout <<i<<" "<< father[i]<<"\n";
//	}
		 
	set<int> gangNum ;//gang number 
	
	//开始处理这些 gang 
	for(i = 0;i< PEO_NUM;i++){	
		int maxTime = 0;
		int fa = findFather(i);
		peo[fa].totalNum += 1;//更新总人数 
		peo[fa].totalRel += peo[i].callTime;// 更新总权重 
		gangNum.insert(findFather(i));//查找节点i的father,并放到set中 		
		
		//找出最长时间通话的人 
		if( peo[peo[fa].maxCallId].callTime < peo[i].callTime){
			peo[fa].maxCallId = i;//更新i的值 
		}
	}
	//cout <<"gangNum = " << gangNum.size()<<"\n"; 
	
	//删除一些不符合条件的数据
	//人数 <= 2; 总联系权重大于K 	
	for(set<int> :: iterator it = gangNum.begin(); it!=gangNum.end();it++){		
		if(peo[*it].totalNum <= 2 || (peo[*it].totalRel / 2) <= K ){
			gangNum.erase(*it);	
			//cout << *it << " ";
		}		
	//	cout << peo[*it].name << " "<< peo[*it].maxCallId <<" "<< peo[*it].callTime<<" "<<peo[*it].totalRel <<" "<<peo[*it].totalNum <<"\n"; 
	}
	
	cout <<gangNum.size()<<"\n"; 
	
	Result res[maxn];//保存结果  用于排序 
	int index = 0;
	for(set<int> :: iterator it = gangNum.begin(); it!=gangNum.end();it++){	
		res[index].name = peo[peo[*it].maxCallId].name;//赋值操作 
		res[index].num = peo[*it].totalNum;//赋值操作 		
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

 
