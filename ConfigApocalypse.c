#include "Library.h"
#include "Functions.h"


int setUpApocalypse(){

	FILE *fp;
	int c;

	fp = fopen("./files/ScreenApocalypse.txt", "r+"); // ouverture du fichier .txt

	init_color(COLOR_MAGENTA, 1000, 100, 100);
	init_color(COLOR_YELLOW, 500, 100, 300); //violet

	init_pair(1, COLOR_MAGENTA, COLOR_MAGENTA);	
	init_pair(2, COLOR_RED, COLOR_RED);
	init_pair(3, COLOR_YELLOW, COLOR_YELLOW);
	init_pair(4, COLOR_BLACK, COLOR_BLUE);
	init_pair(5, COLOR_CYAN, COLOR_CYAN);
	init_pair(6, COLOR_GREEN, COLOR_BLACK);
	init_pair(7, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(8, COLOR_RED, COLOR_BLACK);
	init_pair(9, COLOR_WHITE, COLOR_YELLOW);
	init_pair(10, COLOR_GREEN, COLOR_YELLOW);
	
	
    // Read and display data
	while ((c = fgetc(fp)) != EOF)
	{
		switch(c){
			//Titre :
			case 'f' :
				attron(COLOR_PAIR(1));
				printw(" ");
				attroff(COLOR_PAIR(1));
			break;
			case 'A' :
				attron(COLOR_PAIR(2));
				printw(" ");
				attroff(COLOR_PAIR(2));
			break;
			
			//Arrière plan :
			case 'a' :
				attron(COLOR_PAIR(3));
				printw(" ");
				attroff(COLOR_PAIR(3));
			break;
			
			//Ecran :
			case 'v' : // tour de l'écran
				attron(COLOR_PAIR(4));
				printw("-");
				attroff(COLOR_PAIR(4));
			break;
			case 'e' : // tour de l'écran
				attron(COLOR_PAIR(4));
				printw(" ");
				attroff(COLOR_PAIR(4));
			break;
			case 'c' : //le ciel
				attron(COLOR_PAIR(5));
				printw(" ");
				attroff(COLOR_PAIR(5));
			break;
			case 'h' : // herbe
				attron(COLOR_PAIR(6));
				printw("🌿");
				attroff(COLOR_PAIR(6));
			break;
			case 'p' : //palmier
				attron(COLOR_PAIR(7));
				printw("🌴");
				attroff(COLOR_PAIR(7));
			break;
			case 'q' :
				attron(COLOR_PAIR(8));
				printw("🌻");
				attroff(COLOR_PAIR(8));
			break;
			case 'r' : //route et trotoires
				printw(" ");
			break;
			case '!' :
				attron(A_BOLD);
				attron(COLOR_PAIR(8));
				printw("‼");
				attroff(COLOR_PAIR(8));
				attroff(A_BOLD);
			break;
			case 'w' :
				attron(COLOR_PAIR(9));
				printw("_");
				attroff(COLOR_PAIR(9));
			break;
			
			// "En cours de developpement ... "
			case '0' :
				attron(A_BOLD);
				attron(COLOR_PAIR(10));
				printw("_");
				attroff(COLOR_PAIR(10));
				attroff(A_BOLD);
			break;
			case '1' :
				attron(A_BOLD);
				attron(COLOR_PAIR(10));
				printw("|");
				attroff(COLOR_PAIR(10));
				attroff(A_BOLD);
			break;
			case '6' :
				attron(A_BOLD);
				attron(COLOR_PAIR(10));
				printw("(");
				attroff(COLOR_PAIR(10));
				attroff(A_BOLD);
			break;
			case '9' :
				attron(A_BOLD);
				attron(COLOR_PAIR(10));
				printw(")");
				attroff(COLOR_PAIR(10));
				attroff(A_BOLD);
			break;
			case '7' :
				attron(A_BOLD);
				attron(COLOR_PAIR(10));
				printw("/");
				attroff(COLOR_PAIR(10));
				attroff(A_BOLD);
			break;
			case '4' :
				attron(A_BOLD);
				attron(COLOR_PAIR(10));
				printw("\\");
				attroff(COLOR_PAIR(10));
				attroff(A_BOLD);
			break;
			
			
			default :
				printw("%c",c);
			break;
		}
	}
	fclose(fp); // fermeture du fichier

	return 1;
}


/*
char ** allocCarApocalypse(int nb_l, int nb_c){
	int i;
	char **mat;

	mat = malloc (nb_l*sizeof(char*));//pour remplir la matrice de 0

	for (i=0; i<nb_l; i++){
		mat[i] = malloc (nb_c*sizeof(char));//idem pour les colonne
	}
	return mat;
}

void freeCarApocalypse (char **mat, int nb_l){
	int i;

	for (i=0; i<nb_l; i++){
		free (mat[i]);
		mat[i] = NULL;
	}
	free(mat);
	mat=NULL;
}

WINDOW *screenSetUpCarApocalypse(int nb_l, int nb_c, int y, int x){
	//configuration de ncurses et l'écran
	initscr();
	WINDOW *w = newwin(nb_l, nb_c, y, x);
	cbreak();
	nodelay(w, TRUE);
	start_color();
	noecho();
	refresh();
	curs_set(0);

	return w;
}


void loadingCarApocalypse(int nb_l, int nb_c, char **mat){
	int i,j ;

	FILE *fichCar;
	fichCar = fopen("./files/CarScreenApocalypse.txt", "r");

	for (i=0; i<nb_l; i++){
		for (j=0; j<nb_c; j++){
				fscanf(fichCar, "%c", &(mat[i][j]));
		}
	}
	fclose(fichCar);
}

//nb_l = 4
//nb_c = 14
//y = 110
//x =62

void printCarApocalypse(int nb_l, int nb_c, char **mat, WINDOW *car, int *y, int *x){
		for (int i=0; i<nb_l; i++) {
			for (int j=0; j<nb_c; j++){
				if (*y+j > 110 && *y+j < 143) {
					move(*x+i,*y+j);
					//attron(COLOR_PAIR(8));
					printw("%c", mat[i][j]);
					//attroff(COLOR_PAIR(8));
				}
			}
		usleep(DELAY2);//temps minimum entre les refresh
		refresh();
	}

}

*/



