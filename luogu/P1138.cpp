#include<iostream>
using namespace std;

const int maxN = 10005;
int arr[maxN];
//使用快排 
int partition(int left,int right){
	int pivot_key = arr[left];//临时存储pivot_key
	while(left < right){
		while(left < right && arr[right] >= pivot_key){
			right--;
		}
		arr[left] = arr[right];
		while(left < right && arr[left] <= pivot_key){
			left++;
		}
		arr[right] = arr[left];
	} 
	arr[left] = pivot_key; 
	return left;//最后要返回的分界点 
}

void quick_sort(int left,int right){	
	if(left >= right){
		return;
	}
	int mid = partition(left,right);
	quick_sort(left,mid-1);
	quick_sort(mid+1,right);
}

int main(){
	int n , k;
	cin >> n >> k;
	for (int i = 0;i< n;i++)
		cin >> arr[i];
	
	quick_sort(0,n-1);		
	
	//找出第k小的数 
	int pre = arr[0]; 
	int cnt = 1;
	if (k == 1){
		cout << pre;
		return 0;
	}
	int i ;
	for (i = 1;i < n;i++){
		//cout << arr[i]<<" ";
		if (arr[i] != pre){
			pre = arr[i];
			cnt ++;
			if (cnt == k){
				cout << arr[i]<<"\n";
				return 0;
			}
		}
	}
	if (i==n){
		cout << "NO RESULT";
	}
}
/*
9 3
3 3 7 2 5 1 2 4 6
*/
