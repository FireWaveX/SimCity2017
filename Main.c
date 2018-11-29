
#include "Library.h"
#include "Functions.h"


int main(int argc, char const *argv[])
{	
	launcher();
	//erase();
	//endwin(); //restaure les paramètre par défaut du terminal

	return 0;
}



/*
		//création d'une voiture controllable par l'utilisateur
		int newY;
		int newX;

		switch (ch){ // action en fonction de l'entrée de l'utilisateur
			case 'z':
				newY = myCar->posY-1;
				newX = myCar->posX;
			break;
			case 'd':
				newY = myCar->posY;
				newX = myCar->posX + 1;
			break;
			case 's':
				newY = myCar->posY + 1;
				newX = myCar->posX;
			break;
			case 'q':
				newY = myCar->posY;
				newX = myCar->posX - 1;
			break;
			default:
			break;
		}

		checkPosition(myCar, newY, newX);
		*/
