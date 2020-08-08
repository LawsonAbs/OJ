#include<cstdio>
#include<algorithm>
#include<iostream>

using namespace std;
struct item{
	int index = -1;//表示当前的这个商品的索引 
	int accNum = 0 ;//每种商品的访问量
};

int cmp(item i1,item i2){
	if(i1.accNum == i2.accNum) return i1.index < i2.index ;
	return i1.accNum > i2.accNum;
}

int cmp_index(item i1,item i2){
	return i1.index < i2.index ;	
}

int main(){
	int num,limit;	 
	scanf("%d %d",&num,&limit);
	item it[num];
	int i,j;
	int accItem;
	int k;
	
	//使用二分法寻找合适的数字 
	int high ,low ,mid ;
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
		
		//将如下的代码修改成使用2分法 
		//但是存在的问题是：如果使用二分法，那么前提得是：it[i].index 呈一个有序的状态，
		//如果这个非有序序列，那么就无法使用二分法 
		sort(it,it+i,cmp_index);
		high = i-1;
		low = 0;		
		while(low <= high){
			mid = (high + low)/2; //求出mid的值
			//printf("mid = %d\n",mid);
			if(it[mid].index < accItem){
				low = mid + 1; 				
			}
			else if(it[mid].index > accItem){
				high = mid - 1;	
			}
			else break;
		}
		
		if(it[mid].index == accItem){//如果当前输入的值已经存在了			
				it[mid].accNum++;			
		}
		else{
			it[i].accNum++;
			it[i].index = accItem;//表示这个结构体中访问的就是accItem这一项							
		}		
	}	
}
/*
12 3
3 5 7 5 5 3 2 1 8 3 8 12

*/
