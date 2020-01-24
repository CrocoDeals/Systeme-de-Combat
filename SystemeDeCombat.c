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



int attackRandomPlayer (struct Joueur joueur, struct Monstre monstre){
	//attaque aléatoire slime
	int degatsActuels;
	degatsActuels=monstre.att/joueur.def;
	joueur.pv=joueur.pv-degatsActuels;
	return degatsActuels;
}

int main(){

		srand(time(NULL));
		joueur guerrier = {30, 30, 20, 20, 4, 2, 1, 100, 1, false};
		joueur pretre = {15, 15, 45, 45, 2, 1, 1, 100, 1, false};
		joueur mage = {20, 20, 40, 40, 4, 1, 1, 100, 1, false};
		monstre slime = {20, 20, 20, 4, 1, false}; // id ?
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
			printf("quel joueur attaquer ? (1)guerrier (2)pretre (3)mage\n");
			scanf("%d", &attackedPlayer);

actionSlime = rand()%1 +1;

switch (actionSlime){
	//attaque slime
	case 1:
			if (slime.pv <= 0) {
				printf("Slime est mort !\n");
				break;
			} else if(slime.pv >= 0){
				printf("Slime a %d points de vie.\n", slime.pv);
			}
			printf("Slime attaque !\n");
			//attackedPlayer=rand()%3 +1;

		 //choix aléatoire du joueur attaqué
			switch (attackedPlayer) {
				case 1:
					//slime attaque guerrier
					degatsActuels=attackRandomPlayer(guerrier,slime);
					printf("Le guerrier prend %d degats. PV Guerrier = %d\n",degatsActuels,guerrier.pv);
					break;
				case 2:
					//slime attaque prêtre
					degatsActuels=attackRandomPlayer(pretre,slime);
					printf("Le pretre prend %d degats. PV Pretre = %d\n",degatsActuels,pretre.pv);

					break;
				case 3:
					//slime attaque mage
					degatsActuels=attackRandomPlayer(mage,slime);
					printf("Le mage prend %d degats. PV Mage = %d\n",degatsActuels,mage.pv);
					break;
				}
				break;

	//defense Slime
	case 2:
				printf("Slime se protege en augmentant sa defense, les degats infliges sont reduits\n");
				slime.def=slime.def*4;
				break;
	//poison Slime
  case 3:
			 printf("Slime utilise un sort de poison\n");

	}
}
}
