#include <iostream>
using namespace std;

char *gets(char *s){
	int c;
	char *dest= s;
	int gotchar = 0;
	while((c=getchar())!='\n' && c!=EOF){
		*dest++ = c;
		gotchar= 1;
	}
	*dest++ = '\0';
	if(c == EOF && !gotchar)
		return NULL;
	return s;	
}

int main () {
	char ch[10];
	gets(ch);
	puts(ch);
}
