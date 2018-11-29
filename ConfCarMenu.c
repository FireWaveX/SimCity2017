
#include "Library.h"
#include "Functions.h"



char ** allocCarMenu(int nb_l, int nb_c){
	int i;
	char **mat;

	mat = malloc (nb_l*sizeof(char*));//pour remplir la matrice de 0

	for (i=0; i<nb_l; i++){
		mat[i] = malloc (nb_c*sizeof(char));//idem pour les colonne
	}
	return mat;
}

void freeCarMenu (char **mat, int nb_l){
	int i;

	for (i=0; i<nb_l; i++){
		free (mat[i]);
		mat[i] = NULL;
	}
	free(mat);
	mat=NULL;
}

//Fenêtre propre à la voiture du menu
WINDOW *screenSetUpCarMenu(int nb_l, int nb_c, int y, int x){
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


void loadingCarMenu (int nb_l, int nb_c, char **mat){
	int i,j ;

	FILE *fichCar;
	fichCar = fopen("./files/CarMenu.txt", "r");

	for (i=0; i<nb_l; i++){
		for (j=0; j<nb_c; j++){
				fscanf(fichCar, "%c", &(mat[i][j]));
		}
	}
	fclose(fichCar);
}


void printCarMenu (int nb_l, int nb_c, char **mat, WINDOW *car, int *y, int *x){
		for (int i=0; i<nb_l; i++) {
			for (int j=0; j<nb_c; j++){
				if (*y+j > 0 && *y+j < 264) {
					move(*x+i,*y+j);
					attron(COLOR_PAIR(8));
					printw("%c", mat[i][j]);
					attroff(COLOR_PAIR(8));
				}
			}
		usleep(DELAY);//temps minimum entre les refresh
		refresh();
	}
}

