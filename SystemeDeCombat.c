#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){

		// http://bit.ly/35Q6ffC
		srand(time(NULL));
    int pvHeros = 30;
		int pvMonstre = 20;
		int pmHeros = 30;
		int pmMonstre = 30;
		int attaqueEpee = 4;
		int contreAttaque = 4;
		int attaquePoison = 1;
		int coutPoison = 6;
		int choixAction;
		int actionSlime;
		bool isPoisoned = false;

    printf("Vous avez %d points de vie et %d points de magie.\n", pvHeros, pmHeros);
		printf("Slime a %d points de vie et %d points de magie.\n", pvMonstre, pmMonstre);

		while (pvMonstre > 0 && pvHeros > 0 ) {
			contreAttaque = 4;
			attaqueEpee = 4;
			printf("C'est votre Tour que voulez-vous faire ? Attaque(1) // Defense(2) // Poison (3)\n--------------------------------------------------------------------------------\n");
			scanf("%d", &choixAction);
			actionSlime = rand() % 2;
				if(pmHeros <= 30){
					pmHeros++;
				}
				if(pmMonstre <= 30){
					pmMonstre++;
				}
				if(isPoisoned == true){
					printf("Slime subit des degats du Poison, il perd 1 pv !\n");
					pvMonstre = pvMonstre - attaquePoison;
				}

			switch (choixAction){
					case 1:
					// Case Attaque
							if (actionSlime == 0) {
								printf("--------------------------------------------------------------------------------\nHeros lance Coup d'Epee !\nSlime subit %d de degats !\n", attaqueEpee);
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
									printf("Vous avez %d points de vie et %d points de magie.\n", pvHeros, pmHeros);
								}
							} else if(actionSlime == 1){
								attaqueEpee = 1;
								printf("--------------------------------------------------------------------------------\nSlime se defend ! Il subit moins de degats.\n");
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
					// Case Defense
					contreAttaque = contreAttaque / 4;
					if (actionSlime == 0) {
						printf("--------------------------------------------------------------------------------\nSlime charge sur vous ! Vous perdez %d points de vie !\n", contreAttaque);
						pvHeros = pvHeros - contreAttaque;
						if (pvHeros <= 0) {
							printf("Vous etes mort. Game Over !\n");
							break;
						} else if(pvHeros >= 0){
							printf("Vous avez %d points de vie.\n", pvHeros);
						}
					} else if(actionSlime == 1){
						printf("--------------------------------------------------------------------------------\nSlime se defend ! Il subit moins de degats.\n", contreAttaque);
						printf("Vous vous defendez aussi ! La bataille de regard commence.\n");
					}
						break;
					case 3:
					// Case Poison
					if(pmHeros <= 5){
						printf("Vous n'avez pas assez de points de magie pour lancer ce sort!\n");
						break;
					}else if(pmHeros >= 5){
						if (actionSlime == 0) {
							printf("--------------------------------------------------------------------------------\nHeros lance Poison !\nSlime subit %d de degats par tour !\n", attaquePoison);
							isPoisoned = true;
							pmHeros = pmHeros - coutPoison;
							pvMonstre = pvMonstre - attaquePoison;
							if (pvMonstre <= 0) {
								printf("Slime est mort !\n");
								break;
							} else if(pvMonstre >= 0){
								printf("Slime a %d points de vie.\n", pvMonstre);
							}
							printf("\nSlime attaque immediatement ! Vous perdez %d points de vie !\n", contreAttaque);
							pvHeros = pvHeros - contreAttaque;
							if (pvHeros <= 0) {
								printf("Vous etes mort. Game Over !\n");
								break;
							} else if(pvHeros >= 0){
								printf("Vous avez %d points de vie et %d points de magie.\n", pvHeros, pmHeros);
							}
						} else if(actionSlime == 1){
							attaqueEpee = 1;
							printf("--------------------------------------------------------------------------------\nSlime se defend ! Il subit moins de degats.\n");
							printf("\nHeros lance Poison !\nSlime subit %d de degats par tour !\n", attaqueEpee);
							pvMonstre = pvMonstre - attaqueEpee;
							if (pvMonstre <= 0) {
								printf("Slime est mort !\n");
								break;
							} else if(pvMonstre >= 0){
								printf("Slime a %d points de vie.\n", pvMonstre);
							}
						}
						break;
					}
					default:
						printf("Veuillez choisir entre les choix possibles.\n");
						break;
			}
		}
	return 0;
}
