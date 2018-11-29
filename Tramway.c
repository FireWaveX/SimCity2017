#include "Library.h"
#include "Functions.h"

// chargement de la tête des tramway
Tram * setUpTram(char c){

	Tram * newTram;
	
	time_t t;
	srand((unsigned) time(&t));

	newTram = (Tram*) malloc(sizeof(Tram)); // alocation de la mémoire
	
	init_pair(17, COLOR_CYAN, COLOR_BLACK);
	
	switch (c) {
		case 'b' : // Tram vers le bas
			newTram->posY = 1;
			newTram->posX = 154;
			newTram->isOn = SYM1;
			newTram->wait_b = 50;

			attron(COLOR_PAIR(17));
			mvprintw(newTram->posY, newTram->posX, "🚦");
			attroff(COLOR_PAIR(17));
		break;
	
		case 'h' : // Tram vers le haut
			newTram->posY = 83;
			newTram->posX = 161;
			newTram->isOn = SYM1;
			newTram->wait_h = 50;

			attron(COLOR_PAIR(17));
			mvprintw(newTram->posY, newTram->posX, "🚦");
			attroff(COLOR_PAIR(17));
		break;
	
		default :
		break;
	}	
	return newTram;
}




int checkTramPosition (Tram * myTram){
	
	int y = 0;
	wchar_t exit = SYM7;
	
	/*if (myTram->posX == 154){ // tram vers le bas

		y = myTram->posY+1;
		stopTram(myTram, y, 0);
		
	}
	else if (myTram->posX == 161) { //tram vers le haut

		y = myTram->posY-1;
		stopTram(myTram, y, 0);
	}*/

	if (myTram->posX == 154){ // tram vers le bas
		if (myTram->posY == 6){
			if(myTram->wait_b != 0) {
				y = myTram->posY;
				myTram->wait_b = myTram->wait_b -1 ;
			}
			else {
				y = myTram->posY+1;
			}
		}
		else { 
			y = myTram->posY+1; 
		}
	}
	else if (myTram->posX == 161) { //tram vers le haut
		if (myTram->posY == 1){
			if(myTram->wait_h != 0) {
				y = myTram->posY;
				myTram->wait_h = myTram->wait_h -1 ;
			}
			else {
				y = myTram->posY-1;
			}
		}
		else {
			y = myTram->posY-1;
		}
	}
	
	if (myTram->isOn == exit) { // le tram sort de la map	
		disappearTram (myTram, y, myTram->posX, exit);
	}
	else { // le tram va à la case suivante
		int nextCh = mvinch(y,myTram->posX);
		
		switch (nextCh) {
		 	case SYM7 : moveTram(myTram, y, myTram->posX); break;
		 	case SYM1 : moveTram(myTram, y, myTram->posX); break;
		 	default: break;
		}
	}
	return 1;
}


// déplacement des tramways
int moveTram(Tram * myTram, int y, int x) {

	int oldX = myTram->posX;
	int oldY = myTram->posY; // récupère la position x,y du tramway au dernier tour 
	
	move(oldY,oldX);
	
	wchar_t nextCh;
	nextCh = mvinch(y,x); // récupère le signe qui va être "en dessous" du tramway
	
	myTram->isOn = nextCh; // on assigne le caractère en dessous du tramway à isOn
	
	myTram->posX = x;
	myTram->posY = y; // assignation des coordonnées du tramway
	init_pair(17, COLOR_CYAN, COLOR_BLACK); // pour la couleur du tramway
	
	if (myTram->posX == 154){ // tram vers le bas	
		// affichage du tramway (6 wagons)
		mvprintw(0, x, "─");
		if ((y != 1) && (y !=2) && (y != 3) && (y != 4) && (y !=5) && (y != 6)) {
			attron(COLOR_PAIR(17));
			mvprintw(y, x, "🚦");
			attroff(COLOR_PAIR(17));
			mvprintw(y-6, x, "│");
		}
		else {
			attron(COLOR_PAIR(17));
			mvprintw(y, x, "🚦");
			attroff(COLOR_PAIR(17));
		}
	}
	else if (myTram->posX == 161) { //tram vers le haut
		// affichage du tramway (6 wagons)		
		mvprintw(84, x, "─");	
		if ((y != 78) && (y !=79) && (y != 80) && (y != 81) && (y !=82) && (y != 83)) {
			attron(COLOR_PAIR(17));
			mvprintw(y, x, "🚦");
			attroff(COLOR_PAIR(17));
			mvprintw(y+6, x, "│");
		}
		else {
			attron(COLOR_PAIR(17));
			mvprintw(y, x, "🚦");
			attroff(COLOR_PAIR(17));		
		}

	}
	return 1;
}

//Sortie de la map du tramway
int disappearTram (Tram * myTram, int y, int x, wchar_t exit){

	int oldX = myTram->posX;
	int oldY = myTram->posY; // récupère la position x,y du tramway au dernier tour 
	
   init_pair(17, COLOR_CYAN, COLOR_BLACK);

	if (exit == SYM7)
	{		
		if (myTram->posX == 154){ // tram vers le bas			
			int i;
			for (i=0; i<6; i++) {
				mvprintw(myTram->posY-i,myTram->posX, "│");
				mvprintw(oldY,oldX,"─");
			}			
		}
		else if (myTram->posX == 161) { //tram vers le haut		
			int i;
			for (i=0; i<6; i++) {			
				mvprintw(myTram->posY+i,myTram->posX, "│");
				mvprintw(oldY,oldX,"─");
			}
		}
		
		wchar_t nextCh;
		nextCh = mvinch(y,x);
		myTram->isOn = nextCh; // on assigne le caractère en dessous du tramway à isOn

		myTram->posX = x;
		myTram->posY = y; // assignation des coordonnées du tramway
		
		return 1;
	}
	else {
		move(oldY,oldX);
		printw("%lc",myTram->isOn);
	}
	
	wchar_t nextCh;
	nextCh = mvinch(y,x);
	myTram->isOn = nextCh; // on assigne le caractère en dessous du tramway à isOn
	
	myTram->posX = x;
	myTram->posY = y; // assignation des coordonnées du tramway

	return 1;
}








