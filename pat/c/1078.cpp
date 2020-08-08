#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>

using namespace std;

//���һ�� >=num ���� 
int getPrime(int num){
	int i; 
	if(num == 1)		return 2;  
	while(true){//
		for( i = 2;i <= sqrt(num);i++ ){
			if(num % i == 0){
				num++;
				break;//˵���������� 
			}
		}
		if(i > sqrt(num)){
			break;
		}
	}
	return num;
}

int main(){
	int mSize,N;//����Msize ��table size�� N����Ҫ���������������M�Ǵ��������ֵ����� 
	cin >> mSize >> N ;
	int i ,j;
	int tSize;
	tSize = getPrime(mSize);		
	int array[N];
	int hashTable[tSize];//�õ�һ��tSize ��С��hash �� 
	
	memset(hashTable,0,sizeof(hashTable)); 
	//����������n���� 
	for(i = 0;i< N;i++){
		cin >> array[i];
	}
		
	//insert into table
	int index;//��Ԫ�ط���hashTable ���±� 
	int res[N] ;
	int count = 0;
	for(i = 0;i< N;i++){		
		for(j = 0;j < tSize ;j++){
			index = (array[i] + (j * j)) % tSize ;
			if(hashTable[index] == 0){
				hashTable[index] = array[i];//��ֵ���� 				
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
