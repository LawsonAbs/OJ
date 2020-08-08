#include<cstdio>
#include<algorithm>
#include<iostream>

using namespace std;
struct item{
	int index = -1;//表示当前的这个商品的索引 
	int accNum = 0 ;//每种商品的访问量
	int order ;//访问的顺序 
	int isVisit =0;//表示是否访问过 
};

int cmp(item i1,item i2){
	if(i1.accNum == i2.accNum) return i1.index < i2.index ;
	return i1.accNum > i2.accNum;
}

int main(){
	int num,limit;	 
	scanf("%d %d",&num,&limit);
	item it[num];
	int i,j;
	int accItem;
	int k;
	for(i = 0;i< num;i++){//这里的i只是用作控制输入，不作下标用 
		scanf("%d",&accItem);				
		if(i != 0){
			k = min(limit,i);
			sort(it,it+i,cmp);
			printf("%d: ",accItem);
			for(j = 0;j< k;j++){
				if(j != k - 1) 	{									
					printf("%d ",it[j].index);
				}
				else{
					printf("%d",it[j].index);
				}
 			}printf("\n");			
		}
		
		for(j = 0;j< i;j++){
			if(it[j].index == accItem){				
				it[j].accNum++;
				it[j].order = i;//重置order的值 
				//cout << "index = " << it[j].index << ",accNum = "<<it[j].accNum << endl; 
				break;
			}
		}
		if(j == i){
			it[i].accNum++;
			it[i].index = accItem;//表示这个结构体中访问的就是accItem这一项
			it[i].order = i;				
		}		
	}	
}
/*
12 3
3 5 7 5 5 3 2 1 8 3 8 12

*/
