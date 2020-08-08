#include<cstdio>
#include<algorithm>
#include<map>
#include<queue> 
#include<iostream>
#define maxn 1005

using namespace std;

struct Mice{
	int weight;//��ʵ���������û��˵����Ƿ�������
	int initOrder;//��ʼ�ı���˳��
	int rank;// ˳�� 	
	int finRank;
};

Mice mice[maxn];
Mice tempMice;
int playOrder[maxn];

//�������������������� 
int cmp2(Mice m1,Mice m2){
	return m1.rank > m2.rank;
}

//���ճ�ʼ˳��������� 
int cmp3(Mice m1,Mice m2){
	return m1.initOrder < m2.initOrder;
}

int main(){
	int Np,Ng;
	cin >> Np >> Ng;
	int i,j;
	int tempIndex;
	//�������mice������ 
	for(i = 0;i< Np;i++){
		cin >> mice[i].weight;
		mice[i].initOrder = i;
	}
	//�����ʼ��ҵ�˳�� 
	for(i = 0;i< Np;i++){
		cin >> playOrder[i];
	}					
	queue<int> que;//���Ԫ�ص��±� 
	
	//����ʼ��ҵ�˳�򣬼��뵽������
	for(i = 0;i< Np;i++){		
		que.push(playOrder[i]);
	}
	//������� -1 ֻ��һ����Ƿ�������ȷ����һ���Ѿ������� 	
	que.push(-1); 
	
	int index = 1; 
	int maxWeight = -1;	//��ʾ������������ 
	int preIndex = -1;
	int count = 1;	
	int flag = 0;
	while(que.size() > 2){//������ֻʣ���2��Ԫ��ʱ ��ֹͣѭ��		
		index = 0; //reset to 0	
		maxWeight = -1;	//��ֵ&���� 
		preIndex = -1;//��ֵ&����  => ��ʼֵ�����ú���Ҫ������ 
		while(index < Ng && !que.empty()){ //˵����Ҫ��ʼ������ 
			tempIndex = que.front();//ȡ����Ԫ��						
			if(tempIndex == -1 ) {//���������ǵ�ʱ��ֱ����ӣ����ٴ��� 
				flag = 1;
				que.pop();
				break;//ֱ������while 
			} 
			//��ͬ������һ����Ҫ�����һ�� 		
			mice[tempIndex].rank = count; 
						
			if(mice[tempIndex].weight > maxWeight){//�����ǰ��Mice С�� maxWeight������Ҫɾ����ǰ��frontMice 								
				maxWeight = mice[tempIndex].weight;//��weight
				preIndex = tempIndex;//���±� 
			}						
			index++;
			que.pop();//�����Ƴ� 			
		}		
		
		//������Ԫ�ؼ��뵽������ 		
		if(preIndex != -1) que.push(preIndex);
		
		if(flag == 1) {//���������ǵ�ʱ��ֱ����ӣ����ٴ��� 
			count ++;			
			que.push(-1);
			flag = 0;
		}		
	}
	
	//д���������� 
	if(Np % Ng == 0 ){//��Ȼ��tempMice�Ž�ȥ�ˣ�������Ϊ-1 ���ֵ��û���ó������������ʱ�����Ҫ��ȡtempMice��ֵ������ que.front()��ֵ�� 		
	//	cout <<"preIndex = "<<preIndex;	
		mice[preIndex].rank = count+1; 
	}	
	else mice[que.front()].rank = count;
	
	sort(mice,mice+Np,cmp2);

	int rank = 1;//������ 
	mice[0].finRank = 1;//������һ 
	for(i = 1;i< Np;i++){
		if( mice[i].rank == mice[i-1].rank ) {//���rank���� ����һ��rank��ͬ 
			mice[i].finRank =  rank;			
		}
		else{//������ȵĻ� 
			rank = i+1;// ����i��ֵ 
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
