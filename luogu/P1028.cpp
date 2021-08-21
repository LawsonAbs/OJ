#include<iostream>
using namespace std;

int res = 0;
const int maxN = 1005;

//使用记忆化搜索，否则会TLE
int record[maxN];  //记录每个数字可以拆分的个数
 
//返回数字num可以得到的个数 
void get_num(int num){
	if (num == 1) //边界条件 
		return ; // 最后这一种 
	if (record[num]!= -1){
		res += record[num]; 
		return ; //直接加完返回 
	}
	int start = res;
	for (int i = 1;i<= num/2;i++){ //递归循环 				
		res ++;
		get_num(i);
	}
	record[num] = res- start;//记录这个数可以的次数 
}

int main(){
	int n;
	cin >> n;
	fill(record,record+maxN,-1); 
	get_num(n);
	cout << res + 1 <<"\n";
//	for (int i = 1;i<=6;i++){
//		cout << record[i] << " ";
//	}
} 
