#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <string>
#include <string.h>
using namespace std;
char mars1[13][20]={"tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
char mars2[13][20]={"","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
map<char*,int>maps;

int main()
{
    int n;
    char str[20];
    int decade,digit;
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++){
        gets(str);
        if('0'<=str[0]&&str[0]<='9'){
            int num=atoi(str);
            if(num/13 && num%13==0){
                //注意整除的情况。。。
                printf("%s\n",mars2[num/13]);
            }
            else if(num/13){
                decade=num/13;
                digit=num%13;
                printf("%s %s\n",mars2[decade],mars1[digit]);
            }
            else{
                printf("%s\n",mars1[num]);
            }
        }
        else{
            int len=strlen(str);
            //如果是一个字符串的话，加上\0顶多4位。不过要注意也要比较下十位数
            if(len<5){
                digit=-1;
                for(int i=0;i<13;i++){
                    if(strcmp(str,mars1[i])==0){
                        digit=i;
                        break;
                    }
                }
                if(digit==-1){
                    for(int i=1;i<13;i++){
                        if(strcmp(str,mars2[i])==0){
                            decade=i;
                            break;
                        }
                    }
                    printf("%d\n",decade*13);
                }
                else
                    printf("%d\n",digit);
            }
            else{
                char tmp[20];
                int i;
                for(i=0;i<len && str[i]!=' ';i++){
                    tmp[i]=str[i];
                }
                tmp[i]='\0';
                //十位数
                for(int k=1;k<13;k++){
                    if(strcmp(tmp,mars2[k])==0){
                        decade=k;
                        break;
                    }
                }
                i++;
                int p=0;
                for(;i<len;i++,p++)
                    tmp[p]=str[i];
                tmp[p]='\0';
                //个位数
                for(int k=0;k<13;k++){
                    if(strcmp(tmp,mars1[k])==0){
                        digit=k;
                        break;
                    }
                }
                printf("%d\n",decade*13+digit);

            }
        }
    }
    return 0;
}
