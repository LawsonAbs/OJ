#include <stdio.h>
#include <string.h>

typedef struct {
  char address [10];//结点地址
  int data;// 结点数据
  char next[10];//结点下一地址   
}Node;

//采用静态链表实现 
Node node[100002];
Node nodeTemp[100002];//表示暂存k个结点  
Node nodeTemp2[100002];//存储最终的结果 

int main(){
   char startAddress[10];//起始地址
   int N;//结点总个数
   int k;//反转数 
   int i,j;
   int location = 0;
   
   scanf("%s %d %d",startAddress,&N,&k); 
   
   for(i = 0;i<N;i++){
     scanf("%s %d %s",node[i].address,&node[i].data,node[i].next);     
    }
      
   //找到开始节点的下标，放于location处 
   while( strcmp(node[location].address,startAddress) != 0){
     location++; 
   }
   
   int count  = 1;//记录值，判断是否等于K 
   
   //printf("node[startAddress] = %s %d %s\n",node[location].address,node[location].data,node[location].next);
   
   int a = 0 ,b = 0;
   nodeTemp[0] = node[location];
   //nodeTemp2[b++] = nodeTemp[0];
   
   while(a<N && strcmp(node[location].next,"-1") !=0){
     for(i = 0;i<N;i++) {
       if( strcmp(node[i].address,node[location].next) == 0){//遍历所有结点找到当前结点的下一个结点          
        location = i;//更新location的位置 
        //printf("location = %d\n",location);
        nodeTemp[count++] = node[i];//结构体整体赋值
        //printf("%s %d %s\n",nodeTemp[count-1].address,nodeTemp[count-1].data,nodeTemp[count-1].next);
        a++;//表示已经满足条件的节点数    
       }
       
       if(count == k){
         for(j =count -1;j>=0;j--){           
           nodeTemp2[b++] = nodeTemp[j];           
           //printf("%s %d %s\n",nodeTemp[j].address,nodeTemp[j].data,nodeTemp[j].next);                  
         }
         count =0;//输出完以后，归零 
       }     
     }     
  }
//  printf("b = %d",b);
  
  if(count < k){    
    for(j =(N/k) * k;j<N;j++){           
       
       nodeTemp2[b++] = node[j];//将其赋值  
      //printf("哈哈%s %d %s\n",nodeTemp2[j].address,nodeTemp2[j].data,nodeTemp2[j].next);     
     }  
  }
  
  //printf("正式输出：\n");
  for(i = 0;i<b;i++){
    if(i!=b-1){
      printf("%s %d %s\n",nodeTemp2[i].address,nodeTemp2[i].data,nodeTemp2[i+1].address);          
    }
    else{
      printf("%s %d -1\n",nodeTemp2[i].address,nodeTemp2[i].data);          
    }    
  }
}
/**
00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218


00100 6 3
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
**/ 
