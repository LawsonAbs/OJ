#include <stdio.h>

typedef struct {
	int address;
	char data;
	int next;
}Node;

Node n[100002];
Node n1[100002],n2[100002];
	

int main(){
	int start1,start2,number;//起始地点1，起始地点2 
	int i ;
	scanf("%d %d %d",&start1,&start2,&number);
	
	for (i = 0;i<number;i++){
		scanf("%d %c %d",&n[i].address,&n[i].data,&n[i].next);
	}	
	
	for(i = 0;i<number;i++){
		if(n[i].address == start1){
			n1[0] = n[i];	
		}
		if(n[i].address == start2){
			n2[0] = n[i];
		}		
	} 
	
	//printf("%d %d\n%d %d",n1[0].address,n1[0].next,n2[0].address,n2[0].next);
	
	int count1 = 0,count2 = 0;
	int j = 0;
	while(n1[count1].next!=-1 || n2[count2].next!=-1 ){
		for(j = 0;j<number;j++){
			if(n[j].address == n1[count1].next){
				count1++;
				n1[count1] = n[j];				
			}
			
			if(n[j].address == n2[count2].next){
				count2++;
				n2[count2] = n[j];				
			}
		}		
	}

//	for(i = 0;i<=count1;i++){
//		printf("%d %d-->",n1[i].address,n1[i].next);
//	}printf("\n"); 
//	
//	for(i = 0;i<=count2;i++){
//		printf("%d %d-->",n2[i].address,n2[i].next);
//	}printf("\n");
	
//2.从尾部开始遍历，找到第一个不相同的结点
	for(i = count1;i>=0;i--){
		for(j = count2;j>= 0;j--){
			if(n1[i].address == n2[j].address){
				i--;				
			}
			else if(n1[i].address != n2[j].address){
				//printf("%d %d\n",n1[i].address,n2[j].address); 
				if(n1[i+1].address == 0){
					printf("-1");
					return 0;
				}
				else{
					printf("%d",n1[i+1].address);//直接输出 
					return 0;					
				}
			}
		}
	} 
}


//1.从头开始遍历，会花费很多时间-->从最尾部开始遍历 
//	int flag = 1;
//	for(i = 0;i<count1;i++){
//		for(j = 0;j<count2;j++){
//			if(n1[i].address == n2[j].address){
//				flag = 0;
//				printf("%d",n1[i].address);
//				return 0;
//			}
//		}		
//	}
//	if(flag){
//		printf("-1");
//	}


/**
11111 22222 9
67890 i 00002
00010 a 12345
00003 g -1
12345 D 67890
00002 n 00003
22222 B 23456
11111 L 00001
23456 e 67890
00001 o 00010

11111 11111 9
67890 i 00002
00010 a 12345
00003 g -1
12345 D 67890
00002 n 00003
22222 B 23456
11111 L 00001
23456 e 67890
00001 o 00010

00001 00002 4
00001 a 10001
10001 s -1
00002 a 10002
10002 t -1
**/

//1.00001与1是相等的 
//	int a = 00001,b = 1;
//	if(a==b){
//		printf("e");
//	}
	
	
//2.	
//	for(i = 0;i<count1;i++){
//		printf("%d %d-->",n1[i].address,n1[i].next);
//	}printf("\n"); 
//	
//	for(i = 0;i<count2;i++){
//		printf("%d %d-->",n2[i].address,n2[i].next);
//	}printf("\n");
