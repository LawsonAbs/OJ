#include <stdio.h>
#include <string.h>

int main(){
	char str[1000];
	scanf("%s",str);
	
	int sum ;
	int length = strlen(str);
	int i = 0;
	for(i = 0;i<length;i++){
		sum = sum +(str[i]-'0');
	}
	
	char letter[12][10]={{"zero"},{"one"},{"two"},{"three"},{"four"},{"five"},{"six"},{"seven"},{"eight"},{"nine"},{"ten"}};
	int array[100];
	int count = 0;
	
	if(sum == 0){
		printf("zero");
		return 0; 
	}
	while(sum!=0){
		array [count++] = sum%10;
		sum /=10; 
	}
	
	
	for(i = count -1;i>= 0;i--){
		if(i!= 0){
			printf("%s ",letter[array[i]]);	
		}
		else{
			printf("%s",letter[array[i]]);	
		}		
	}
}
