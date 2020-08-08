#include<cstdio>
#include<map>
#include<set>
#include<iterator>
using namespace std;

int main(){
	int N,M;// number of couples; the number of party guests
	scanf("%d",&N);
	int i,j;
	map<int,int> couple;
	int a,b;
	for(i = 0;i< N;i++){
		scanf("%d %d",&a,&b);
		if(a > b)	couple[b] = a;		
		else couple[a] = b;		
	}
	scanf("%d",&M);
	int id;
	set<int> queryName;
	for(i = 0;i< M;i++){
		scanf("%d",&id);
		queryName.insert(id);//set �е�Ԫ�����ź���� 
	}
	
	set<int> result = queryName;	
	int key; 
	int value;
	for(set<int> :: iterator it = queryName.begin(); it!=queryName.end(); it++){
		key = *it; 				
		if(couple.find(key) != couple.end()){//˵���ҵ� key
			value = couple[key];
			if(queryName.find(value) != queryName.end()){//˵�������ҵ� value 
				//printf("%d %d",key,value);
				result.erase(key);
				result.erase(value);				
			}
		}
	}//printf("\n\n");
		
	int count = result.size();
	if(count > 0){
		printf("%d\n",result.size());
		set<int> ::iterator temp; 
		for(set<int> :: iterator it = result.begin(); it != result.end() ; it++){		
			if(count==1) printf("%05d",*it);
			else printf("%05d ",*it);
			count --;
		}		
	}
	else
	printf("0");
}
/*
3
11111 22222
33333 44444
55555 66666
6
11111 22222 33333 44444 55555 66666


3
11111 22222
33333 44444
55555 66666
5
01111 54321 77777 55555 66666
*/

