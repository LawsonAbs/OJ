#include <stdio.h>
#include <math.h>

#define size 100//6λ�㹻

/*
1.���һ��������������ô������ʲô�����¶���������
*/ 

//�ڵ�ǰradix���Ʒ�ת��ת����ʮ������total 
int  reverse(int a ,int radix){//aΪ����radixΪ���� 
  int total  = 0 ,i = 0 ,j ;
  int array[size];  
  while(a!=0){//Ϊ�˵õ���λ�ϵ��� ---> ��Ҫ����10 
    array[i++] = a % radix;
    a /= radix;
  }     
  for(j = 0;j < i;j++){
    //printf("%d ",array[j]);
    total *= radix;
    total += array[j];
  }  
  //printf("��ת�� = %d\n",total);
  return total;
}


//�ж�һ�����Ƿ�Ϊ���� 
bool isPrime(int total){
  if(total == 2){//�����2,��ֱ�ӷ���true 
    return true;
  } 
  int i ;
  for(i = 2;i <= sqrt(total);i++){//�����жϴ�2��ʼ 
    if(total % i == 0){
      return false;//����false 
    }
  }
  if(i > sqrt(total)){//ע��������>= 
    return true;//����true 
  }
  return false;
} 

int main(){
  int number;
  int radix;
  while(scanf("%d %d",&number,&radix) == 2 ){
    if(number < 0){
      break;
    }
    if(number == 1 || number == 0){
      printf("No\n");
    }
    else{
      if(isPrime(number)){
        int total2 = reverse(number,radix);      
        if(isPrime(total2)){
          printf("Yes\n");
        }
        else
          printf("No\n"); 
        }
      else
        printf("No\n");      
    }    
  }    
} 
/**
797 2
61 2
73 10
1 2
0 2
-2
*/

