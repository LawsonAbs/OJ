#include<cstdio>
#include<set> 
#include<algorithm>
#include<iostream>
#define maxn 105
using namespace std;

struct result{
	int a;
	int b;
};

int N;
set<int> a;
int index = 0;
result res[maxn];

//�ж�����array�Ƿ���һ����׼�Ľ�� 
bool judge(){	
	//�ж��Ƿ���ǰ��ì�ܵĴ� 
	for(set<int>::iterator it1=a.begin();it1!=a.end();it1++){
		for(set<int>::iterator it2=a.begin();it2!=a.end();it2++){ 
			if((*it1) == (-1) * (*it2)) return false;
		}
	}
	
	int count = 0; 
	for(set<int>::iterator it = a.begin();it!=a.end();it++){
		if(*it < 0) count++;
	} 
	if(count != 2) return false;//˵������������		
	return true;	 
}


void printRes(){
	int count = 2;
	int res1 , res2;//�������˵Ľ��	
	for(set<int>::iterator it2 = a.begin();it2!=a.end();it2++){		
		if( (*it2) < 0 && count > 1 ) {
			res[index].b = *it2 * (-1);	 
			res1 = *it2 *(-1);
			count --;			
		}
		else if((*it2) < 0 ){
			res[index].a = *it2 * (-1) ;
			res2 = *it2 * (-1);	
			count --;
			break;//������ȫ��		
		}		 
	}
	index++;
	//cout<<res2 << " "<< res1 << endl;
}

bool cmp(result r1,result r2){
	if(r1.a == r2.a) return r1.b < r2.b;
	return r1.a < r2.a;	
}

int main(){	
	int i,j,k;
	int info[maxn];
	cin >> N;
	for(i = 1;i<= N;i++){
		cin >> info[i];
	}
	
	//�������ѵ���i�� j ������ 		
	for(i = 1;i <= N ;i++){
		for(j = i+1;j <= N;j++){
			//cout <<"i = "<<i<<",j = "<< j<<"\n";						
			a.clear();//�Ȱ����е�Ԫ��ɾ�� 
			//����ǰ��Ԫ����ӵ�set �� 
			for(k =1 ;k<=N;k++){
				if(k == i || k==j) {//�����෴��Ԫ�� 
					a.insert( ((-1)*info[k]) );	
				}
				else {//���� ���� info[k] 
					a.insert(info[k]);	
				}
			}
			
			//���i������ 
			a.insert(-i);
			
//			//cout<< i<<" ������ "<<endl; 
//			for(set<int>::iterator it=a.begin();it!=a.end();it++){
//				cout << *it << " ";
//			}cout<<endl;
								
			if(judge())  printRes();
								
			//���j������ 
			a.erase(-i);//�Ƚ������ -i ɾ����Ȼ����� -j �ڵ�				 
			a.insert(-j);
			
		//	cout<< j<<" ������ "<<endl; 
//			for(set<int>::iterator it=a.begin();it!=a.end();it++){
//				cout << *it << " ";
//			}cout<<endl;
			
			if(judge())	printRes();			
		}			
	}	
	
	if(index == 0){
		cout << "No Solution"<<"\n";
	}else{
		sort(res,res+index,cmp);
		cout << res[0].a<<" "<<res[0].b;	
	}	
}
/*
6
+6
+3
+1
-5
-2
+4


6
+6
+3
+1
+5
+2
+4


5
-2
+3
-4
+5
+4


5
-2
+2
-4
+5
+4
*/
