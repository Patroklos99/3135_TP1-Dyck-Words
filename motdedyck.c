#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define TAILLE_MOT 40
#define USAGE "\
Usage: %s [HEIGHT,AREA] <LETTER 1> <LETTER 2> <WORD>\n\
\n\
Draws on an ASCII path of dycks word. The dycks word is provided on stdin and\n\
the result is printed on stdout. The length of the word must not exceed 40 characters.\n\
\n\
If no argument is provided, the program prints this help and exit.\n\
\n\
Program parameters :\n\
  HEIGHT                    Optional parameter to calculate the height of the\n\
                            path under the word of dyck.\n\
  AREA                      Optional parameter to calculate the height of\n\
                            the path under the word of dyck.\n\
  LETTER 1, LETTER 2        Define the alphabet of the word.\n\
  WORD                      Word of dyck to draw.\n\
  "


struct motDeDyck {
    char mot[TAILLE_MOT];   //Le mot saisi
    char haut;              //Caractere ascendant
    char bas;               //Caractere descendant
};

enum error {
    OK                          = 0,
    ERREUR_ARGUMENTS_INVALIDES  = 1,
    ERREUR_DONNEES_INVALIDES    = 2,
    ERREUR_MOT_TROP_LONG        = 3,
    ERREUR_LETTRE_INTERDITE     = 4,
    ERREUR_MOT_NON_EQUILIBRE    = 5
};

int main(int argc, char *argv[]) {
    printf("Hello world\n"); 	
    return 0;

    char arr[100];
    int q = 0;
    int w = 0;
    char un[3];
    char deux[3];
    char trois[40];
    int pos;
    int x = 0;
    int y = 0;
    int max = -1;

    fgets(arr, 100, stdin);
    sscanf(arr, "%s %s %s", &un, &deux, &trois);

    for (int k = 0; trois[k]; k++) {
        if (trois[k] == un[1]) {
            q++;
        } else {
            w++;
        }
    }
}
