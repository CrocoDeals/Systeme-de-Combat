#include <stdio.h>

int main(){

	// http://bit.ly/35Q6ffC

    int pvHeros = 30;
		int pvMonstre = 10;
		int attaqueEpee = 2;
		int contreAttaque = 4;
		int choixAction;

    printf("Vous avez %d points de vie.\n", pvHeros);
		printf("Slime a %d points de vie.\n", pvMonstre);

		while (pvMonstre > 0 && pvHeros > 0 ) {
			contreAttaque = 4;
			printf("C'est votre Tour que voulez-vous faire ? Attaque(1) ou Defense(2)\n\n");
			scanf("%d", &choixAction);

			switch (choixAction){
				case 1:
					printf("\nHeros lance Coup d'Epee !\nSlime subit %d de degats !\n", attaqueEpee);
					pvMonstre = pvMonstre - attaqueEpee;
					printf("Slime a %d points de vie.\n", pvMonstre);
					printf("\nSlime contre-attaque immediatement ! Vous perdez %d points de vie !\n", contreAttaque);
					pvHeros = pvHeros - contreAttaque;
					printf("Vous avez %d points de vie.\n", pvHeros);
					break;
				case 2:
					contreAttaque = contreAttaque / 4;
					printf("\nSlime contre-attaque immediatement ! Vous perdez %d points de vie !\n", contreAttaque);
					pvHeros = pvHeros - contreAttaque;
					printf("Vous avez %d points de vie.\n", pvHeros);
					break;
				default:
					printf("Veuillez choisir entre les choix possibles.\n");
					break;
			}

				if (pvHeros <= 0) {
					printf("Vous etes mort. Game Over !\n");
				}
				if (pvMonstre <= 0) {
					printf("Slime est mort !\n");
				}
		}
	return 0;
}
