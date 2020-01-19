#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){

		// http://bit.ly/35Q6ffC
		srand(time(NULL));
    int pvHeros = 30;
		int pvMonstre = 10;
		int attaqueEpee = 4;
		int contreAttaque = 4;
		int choixAction;
		int actionSlime;

    printf("Vous avez %d points de vie.\n", pvHeros);
		printf("Slime a %d points de vie.\n", pvMonstre);

		while (pvMonstre > 0 && pvHeros > 0 ) {
			contreAttaque = 4;
			attaqueEpee = 4;
			printf("C'est votre Tour que voulez-vous faire ? Attaque(1) ou Defense(2)\n-----------------------------------------------------------------\n");
			scanf("%d", &choixAction);
			actionSlime = rand() % 2;

			switch (choixAction){
				case 1:
						if (actionSlime == 0) {
							printf("-----------------------------------------------------------------\nHeros lance Coup d'Epee !\nSlime subit %d de degats !\n", attaqueEpee);
							pvMonstre = pvMonstre - attaqueEpee;
							if (pvMonstre <= 0) {
								printf("Slime est mort !\n");
								break;
							} else if(pvMonstre >= 0){
								printf("Slime a %d points de vie.\n", pvMonstre);
							}
							printf("\nSlime contre-attaque immediatement ! Vous perdez %d points de vie !\n", contreAttaque);
							pvHeros = pvHeros - contreAttaque;
							if (pvHeros <= 0) {
								printf("Vous etes mort. Game Over !\n");
								break;
							} else if(pvHeros >= 0){
								printf("Vous avez %d points de vie.\n", pvHeros);
							}
						} else if(actionSlime == 1){
							attaqueEpee = 1;
							printf("-----------------------------------------------------------------\nSlime se defend ! Il subit moins de degats.\n");
							printf("\nHeros lance Coup d'Epee !\nSlime subit %d de degats !\n", attaqueEpee);
							pvMonstre = pvMonstre - attaqueEpee;
							if (pvMonstre <= 0) {
								printf("Slime est mort !\n");
								break;
							} else if(pvMonstre >= 0){
								printf("Slime a %d points de vie.\n", pvMonstre);
							}
						}
					break;
				case 2:
				contreAttaque = contreAttaque / 4;
				if (actionSlime == 0) {
					printf("-----------------------------------------------------------------\nSlime charge sur vous ! Vous perdez %d points de vie !\n", contreAttaque);
					pvHeros = pvHeros - contreAttaque;
					if (pvHeros <= 0) {
						printf("Vous etes mort. Game Over !\n");
						break;
					} else if(pvHeros >= 0){
						printf("Vous avez %d points de vie.\n", pvHeros);
					}
				} else if(actionSlime == 1){
					printf("-----------------------------------------------------------------\nSlime se defend ! Il subit moins de degats.\n", contreAttaque);
					printf("Vous vous defendez aussi ! La bataille de regard commence.\n");
				}
					break;
				default:
					printf("Veuillez choisir entre les choix possibles.\n");
					break;
			}
		}
	return 0;
}
