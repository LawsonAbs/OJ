#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>

using namespace std;

//获得一个 >=num 素数 
int getPrime(int num){
	int i; 
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
	int mSize,N,M;//其中Msize 是table size； N是需要插入的数字总数；M是待查找数字的总数 
	cin >> mSize >> N >> M;
	int i ,j;
	int tSize;
	tSize = getPrime(mSize);
	//cout << "tSize = "<< tSize << "\n";	
	int array[N];
	int hashTable[tSize];//得到一个tSize 大小的hash 表 
	
	memset(hashTable,0,sizeof(hashTable)); 
	//输入待插入的n个数 
	for(i = 0;i< N;i++){
		cin >> array[i];
	}
			
	int query[M];
	for(i = 0;i< M ;i++){
		cin >> query[i];
	}
		
	//insert into table
	int index;//将元素放入hashTable 的下标 
	int flag = 0; 
	for(i = 0;i< N;i++){		
		for(j = 0;j < tSize ;j++){
			index = (array[i] + (j * j)) % tSize ;
			if(hashTable[index] == 0){
				hashTable[index] = array[i];
				break;
			}
		}
		if(j == tSize){
			flag = 1;
			cout << array[i]<<" ";
		}	
	}
	if(flag == 1)
		cout<<"cannot be inserted."<<"\n";
	
	
	//查询m个数
	double count = 0;//查找次数 	
	for(i = 0;i< M;i++){		 
		for(j = 0;j < tSize ;j++){
			count ++;//查找次数 
			index = (query[i] + (j * j)) % tSize ;		
			if(hashTable[index] == query[i] ){//说明找到了 		
				break;
			}
			if( hashTable[index] == 0 ){//说明query[i]这个元素不存在 
				break; 
			}
		}
		if(j == tSize){
			count++;
		}
		//cout <<"query[i] = "<<query[i]<<",count = "<<count<<"\n";
	} 
	
	//cout << "count = "<< count<<endl;
	double aveNum = count / M;
//	aveNum = round(aveNum);
	printf("%.1f\n",aveNum);
	//cout << aveNum;
}
/*
4 5 4
10 6 4 15 11
11 4 15 2

5 5 2
10 6 4 15 11
15 2

5 5 2
10 6 4 15 11
15 6


4 5 4
10 6 4 13 11
11 4 15 2
*/
