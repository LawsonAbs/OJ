#include<cstdio>
#include<set>
#include<iostream>
#include<cstring>

using namespace std;

struct node{
	int cnt;
	int value;
	
	bool operator<(const node &n)const{
		if(n.cnt == cnt) return n.value > value;
		return n.cnt < cnt; 
	}
};

int rate[50005];

int main(){
	int num,limit;	 
	scanf("%d %d",&num,&limit);
	set<node> s;//用于存放浏览记录的 set 
	int i,j;
	int accItem;
	int k;
	node n;//定义一个临时的node 变量 	 
	memset(rate,0,sizeof(rate));//初始化rate数组
	 
	for(i = 0;i< num;i++){//这里的i只是用作控制输入，不作下标用 
		scanf("%d",&accItem);
		
		//遍历这个it，然后得到其中的值 		
		int size = s.size(); 
		k = min(limit,size);//求出输出的项数 		
		if(i > 0){
			//cout << "k = "<<k<<endl;
			cout<<accItem<<": ";	
			set<node>::iterator it;
			for(it = s.begin(),j = 0;it !=s.end() && j<k; it++,j++){			
				if(j!=k-1)	cout << it->value<<" ";//输出值 
				else cout<< it->value<<endl;
			}	
		}
				
		n.value = accItem;		
		n.cnt = rate[accItem];
		rate[accItem]++;//现在访问过这个商品了，需要将其访问次数加一
		
		
		//但是现在的问题是，如果使用find()函数，那么这个set查找的是什么元素呢？（是value还是cnt呢?）
		//答案是：既非cnt，也不是value。而是一个node 变量。
		//所以现在需要定义 一个临时 的node变量 n。然后判断 n  是否 
		 
		if(s.find(n) != s.end()){//说明该商品已经浏览过 
			s.erase(n);//删除这个商品 
			//cout<<"找到了这个商品"<<endl;
			//然后再将这个商品添加到set中 					
		}
		n.cnt = rate[accItem];
		s.insert(n);				
	}
}
/*
12 10
3 5 7 5 5 3 2 1 8 3 8 12
*/
