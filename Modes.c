#include "Library.h"
#include "Functions.h"

int modeFluide(int danger){
	system("clear");
	setlocale(LC_ALL, "en_US.UTF-8");

	screenSetUp(); // dans ConfigMap.c => initialisation du 
	setUpMap(); // dans ConfigMap.c => chargement du fichier Map.txt sur la console
	time_t t;
	
// Intializes random number generator
	srand((unsigned) time(&t));

	Liste *liste = malloc(sizeof(*liste));

	CarBot * bot = setUpFirstRandomCar(liste); // Dans Carbot.c => initialisation de la première voiture aléatoire

	Tram * myTramB = setUpTram('b'); // Dans Tramway.c => initialisation des tramways vers le bas (b) et vers le haut (h)
	Tram * myTramH = setUpTram('h');

	CarBot *precedent;
	precedent = malloc(sizeof(CarBot));
	precedent = bot;

	initLights(); //Dans  the lights

	int n = 0; //used to control lights
	int m = 1;
	char ch;
	while((ch = getch()) != 'm')	// touche "m" pour revenir au menu
	{
		int k = randomGen(99);

		if (danger == 0)
		{
			if (k > 90) 				// permet de limiter le nombre de voitures
			{
				CarBot * bot = setUpRandomCar();
				insertCarInList(liste, bot);
			}
		}
		else
		{
			if (k > 50) 				// permet de limiter le nombre de voitures
			{
				CarBot * bot = setUpRandomCar();
				insertCarInList(liste, bot);
			}
		}
		
		CarBot *actuel = liste->premier;

		 while (actuel != NULL)
		 {
		 	if (actuel->etat == 1)
		 	{
		 		checkBotPosition(actuel, liste, precedent, danger);
				actuel= actuel->next;
				precedent = actuel;
			}
		 	else
		 	{
		 		CarBot *tempBot; // voiture temporaire
				tempBot = malloc(sizeof(CarBot));
				tempBot = bot;
		 		tempBot = actuel->next;
		 		eraseBotCar(liste, actuel, precedent);
		 		actuel = tempBot;
		 	}
		 }		
		checkTramPosition(myTramB);
		checkTramPosition(myTramH);

		if (m%50 == 0)
		{
			changeLightsOrange(n%2);
		}
		if (m%100 == 0)
		{
			changeLights(n%2);
			n++;
		} m++;
			
		//ralenti le code
		for (int i = 0; i < 11000000; ++i) //13000000 par defaut
		{
		}
	}
	erase();
	endwin(); //restaure les paramètres par défaut du terminal
	
	launcher();
	return 0;
}



int help(){
	system("clear");
	setlocale(LC_ALL, "en_US.UTF-8");
	
	screenSetUp();
	setUpHelp();
	refresh();
	char ch;
	
	while((ch = getch()) != 'm')	// touche "m" pour revenir au menu
	{
	}
	
	erase();
	endwin(); //restaure les paramètre par défaut du terminal
	
	launcher();
	return 0;
}




int apocalypse(){
	system("clear");
	setlocale(LC_ALL, "en_US.UTF-8");
	
	screenSetUp();
	setUpApocalypse();
	refresh();
	char ch;

	while((ch = getch()) != 'm')	// touche "m" pour revenir au menu
	{
		
	}
	erase();
	endwin(); //restaure les paramètre par défaut du terminal
	
	launcher();
	return 0;
}





/*
int apocalypse(){
	system("clear");
	setlocale(LC_ALL, "en_US.UTF-8");
	
	screenSetUp();
	setUpApocalypse();
	refresh();
	char ch;
	
	int nb_lCar = 4; int nb_cCar = 14;
	int yCar = 124; int xCar = 62;
	WINDOW *carA = screenSetUpCarApocalypse(nb_lCar, nb_cCar, yCar, xCar);
	//wrefresh(menu);

	char **matCarApocalypse = allocCarApocalypse(nb_lCar, nb_cCar);
	loadingCarApocalypse(nb_lCar, nb_cCar, matCarApocalypse);

	int x2 = 62;
	int y2 = 110; //110+14=124

	while((ch = getch()) != 'm')	// touche "m" pour revenir au menu
	{
		printCarApocalypse(nb_lCar, nb_cCar, matCarApocalypse, carA, &y2, &x2);
		refresh();
		
		y2++;
		if(y2 == 143) {
			y2=110;
			x2=62;
		}
		
	}
	freeCarApocalypse(matCarApocalypse, nb_lCar);
	werase(carA);
	erase();
	endwin(); //restaure les paramètre par défaut du terminal
	
	launcher();
	return 0;
}
*/

