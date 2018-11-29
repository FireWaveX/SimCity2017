#include "Library.h"
#include "Functions.h"


int setUpHelp(){

	FILE *fp;
	int c;

	fp = fopen("./files/ScreenHelp.txt", "r+"); // ouverture du fichier .txt

    // Read and display data
	while ((c = fgetc(fp)) != EOF)
	{
		init_color(COLOR_GREEN, 100, 500, 100);
		init_color(COLOR_MAGENTA, 1000, 100, 100);


		init_pair(1, COLOR_GREEN, COLOR_GREEN);
		init_pair(2, COLOR_CYAN, COLOR_CYAN);
		init_pair(3, COLOR_BLUE, COLOR_BLUE);
		init_pair(4, COLOR_YELLOW, COLOR_GREEN);

		switch(c){
			//Background
			case 'h' :
				attron(COLOR_PAIR(1));
				printw(" ");
				attroff(COLOR_PAIR(1));
			break;
			
			//Titre
			case ':' :
				attron(COLOR_PAIR(2));
				printw(" ");
				attroff(COLOR_PAIR(2));
			break;
			
			case 'H' :
				attron(COLOR_PAIR(3));
				printw(" ");
				attroff(COLOR_PAIR(3));
			break;
			
			//Ecritures
			case '_' :
				attron(A_BOLD);
				attron(COLOR_PAIR(4));
				printw("_");
				attroff(COLOR_PAIR(4));
				attroff(A_BOLD);
			break;
			case '|' :
				attron(A_BOLD);
				attron(COLOR_PAIR(4));
				printw("|");
				attroff(COLOR_PAIR(4));
				attroff(A_BOLD);
			break;
			case '(' :
				attron(A_BOLD);
				attron(COLOR_PAIR(4));
				printw("(");
				attroff(COLOR_PAIR(4));
				attroff(A_BOLD);
			break;
			case ')' :
				attron(A_BOLD);
				attron(COLOR_PAIR(4));
				printw(")");
				attroff(COLOR_PAIR(4));
				attroff(A_BOLD);
			break;
			case '/' :
				attron(A_BOLD);
				attron(COLOR_PAIR(4));
				printw("/");
				attroff(COLOR_PAIR(4));
				attroff(A_BOLD);
			break;
			case SYM9 :
				attron(A_BOLD);
				attron(COLOR_PAIR(4));
				printw("\\");
				attroff(COLOR_PAIR(4));
				attroff(A_BOLD);
			break;
			
			//Autre	
			default :
				printw("%c",c);
			break;
		}
	}

	fclose(fp); // fermeture du fichier

	return 1;
}





