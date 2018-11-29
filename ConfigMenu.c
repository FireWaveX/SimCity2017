#include "Library.h"
#include "Functions.h"


int setUpMenu(){

	FILE *fp;
	int c;

	fp = fopen("./files/Menu.txt", "r+"); // ouverture du fichier .txt

	// color definition rgb : yellow + magenta + blue + black + cyen + green + red +++ white
	init_color(COLOR_YELLOW, 1000, 500, 0);
	init_color(COLOR_MAGENTA, 700, 100, 500);
	init_color(COLOR_BLUE, 250, 250, 1000);

	//init_pair(1, COLOR_CYAN, COLOR_RED);
	init_pair(2, COLOR_BLUE, COLOR_BLUE);
	init_pair(3, COLOR_CYAN, COLOR_CYAN);

   init_pair(4, COLOR_GREEN, COLOR_BLACK);
   init_pair(5, COLOR_RED, COLOR_BLACK);

   init_pair(6, COLOR_YELLOW, COLOR_BLACK);

   init_pair(7, COLOR_MAGENTA, COLOR_BLACK);
   init_pair(8, COLOR_WHITE, COLOR_BLACK);

    // Read and display data
	while ((c = fgetc(fp)) != EOF)
	{
		switch(c){
			//Background :
			case 's' :
				//attron(COLOR_PAIR(1));
				printw(" ");
				//attroff(COLOR_PAIR(1));
			break;
			case 'r' :
				printw(" ");
			break;
			
			
			// Pour titre (Simcity) :			
			case '.' :
				attron(COLOR_PAIR(2));
				printw(" ");
				attroff(COLOR_PAIR(2));
			break;
			case 'l' :
				attron(A_BOLD);
				attron(COLOR_PAIR(3));
				printw(" ");
				attroff(COLOR_PAIR(3));
				attroff(A_BOLD);
			break;


		//Pour "Normal"
			case 'O' :
				attron(COLOR_PAIR(4));attron(A_BOLD);
				printw("O");
				attroff(COLOR_PAIR(4));attroff(A_BOLD);
			break;
			case ')' :
				attron(COLOR_PAIR(4));attron(A_BOLD);
				printw(")");
				attroff(COLOR_PAIR(4));attroff(A_BOLD);
				break;

		//Pour "Danger"
			case ':' :
				attron(COLOR_PAIR(5));attron(A_BOLD);
				printw(":");
				attroff(COLOR_PAIR(5));attroff(A_BOLD);
			break;
			case '+' :
				attron(COLOR_PAIR(5));attron(A_BOLD);
				printw("+");
				attroff(COLOR_PAIR(5));attroff(A_BOLD);
			break;
			case '#' :
				attron(COLOR_PAIR(5));attron(A_BOLD);
				printw("#");
				attroff(COLOR_PAIR(5));attroff(A_BOLD);
			break;

		//Pour "Apocalypse"
			case 'o' :
				attron(COLOR_PAIR(6));
				printw("o");
				attroff(COLOR_PAIR(6));
			break;
			case '|' :
				attron(COLOR_PAIR(6));
				printw("|");
				attroff(COLOR_PAIR(6));
			break;
			case 'v' :
				attron(COLOR_PAIR(6));
				printw("v");
				attroff(COLOR_PAIR(6));
			break;
			case '/' :
				attron(COLOR_PAIR(6));
				printw("/");
				attroff(COLOR_PAIR(6));
			break;
			case SYM9 :
				attron(COLOR_PAIR(6));
				printw("\\");
				attroff(COLOR_PAIR(6));
			break;
			case '<' :
				attron(COLOR_PAIR(6));
				printw("<");
				attroff(COLOR_PAIR(6));
			break;
			case '>' :
				attron(COLOR_PAIR(6));
				printw(">");
				attroff(COLOR_PAIR(6));
			break;
			case '_' :
				attron(COLOR_PAIR(6));
				printw("_");
				attroff(COLOR_PAIR(6));
			break;



		//Pour "Help" et "Quit"
			case '8' :
				attron(A_BOLD);
				attron(COLOR_PAIR(7));
				printw("_");
				attroff(COLOR_PAIR(7));
				attroff(A_BOLD);
			break;
			case '1' :
				attron(A_BOLD);
				attron(COLOR_PAIR(7));
				printw("|");
				attroff(COLOR_PAIR(7));
				attroff(A_BOLD);
			break;
			case '7' :
				attron(A_BOLD);
				attron(COLOR_PAIR(7));
				printw("/");
				attroff(COLOR_PAIR(7));
				attroff(A_BOLD);
			break;
			case '4' :
				attron(A_BOLD);
				attron(COLOR_PAIR(7));
				printw("\\");
				attroff(COLOR_PAIR(7));
				attroff(A_BOLD);
			break;
			case '\'' :
				attron(A_BOLD);
				attron(COLOR_PAIR(7));
				printw("\'");
				attroff(COLOR_PAIR(7));
				attroff(A_BOLD);
			break;
			case '3' :
				attron(A_BOLD);
				attron(COLOR_PAIR(7));
				printw("}");
				attroff(COLOR_PAIR(7));
				attroff(A_BOLD);
			break;


			// Pour la voiture
			case '{' :
				attron(COLOR_PAIR(7));
				printw("/");
				attroff(COLOR_PAIR(7));
			break;
			case '}' :
				attron(COLOR_PAIR(7));
				printw("\\");
				attroff(COLOR_PAIR(7));
			break;


			default :

				printw("%c",c);

			break;
		}

	}

	fclose(fp); // fermeture du fichier

	return 1;

}
