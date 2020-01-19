#include <stdio.h>

int main(){

	// http://bit.ly/35Q6ffC

    int pvHeros = 30;
		int pvMonstre = 10;
		int attaqueEpee = 2;
		int contreAttaque = 10;

    printf("Vous avez %d points de vie.\n", pvHeros);
		printf("Slime a %d points de vie.\n", pvMonstre);

		while (pvMonstre > 0 && pvHeros > 0 ) {
			printf("Heros lance Coup d'Epee !\nSlime subit %d de degats !\n", attaqueEpee);
	    pvMonstre = pvMonstre - attaqueEpee;
			printf("Slime a %d points de vie.\n", pvMonstre);
			printf("Slime contre-attaque immediatement ! Vous perdez %d points de vie !\n", contreAttaque);
			pvHeros = pvHeros - contreAttaque;
			printf("Vous avez %d points de vie.\n", pvHeros);
				if (pvHeros <= 0) {
					printf("Vous etes mort. Game Over !\n");
				}
				if (pvMonstre <= 0) {
					printf("Slime est mort !\n");
				}
		}
	return 0;
}
