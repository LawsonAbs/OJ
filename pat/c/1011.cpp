#include <stdio.h>
#include <alogrithm>
using namespace std;

typedef struct{
	double win;
	double lose;
	double tie;
	char flag ;
}Game;

double max(double a ,double b ){
	if(a>=b){
		return a;
	}
	else
	return b;
}

int main(){
	Game game[3];
	int i  = 0;
	while(3--){
		scanf("%lf %lf %lf",&game[i].win,&game[i].tie,&game[i].lose);
		i++;
	}
	
	
	double max1,max2,max3;
	for(i = 0;i<3;i++){
		max1 = game[i].win>game[i].tie? game[i].win: game[i].tie;
		game[]
	}
	
	max1 = max(max(game[0].win,game[0].tie),game[0].lose);
	max2 = max(max(game[1].win,game[1].tie),game[1].lose);
	max3 = max(max(game[2].win,game[2].tie),game[2].lose);

}
