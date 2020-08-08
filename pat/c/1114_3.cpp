#include<cstdio>
#include<iostream>
#include<climits>
#include<algorithm>
#include<set>
#define maxn 10005

using namespace std;

struct family{
	int id;
	int father;
	int mother;
	int childNum;
	int child[10];
	double estateNum = 0;//estate num
	int area = 0;	
};

//���ÿ���ڵ����Ϣ 
struct Node{
	int id;
	int sun;
	int isVisit = 1;//��ʾ�ѷ��� 
	int familyNum = 0;//��ʾ������������ 
	double estateNum = 0;
	int area = 0;	
	double avgEstate;
	double avgArea;
}; 

family fam[maxn];
Node node[10000];//���ڱ��ÿ���ڵ��sun�ڵ� 
set<int> peo;

//Ѱ�Ҹ��ڵ� 
int findSun(int a){
	//����ڵ�a�� sun�����Լ�������һֱѰ�� 
	while(node[a].sun != a){
		a = node[a].sun; 
	}
	return a;	 
} 

//�ϲ������ڵ�
void unionSun(int a,int b){
	int sunA = findSun(a);
	int sunB = findSun(b);
	node[max(sunA,sunB)].sun = min(sunA,sunB);
}

int cmp(Node n1,Node n2){
	if ( n1.avgArea == n2.avgArea )  return n1.id < n2.id;
	return n1.avgArea > n2.avgArea;
} 

int main(){
	int N;
	cin >> N;
	int i, j;
	int childNum;	
	
	//��ʼ�������� 
	for(i = 1;i<10000;i++){
		node[i].sun = i;
		node[i].id = i;		
	}
	
	int minValue ; 
	for(i = 0;i< N;i++){
		minValue = INT_MAX;
		cin >> fam[i].id >> fam[i].father >> fam[i].mother >> childNum ;
		minValue = min(minValue,fam[i].id);
		node[fam[i].id].isVisit  = 0;
		peo.insert(fam[i].id);
		if(fam[i].father!=-1) {
			minValue = min(minValue,fam[i].father);
			node[fam[i].father].isVisit  = 0;		
			peo.insert(fam[i].father);
		}
		if(fam[i].mother!=-1){
			minValue = min(minValue,fam[i].mother);
			node[fam[i].mother].isVisit  = 0;	
			peo.insert(fam[i].mother);
		}
		
		for(j = 0;j< childNum;j++){
			cin >> fam[i].child[j];
			minValue = min(minValue,fam[i].child[j]);
			node[fam[i].child[j]].isVisit  = 0;	
			peo.insert(fam[i].child[j]);
		}
		cin >> fam[i].estateNum >> fam[i].area;			
		
		//�ϲ����� 
		unionSun(fam[i].id,minValue);	
		
		//�ϲ���ĸ 
		if(fam[i].father!=-1)  unionSun(fam[i].father,minValue);
		if(fam[i].mother!=-1)  unionSun(fam[i].mother,minValue);
		
		//�ϲ����� 
		for(j = 0;j< childNum;j++){
			unionSun(fam[i].child[j], minValue);
		}		
	}

	cout <<"\nThe information of every nodes' sun:"<< "\n";
	for(i = 1;i< 10000;i++){
		if( findSun(i) != i && node[i].isVisit == 0){
			cout << "i = "<<i<< ",node[i] = "<< node[i].sun<<"\n";
		}
	}
	
	//�ҳ��м�����ͥ
	int familyCount = 0; 
	int res[maxn];// �洢�������յ���Ա�������Ϣ 
	int tempSun; 
	
	//�ҳ���ͬ��family�����Լ�ÿ��family������ 
	//ʹ������forѭ�� �ҳ����е�id 
	for(set<int>:: iterator it =peo.begin();it != peo.end();it++){
		tempSun = findSun(*it);//�ҳ�*it����ڵ��sun 						
		node[tempSun].familyNum ++;
		if( node[tempSun].isVisit != 1 ){//��ʾδ���ʹ� 			
			node[tempSun].isVisit = 1; 
			res[familyCount] =  tempSun;//�洢���������Ϣ 								
			familyCount ++;
		}
	}
		
	//����Ʋ�  //�����е����ݶ��ۼӵ����ڵ��� 
	for(i = 0;i< N;i++){
		tempSun = findSun(fam[i].id); 	
		cout <<"i = "<< fam[i].id << ",tempSun = "<< tempSun ;
		cout <<",fam[i].estateNum = " << fam[i].estateNum <<", fam[i].area = "<<fam[i].estateNum<< "\n"; 			
		
		node[tempSun].estateNum += fam[i].estateNum; //���㷿����
		node[tempSun].area += fam[i].area;//�������		
	}	
	cout << "familyCount = "<<familyCount<<"\n";			
	
	cout << "\n���������Ϣ===="<<"\n"; 	
	//sort(node,node+10000,cmp);
	for(i = 0;i < familyCount;i++){
		tempSun = res[i];
		node[tempSun].avgEstate = node[tempSun].estateNum / node[tempSun].familyNum;
		node[tempSun].avgArea = node[tempSun].area / node[tempSun].familyNum;		
		printf("%04d %d %.3f %.3f\n",tempSun,node[tempSun].familyNum,node[tempSun].avgEstate,node[tempSun].avgArea);
	}	
}

/*
10
6666 5551 5552 1 7777 1 100
1234 5678 9012 1 0002 2 300
8888 -1 -1 0 1 1000
2468 0001 0004 1 2222 1 500
7777 6666 -1 0 2 300
3721 -1 -1 1 2333 2 150
9012 -1 -1 3 1236 1235 1234 1 100
1235 5678 9012 0 1 50
2222 1236 2468 2 6661 6662 1 300
2333 -1 3721 3 6661 6662 6663 1 100


1
6666 5551 5552 1 7777 1 100

*/
