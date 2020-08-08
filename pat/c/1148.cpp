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

//判断数组array是否是一个标准的结果 
bool judge(){	
	//判断是否有前后矛盾的答案 
	for(set<int>::iterator it1=a.begin();it1!=a.end();it1++){
		for(set<int>::iterator it2=a.begin();it2!=a.end();it2++){ 
			if((*it1) == (-1) * (*it2)) return false;
		}
	}
	
	int count = 0; 
	for(set<int>::iterator it = a.begin();it!=a.end();it++){
		if(*it < 0) count++;
	} 
	if(count != 2) return false;//说明狼人数错误		
	return true;	 
}


void printRes(){
	int count = 2;
	int res1 , res2;//保存狼人的结果	
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
			break;//处理完全了		
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
	
	//假设撒谎的是i和 j 两个人 		
	for(i = 1;i <= N ;i++){
		for(j = i+1;j <= N;j++){
			//cout <<"i = "<<i<<",j = "<< j<<"\n";						
			a.clear();//先把所有的元素删除 
			//将当前的元素添加到set 中 
			for(k =1 ;k<=N;k++){
				if(k == i || k==j) {//插入相反的元素 
					a.insert( ((-1)*info[k]) );	
				}
				else {//否则 插入 info[k] 
					a.insert(info[k]);	
				}
			}
			
			//如果i是狼人 
			a.insert(-i);
			
//			//cout<< i<<" 是狼人 "<<endl; 
//			for(set<int>::iterator it=a.begin();it!=a.end();it++){
//				cout << *it << " ";
//			}cout<<endl;
								
			if(judge())  printRes();
								
			//如果j是狼人 
			a.erase(-i);//先将上面的 -i 删除，然后添加 -j 节点				 
			a.insert(-j);
			
		//	cout<< j<<" 是狼人 "<<endl; 
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
