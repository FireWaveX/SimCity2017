#include "Library.h"
#include "Functions.h"

/*** Création de la 1ère voiture ***/
CarBot * setUpFirstRandomCar(Liste *liste){

	CarBot *newBot;

	init_pair(50, COLOR_WHITE, COLOR_BLACK);	// définition de la couleur de la ère voiture

	int spawners[MAX][3] = {{SPAWN2},{SPAWN3},{SPAWN4},{SPAWN5},{SPAWN6},{SPAWN8},{SPAWN9},{SPAWN10},{SPAWN11}}; // liste des spawns des voitures

	time_t t;
	srand((unsigned) time(&t));		//initialisation du module rand();
	int i = rand() % 8; 	// entre 0 et 8
	int h = i + 1; 			// entre 1 et 9

	int j = h; // j est le numero de destination de la voiture, h est le numero de depart, i correspond au numero de depart pour le tableau

	while(j == h) // évite que j == i
	{
		j = rand() % 8; // entre 0 et 8
		j++; // entre 1 et 9
	}

	int r = rand()%1;
	int isA;

	if (r == 0)
	{
		isA = 1;
	}
	else if (r == 1)
	{
		isA = 2;
	}
	else
	{
		isA = 1;
	}
	

	char * dirrs = getDirrs(h,j);
	
	newBot = malloc(sizeof(CarBot)); // alocation de la mémoire pour la voiture

	newBot->posY 		= spawners[i][0];
	newBot->posX 		= spawners[i][1];
	newBot->isOn 		= ' ';
	newBot->dirrection 	= spawners[i][2];
	newBot->couleur		= 50; // plage des couleur pour la voiture entre 50 et 55
	newBot->isA 		= isA;
	newBot->destination = j;
	newBot->parcour 	= dirrs;
	newBot->indiceParcour = 0;
	newBot->etat		= 1;
	newBot->next 		= NULL;

	liste->premier = newBot;
	liste->fin = newBot;

	attron(A_BOLD);
	attron(COLOR_PAIR(newBot->couleur));
	if (newBot->isA == 1)
	{
		mvprintw(newBot->posY, newBot->posX,"🚘");
	}
	else
	{
		mvprintw(newBot->posY, newBot->posX,"🕶");
	}	
	attroff(COLOR_PAIR(newBot->couleur));
	attroff(A_BOLD);

	return newBot;
}

CarBot * setUpRandomCar(){

	CarBot *newBot;

	// color definition rgb
	init_color(COLOR_MAGENTA, 	1000, 500,  900);
	init_color(COLOR_YELLOW, 	1000, 1000, 0);
	init_color(COLOR_BLUE, 		500,  500,  500);
	init_color(COLOR_CYAN, 		350,  600,  1000);

	init_pair(50, COLOR_WHITE, 		COLOR_BLACK);
    init_pair(51, COLOR_GREEN, 		COLOR_BLACK);
    init_pair(52, COLOR_YELLOW, 	COLOR_BLACK);
    init_pair(53, COLOR_RED, 		COLOR_BLACK);
    init_pair(54, COLOR_CYAN, 		COLOR_BLACK);
    init_pair(55, COLOR_MAGENTA, 	COLOR_BLACK);

	int spawners[MAX][3] = {{SPAWN2},{SPAWN3},{SPAWN4},{SPAWN5},{SPAWN6},{SPAWN8},{SPAWN9},{SPAWN10},{SPAWN11}};

	int i = randomGen(8); // entre 0 et 8
	int h = i + 1; 		  // entre 1 et 9

	int j = h; 			// j est le numero de destination de la voiture, h est le numero de depart, 
						// i correspond au numero de depart pour le tableau
	while(j == h) 		// évite que j == i
	{
		j = rand() % 8; // entre 0 et 8
		j++; 			// entre 1 et 9
	}

	int r = rand()%1;
	int isA;

	if (r == 0)
	{
		isA = 1;
	}
	else
	{
		isA = 2;
	}

	int couleur  = (rand() % 5) + 50; 	// entre 50 et 55

	char * dirrs = getDirrs(h,j);
	
	newBot = malloc(sizeof(CarBot)); 	// alocation de la mémoire pour la voiture

	newBot->posY 		= spawners[i][0];
	newBot->posX 		= spawners[i][1];
	newBot->isOn 		= ' ';
	newBot->dirrection 	= spawners[i][2];
	newBot->couleur		= couleur; 		// plage des couleur pour la voiture entre 50 et 55
	newBot->destination = j;
	newBot->isA 		= isA;
	newBot->parcour 	= dirrs;
	newBot->indiceParcour = 0;
	newBot->etat		= 1;
	newBot->next 		= NULL;

	attron(A_BOLD);
	attron(COLOR_PAIR(newBot->couleur));
	if (newBot->isA == 1)
	{
		mvprintw(newBot->posY, newBot->posX,"🚘");
	}
	else
	{
		mvprintw(newBot->posY, newBot->posX,"🕶");
	}	
	attroff(COLOR_PAIR(newBot->couleur));
	attroff(A_BOLD);

	return newBot;
}

int checkBotPosition(CarBot * botCar, Liste * liste, CarBot * botPrecedent, int danger){

	int y = 0;
	int x = 0;

	char dirr = botCar->dirrection;

	switch (dirr)
	{
		case 'd' : y = botCar->posY; x = botCar->posX +1;break;
		case 'g' : y = botCar->posY; x = botCar->posX -1;break;
		case 'h' : y = botCar->posY -1; x = botCar->posX;break;
		case 'b' : y = botCar->posY +1; x = botCar->posX;break;
		default: break;
	}

	wchar_t etoile = HIDN1;
	wchar_t plus   = HIDN2;

	if (botCar->isOn == etoile)
	{
		moveBotCarSpecial(botCar, y, x, etoile);
	}
	else if (botCar->isOn == plus)
	{
		//eraseBotCar(liste, botCar, botPrecedent);
		botCar->etat = 0;
	}
	else
	{
		int nextCh = mvinch(y,x);

		int nextChDroite = mvinch(y,x+1);
		int nextChGauche = mvinch(y,x-1);

		if (dirr == 'd' && nextChDroite == SYM8)
		{
			moveBotCar(botCar, botCar->posY, botCar->posX);
			move(0,0);
			printw("%c", 'c');
		}
		else if (dirr == 'g' && nextChGauche == SYM8)
		{
			moveBotCar(botCar, botCar->posY, botCar->posX);
		}
		else
		{
			switch (nextCh)
			{ 
				case ' ': 	moveBotCar(botCar, y, x); break;
				case '.': 	moveBotCar(botCar, botCar->posY, x); break;
			 	case ':': 	moveBotCar(botCar, y, botCar->posX); break;
			 	case HIDN1: moveBotCar(botCar, y, x); break;
			 	case SYM1 : moveBotCar(botCar, y, x); break;
			 	case SYM3 : moveBotCar(botCar, y, x); break;
				case SYM4 : moveBotCar(botCar, y, x); break;
				case SYM5 : moveBotCar(botCar, y, x); break;
				case SYM6 : moveBotCar(botCar, y, x); break;
				case SYM8 : moveBotCar(botCar, botCar->posY, botCar->posX); break;
				case HIDN2: moveBotCar(botCar, y, x); ;break;
				/* lights */
				case SYM2 : lightBotCar(botCar, y, x, danger); break;
				case '-': 	lightBotCar(botCar, y, x, danger); break;
			 	default: break;
			}
		}			
	}

	return 1;
}



int moveBotCar(CarBot * botCar, int y, int x){

	int oldX = botCar->posX;
	int oldY = botCar->posY; 	// récupère la position x,y de la voiture au dernier tour 

	move(oldY,oldX);
	printw("%lc",botCar->isOn); // suprime la voiture pour afficher le caractère qu'il y avait "en dessous"

	wchar_t nextCh;
	nextCh = mvinch(y,x); 		// récupère le signe qui va être "en dessous" de la voiture 

	botCar->isOn = nextCh; 		// on assigne le caractère en dessous de la voiture à isOn

	botCar->posX = x;
	botCar->posY = y; 			// assignation des coordonnées de la voiture 

	attron(A_BOLD);
	attron(COLOR_PAIR(botCar->couleur));
	if (botCar->isA == 1)
	{
		mvprintw(botCar->posY, botCar->posX,"🚘");
	}
	else
	{
		mvprintw(botCar->posY, botCar->posX,"🕶");
	}	
	attroff(COLOR_PAIR(botCar->couleur));
	attroff(A_BOLD);

	return 1;
}

// Pour les changement de direction (aux intesections)
int moveBotCarSpecial(CarBot * botCar, int y, int x, wchar_t special){

	char * dirrs = (char *)malloc(100);
	strcpy (dirrs, botCar->parcour);

	int ind = botCar->indiceParcour;
	char dirr = dirrs[ind];

	botCar->indiceParcour = ind + 1;

	if (dirr == 'h')
	{
		botCar->dirrection = 'h';
		y = botCar->posY-1;
		x = botCar->posX;
	}
	else if (dirr == 'd')
	{
		botCar->dirrection = 'd';
		y = botCar->posY;
		x = botCar->posX+1;
	}
	else if (dirr == 'b')
	{
		botCar->dirrection = 'b';
		y = botCar->posY+1;
		x = botCar->posX;
	}
	else if (dirr == 'g')
	{
		botCar->dirrection = 'g';
		y = botCar->posY;
		x = botCar->posX-1;
	}

	free(dirrs);

	int oldX = botCar->posX;
	int oldY = botCar->posY; 		// récupère la position x,y de la voiture au dernier tour 

	init_pair(2, COLOR_BLACK, COLOR_BLACK);

	if (special == HIDN1)
	{
		attron(COLOR_PAIR(2));
		move(oldY,oldX);
		printw("*");				// suprime la voiture pour afficher le caractère qu'il y avait "en dessous"
		attroff(COLOR_PAIR (2));
	}
	else
	{
		move(oldY,oldX);
		printw("%lc",botCar->isOn); 
	}

	wchar_t nextCh;
	nextCh = mvinch(y,x); 			// récupère le signe qui va être "en dessous" de la voiture 

	botCar->isOn = nextCh; 			// on assigne le caractère en dessous de la voiture à isOn

	botCar->posX = x;
	botCar->posY = y; 				// assignation des coordonnées de la voiture 

	attron(A_BOLD);
	attron(COLOR_PAIR(botCar->couleur));
	if (botCar->isA == 1)
	{
		mvprintw(botCar->posY, botCar->posX,"🚘");
	}
	else
	{
		mvprintw(botCar->posY, botCar->posX,"🕶");
	}	
	attroff(COLOR_PAIR(botCar->couleur));
	attroff(A_BOLD);

	return 1;
}

// Sorite de la carte
void eraseBotCar(Liste * liste, CarBot * botCar, CarBot * botPrecedent){

	int oldX = botCar->posX;
	int oldY = botCar->posY; 		// récupère la position x,y de la voiture au dernier tour 

	init_pair(2, COLOR_BLACK, COLOR_BLACK);

	attron(COLOR_PAIR(2));
	move(oldY,oldX);
	printw("+");					// suprime la voiture pour afficher le caractère de suppression de voiture
	attroff(COLOR_PAIR (2));

	if (liste->fin == botCar)
	{
		liste->fin = botPrecedent;
	}
	else if (liste->premier == botCar)
	{
		liste->premier = botCar->next;
	}
	else
	{
		botPrecedent->next = botCar->next;
	}
}



void insertCarInList(Liste * liste, CarBot * bot)
{

	if (liste->premier == NULL)
	{
		liste->premier = bot;
		liste->fin = bot;
	}
	else
	{
		liste->fin->next = bot;
		liste->fin = bot;
	}
	
}


char * getDirrs(int i, int j)
{
	char * list;

	if (i == 1)
	{
		switch(j)
		{
			case 2 : list = DIRR1_2; break;
			case 3 : list = DIRR1_3; break;
			case 4 : list = DIRR1_4; break;
			case 5 : list = DIRR1_5; break;
			case 6 : list = DIRR1_6; break;
			case 7 : list = DIRR1_7; break;
			case 8 : list = DIRR1_8; break;
			case 9 : list = DIRR1_9; break;
		}
	}
	else if (i == 2)
	{
		switch(j)
		{
			case 1 : list = DIRR2_1; break;
			case 3 : list = DIRR2_3; break;
			case 4 : list = DIRR2_4; break;
			case 5 : list = DIRR2_5; break;
			case 6 : list = DIRR2_6; break;
			case 7 : list = DIRR2_7; break;
			case 8 : list = DIRR2_8; break;
			case 9 : list = DIRR2_9; break;
		}
	}
	else if (i == 3)
	{
		switch(j)
		{
			case 1 : list = DIRR3_1; break;
			case 2 : list = DIRR3_2; break;
			case 4 : list = DIRR3_4; break;
			case 5 : list = DIRR3_5; break;
			case 6 : list = DIRR3_6; break;
			case 7 : list = DIRR3_7; break;
			case 8 : list = DIRR3_8; break;
			case 9 : list = DIRR3_9; break;
		}
	}
	else if (i == 4)
	{
		switch(j)
		{
			case 1 : list = DIRR4_1; break;
			case 2 : list = DIRR4_2; break;
			case 3 : list = DIRR4_3; break;
			case 5 : list = DIRR4_5; break;
			case 6 : list = DIRR4_6; break;
			case 7 : list = DIRR4_7; break;
			case 8 : list = DIRR4_8; break;
			case 9 : list = DIRR4_9; break;
		}
	}
	else if (i == 5)
	{
		switch(j)
		{
			case 1 : list = DIRR5_1; break;
			case 2 : list = DIRR5_2; break;
			case 3 : list = DIRR5_3; break;
			case 4 : list = DIRR5_4; break;
			case 6 : list = DIRR5_6; break;
			case 7 : list = DIRR5_7; break;
			case 8 : list = DIRR5_8; break;
			case 9 : list = DIRR5_9; break;
		}
	}
	else if (i == 6)
	{
		switch(j)
		{
			case 1 : list = DIRR6_1; break;
			case 2 : list = DIRR6_2; break;
			case 3 : list = DIRR6_3; break;
			case 4 : list = DIRR6_4; break;
			case 5 : list = DIRR6_5; break;
			case 7 : list = DIRR6_7; break;
			case 8 : list = DIRR6_8; break;
			case 9 : list = DIRR6_9; break;
		}
	}
	else if (i == 7)
	{
		switch(j)
		{
			case 1 : list = DIRR7_1; break;
			case 2 : list = DIRR7_2; break;
			case 3 : list = DIRR7_3; break;
			case 4 : list = DIRR7_4; break;
			case 5 : list = DIRR7_5; break;
			case 6 : list = DIRR7_6; break;
			case 8 : list = DIRR7_8; break;
			case 9 : list = DIRR7_9; break;
		}
	}
	else if (i == 8)
	{
		switch(j)
		{
			case 1 : list = DIRR8_1; break;
			case 2 : list = DIRR8_2; break;
			case 3 : list = DIRR8_3; break;
			case 4 : list = DIRR8_4; break;
			case 5 : list = DIRR8_5; break;
			case 6 : list = DIRR8_6; break;
			case 7 : list = DIRR8_7; break;
			case 9 : list = DIRR8_9; break;
		}
	}
	else if (i == 9)
	{
		switch(j)
		{
			case 1 : list = DIRR9_1; break;
			case 2 : list = DIRR9_2; break;
			case 3 : list = DIRR9_3; break;
			case 4 : list = DIRR9_4; break;
			case 5 : list = DIRR9_5; break;
			case 6 : list = DIRR9_6; break;
			case 7 : list = DIRR9_7; break;
			case 8 : list = DIRR9_8; break;
		}
	}

	return list;
}


int randomGen(int a){

	int k = rand() % a;

	return k;
}


