#include <stdio.h>
#include <string.h>
/*
1.ʹ��ȫ�ֱ��������������鷶Χ 
*/
#define size  100001
	
int main(){
	char string[size];//�洢�ַ��� 
	
	scanf("%s",string);//�����ַ���
	int length;
	length = strlen(string);//����ַ����ĳ���
	//printf("%d",length);
	 
 	int i, j ,k ;	
 	int total  = 0;//������ʾ�ж��ٸ�pat 
	//���� 
	for(i = 0;i<length;i++){
		if(string[i] == 'P'){//�����ͷһ���ַ�Ϊp 
			for(j = i+1;j<length;j++){
				if(string[j] == 'A'){//�������һ����ΪA 
					for(k = j+1;k<length;k++){
						if(string[k] == 'T'){
							total++;
							total %= 1000000007;
						} 
					}
				}
			}			
		}
	} 
	printf("%d",total);
}

/*
APPAPT

PAT
**/
