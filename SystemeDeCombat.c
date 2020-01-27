#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

struct Joueur{
	int pv;
	int pvMax;
	int pm;
	int pmMax;
	int att;
	int def;
	int xp;
	int xpMax;
	int level;
	bool isPoisoned;
	};
typedef struct Joueur joueur;

struct Monstre{
	int pv;
	int pm;
	int pmMax;
	int att;
	int def;
	bool isBurned;
};
typedef struct Monstre monstre;

struct Poison{
	int degatPoison;
	int coutPM;
};
typedef struct Poison poison;

int soin(struct Joueur joueur){
		if(joueur.pv + 10 >= joueur.pvMax){
			joueur.pv = joueur.pvMax;
		} else {
			joueur.pv = joueur.pv + 10;
		}
	return joueur.pv;
}

int miracle(struct Joueur joueur){
		if(joueur.pv + 5 >= joueur.pvMax){
			joueur.pv = joueur.pvMax;
		} else {
			joueur.pv = joueur.pv + 5;
		}
	return joueur.pv;
}

int main(){

		srand(time(NULL));
		joueur guerrier = {30, 30, 20, 20, 8, 2, 1, 100, 1, false};
		joueur pretre = {15, 15, 45, 45, 4, 1, 1, 100, 1, false};
		joueur mage = {20, 20, 40, 40, 8, 1, 1, 100, 1, false};
		monstre slime = {40, 40, 40, 8, 1, false};
		monstre bat= {50, 40, 40, 7, 1, false};
    monstre skeleton={70, 40, 40, 5, 1, false};
		int choixAction;
		int done;
		int actionMonstre;
		int degatActuels;
		int attackedPlayer;
		// PV MONSTRE -= fonction    fonction(1,nmJoueur)
		// int TourJeu(int nAction, joueur joueur){
		// switch(nAction) { case1 : break;}
		// }
		printf("\nVotre Equipe :\n---------------------------------\n");
    printf("|Guerrier : | %d PV | - | %d PM |\n---------------------------------\n", guerrier.pv, guerrier.pm);
		printf("|  Pretre : | %d PV | - | %d PM |\n---------------------------------\n", pretre.pv, pretre.pm);
		printf("|    Mage : | %d PV | - | %d PM |\n---------------------------------\n", mage.pv, mage.pm);

while(slime.pv > 0 || pretre.pv > 0 && guerrier.pv > 0 && mage.pv > 0){
		// Tour Guerrier
		while(guerrier.pv > 0){
			guerrier.def = 2;
			degatActuels = 0;
			done = 0;
			do{
				printf("\nC'est votre Tour que voulez-vous faire ? Attaque (1) // Defense (2) // Coup Puissant (3) // Antidote (4) \n");
				scanf("%d", &choixAction);
					switch(choixAction){
						case 1:
							// Case attaque
							printf("\nGuerrier decide d'attaquer : Slime (1) Bat (2) Skeleton(3)\n");
							scanf("%d",&attackedPlayer);
								switch (attackedPlayer){
									case 1:
										// Guerrier attaque Slime
										printf("\nGuerrier lance Coup d'Epee !\n");
										degatActuels = guerrier.att/slime.def;
										slime.pv = slime.pv - degatActuels;
										printf("\nLe Slime subit %d points de degats\n", degatActuels);
												if(slime.pv <= 0){
							            printf("Le Slime est mort !\n");
							            break;
							          } else if(slime.pv >= 0){
							            printf("Slime : %d PV\n", slime.pv);
							          }
											done = 1;
											break;
									case 2:
									// Guerrier attaque Bat
									printf("\nGuerrier lance Coup d'Epee !\n");
									degatActuels = guerrier.att/bat.def;
									bat.pv = bat.pv - degatActuels;
									printf("\nLa Chauve-Souris subit %d points de degats\n", degatActuels);
											if(bat.pv <= 0){
												printf("La Chauve-Souris est mort !\n");
												break;
											} else if(bat.pv >= 0){
												printf("Bat : %d PV\n", bat.pv);
											}
										done = 1;
										break;
									case 3:
									// Guerrier attaque Skeleton
									printf("\nGuerrier lance Coup d'Epee !\n");
									degatActuels = guerrier.att/bat.def;
									skeleton.pv = skeleton.pv - degatActuels;
									printf("\nLe Squelette subit %d points de degats\n", degatActuels);
											if(skeleton.pv <= 0){
												printf("Le Squellette est mort !\n");
												break;
											} else if(skeleton.pv >= 0){
												printf("Skeleton : %d PV\n", skeleton.pv);
											}
										done = 1;
										break;
								}
							break;

						case 2:
							// Case Defense
							printf("\nGuerrier se defend. \nIl subit moins de degats.\n");
							guerrier.def = guerrier.def * 4;
							done = 1;
							break;
						case 3:
							// Case Coup Puissant
							printf("\nGuerrier decide d'attaquer : Slime (1) Bat (2) Skeleton(3)\n");
							scanf("%d",&attackedPlayer);
								switch (attackedPlayer){
									case 1:
										// Guerrier attaque Slime
											if(guerrier.pm <= 3){
													printf("Pas assez de Points de Magie");
											} else if (guerrier.pm >= 4) {
													printf("\nGuerrier lance Coup Puissant !\n");
													degatActuels = guerrier.att * 2;
													guerrier.pm = guerrier.pm - 4;
													slime.pv = slime.pv - degatActuels;
													printf("\nLe monstre subit %d points de degats\n", degatActuels);
														if(slime.pv <= 0){
									            printf("Le slime est mort !\n");
									            break;
									          } else if(slime.pv >= 0){
									            printf("Slime : %d PV\n", slime.pv);
									          }
													done = 1;
											}
											break;
									case 2:
									// Guerrier attaque Bat
										if(guerrier.pm <= 3){
												printf("Pas assez de Points de Magie");
										} else if (guerrier.pm >= 4) {
												printf("\nGuerrier lance Coup Puissant !\n");
												degatActuels = guerrier.att * 2;
												guerrier.pm = guerrier.pm - 4;
												bat.pv = bat.pv - degatActuels;
												printf("\nLe monstre subit %d points de degats\n", degatActuels);
													if(bat.pv <= 0){
														printf("La Bat est mort !\n");
														break;
													} else if(bat.pv >= 0){
														printf("Bat : %d PV\n", bat.pv);
													}
												done = 1;
										}
										break;
									case 3:
									// Guerrier attaque Skeleton
										if(guerrier.pm <= 3){
												printf("Pas assez de Points de Magie");
										} else if (guerrier.pm >= 4) {
												printf("\nGuerrier lance Coup Puissant !\n");
												degatActuels = guerrier.att * 2;
												guerrier.pm = guerrier.pm - 4;
												skeleton.pv = skeleton.pv - degatActuels;
												printf("\nLe monstre subit %d points de degats\n", degatActuels);
													if(skeleton.pv <= 0){
														printf("Le skeleton est mort !\n");
														break;
													} else if(skeleton.pv >= 0){
														printf("Skeleton : %d PV\n", skeleton.pv);
													}
												done = 1;
										}
										break;
									}
									break;

						case 4:
							// Case Antidote
							printf("\nGuerrier lance Antidote !\n");
							guerrier.isPoisoned = false;
							printf("\nGuerrier perd le status 'empoisonne'.\n");
							done = 1;
							break;
					}
			} while(!done);
			break;
		}

		// Tour Prêtre
		while(pretre.pv > 0){
			int choixSoin;
			degatActuels = 0;
			done = 0;
			do{
				printf("\nC'est votre Tour que voulez-vous faire ? Attaque (1) // Soin (2) // Miracle (3) // Antidote (4) \n");
				scanf("%d", &choixAction);
					switch(choixAction){
						case 1:
							// Case attaque
							printf("\nPretre lance Coup d'baton !\n");
							degatActuels = pretre.att/slime.def;
							slime.pv = slime.pv - degatActuels;
							printf("\nLe monstre subit %d points de degats\n", degatActuels);
							done = 1;
							break;
						case 2:
							// Case Soin
							if(pretre.pm <= 3){
									printf("Pas assez de Points de Magie");
								} else if (pretre.pm >= 4) {
									printf("\nPretre lance Soin ! \n Qui soignez-vous ? Guerrier (1) Mage (2) Pretre (3)\n");
									scanf("%d", &choixSoin);
									pretre.pm = pretre.pm - 4;
									switch (choixSoin) {
										case 1:
											printf("\nGuerrier recupere 10 PV\n");
											guerrier.pv = soin(guerrier);
											printf("Guerrier : %d PV",guerrier.pv);
											break;
										case 2:
											printf("\nMage recupere 10 PV\n");
											mage.pv = soin(mage);
											printf("Mage : %d PV",mage.pv);
											break;
										case 3:
											printf("\nVous recuperez 10 PV\n");
											pretre.pv = soin(pretre);
											printf("Pretre : %d PV",pretre.pv);
											break;
								}
								done = 1;
							}
							break;
							case 3:
								// Case Miracle
								if(pretre.pm <= 8){
										printf("Pas assez de Points de Magie");
									} else if (pretre.pm >= 9) {
										pretre.pm = pretre.pm - 9;
										printf("\nPretre lance Miracle !\n");
										guerrier.pv = miracle(guerrier);
										pretre.pv = miracle(pretre);
										mage.pv = miracle(mage);
										printf("\nUn Miracle ! Toute l'equipe recupere 5 PV\n");
										done = 1;
										break;
									}
							case 4:
								// Case Antidote
								printf("\nPretre lance Antidote !\n");
								guerrier.isPoisoned = false;
								printf("\nPretre perd le status 'empoisonne'.\n");
								done = 1;
								break;
						}
			} while(!done);
			break;
		}

		// Tour Mage
		while(mage.pv > 0){
			int choixSoin;
			degatActuels = 0;
			done = 0;
			do{
				printf("\nC'est votre Tour que voulez-vous faire ? Attaque (1) // Boule de Feu (2) // Frappe de Flame (3) // Antidote (4) \n");
				scanf("%d", &choixAction);
					switch(choixAction){
						case 1:
							// Case attaque
								printf("\nMage lance Coup d'baton !\n");
								degatActuels = mage.att/slime.def;
								slime.pv = slime.pv - degatActuels;
								printf("\nLe monstre subit %d points de degats\n", degatActuels);
								done = 1;
							break;
						case 2:
							// Case Boule de Feu
							if(mage.pm <= 5){
								printf("Pas assez de Points de Magie");
								} else if(mage.pm >= 6){
									mage.pm = mage.pm - 6;
									printf("\nMage lance Boule de Feu ! \n");
									degatActuels = 10 / slime.def;
									slime.pv = slime.pv - degatActuels;
									printf("\nLe monstre subit %d points de degats\n", degatActuels);
									done = 1;
								}
								break;
						case 3:
							// Case Frappe de Flame
							if(mage.pm <= 7){
								printf("Pas assez de Points de Magie");
							} else if(mage.pm >= 8){
								mage.pm = mage.pm - 8;
								printf("\nMage lance Frappe de Flamme ! \n");
								degatActuels = 6 / slime.def;
								slime.pv = slime.pv - degatActuels;
								printf("\nLe monstre subit %d points de degats\n", degatActuels);
								done = 1;
							}
							break;
						case 4:
							// Case Antidote
							printf("\nMage lance Antidote !\n");
							mage.isPoisoned = false;
							printf("\nMage perd le status 'empoisonne'.\n");
							done = 1;
							break;
					}
			} while(!done);
			break;
		}

		while (slime.pv > 0 ) {
			actionMonstre = rand()%3 +1;
			switch (actionMonstre){
				//attaque slime
				case 1:
						if (slime.pm<slime.pmMax) {
							slime.pm++;
						}
						slime.def=1;
						printf("Slime attaque !\n");
					 //choix aléatoire du joueur attaqué
					 	attackedPlayer=rand()%3 +1;
						switch (attackedPlayer) {
							case 1:
								//slime attaque guerrier
								degatActuels=slime.att/guerrier.def;
								guerrier.pv=guerrier.pv-degatActuels;
									printf("Le guerrier prend %d degats. PV Guerrier = %d\n",degatActuels,guerrier.pv);
										if(guerrier.pv <= 0){
					            printf("Le guerrier est mort !\n");
					            break;
					          } else if(guerrier.pv >= 0){
					            printf("Joueur : %d PV\n", guerrier.pv);
					          }
								break;
							case 2:
								//slime attaque prêtre
								degatActuels=slime.att/pretre.def;
								pretre.pv=pretre.pv-degatActuels;
									printf("Le pretre prend %d degats. PV Pretre = %d\n",degatActuels,pretre.pv);
										if(pretre.pv <= 0){
					            printf("Le pretre est mort ! !\n");
					            break;
					          } else if(pretre.pv >= 0){
					            printf("Joueur : %d PV\n", pretre.pv);
					          }
								break;
							case 3:
								//slime attaque mage
								degatActuels=slime.att/mage.def;
								mage.pv=mage.pv-degatActuels;
									printf("Le mage prend %d degats. PV Mage = %d\n",degatActuels,mage.pv);
										if(mage.pv <= 0){
					            printf("Le mage est mort !!\n");
					            break;
					          } else if(mage.pv >= 0){
					            printf("Joueur : %d PV\n", mage.pv);
					          }
								break;
							}
						break;
				//defense Slime
				case 2:
							if (slime.pm<slime.pmMax) {
							slime.pm++;
							}
							slime.def=1;
							printf("Slime se protege en augmentant sa defense, les degats infliges sont reduits\n");
							slime.def=slime.def*4;
						break;
				//poison Slime
			  case 3:
							slime.def=1;
								if (slime.pm<slime.pmMax) {
								slime.pm++;
								}
							if(slime.pm<=4) {
								printf("Le slime lance un sort de poison mais il n'a plus de magie. Son tour passe.\n");
								break;
							} else if(slime.pm>=5) {
								 printf("Slime utilise un sort de poison\n");
								 //choix aléatoire du joueur empoisonné
								 attackedPlayer=rand()%3 +1;
									switch (attackedPlayer) {
										case 1:
											//slime poison guerrier
												degatActuels=1;
												slime.pm=slime.pm-5;
												printf("PM Slime = %d\n",slime.pm);
												guerrier.isPoisoned=true;
												guerrier.pv=guerrier.pv-degatActuels;
												printf("Le guerrier est empoisonne et prend %d degats. PV Guerrier = %d\n",degatActuels,guerrier.pv);
													if(guerrier.pv <= 0){
														 printf("Le guerrier est mort !\n");
														 break;
													 } else if(guerrier.pv >= 0){
														 printf("Joueur : %d PV\n", guerrier.pv-degatActuels);
													 }
												break;
										case 2:
											//slime poison prêtre
												if (slime.pm<slime.pmMax) {
									 			slime.pm++;
								 				}
												slime.pm=slime.pm-5;
												printf("PM Slime = %d\n",slime.pm);
												pretre.isPoisoned=true;
												degatActuels=1;
												pretre.pv=pretre.pv-degatActuels;
												printf("Le pretre est empoisonne et prend %d degats. PV Pretre = %d\n",degatActuels,pretre.pv);
													if(pretre.pv <= 0){
														 printf("Le pretre est mort ! !\n");
														 break;
													 } else if(pretre.pv >= 0){
														 printf("Joueur : %d PV\n", pretre.pv);
													 }
											break;
										case 3:
											//slime poison mage
												if (slime.pm<slime.pmMax) {
									 			slime.pm++;
								 				}
												slime.pm=slime.pm-5;
												printf("PM Slime = %d\n",slime.pm);
												mage.isPoisoned=true;
												degatActuels=1;
												mage.pv=mage.pv-degatActuels;
												printf("Le mage est empoisonne et prend %d degats. PV Mage = %d\n",degatActuels,mage.pv);
													if(mage.pv <= 0){
														 printf("Le mage est mort !!\n");
														 break;
													 } else if(mage.pv >= 0){
														 printf("Joueur : %d PV\n", mage.pv);
													 }
											break;
										}
								}
						break;
					}
					break;
				}
}
	return 0;
}
