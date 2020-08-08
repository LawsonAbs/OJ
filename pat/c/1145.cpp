#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>

using namespace std;

//���һ�� >=num ���� 
int getPrime(int num){
	int i; 
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
	int mSize,N,M;//����Msize ��table size�� N����Ҫ���������������M�Ǵ��������ֵ����� 
	cin >> mSize >> N >> M;
	int i ,j;
	int tSize;
	tSize = getPrime(mSize);
	//cout << "tSize = "<< tSize << "\n";	
	int array[N];
	int hashTable[tSize];//�õ�һ��tSize ��С��hash �� 
	
	memset(hashTable,0,sizeof(hashTable)); 
	//����������n���� 
	for(i = 0;i< N;i++){
		cin >> array[i];
	}
			
	int query[M];
	for(i = 0;i< M ;i++){
		cin >> query[i];
	}
		
	//insert into table
	int index;//��Ԫ�ط���hashTable ���±� 
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
	
	
	//��ѯm����
	double count = 0;//���Ҵ��� 	
	for(i = 0;i< M;i++){		 
		for(j = 0;j < tSize ;j++){
			count ++;//���Ҵ��� 
			index = (query[i] + (j * j)) % tSize ;		
			if(hashTable[index] == query[i] ){//˵���ҵ��� 		
				break;
			}
			if( hashTable[index] == 0 ){//˵��query[i]���Ԫ�ز����� 
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
