#include<cstdio>
#include<algorithm>
#include<map>
#include<queue> 
#include<iostream>
#define maxn 10005

using namespace std;

struct Mice{
	int weight;//其实这个点文中没有说清楚是否是整数
	int initOrder;//初始的比赛顺序
	int rank;// 顺序 
	int playOrder;
	int finRank;
};

Mice mice[maxn];
Mice tempMice;

//按照玩家顺序进行排序 
int cmp1(Mice m1,Mice m2){
	return m1.playOrder < m2.playOrder;
}

//按照最终排名进行排序 
int cmp2(Mice m1,Mice m2){
	return m1.rank > m2.rank;
}

//按照初始顺序进行排序 
int cmp3(Mice m1,Mice m2){
	return m1.initOrder < m2.initOrder;
}

int main(){
	int Np,Ng;
	cin >> Np >> Ng;
	int i,j;
	//输入各个mice的重量 
	for(i = 0;i< Np;i++){
		cin >> mice[i].weight;
		mice[i].initOrder = i;
	}
	//输出初始顺序 
	for(i = 0;i< Np;i++){
		cin >> mice[i].playOrder;
	}
	
	sort(mice,mice+Np,cmp1);			
	queue<Mice> que;//存放
	
	for(i = 0;i< Np;i++){
		tempMice.playOrder = mice[i].playOrder;
		tempMice.weight = mice[i].weight;//加入第一元素 
		que.push(tempMice);//加入到队列中			
	}
	//下面这个tempMice只是一个标记符，用于确定这一遍已经到底了 
	tempMice.playOrder = -1;
	tempMice.weight = -1;
	que.push(tempMice); 
	
	int index = 1; 
	int maxWeight = -1;	//表示的是最大的重量 
	int preIndex = -1;
	int count = 1;	
	int flag = 0;
	while(que.size() != 2){//当队列只剩最后2个元素时 		
		index = 0; //reset to 0	
		maxWeight = -1;	//赋值&重置 
		while(index < Ng && !que.empty()){ //说明需要开始处理了 
			tempMice = que.front();//取队首元素			
			cout <<"first = "<< tempMice.playOrder <<", second = "<<tempMice.weight<<"\n";
			if(tempMice.playOrder == -1 || tempMice.weight == -1) {//如果遇到标记的时候，直接入队，不再处理 
				flag = 1;
				que.pop();
				break;//直接跳出while 
			} 
			//不同的条件一定不要耦合在一起 		
			mice[tempMice.playOrder].rank = count; 
			
			
			if(tempMice.weight > maxWeight){//如果当前的Mice 小于 maxWeight，则需要删除当前的frontMice 								
				maxWeight = tempMice.weight;//赋weight
				preIndex = tempMice.playOrder;//赋下标 
			}						
			index++;
			que.pop();//队首移除 			
		}		
		
		//将最大的元素加入到队列中 
		tempMice.playOrder = preIndex;
		tempMice.weight = maxWeight;
		que.push(tempMice);
		
		if(flag == 1) {//如果遇到标记的时候，直接入队，不再处理 
			count ++;
			tempMice.playOrder = -1;
			tempMice.weight = -1;
			que.push(tempMice);	
			flag = 0;
		}		
	}
	
	//写出最大的排名 
	mice[que.front().playOrder].rank = count; 
	
	for(i = 0;i< Np;i++){
		cout<< mice[i].weight<<", "<<mice[i].rank <<"\n";		
	}
	cout <<"===="<<"\n" ;
	
	sort(mice,mice+Np,cmp2);
	for(i = 0;i< Np;i++){
		cout<< mice[i].weight<<", "<<mice[i].rank <<"\n";		
	}

	int rank = 1;//总排名 
	mice[0].finRank = 1;//排名第一 
	for(i = 1;i< Np;i++){
		if( mice[i].rank == mice[i-1].rank ) {//如果rank排名 和上一个rank相同 
			mice[i].finRank =  rank;
			cout<< mice[i].weight <<":"<<mice[i].rank<<"\n";
		}
		else{//如果不等的话 
			rank = i+1;// 更新i的值 
			mice[i].finRank = rank;
		}		
	}
	
	sort(mice,mice+Np,cmp3);
	for(i = 0;i< Np;i++){
		cout << mice[i].weight<<", "<<mice[i].finRank<<"\n";
		//cout<< mice[i].finRank ;
		if(i!=(Np-1)) cout <<" ";
	}	
}
/*
11 3
25 18 0 46 37 3 19 22 57 56 10
6 0 8 7 10 5 9 1 4 2 3

*/
