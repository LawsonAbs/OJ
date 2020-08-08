#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>

using namespace std;

//获得一个 >=num 素数 
int getPrime(int num){
	int i; 
	if(num == 1)		return 2;  
	while(true){//
		for( i = 2;i <= sqrt(num);i++ ){
			if(num % i == 0){
				num++;
				break;//说明不是素数 
			}
		}
		if(i > sqrt(num)){
			break;
		}
	}
	return num;
}

int main(){
	int mSize,N;//其中Msize 是table size； N是需要插入的数字总数；M是待查找数字的总数 
	cin >> mSize >> N ;
	int i ,j;
	int tSize;
	tSize = getPrime(mSize);		
	int array[N];
	int hashTable[tSize];//得到一个tSize 大小的hash 表 
	
	memset(hashTable,0,sizeof(hashTable)); 
	//输入待插入的n个数 
	for(i = 0;i< N;i++){
		cin >> array[i];
	}
		
	//insert into table
	int index;//将元素放入hashTable 的下标 
	int res[N] ;
	int count = 0;
	for(i = 0;i< N;i++){		
		for(j = 0;j < tSize ;j++){
			index = (array[i] + (j * j)) % tSize ;
			if(hashTable[index] == 0){
				hashTable[index] = array[i];//赋值操作 				
				res[count++] = index;
				break;
			}
		}
		if(j == tSize){	
			res[count++] = -1;					
		}	
	}
	
	for(i = 0;i< count;i++){
		if(i != count-1){
			if(res[i] == -1){
				cout <<"- ";	
			}
			else{
				cout << res[i]<<" ";
			}			
		} 	
		else {
			if(res[i] == -1){
				cout <<"-";	
			}
			else{
				cout << res[i];
			}
		}
	} 
}
/*
4 4
10 6 4 15

4 4
10 6 4 11

1 2
1 3
*/
