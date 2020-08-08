#include<cstdio> 
#include<algorithm>
#include<functional>
#include<math.h>
using namespace std;

int main(){
	int N;
	scanf("%d",&N);
	double ropeLen [N];
	for(int i = 0;i< N;i++){
		scanf("%lf",&ropeLen[i]);//input the length of rope				 
	}
	
	sort(ropeLen,ropeLen+N,less<double>());
	
	//printf("============after sort ========\n");
//	for(int i = 0;i< N;i++){
//		printf("%.2f ",ropeLen[i]);//input the length of rope				 
//	}printf("\n");
		
	double res = ropeLen[0]; 
	//如果说明有两根以上的绳子 
	if(N > 1){
		res = ropeLen[0]/2 + ropeLen[1]/2;
		for(int i = 2;i < N;i++){		
			res = res/2 + ropeLen[i]/2 ;
			//printf("i = %d , %2.f \n",i,res);
		}		
		//printf("%.2f\n",res);
		res = floor(res );
		//printf("cell(res) = %.0f",res);
		printf("%.0f",res);
	}
	else{//如果只有一根绳子 
		printf("%.0f",res);	
	} 	
}
/*
8
10 15 12 3 4 13 1 15

1 3 4 10 12 13 15 15 

*/
