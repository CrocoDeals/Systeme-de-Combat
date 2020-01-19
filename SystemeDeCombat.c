#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){

		// http://bit.ly/35Q6ffC
		srand(time(NULL));
    int pvHeros = 30;
		int pvMonstre = 20;
		int pmHeros = 20;
		int pmMonstre = 20;
		int attaqueEpee = 4;
		int contreAttaque = 4;
		int attaquePoison = 1;
		int coutPoison = 6;
		int coutAntidote = 9;
		int choixAction;
		int actionSlime;
		bool isMonstrePoisoned = false;
		bool isHerosPoisoned = false;

    printf("Vous avez %d points de vie et %d points de magie.\n", pvHeros, pmHeros);
		printf("Slime a %d points de vie et %d points de magie.\n", pvMonstre, pmMonstre);

		while (pvMonstre > 0 && pvHeros > 0 ) {
			// Initialisation des variables d'attaque en cas de réduction de dégats --> Permet de réduire les variables lors d'une défense et puis de les réaugmenter au retour dans la boucle
			contreAttaque = 4;
			attaqueEpee = 4;
			// Lancement du tour joueur et du choix entre les 3 actions primaires Attaque(1) Defense (2) Poison (3) Antidote (4)
			printf("----------------------------------------------------------------------------------------------\nC'est votre Tour que voulez-vous faire ? Attaque(1) // Defense(2) // Poison (3) // Antidote(4) \n----------------------------------------------------------------------------------------------\n");
			scanf("%d", &choixAction);
			// Mise en place de l'aléatoire sur l'action du Slime '% 3' veut dire qu'on lance le random sur 3 valeurs : 0, 1 et 2
			actionSlime = rand() % 3;
			switch (choixAction){
					case 1:
					// Case Attaque
					// Regeneration de pm et Vérification du Poison
							if(pmHeros <= 20){
								pmHeros++;
							}
							if(pmMonstre <= 20){
								pmMonstre++;
							}
							// Verification et perte de pv pour les empoisonnés
							if(isMonstrePoisoned == true){
								printf("---------------------------------------------------------------------------------------------\nSlime subit des degats du Poison, il perd 1 pv !\n");
								pvMonstre = pvMonstre - attaquePoison;
								if (pvMonstre <= 0) {
									printf("Slime est mort !\n");
									break;
								} else if(pvMonstre >= 0){
									printf("Slime a %d points de vie.\n", pvMonstre);
								}
							}
							if(isHerosPoisoned == true){
								printf("----------------------------------------------------------------------------------------------\nVous subissez des degats du Poison, vous perdez 1 pv !\n");
								pvHeros = pvHeros - attaquePoison;
								if (pvHeros <= 0) {
									printf("Vous etes mort. Game Over !\n");
									break;
								} else if(pvHeros >= 0){
									printf("Vous avez %d points de vie et %d points de magie.\n", pvHeros, pmHeros);
								}
							}

								// Slime Attaque
								if (actionSlime == 0) {
									printf("----------------------------------------------------------------------------------------------\nHeros lance Coup d'Epee !\nSlime subit %d de degats !\n", attaqueEpee);
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
								// Slime Defense
								} else if(actionSlime == 1){
									attaqueEpee = 1;
									printf("----------------------------------------------------------------------------------------------\nSlime se defend ! Il subit moins de degats.\n");
									printf("\nHeros lance Coup d'Epee !\nSlime subit %d de degats !\n", attaqueEpee);
									pvMonstre = pvMonstre - attaqueEpee;
									if (pvMonstre <= 0) {
										printf("Slime est mort !\n");
										break;
									} else if(pvMonstre >= 0){
										printf("Slime a %d points de vie.\n", pvMonstre);
									}
								// Slime Poison
								} else if(actionSlime == 2){
								// Les points de magie sont inférieurs à 6 --> Choix entre Attaque et Defense
									if(pmMonstre <= 5){
										// Mise en place de l'aléatoire sur l'action du Slime '% 2' veut dire qu'on lance le random sur 2 valeurs : 0 et 1
										// Le slime n'a pas assez de points de magie --> On relance le Random sur Attaque ou Defense
										actionSlime = rand() % 2;
										if (actionSlime == 0) {
											printf("---------------------------------------------------------------------------------------------\nHeros lance Poison !\nSlime subit %d de degats par tour !\n", attaquePoison);
											isMonstrePoisoned = true;
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
											printf("---------------------------------------------------------------------------------------------\nSlime se defend ! Il subit moins de degats.\n");
											printf("\nHeros lance Poison !\nSlime subit %d de degats par tour !\n", attaqueEpee);
											pvMonstre = pvMonstre - attaqueEpee;
												if (pvMonstre <= 0) {
													printf("Slime est mort !\n");
													break;
												} else if(pvMonstre >= 0){
													printf("Slime a %d points de vie.\n", pvMonstre);
												}
										}
								// Les points de magie sont supérieurs à 5 --> Heros empoisonné
									}else if(pmMonstre >= 5){
									printf("----------------------------------------------------------------------------------------------\nSlime utilise Poison !\n");
									printf("\nVous subissez des degats de poison tout les tours.\n");
									isHerosPoisoned = true;
									pmMonstre = pmMonstre - coutPoison;
									pvHeros = pvHeros - attaquePoison;
										if (pvHeros <= 0) {
											printf("Vous etes mort. Game Over !\n");
											break;
										} else if(pvHeros >= 0){
											printf("Vous avez %d points de vie et %d points de magie.\n", pvHeros, pmHeros);
										}
								}
								}
						break;
					case 2:
						// Case Defense
						// Regeneration de pm et Vérification du Poison
						if(pmHeros <= 30){
							pmHeros++;
						}
						if(pmMonstre <= 30){
							pmMonstre++;
						}
						// Verification et perte de pv pour les empoisonnés
						if(isMonstrePoisoned == true){
							printf("----------------------------------------------------------------------------------------------\nSlime subit des degats du Poison, il perd 1 pv !\n");
							pvMonstre = pvMonstre - attaquePoison;
								if (pvMonstre <= 0) {
									printf("Slime est mort !\n");
									break;
								} else if(pvMonstre >= 0){
									printf("Slime a %d points de vie.\n", pvMonstre);
								}
						}
						if(isHerosPoisoned == true){
							printf("----------------------------------------------------------------------------------------------\nSlime subit des degats du Poison, il perd 1 pv !\n");
							pvHeros = pvHeros - attaquePoison;
								if (pvHeros <= 0) {
									printf("Vous etes mort. Game Over !\n");
									break;
								} else if(pvHeros >= 0){
									printf("Vous avez %d points de vie et %d points de magie.\n", pvHeros, pmHeros);
								}
						}

						// Reduction des dommages de l'attaque --> Defense
						contreAttaque = contreAttaque / 4;

						// Slime Attaque
								if (actionSlime == 0) {
									printf("---------------------------------------------------------------------------------------------\nSlime charge sur vous ! Vous perdez %d points de vie !\n", contreAttaque);
									pvHeros = pvHeros - contreAttaque;
										if (pvHeros <= 0) {
											printf("Vous etes mort. Game Over !\n");
											break;
										} else if(pvHeros >= 0){
											printf("Vous avez %d points de vie.\n", pvHeros);
										}
						// Slime Defense
								} else if(actionSlime == 1){
									printf("---------------------------------------------------------------------------------------------\nSlime se defend ! Il subit moins de degats.\n", contreAttaque);
									printf("Vous vous defendez aussi ! La bataille de regard commence.\n");

						// Slime Poison
								} else if(actionSlime == 2){
						// Les points de magie sont inférieurs à 6 --> Choix entre Attaque et Defense
									if(pmMonstre <= 5){
										// Mise en place de l'aléatoire sur l'action du Slime '% 2' veut dire qu'on lance le random sur 2 valeurs : 0 et 1
										// Le slime n'a pas assez de points de magie --> On relance le Random sur Attaque ou Defense
										actionSlime = rand() % 2;
										if (actionSlime == 0) {
											printf("----------------------------------------------------------------------------------------------\nHeros lance Poison !\nSlime subit %d de degats par tour !\n", attaquePoison);
											isMonstrePoisoned = true;
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
											printf("----------------------------------------------------------------------------------------------\nSlime se defend ! Il subit moins de degats.\n");
											printf("\nHeros lance Poison !\nSlime subit %d de degats par tour !\n", attaqueEpee);
											pvMonstre = pvMonstre - attaqueEpee;
												if (pvMonstre <= 0) {
													printf("Slime est mort !\n");
													break;
												} else if(pvMonstre >= 0){
													printf("Slime a %d points de vie.\n", pvMonstre);
												}
											}
				  	// Les points de magie sont supérieurs à 5 --> Heros empoisonné
									}else if(pmMonstre >= 5){
										printf("---------------------------------------------------------------------------------------------\nSlime utilise Poison !\n");
										printf("\nVous subissez des degats de poison tout les tours.\n");
										isHerosPoisoned = true;
										pmMonstre = pmMonstre - coutPoison;
										pvHeros = pvHeros - attaquePoison;
											if (pvHeros <= 0) {
												printf("Vous etes mort. Game Over !\n");
												break;
											} else if(pvHeros >= 0){
												printf("Vous avez %d points de vie et %d points de magie.\n", pvHeros, pmHeros);
											}
									}
								}
						break;
					case 3:
					// Case Poison
					// Regeneration des points de magie
					if(pmHeros <= 30){
						pmHeros++;
					}
					if(pmMonstre <= 30){
						pmMonstre++;
					}
					// Verification et perte de pv pour les empoisonnés
					if(isMonstrePoisoned == true){
						printf("----------------------------------------------------------------------------------------------\nSlime subit des degats du Poison, il perd 1 pv !\n");
						pvMonstre = pvMonstre - attaquePoison;
							if (pvMonstre <= 0) {
								printf("Slime est mort !\n");
								break;
							} else if(pvMonstre >= 0){
								printf("Slime a %d points de vie.\n", pvMonstre);
							}
					}
					if(isHerosPoisoned == true){
						printf("----------------------------------------------------------------------------------------------\nSlime subit des degats du Poison, il perd 1 pv !\n");
						pvHeros = pvHeros - attaquePoison;
							if (pvHeros <= 0) {
								printf("Vous etes mort. Game Over !\n");
								break;
							} else if(pvHeros >= 0){
								printf("Vous avez %d points de vie et %d points de magie.\n", pvHeros, pmHeros);
							}
					}
					// Les points de magie sont inférieurs à 6 --> Pas assez de points alors sorti
					if(pmHeros <= 5){
						printf("---------------------------------------------------------------------------------------------\nVous n'avez pas assez de points de magie pour lancer ce sort!\n");
						break;
					// Les points de magie sont supérieurs à 5 --> Application du poison tout en fesant attaquer le Slime
						}else if(pmHeros >= 5){
							// Slime Attaque mais subit le poison
							if (actionSlime == 0) {
								printf("----------------------------------------------------------------------------------------------\nHeros lance Poison !\nSlime subit %d de degats par tour !\n", attaquePoison);
								isMonstrePoisoned = true;
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
							// Slime Defense mais subit le poison
							} else if(actionSlime == 1){
								attaqueEpee = 1;
								printf("----------------------------------------------------------------------------------------------\nSlime se defend ! Il subit moins de degats.\n");
								printf("\nHeros lance Poison !\nSlime subit %d de degats par tour !\n", attaqueEpee);
								pvMonstre = pvMonstre - attaqueEpee;
								if (pvMonstre <= 0) {
									printf("Slime est mort !\n");
									break;
								} else if(pvMonstre >= 0){
									printf("Slime a %d points de vie.\n", pvMonstre);
								}
							// Slime Poison mais subit le poison
							}else if(actionSlime == 2){
							// Les points de magie sont inférieurs à 6 --> Choix entre Attaque et Defense
								if(pmMonstre <= 5){
									// Mise en place de l'aléatoire sur l'action du Slime '% 2' veut dire qu'on lance le random sur 2 valeurs : 0 et 1
									// Le slime n'a pas assez de points de magie --> On relance le Random sur Attaque ou Defense
									actionSlime = rand() % 2;
										if (actionSlime == 0) {
											printf("---------------------------------------------------------------------------------------------\nHeros lance Poison !\nSlime subit %d de degats par tour !\n", attaquePoison);
											isMonstrePoisoned = true;
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
							// Les points de magie sont supérieurs à 5 --> Heros empoisonné
									}else if(pmMonstre >= 5){
										printf("--------------------------------------------------------------------------------------------\nSlime utilise Poison !\n");
										printf("\nVous subissez des degats de poison tout les tours.\n");
										isHerosPoisoned = true;
										pmMonstre = pmMonstre - coutPoison;
										pvHeros = pvHeros - attaquePoison;
											if (pvHeros <= 0) {
												printf("Vous etes mort. Game Over !\n");
												break;
											} else if(pvHeros >= 0){
												printf("Vous avez %d points de vie et %d points de magie.\n", pvHeros, pmHeros);
											}
										}
							}
						}
						break;
						case 4:
							// Case Antidote
							// Regeneration de pm et Vérification du Poison
							if(pmHeros <= 30){
								pmHeros++;
							}
							if(pmMonstre <= 30){
								pmMonstre++;
							}

							// Utilisation du sort Antidote
							printf("----------------------------------------------------------------------------------------------\nHeros lance Antidote !\n");
							isHerosPoisoned = false;
							pmHeros = pmHeros - coutAntidote;

							// Slime Attaque
									if (actionSlime == 0) {
										printf("---------------------------------------------------------------------------------------------\nSlime charge sur vous ! Vous perdez %d points de vie !\n", contreAttaque);
										pvHeros = pvHeros - contreAttaque;
											if (pvHeros <= 0) {
												printf("Vous etes mort. Game Over !\n");
												break;
											} else if(pvHeros >= 0){
												printf("Vous avez %d points de vie.\n", pvHeros);
											}
							// Slime Defense
									} else if(actionSlime == 1){
										printf("---------------------------------------------------------------------------------------------\nSlime se defend ! Il subit moins de degats.\n", contreAttaque);
										printf("Vous vous defendez aussi ! La bataille de regard commence.\n");

							// Slime Poison
									} else if(actionSlime == 2){
										printf("---------------------------------------------------------------------------------------------\nSlime utilise Poison !\n");
										printf("\nLe Heros est insensible au poison ce tour.\n");
									}
									// Verification et perte de pv pour les empoisonnés
									if(isMonstrePoisoned == true){
										printf("----------------------------------------------------------------------------------------------\nSlime subit des degats du Poison, il perd 1 pv !\n");
										pvMonstre = pvMonstre - attaquePoison;
											if (pvMonstre <= 0) {
												printf("Slime est mort !\n");
												break;
											} else if(pvMonstre >= 0){
												printf("Slime a %d points de vie.\n", pvMonstre);
											}
									}
							break;
					default:
						printf("Veuillez choisir entre les choix possibles.\n");
						break;
			}
		}
	return 0;
}
