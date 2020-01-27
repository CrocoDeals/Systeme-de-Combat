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
	bool isPoisoned;
};
typedef struct Monstre monstre;

struct Poison{
	int degatPoison;
	int coutPM;
};
typedef struct Poison poison;

/*char Slime[]="Slime";
char Guerrier[]="Guerrier";
char Mage[]="Mage";
char Pretre[]="Pretre";*/

void poisonParTour(struct Joueur joueur){
	joueur.pv=joueur.pv-1;
	joueur.isPoisoned=true;
	if (joueur.pv<=0) {
			printf("Le joueur est mort !\n");
		} else if(joueur.pv >= 0){
			printf("PV Restants: %d \n",joueur.pv);
		}
	};




int main(){

		srand(time(NULL));
		joueur guerrier = {30, 30, 20, 20, 4, 2, 1, 100, 1, false};
		joueur pretre = {15, 15, 45, 45, 2, 1, 1, 100, 1, false};
		joueur mage = {20, 20, 40, 40, 4, 1, 1, 100, 1, false};
		monstre slime = {20, 20, 20, 4, 1, false}; // id ?
		monstre bat ={40,20,20,3,4,false};
		int choixAction;
		int actionSlime;
		int attackedPlayer;
		int degatsActuels;
		// PV MONSTRE -= fonction    fonction(1,nmJoueur)
		// int TourJeu(int nAction, joueur joueur){
		// switch(nAction) { case1 : break;}
		// }
		printf("Votre Equipe :\n---------------------------------\n");
    printf("|Guerrier : | %d PV | - | %d PM |\n---------------------------------\n", guerrier.pv, guerrier.pm);
		printf("|  Pretre : | %d PV | - | %d PM |\n---------------------------------\n", pretre.pv, pretre.pm);
		printf("|    Mage : | %d PV | - | %d PM |\n---------------------------------\n", mage.pv, mage.pm);



while (slime.pv > 0 || guerrier.pv > 0 && pretre.pv > 0 && mage.pv > 0) {
//actionSlime = rand()%3 +1;
printf("(1) attaque (2) defense (3) poison\n");
scanf("%d\n",&actionSlime);



switch (actionSlime){
	//attaque slime

	case 1:
			if (slime.pm<slime.pmMax) {
				slime.pm++;
			}
			slime.def=1;
			printf("Slime attaque !\n");
			//attackedPlayer=rand()%3 +1;

		 //choix aléatoire du joueur attaqué

		 scanf("%d", &attackedPlayer);
			switch (attackedPlayer) {
				case 1:
					//slime attaque guerrier
					degatsActuels=slime.att/guerrier.def;
					guerrier.pv=guerrier.pv-degatsActuels;
					printf("Le guerrier prend %d degats. PV Guerrier = %d\n",degatsActuels,guerrier.pv);
					if(guerrier.pv <= 0){
            printf("Le guerrier est mort !\n");
            break;
          } else if(guerrier.pv >= 0){
            printf("Joueur : %d PV\n", guerrier.pv);
          }
					break;
				case 2:
					//slime attaque prêtre
					degatsActuels=slime.att/pretre.def;
					pretre.pv=pretre.pv-degatsActuels;
					printf("Le pretre prend %d degats. PV Pretre = %d\n",degatsActuels,pretre.pv);
					if(pretre.pv <= 0){
            printf("Le pretre est mort ! !\n");
            break;
          } else if(pretre.pv >= 0){
            printf("Joueur : %d PV\n", pretre.pv);
          }
					break;
				case 3:
					//slime attaque mage
					degatsActuels=slime.att/mage.def;
					mage.pv=mage.pv-degatsActuels;
					printf("Le mage prend %d degats. PV Mage = %d\n",degatsActuels,mage.pv);
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
					 //attackedPlayer=rand()%3 +1;
					  scanf("%d", &attackedPlayer);
						switch (attackedPlayer) {
							case 1:
								//slime poison guerrier

									slime.pm=slime.pm-5;
									printf("PM Slime = %d\n",slime.pm);
									guerrier.isPoisoned=true;
									degatsActuels=1;
									guerrier.pv=guerrier.pv-degatsActuels;
									printf("Le guerrier est empoisonne et prend %d degats. PV Guerrier = %d\n",degatsActuels,guerrier.pv);
										if(guerrier.pv <= 0){
											 printf("Le guerrier est mort !\n");
											 break;
										 } else if(guerrier.pv >= 0){
											 printf("Joueur : %d PV\n", guerrier.pv-degatsActuels);
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
									degatsActuels=1;
									pretre.pv=pretre.pv-degatsActuels;
									printf("Le pretre est empoisonne et prend %d degats. PV Pretre = %d\n",degatsActuels,pretre.pv);
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
									degatsActuels=1;
									mage.pv=mage.pv-degatsActuels;
									printf("Le mage est empoisonne et prend %d degats. PV Mage = %d\n",degatsActuels,mage.pv);
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
}
return 0;
}
