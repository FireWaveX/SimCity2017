all : PROJET

ConfCarMenu.o : Library.h Functions.h ConfCarMenu.c
		gcc -c -Wall ConfCarMenu.c -lncursesw -std=c99

Launcher.o : Library.h Functions.h Launcher.c
		gcc -c -Wall Launcher.c -lncursesw -std=c99

ConfigApocalypse.o : Library.h Functions.h ConfigApocalypse.c
		gcc -c -Wall ConfigApocalypse.c -lncursesw -std=c99

ConfigHelp.o : Library.h Functions.h ConfigHelp.c
		gcc -c -Wall ConfigHelp.c -lncursesw -std=c99

Modes.o : Library.h Functions.h Modes.c
		gcc -c -Wall Modes.c -lncursesw -std=c99

ConfigMenu.o : Library.h Functions.h ConfigMenu.c
		gcc -c -Wall ConfigMenu.c -lncursesw -std=c99

ConfigMap.o : Library.h Functions.h ConfigMap.c 
		gcc -c -Wall ConfigMap.c -lncursesw -std=c99

Car.o : Library.h Functions.h Car.c
		gcc -c -Wall Car.c -lncursesw -std=c99
		
CarBot.o : Library.h Functions.h CarBot.c 
		gcc -c -Wall CarBot.c -lncursesw -std=c99
		
Lights.o : Library.h Functions.h Lights.c
		gcc -c -Wall Lights.c -lncursesw -std=c99
				
Tramway.o : Library.h Functions.h Tramway.c 
		gcc -c -Wall Tramway.c -lncursesw -std=c99

Main.o : Functions.h Main.c 
		gcc -c -Wall Main.c -lncursesw -std=c99
		
PROJET : ConfCarMenu.o ConfigMenu.o Launcher.o ConfigHelp.o ConfigApocalypse.o Modes.o ConfigMap.o Car.o CarBot.o Lights.o Tramway.o Main.o
		gcc -o PROJET ConfCarMenu.o Launcher.o ConfigHelp.o ConfigApocalypse.o Modes.o ConfigMenu.o ConfigMap.o Car.o CarBot.o Lights.o Tramway.o Main.o -lncursesw -std=c99

EXECUTION :
		./PROJET
	

