#include<cstdio>
#include<algorithm>
#include<map>
#include<queue> 
#include<iostream>
#define maxn 1005

using namespace std;

struct Mice{
	int weight;//其实这个点文中没有说清楚是否是整数
	int initOrder;//初始的比赛顺序
	int rank;// 顺序 	
	int finRank;
};

Mice mice[maxn];
Mice tempMice;
int playOrder[maxn];

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
	int tempIndex;
	//输入各个mice的重量 
	for(i = 0;i< Np;i++){
		cin >> mice[i].weight;
		mice[i].initOrder = i;
	}
	//输出初始玩家的顺序 
	for(i = 0;i< Np;i++){
		cin >> playOrder[i];
	}					
	queue<int> que;//存放元素的下标 
	
	//将初始玩家的顺序，加入到队列中
	for(i = 0;i< Np;i++){		
		que.push(playOrder[i]);
	}
	//下面这个 -1 只是一个标记符，用于确定这一遍已经到底了 	
	que.push(-1); 
	
	int index = 1; 
	int maxWeight = -1;	//表示的是最大的重量 
	int preIndex = -1;
	int count = 1;	
	int flag = 0;
	while(que.size() > 2){//当队列只剩最后2个元素时 ，停止循环		
		index = 0; //reset to 0	
		maxWeight = -1;	//赋值&重置 
		preIndex = -1;//赋值&重置  => 初始值的设置很重要！！！ 
		while(index < Ng && !que.empty()){ //说明需要开始处理了 
			tempIndex = que.front();//取队首元素						
			if(tempIndex == -1 ) {//如果遇到标记的时候，直接入队，不再处理 
				flag = 1;
				que.pop();
				break;//直接跳出while 
			} 
			//不同的条件一定不要耦合在一起 		
			mice[tempIndex].rank = count; 
						
			if(mice[tempIndex].weight > maxWeight){//如果当前的Mice 小于 maxWeight，则需要删除当前的frontMice 								
				maxWeight = mice[tempIndex].weight;//赋weight
				preIndex = tempIndex;//赋下标 
			}						
			index++;
			que.pop();//队首移除 			
		}		
		
		//将最大的元素加入到队列中 		
		if(preIndex != -1) que.push(preIndex);
		
		if(flag == 1) {//如果遇到标记的时候，直接入队，不再处理 
			count ++;			
			que.push(-1);
			flag = 0;
		}		
	}
	
	//写出最大的排名 
	if(Np % Ng == 0 ){//虽然把tempMice放进去了，但是因为-1 这个值还没有拿出来，所以这个时候就需要获取tempMice的值而不是 que.front()的值了 		
	//	cout <<"preIndex = "<<preIndex;	
		mice[preIndex].rank = count+1; 
	}	
	else mice[que.front()].rank = count;
	
	sort(mice,mice+Np,cmp2);

	int rank = 1;//总排名 
	mice[0].finRank = 1;//排名第一 
	for(i = 1;i< Np;i++){
		if( mice[i].rank == mice[i-1].rank ) {//如果rank排名 和上一个rank相同 
			mice[i].finRank =  rank;			
		}
		else{//如果不等的话 
			rank = i+1;// 更新i的值 
			mice[i].finRank = rank;
		}
	}	
	sort(mice,mice+Np,cmp3);
	for(i = 0;i< Np;i++){		
		cout<< mice[i].finRank ;
		if(i!=(Np-1)) cout <<" ";
	}	
}
/*
11 3
25 18 0 46 37 3 19 22 57 56 10
6 0 8 7 10 5 9 1 4 2 3


11 2
25 18 0 46 37 3 19 22 57 56 10
6 0 8 7 10 5 9 1 4 2 3


10 2
25 18 0 46 37 3 19 22 57 56
6 0 8 7 5 9 1 4 2 3


5 2
25 18 0 46 37
0 1 4 2 3


2 3
23 2
0 1


3 2
45 23 2
0 1


3 3
45 23 2
0 1 2

3 5
45 23 2
0 1 2


1 1
2
0

1 3
2
0

*/
