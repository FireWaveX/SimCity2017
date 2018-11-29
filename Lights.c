
#include "Library.h"
#include "Functions.h"



int lightBotCar(CarBot * botCar, int y, int x, int danger){

	bool pass;

	if (danger == 0)
	{
		switch(botCar->dirrection)
		{
			case 'h': if (mvinch(y,x+2) == RED							   || (mvinch(y,x+2) == ORANGE))								{pass = false;}else{pass = true;}; break;
			case 'd': if((mvinch(y+1,x) == RED) || (mvinch(y+2,x) == RED)  || (mvinch(y+1,x) == ORANGE) || (mvinch(y+2,x) == ORANGE))	{pass = false;}else{pass = true;}; break;
			case 'b': if (mvinch(y,x-2) == RED							   || (mvinch(y,x-2) == ORANGE))								{pass = false;}else{pass = true;}; break;
			case 'g': if((mvinch(y-1,x) == RED) || (mvinch(y-2,x) == RED)  || (mvinch(y-1,x) == ORANGE) || (mvinch(y-2,x) == ORANGE))	{pass = false;}else{pass = true;}; break;
			default: break;
		}
	}
	else
	{
		switch(botCar->dirrection)
		{
			case 'h': if (mvinch(y,x+2) == RED)							  	{pass = false;}
				else{pass = true;}; break;
			case 'd': if((mvinch(y+1,x) == RED) || (mvinch(y+2,x) == RED)) 	{pass = false;}
				else{pass = true;}; break;
			case 'b': if (mvinch(y,x-2) == RED)							  	{pass = false;}
				else{pass = true;}; break;
			case 'g': if((mvinch(y-1,x) == RED) || (mvinch(y-2,x) == RED)) 	{pass = false;}
				else{pass = true;}; break;
			default: break;
		}
	}
		
	if (pass)
	{
		int oldX = botCar->posX;
		int oldY = botCar->posY; // récupère la position x,y de la voiture au dernier tour 

		move(oldY,oldX);
		printw("%lc",botCar->isOn); // suprime la voiture pour afficher le caractère qu'il y avait "en dessous"

		wchar_t nextCh;
		nextCh = mvinch(y,x); // récupère le signe qui va être "en dessous" de la voiture 

		botCar->isOn = nextCh; // on assigne le caractère en dessous de la voiture à isOn

		botCar->posX = x;
		botCar->posY = y; // assignation des coordonnées de la voiture 

		attron(COLOR_PAIR(botCar->couleur));
		mvprintw(y,x,"🚘");
		attroff(COLOR_PAIR(botCar->couleur));
	}
	return 1;
}




void initLights (){

	int redLights[MAX_R][2]   = {{LIGHT_R_1},{LIGHT_R_2},{LIGHT_R_3},{LIGHT_R_4},{LIGHT_R_5},{LIGHT_R_6},{LIGHT_R_7},{LIGHT_R_8}};
	int greenLights[MAX_G][2] = {{LIGHT_G_1},{LIGHT_G_2},{LIGHT_G_3},{LIGHT_G_4},{LIGHT_G_5},{LIGHT_G_6},{LIGHT_G_7},{LIGHT_G_8},{LIGHT_G_9},{LIGHT_G_10}};

	for (int i = 0; i < MAX_R; ++i)
	{
		
		int y = redLights[i][0];
		int x = redLights[i][1];

		init_pair(42, COLOR_RED, COLOR_BLACK);
		attron(COLOR_PAIR(42));
		move(y,x);
		printw("%lc",LIGHT);
		attroff(COLOR_PAIR (42));

	}

	for (int i = 0; i < MAX_G; ++i)
	{
		
		int y = greenLights[i][0];
		int x = greenLights[i][1];

		init_pair(43, COLOR_GREEN, COLOR_BLACK);
		attron(COLOR_PAIR(43));
		move(y,x);
		printw("%lc",LIGHT);
		attroff(COLOR_PAIR (43));

	}

}

void changeLights (int n){
	// if n == 0, then red lights go red & green lights go green
	// if n == 1, then red lights go green & green lights go red

	int redLights[MAX_R][2]   = {{LIGHT_R_1},{LIGHT_R_2},{LIGHT_R_3},{LIGHT_R_4},{LIGHT_R_5},{LIGHT_R_6},{LIGHT_R_7},{LIGHT_R_8}};
	int greenLights[MAX_G][2] = {{LIGHT_G_1},{LIGHT_G_2},{LIGHT_G_3},{LIGHT_G_4},{LIGHT_G_5},{LIGHT_G_6},{LIGHT_G_7},{LIGHT_G_8},{LIGHT_G_9},{LIGHT_G_10}};

	init_pair(42, COLOR_RED, COLOR_BLACK);
	init_pair(43, COLOR_GREEN, COLOR_BLACK);

	if (n == 1)
	{
		for (int i = 0; i < MAX_R; ++i)
		{
			
			int y = redLights[i][0];
			int x = redLights[i][1];

			attron(COLOR_PAIR(42));
			move(y,x);
			printw("%lc",LIGHT);
			attroff(COLOR_PAIR (42));

		}

		for (int i = 0; i < MAX_G; ++i)
		{
			
			int y = greenLights[i][0];
			int x = greenLights[i][1];

			attron(COLOR_PAIR(43));
			move(y,x);
			printw("%lc",LIGHT);
			attroff(COLOR_PAIR (43));

		}
	}
	else
	{
		for (int i = 0; i < MAX_R; ++i)
		{
			
			int y = redLights[i][0];
			int x = redLights[i][1];

			attron(COLOR_PAIR(43));
			move(y,x);
			printw("%lc",LIGHT);
			attroff(COLOR_PAIR (43));

		}

		for (int i = 0; i < MAX_G; ++i)
		{
			
			int y = greenLights[i][0];
			int x = greenLights[i][1];

			attron(COLOR_PAIR(42));
			move(y,x);
			printw("%lc",LIGHT);
			attroff(COLOR_PAIR (42));

		}
	}

}

void changeLightsOrange (int n){
	// if n == 0, then red lights go red & green lights go green
	// if n == 1, then red lights go green & green lights go red

	int redLights[MAX_R][2]   = {{LIGHT_R_1},{LIGHT_R_2},{LIGHT_R_3},{LIGHT_R_4},{LIGHT_R_5},{LIGHT_R_6},{LIGHT_R_7},{LIGHT_R_8}};
	int greenLights[MAX_G][2] = {{LIGHT_G_1},{LIGHT_G_2},{LIGHT_G_3},{LIGHT_G_4},{LIGHT_G_5},{LIGHT_G_6},{LIGHT_G_7},{LIGHT_G_8},{LIGHT_G_9},{LIGHT_G_10}};

	init_pair(42, COLOR_RED, COLOR_BLACK);
	init_pair(43, COLOR_GREEN, COLOR_BLACK);
	init_pair(44, COLOR_YELLOW, COLOR_BLACK);

	if (n == 1)
	{
		for (int i = 0; i < MAX_R; ++i)
		{			
			int y = redLights[i][0];
			int x = redLights[i][1];

			attron(COLOR_PAIR(44));
			move(y,x);
			printw("%lc",LIGHT);
			attroff(COLOR_PAIR (44));
		}

		for (int i = 0; i < MAX_G; ++i)
		{			
			int y = greenLights[i][0];
			int x = greenLights[i][1];

			attron(COLOR_PAIR(42));
			move(y,x);
			printw("%lc",LIGHT);
			attroff(COLOR_PAIR (42));
		}
	}
	else
	{
		for (int i = 0; i < MAX_R; ++i)
		{
			int y = redLights[i][0];
			int x = redLights[i][1];

			attron(COLOR_PAIR(42));
			move(y,x);
			printw("%lc",LIGHT);
			attroff(COLOR_PAIR (42));
		}
		
		for (int i = 0; i < MAX_G; ++i)
		{
			int y = greenLights[i][0];
			int x = greenLights[i][1];

			attron(COLOR_PAIR(44));
			move(y,x);
			printw("%lc",LIGHT);
			attroff(COLOR_PAIR (44));
		}
	}
}



