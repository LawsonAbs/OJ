#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define maxSize 10002

typedef struct{
	int flag;//��־λ 
	char number[10];
}Data;

Data da[maxSize];
bool cmp (Data d1,Data d2){	
	return (strcmp(d1.number,d2.number))< 0;
}

int main(){
	int n;
	scanf("%d",&n);
	int i ,array[10],sum[10];
	for(i = 0;i<n;i++){
		scanf("%s",da[i].number);
		da[i].flag = 1;
		array[da[i].number[0]-'0']++;//���㿪ͷ��ĸ���ֵĴ��� 
	}
	
	sort(da,da+n,cmp); 
	//��֤���	
	for(i = 0;i< n;i++){
		printf("%s ",da[i].number);
	}printf("\n");

	int bak[10];
	for(i = 0;i< 10;i++){
		bak[i] = array[i];
	} 
	
	int a = 0;
	char result[maxSize];//�����	
	i = 0;//���� 
	while(a < 10) {
		while(array[a]--){//��ʾ�Ƿ�ȫ�������� 
			if(array[a]  == 1){//�����ֿ�ͷ����ֻ��1�� 
				strcat(result , da[i].number);
				array[a] --;				
				i++;
			}
			else if(array[a]  == 2){
				strcat(result,da[i].number);
				i++;
				array[a] --;
				strcat(result,da[i].number);
				i++;				
				array[a] --;
			}
			else{
				char min[maxSize];
				strcpy(min,da[i].number);//�������һ��Ϊ��С�� 
				int len1 = strlen(min);
				
				int k = i; 
				while(k <i + bak[a]){//����ѡ���һ���� 
					if(da[k].flag && k !=i){
						break;
					}
					k++;
				}				
				int len2 = strlen(da[k].number);
				
				if(len1 < len2){
					char temp[maxSize];
					strcpy(temp,da[i].number);//�ȸ���
					strcat(temp,da[i+2].number);//��ƴ��
					printf("temp = %s\n",temp);
					if(strcmp(temp , da[i+1].number) > 0){
						if( == bak[a]){
							da[i+2].flag = 0;//��ʾ�Ѿ����ʹ�
							strcat(result ,da[i+1].number);					
							array[a] --;
							i = (i+1) % array[a];	
						}
						else{
							
						}						
					} 
				}
				else if(len1 == len2){
					da[i].flag = 0;
					strcat(result , da[i].number); 					
					array[a] --;
					i++;//������һλ 
				}	
			} 			 
		}
		a++;
	}
}
/**
5 32 321 3214 0229 87

5 32 321 3210 0229 87
*/
 
