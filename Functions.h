#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "Constants.h"
#include "Library.h"


				/*__________ STRUCTURES ____________*/
/* Definition des Voitures */
typedef struct Car {
	int posY;
	int posX;
	wchar_t isOn;
}Car;

/* Definition des "voitures robots" */
typedef struct CarBot CarBot;
struct CarBot {
	int posY;
	int posX;
	char dirrection;
	int destination;
	int couleur;
	wchar_t isOn;
	int isA;
	char * parcour;
	int indiceParcour;
	int etat; 			//1 : ne pas supprimer ; 0 : à supprimer
	CarBot * next;
};

/* Definition des listes chainées */
typedef struct Liste Liste;
struct Liste {
    CarBot *premier;
    CarBot * fin;
};

/* Definition du tramway */
typedef struct Tram {
	int posY, posX;
	wchar_t isOn;
	int wait_b;
	int wait_h;
}Tram;


			/*__________ PROTOTYPES ____________*/

		/** Graphisme **/
	
// Pour ConfigMenu.c
int setUpMenu();

// Pour ConfigCarMenu.c
char ** allocCarMenu(int nb_l, int nb_c);
void freeCarMenu (char **mat, int nb_l);
WINDOW *screenSetUpCarMenu(int nb_l, int nb_c, int y, int x);
void loadingCarMenu (int nb_l, int nb_c, char **mat);
void printCarMenu (int nb_l, int nb_c, char **mat, WINDOW *car, int *y, int *x);

// Pour ConfigHelp.c
int setUpHelp();

// Pour ConfigMap.c
int screenSetUp(); // new window on the console
int setUpMap(); // initialisation of the map

// Pour ConfigApocalypse
int setUpApocalypse();


		/** Technique **/

// Pour Launcher.c
void launcher();

// Pour Modes.c
int modeFluide(int danger);
int help();
int apocalypse();

// Pour Car.c (utilisable pour un éventuel mode joueur)
Car * setUpCar(); // initialisation of the car
int moveCar(Car * mycar, int y, int x); //moving of the car
int checkPosition(Car * mycar, int y, int x); // check if the car can move to new coordinates

// Pour CarBot.c
CarBot * setUpFirstRandomCar(Liste *liste);
CarBot * setUpRandomCar();
int moveBotCar(CarBot * bot, int y, int x);
int moveBotCarSpecial(CarBot * botCar, int y, int x, wchar_t special); // déplace le bot et change sa dirrection si nécessaire
int checkBotPosition(CarBot * bot, Liste * liste, CarBot * botPrecedent, int danger);
char * getDirrs(int i, int j); // donne la dirrection au bot
void eraseBotCar(Liste * liste, CarBot * botCar, CarBot * botPrecedent);
void insertCarInList(Liste * liste, CarBot * bot);
int randomGen(int a);

// Pour Lights.c
void initLights ();
void changeLights ();
void changeLightsOrange ();
int lightBotCar(CarBot * bot, int y, int x, int danger);

// Pour Tramway.c
Tram *setUpTram(char c); // initialisation of Tram
int moveTram(Tram * myTram, int y, int x); //moving of the Tramway
int checkTramPosition(Tram * myTram);
int disappearTram (Tram * myTram, int y, int x, wchar_t exit);



#endif
