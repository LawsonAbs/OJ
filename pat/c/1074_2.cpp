#include <stdio.h>
#include <string.h>

typedef struct {
  char address [10];//����ַ
  int data;// �������
  char next[10];//�����һ��ַ   
}Node;

//���þ�̬����ʵ�� 
Node node[100002];
Node nodeTemp[100002];//��ʾ�ݴ�k�����  
Node nodeTemp2[100002];//�洢���յĽ�� 

int main(){
   char startAddress[10];//��ʼ��ַ
   int N;//����ܸ���
   int k;//��ת�� 
   int i,j;
   int location = 0;
   
   scanf("%s %d %d",startAddress,&N,&k); 
   
   for(i = 0;i<N;i++){
     scanf("%s %d %s",node[i].address,&node[i].data,node[i].next);     
    }
      
   //�ҵ���ʼ�ڵ���±꣬����location�� 
   while( strcmp(node[location].address,startAddress) != 0){
     location++; 
   }
   
   int count  = 1;//��¼ֵ���ж��Ƿ����K 
   
   //printf("node[startAddress] = %s %d %s\n",node[location].address,node[location].data,node[location].next);
   
   int a = 0 ,b = 0;
   nodeTemp[0] = node[location];
   //nodeTemp2[b++] = nodeTemp[0];
   
   while(a<N && strcmp(node[location].next,"-1") !=0){
     for(i = 0;i<N;i++) {
       if( strcmp(node[i].address,node[location].next) == 0){//�������н���ҵ���ǰ������һ�����          
        location = i;//����location��λ�� 
        //printf("location = %d\n",location);
        nodeTemp[count++] = node[i];//�ṹ�����帳ֵ
        //printf("%s %d %s\n",nodeTemp[count-1].address,nodeTemp[count-1].data,nodeTemp[count-1].next);
        a++;//��ʾ�Ѿ����������Ľڵ���    
       }
       
       if(count == k){
         for(j =count -1;j>=0;j--){           
           nodeTemp2[b++] = nodeTemp[j];           
           //printf("%s %d %s\n",nodeTemp[j].address,nodeTemp[j].data,nodeTemp[j].next);                  
         }
         count =0;//������Ժ󣬹��� 
       }     
     }     
  }
//  printf("b = %d",b);
  
  if(count < k){    
    for(j =(N/k) * k;j<N;j++){           
       
       nodeTemp2[b++] = node[j];//���丳ֵ  
      //printf("����%s %d %s\n",nodeTemp2[j].address,nodeTemp2[j].data,nodeTemp2[j].next);     
     }  
  }
  
  //printf("��ʽ�����\n");
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
