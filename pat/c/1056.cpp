#include<cstdio>
#include<algorithm>
#include<map>
#include<queue> 
#include<iostream>
#define maxn 10005

using namespace std;

struct Mice{
	int weight;//��ʵ���������û��˵����Ƿ�������
	int initOrder;//��ʼ�ı���˳��
	int rank;// ˳�� 
	int playOrder;
	int finRank;
};

Mice mice[maxn];
Mice tempMice;

//�������˳��������� 
int cmp1(Mice m1,Mice m2){
	return m1.playOrder < m2.playOrder;
}

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
	//�������mice������ 
	for(i = 0;i< Np;i++){
		cin >> mice[i].weight;
		mice[i].initOrder = i;
	}
	//�����ʼ˳�� 
	for(i = 0;i< Np;i++){
		cin >> mice[i].playOrder;
	}
	
	sort(mice,mice+Np,cmp1);			
	queue<Mice> que;//���
	
	for(i = 0;i< Np;i++){
		tempMice.playOrder = mice[i].playOrder;
		tempMice.weight = mice[i].weight;//�����һԪ�� 
		que.push(tempMice);//���뵽������			
	}
	//�������tempMiceֻ��һ����Ƿ�������ȷ����һ���Ѿ������� 
	tempMice.playOrder = -1;
	tempMice.weight = -1;
	que.push(tempMice); 
	
	int index = 1; 
	int maxWeight = -1;	//��ʾ������������ 
	int preIndex = -1;
	int count = 1;	
	int flag = 0;
	while(que.size() != 2){//������ֻʣ���2��Ԫ��ʱ 		
		index = 0; //reset to 0	
		maxWeight = -1;	//��ֵ&���� 
		while(index < Ng && !que.empty()){ //˵����Ҫ��ʼ������ 
			tempMice = que.front();//ȡ����Ԫ��			
			cout <<"first = "<< tempMice.playOrder <<", second = "<<tempMice.weight<<"\n";
			if(tempMice.playOrder == -1 || tempMice.weight == -1) {//���������ǵ�ʱ��ֱ����ӣ����ٴ��� 
				flag = 1;
				que.pop();
				break;//ֱ������while 
			} 
			//��ͬ������һ����Ҫ�����һ�� 		
			mice[tempMice.playOrder].rank = count; 
			
			
			if(tempMice.weight > maxWeight){//�����ǰ��Mice С�� maxWeight������Ҫɾ����ǰ��frontMice 								
				maxWeight = tempMice.weight;//��weight
				preIndex = tempMice.playOrder;//���±� 
			}						
			index++;
			que.pop();//�����Ƴ� 			
		}		
		
		//������Ԫ�ؼ��뵽������ 
		tempMice.playOrder = preIndex;
		tempMice.weight = maxWeight;
		que.push(tempMice);
		
		if(flag == 1) {//���������ǵ�ʱ��ֱ����ӣ����ٴ��� 
			count ++;
			tempMice.playOrder = -1;
			tempMice.weight = -1;
			que.push(tempMice);	
			flag = 0;
		}		
	}
	
	//д���������� 
	mice[que.front().playOrder].rank = count; 
	
	for(i = 0;i< Np;i++){
		cout<< mice[i].weight<<", "<<mice[i].rank <<"\n";		
	}
	cout <<"===="<<"\n" ;
	
	sort(mice,mice+Np,cmp2);
	for(i = 0;i< Np;i++){
		cout<< mice[i].weight<<", "<<mice[i].rank <<"\n";		
	}

	int rank = 1;//������ 
	mice[0].finRank = 1;//������һ 
	for(i = 1;i< Np;i++){
		if( mice[i].rank == mice[i-1].rank ) {//���rank���� ����һ��rank��ͬ 
			mice[i].finRank =  rank;
			cout<< mice[i].weight <<":"<<mice[i].rank<<"\n";
		}
		else{//������ȵĻ� 
			rank = i+1;// ����i��ֵ 
			mice[i].finRank = rank;
		}		
	}
	
	sort(mice,mice+Np,cmp3);
	for(i = 0;i< Np;i++){
		cout << mice[i].weight<<", "<<mice[i].finRank<<"\n";
		//cout<< mice[i].finRank ;
		if(i!=(Np-1)) cout <<" ";
	}	
}
/*
11 3
25 18 0 46 37 3 19 22 57 56 10
6 0 8 7 10 5 9 1 4 2 3

*/
