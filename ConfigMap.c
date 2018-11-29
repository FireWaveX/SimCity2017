

#include "Library.h"
#include "Functions.h"

//Configuration de ncurses et l'écran
int screenSetUp(){
	WINDOW *w = initscr();
	cbreak();
	nodelay(w, TRUE);
	start_color();
	noecho();
	refresh();
	curs_set(0);

	return 1;
}


int setUpMap(){

	FILE *fp;
	int c;

	fp = fopen("./files/Map.txt", "r+"); // ouverture du fichier .txt avec la carte

	// color definition rgb
	init_color(COLOR_MAGENTA, 1000, 500, 900);
	init_color(COLOR_YELLOW, 1000, 1000, 0);
	init_color(COLOR_BLUE, 500, 500, 500);
	init_color(COLOR_CYAN, 350, 600, 1000);
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	
    init_pair(2, COLOR_BLACK, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);
    init_pair(5, COLOR_BLACK, COLOR_CYAN);
    init_pair(6, COLOR_RED, COLOR_BLUE);
    init_pair(7, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(8, COLOR_GREEN, COLOR_GREEN);
    init_pair(9, COLOR_BLUE, COLOR_YELLOW);
    init_pair(10, COLOR_MAGENTA, COLOR_YELLOW);
    init_pair(11, COLOR_GREEN, COLOR_YELLOW);
    init_pair(12, COLOR_BLUE, COLOR_BLUE);
    init_pair(13, COLOR_BLACK, COLOR_CYAN);
    init_pair(14, COLOR_BLACK, COLOR_BLUE);
    init_pair(15, COLOR_BLACK, COLOR_YELLOW);
    init_pair(16, COLOR_BLACK, COLOR_WHITE);
    init_pair(17, COLOR_CYAN, COLOR_BLACK);
   
    // Read and display data 
	while ((c = fgetc(fp)) != EOF) // algo qui print la carte sur la console
	{
		switch(c){
			case 'p' : //palmiers
				attron(COLOR_PAIR(3));
				printw("🌴");
				attroff(COLOR_PAIR(3));
			break;
			case 'h' : //grass
				attron(COLOR_PAIR(3));
				printw("🌿");
				attroff(COLOR_PAIR(3));
			break;
			case 'g' : //grass on iland
				attron(COLOR_PAIR(11));
				printw("🌿");
				attroff(COLOR_PAIR(11));
			break;
			case 'f' : //fleurs jaunes
				attron(COLOR_PAIR(4));
				printw("🌻");
				attroff(COLOR_PAIR(4));
			break;
			case 'm' : //fleurs magenta sur fond noir
				attron(COLOR_PAIR(7));
				printw("🌺");
				attroff(COLOR_PAIR(7));
			break;
			case 'M' : //fleurs magenta sur l'ile
				attron(COLOR_PAIR(10));
				printw("🌺");
				attroff(COLOR_PAIR(10));
			break;
			case 'V' : //couleur verte (fond) => V majuscule !!
				attron(COLOR_PAIR(8));
				printw(" ");
				attroff(COLOR_PAIR(8));
			break;
			case 'i' : //couleur jaune (fond) pour l'ile
				attron(COLOR_PAIR(9));
				printw(".");
				attroff(COLOR_PAIR(9));
			break;
			case 'P' : //noir sur l'ile
				attron(COLOR_PAIR(15));
				printw("⛱");
				attroff(COLOR_PAIR(15));
			break;
			case 'b' : //barbeles
				attron(COLOR_PAIR(6));
				printw("🔸");
				attroff(COLOR_PAIR(6));
			break;
			case '$' : //sac de sous
				attron(COLOR_PAIR(4));
				printw("💰");
				attroff(COLOR_PAIR(4));
			break;
			case 'n' : //nageur
				attron(COLOR_PAIR(13));
				printw("🏊");
				attroff(COLOR_PAIR(13));
			break;
			case 'e' : //l'eau
				attron(COLOR_PAIR(5));
				printw(" ");
				attroff(COLOR_PAIR(5));
			break;
			case '~' : //vague
				attron(COLOR_PAIR(5));
				printw("~");
				attroff(COLOR_PAIR(5));
			break;
			case '>' : //signalisation
				attron(COLOR_PAIR(1));
				printw("➡");
				attroff(COLOR_PAIR(1));
			break;
			case '<' ://signalisation
				attron(COLOR_PAIR(1));
				printw("⬅");
				attroff(COLOR_PAIR(1));
			break;
			case '^' ://signalisation
				attron(COLOR_PAIR(1));
				printw("⬆");
				attroff(COLOR_PAIR(1));
			break;
			case 'v' ://signalisation
				attron(COLOR_PAIR(1));
				printw("⬇");
				attroff(COLOR_PAIR(1));
			break;
			case '*' : //signalisation interne à la carte (intersection)
				attron(COLOR_PAIR(2));
				printw("*");
				attroff(COLOR_PAIR (2));
			break;
			case '+' : //enders pour faire disparaitre la voiture
				attron(COLOR_PAIR(2));
				printw("+");
				attroff(COLOR_PAIR (2));
			break;
			case 't' : //trotoirs
				attron(COLOR_PAIR(12));
				printw(" ");
				attroff(COLOR_PAIR (12));
			break;
			case '.' : //passage pietons
				printw(".");
			break;
			case ':' ://passage pietons
				printw(":");
			break;
			case 'o' ://ballon de foot
				attron(COLOR_PAIR(1));
				printw("⚽️");
				attroff(COLOR_PAIR (1));
			break;
			//lettre ecole et banque
			case 'E' :
				attron(COLOR_PAIR(16));
				printw("E");
				attroff(COLOR_PAIR (16));
			break;
			case 'S' :
				attron(COLOR_PAIR(16));
				printw("S");
				attroff(COLOR_PAIR (16));
			break;
			case 'I' :
				attron(COLOR_PAIR(16));
				printw("I");
				attroff(COLOR_PAIR (16));
			break;
			case 'A' :
				attron(COLOR_PAIR(16));
				printw("A");
				attroff(COLOR_PAIR (16));
			break;
			case 'B' :
				attron(COLOR_PAIR(16));
				printw("B");
				attroff(COLOR_PAIR (16));
			break;
			case 'N' :
				attron(COLOR_PAIR(16));
				printw("N");
				attroff(COLOR_PAIR (16));
			break;
			case 'T' :
				attron(COLOR_PAIR(16));
				printw("T");
				attroff(COLOR_PAIR (16));
			break;
			case 'O' :
				attron(COLOR_PAIR(16));
				printw("O");
				attroff(COLOR_PAIR (16));
			break;
			case 'L' :
				attron(COLOR_PAIR(16));
				printw("L");
				attroff(COLOR_PAIR (16));
			break;
			case 'K' :
				attron(COLOR_PAIR(16));
				printw("K");
				attroff(COLOR_PAIR (16));
			break;
			case 'C' :
				attron(COLOR_PAIR(16));
				printw("C");
				attroff(COLOR_PAIR (16));
			break;
			case 'H' :
				attron(COLOR_PAIR(16));
				printw("H");
				attroff(COLOR_PAIR (16));
			break;
			case 'R' :
				attron(COLOR_PAIR(16));
				printw("R");
				attroff(COLOR_PAIR (16));
			break;
			case 'Y' :
				attron(COLOR_PAIR(16));
				printw("Y");
				attroff(COLOR_PAIR (16));
			break;
			case 'c' :
				attron(COLOR_PAIR(16));
				printw("5");
				attroff(COLOR_PAIR (16));
			break;
			case 'u' :
				attron(COLOR_PAIR(16));
				printw("1");
				attroff(COLOR_PAIR (16));
			break;
			case 'a' :
				attron(COLOR_PAIR(16));
				printw("4");
				attroff(COLOR_PAIR (16));
			break;
			case 'd' :
				attron(COLOR_PAIR(16));
				printw("2");
				attroff(COLOR_PAIR (16));
			break;
			case 'q' :
				attron(COLOR_PAIR(16));
				printw("#");
				attroff(COLOR_PAIR (16));
			break;
			case '&' :
				attron(COLOR_PAIR(16));
				printw(" ");
				attroff(COLOR_PAIR (16));
			break;
			case '{' :
				attron(COLOR_PAIR(2));
				printw("{");
				attroff(COLOR_PAIR (2));
			break;
			case '}' :
				attron(COLOR_PAIR(2));
				printw("}");
				attroff(COLOR_PAIR (2));
			break;
			
			default:
				//attron(COLOR_PAIR(1));
				printw("%c",c);
			break;
		}	
	}

	fclose(fp); // fermeture du fichier

	return 1;
}






