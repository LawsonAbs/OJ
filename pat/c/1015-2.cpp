#include <stdio.h>
#include <math.h>

#define size 100//6位足够

/*
1.如果一个数是素数，那么无论在什么进制下都是素数！
*/ 

//在当前radix进制反转后，转换成十进制数total 
int  reverse(int a ,int radix){//a为数，radix为进制 
  int total  = 0 ,i = 0 ,j ;
  int array[size];  
  while(a!=0){//为了得到各位上的数 ---> 需要除以10 
    array[i++] = a % radix;
    a /= radix;
  }     
  for(j = 0;j < i;j++){
    //printf("%d ",array[j]);
    total *= radix;
    total += array[j];
  }  
  //printf("反转后 = %d\n",total);
  return total;
}


//判断一个数是否为素数 
bool isPrime(int total){
  if(total == 2){//如果是2,则直接返回true 
    return true;
  } 
  int i ;
  for(i = 2;i <= sqrt(total);i++){//素数判断从2开始 
    if(total % i == 0){
      return false;//返回false 
    }
  }
  if(i > sqrt(total)){//注意这里是>= 
    return true;//返回true 
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

