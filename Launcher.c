#include "Library.h"
#include "Functions.h"


void launcher(){

	system("clear");
	setlocale(LC_ALL, "en_US.UTF-8");

	screenSetUp();
	setUpMenu();
	refresh();
	
	int nb_lCar = 24; int nb_cCar = 79;
	int yCar = 243; int xCar = 51;
	WINDOW *carM = screenSetUpCarMenu(nb_lCar, nb_cCar, yCar, xCar);
	//wrefresh(menu);

	char **matCar = allocCarMenu(nb_lCar, nb_cCar);
	loadingCarMenu(nb_lCar, nb_cCar, matCar);

	//move(154, 52);
	//printw("avant while\n");
	int x2 =51; //51
	int y2 = 264; //264 - 79
	char ch;
	
	while((ch = getch()) != 'q') // touche "a" pour quitter
	{
		
		printCarMenu(nb_lCar, nb_cCar, matCar, carM, &y2, &x2);
		refresh();
		
		y2--;
		if(y2 == -79) {
			y2=264;
			x2=51;
		}

		switch (ch) {		
			case 'n' :
				erase();
				werase(carM);
				endwin();
				modeFluide(0);	// 0 = sans danger
			break;
			
			case 'd' :
				erase();
				endwin();
				modeFluide(1);	// 1 = avec danger
			break;
			
			case 'a' :
				erase();
				endwin();
				werase(carM);
				apocalypse();
			break;
			
			case 'h' :
				erase();
				endwin();
				werase(carM);
				help();				
			break;
			
			default :
			break;
		}
	}
	freeCarMenu(matCar, nb_lCar); //libération de la mémoire
	werase(carM);
	erase();
	endwin(); //restaure les paramètre par défaut du terminal
	exit(0);
}


