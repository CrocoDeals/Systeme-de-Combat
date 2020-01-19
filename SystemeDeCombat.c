#include <stdio.h>

int main(){
	
	// http://bit.ly/35Q6ffC
	
    int pvHeros = 30;
	int pvMonstre = 10;
	int attaqueEpee = 2;
    
    printf("Vous avez %d points de vie.\n", pvHeros);
    
    printf("Slime a %d points de vie.\n", pvMonstre);
    
    printf("Heros lance Coup d'Epee !\nSlime subit %d de degats !\n", attaqueEpee);
    
    pvMonstre = pvMonstre - attaqueEpee;
    
    printf("Slime a %d points de vie.", pvMonstre);
	
	/* printf("marquez votre premier chiffre \n --> ");
	scanf("%d",&valeur);
	
	printf("marquez votre second chiffre \n --> ");
	scanf("%d",&valeurdeux);
	
	printf("%d et %d sont les deux valeurs entrees", valeur, valeurdeux); */

	return 0;
}