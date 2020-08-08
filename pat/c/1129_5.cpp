#include<cstdio>
#include<set>
#include<iostream>
#include<cstring>

using namespace std;

struct node{
	int cnt;
	int value;
	
	bool operator<(const node &n)const{
		if(n.cnt == cnt) return n.value > value;
		return n.cnt < cnt; 
	}
};

int rate[50005];

int main(){
	int num,limit;	 
	scanf("%d %d",&num,&limit);
	set<node> s;//���ڴ�������¼�� set 
	int i,j;
	int accItem;
	int k;
	node n;//����һ����ʱ��node ���� 	 
	memset(rate,0,sizeof(rate));//��ʼ��rate����
	 
	for(i = 0;i< num;i++){//�����iֻ�������������룬�����±��� 
		scanf("%d",&accItem);
		
		//�������it��Ȼ��õ����е�ֵ 		
		int size = s.size(); 
		k = min(limit,size);//������������ 		
		if(i > 0){
			//cout << "k = "<<k<<endl;
			cout<<accItem<<": ";	
			set<node>::iterator it;
			for(it = s.begin(),j = 0;it !=s.end() && j<k; it++,j++){			
				if(j!=k-1)	cout << it->value<<" ";//���ֵ 
				else cout<< it->value<<endl;
			}	
		}
				
		n.value = accItem;		
		n.cnt = rate[accItem];
		rate[accItem]++;//���ڷ��ʹ������Ʒ�ˣ���Ҫ������ʴ�����һ
		
		
		//�������ڵ������ǣ����ʹ��find()��������ô���set���ҵ���ʲôԪ���أ�����value����cnt��?��
		//���ǣ��ȷ�cnt��Ҳ����value������һ��node ������
		//����������Ҫ���� һ����ʱ ��node���� n��Ȼ���ж� n  �Ƿ� 
		 
		if(s.find(n) != s.end()){//˵������Ʒ�Ѿ������ 
			s.erase(n);//ɾ�������Ʒ 
			//cout<<"�ҵ��������Ʒ"<<endl;
			//Ȼ���ٽ������Ʒ��ӵ�set�� 					
		}
		n.cnt = rate[accItem];
		s.insert(n);				
	}
}
/*
12 10
3 5 7 5 5 3 2 1 8 3 8 12
*/
