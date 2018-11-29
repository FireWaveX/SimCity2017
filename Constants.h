
		/*** Special symbols ***/
#define SYM1 9474		// │ 
#define SYM2 166		// ¦ 
#define SYM3 10145		// ➡ 
#define SYM4 11013		// ⬅
#define SYM5 11014		// ⬆
#define SYM6 11015		// ⬇
#define SYM7 9472    	// ─
#define SYM8 5535756984 // 🚘
#define SYM9 92   // anti-/

//#define SYM8 U+1F6A6 // 🚦

#define DELAY 800
//#define DELAY2 3000

		/*** Hidden symbols ***/
#define HIDN1 554 	// *
#define HIDN2 555   // +


		/*** Colors ***/
#define ANSI_COLOR_BLACK     "\x1b[31m"
#define ANSI_COLOR_RESET     "\x1b[0m"

		/*** Spawners of car ***/
#define MAX     9
//#define SPAWN1  14,1,'d'
#define SPAWN2  15,1,'d'
#define SPAWN3  1,33,'b'
#define SPAWN4  1,133,'b'
#define SPAWN5  1,178,'b'
#define SPAWN6  11,263,'g'
//#define SPAWN7  12,263,'g'
#define SPAWN8  84,182,'h'
#define SPAWN9  84,137,'h'
#define SPAWN10 84,79,'h'
#define SPAWN11 45,1,'d'

		/*** lights for cars ***/
#define LIGHT 	64 	//@
#define RED 	10816
#define GREEN 	11072
#define ORANGE 	11328


		/*** Spawners of tram ***/
#define SPAWN12 154,1,'b'
#define SPAWN13 161,85,'h' 


		/*** list of red lights ***/
#define MAX_R     8
#define LIGHT_R_1 7,31
#define LIGHT_R_2 19,39
#define LIGHT_R_3 7,131
#define LIGHT_R_4 7,176
#define LIGHT_R_5 19,139
#define LIGHT_R_6 19,184
#define LIGHT_R_7 39,31
#define LIGHT_R_8 46,126

		/*** list of green lights ***/
#define MAX_G     10
#define LIGHT_G_1 10,45
#define LIGHT_G_2 16,25
#define LIGHT_G_3 16,125
#define LIGHT_G_4 16,150
#define LIGHT_G_5 10,166
#define LIGHT_G_6 10,190
#define LIGHT_G_7 42,40
#define LIGHT_G_8 46,30
#define LIGHT_G_9 39,131
#define LIGHT_G_10 47,139

		/*** Dirrections ***/
#define DIRR1_2 "dhhhh"
#define DIRR1_3 "dddhhhh"
#define DIRR1_4 "dddddhhhh"
#define DIRR1_5 "dddddd"
#define DIRR1_6 "ddddb"
#define DIRR1_7 "ddbbbbb"
#define DIRR1_8 "bbddbbb"
#define DIRR1_9 "bg"

#define DIRR2_1 "g"
#define DIRR2_3 "bbdddhhh"
#define DIRR2_4 "bbdddddhhh"
#define DIRR2_5 "bbbddddd"
#define DIRR2_6 "bbbddddb"
#define DIRR2_7 "bbbddbbbbb"
#define DIRR2_8 "bbbbbddbbb"
#define DIRR2_9 "bbbbg"

#define DIRR3_1 "ggg"
#define DIRR3_2 "gh"
#define DIRR3_4 "bbdddhhh"
#define DIRR3_5 "bbdddd"
#define DIRR3_6 "bbbddb"
#define DIRR3_7 "bbbbbbbb"
#define DIRR3_8 "bbbbggbbbb"
#define DIRR3_9 "bbbbggggg"

#define DIRR4_1 "bggggg"
#define DIRR4_2 "gggh"
#define DIRR4_3 "gh"
#define DIRR4_5 "bbdd"
#define DIRR4_6 "bbbb"
#define DIRR4_7 "bggbbbbbbb"
#define DIRR4_8 "bggbbbggbbbb"
#define DIRR4_9 "bggbbbggggg"

#define DIRR5_1 "gggggg"
#define DIRR5_2 "ggggh"
#define DIRR5_3 "ggh"
#define DIRR5_4 "h"
#define DIRR5_6 "gbbbb"
#define DIRR5_7 "bgggbbbbbbb"
#define DIRR5_8 "bgggbbbggbbbb"
#define DIRR5_9 "bgggbbbggggg"

#define DIRR6_1 "hhhgggggg"
#define DIRR6_2 "hhhggggh"
#define DIRR6_3 "hhhggh"
#define DIRR6_4 "hhhhh"
#define DIRR6_5 "d"
#define DIRR6_7 "hhgggbbbbbbb"
#define DIRR6_8 "hhgggbbbggbbb"
#define DIRR6_9 "hhgggbbbggggg"

#define DIRR7_1 "hhhhhhhgggg"
#define DIRR7_2 "hhhhhhhggh"
#define DIRR7_3 "hhhhhhhh"
#define DIRR7_4 "hhhhhddhhh"
#define DIRR7_5 "hhhhhdddd"
#define DIRR7_6 "hhhhdb"
#define DIRR7_8 "hgggbb"
#define DIRR7_9 "hhhggggg"

#define DIRR8_1 "hhhgghhhhg"
#define DIRR8_2 "hhhgghhhhhh"
#define DIRR8_3 "hhddhhhhhh"
#define DIRR8_4 "hhddhhhddhhh"
#define DIRR8_5 "hhddhhhddd"
#define DIRR8_6 "hhddhhdb"
#define DIRR8_7 "db"
#define DIRR8_9 "hhhgggg"

#define DIRR9_1 "dhhhhgg"
#define DIRR9_2 "ddhhhhhh"
#define DIRR9_3 "dhhhddhhh"
#define DIRR9_4 "dhhhddddhhh"
#define DIRR9_5 "dhhddddd"
#define DIRR9_6 "dhhdddb"
#define DIRR9_7 "ddbbddb"
#define DIRR9_8 "ddbbb"

//Un foreach pour le C ^^ 
#define foreach(item, array); \
    for(int keep = 1, \
            count = 0,\
            size = sizeof (array) / sizeof *(array); \
        keep && count != size; \
        keep = !keep, count++) \
      for(item = (array) + count; keep; keep = !keep)
