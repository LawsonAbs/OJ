#include <stdio.h>
#include <string.h>

int main() {
	char string[100];// N;
	scanf("%s",string);
	
	int length = strlen(string);
	int n1,n2,n3;//
	
	//因为n1与n3只会往小取 ---> 所以先取n1和n3的值，因为除法所得的商是较小值 
	n1 = n3 = (length+2)/3;
	n2 = length +2 - (2 * n1);
	
	
	int i =0,j = 0;
	while(i<n1-1){
		printf("%c",string[i]);
		for(j = 0;j< n2 - 2;j++){
			printf(" ");
		}
		printf("%c\n",string[length-1-i]);
		i++;
	} 
	
	
	for(i = n1 - 1;i<= length-n1;i++){
		printf("%c",string[i]);
	}
}

/**
Helloq

helloworld!wqw

helloworld
**/
