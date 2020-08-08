#include <stdio.h>

int main(){
	int Gellon1,Sickle1,Knut1;
	int Gellon2,Sickle2,Knut2;
	int Gellon,Sickle ,Knut;
	
	scanf("%d.%d.%d %d.%d.%d",&Gellon1,&Sickle1,&Knut1,&Gellon2,&Sickle2,&Knut2);
	Knut = Knut1 + Knut2;
	
	Sickle = Sickle1 + Sickle2;
	Sickle +=(Knut/29);
	Knut = Knut%29;
	
	Gellon = Gellon1 + Gellon2; 
	Gellon += (Sickle / 17);
	
	Sickle %=17;
	
	printf("%d.%d.%d",Gellon,Sickle,Knut);
	
}

/**
3.2.1 10.16.27
**/
