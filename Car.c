#include "Library.h"
#include "Functions.h"

/*** NOTE1 : ce code pourra servir pour implémenter un mode joueur ***/
/*** NOTE2: ce code n'est pas compatible avec certaines fonctions des autres fichiers ***/


/*** Initalisation of car ***/
Car * setUpCar(){

	Car * newCar;

	newCar = malloc(sizeof(Car)); 	// allocation de la mémoire pour la voiture

	newCar->posY = 14;				// position initiale de la voiture
	newCar->posX = 2;
	newCar->isOn = ' ';				// élément en dessous de la voiture

	mvprintw(newCar->posY, newCar->posX, "🚘");	// permet d'afficher la voiture

	return newCar;
}


/*** Vérifie si la voiture peut se déplacer aux nouvelles coordonnées ***/
int checkPosition(Car * mycar, int y, int x){

		int nextCh = mvinch(y,x);	// récupère l'objet aux nouvelles coordonnées

		switch (nextCh) 			// NOTE : les constantes sont définies dans le fichier Constant.h
		{ 
			case ' ': moveCar(mycar, y, x); break;
			case '.': moveCar(mycar, mycar->posY, x); break;
			case '-': moveCar(mycar, y, x); break;
		 	case ':': moveCar(mycar, y, mycar->posX); break;
		 	case HIDN1: moveCar(mycar, y, x); break;
		 	case SYM1 : moveCar(mycar, y, x); break;
		 	case SYM2 : moveCar(mycar, mycar->posY, x); break;
		 	case SYM3 : moveCar(mycar, y, x); break;
			case SYM4 : moveCar(mycar, y, x); break;
			case SYM5 : moveCar(mycar, y, x); break;
			case SYM6 : moveCar(mycar, y, x); break;
		 	default: break;
		}

	return 1;
}


/*** bouge la voiture aux nouvelles coordonnées ***/
int moveCar(Car * mycar, int y, int x){

	int oldX = mycar->posX;			// récupère la position x,y de la voiture avant de bouger
	int oldY = mycar->posY;  

	init_pair(2, COLOR_BLACK, COLOR_BLACK);

	if (mycar->isOn == HIDN1)		// suprime la voiture pour afficher HIDN1
	{
		attron(COLOR_PAIR(2));
		move(oldY,oldX);
		printw("*");				
		attroff(COLOR_PAIR (2));
	}
	else							// suprime la voiture pour afficher le caractère qu'il y avait "en dessous"
	{
		move(oldY,oldX);
		printw("%lc",mycar->isOn); 
	}

	wchar_t nextCh;
	nextCh = mvinch(y,x); 			// récupère le signe qui va être "en dessous" de la voiture 

	mycar->isOn = nextCh; 			// on assigne le caractère en dessous de la voiture à isOn

	mycar->posX = x;
	mycar->posY = y; 				// assignation des coordonnées de la voiture 

	mvprintw(y,x,"🚘"); 				// affichage de la voiture


	return 1;
}



