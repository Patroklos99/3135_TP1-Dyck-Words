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
    OK = 0,
    ERREUR_ARGUMENTS_INVALIDES = 1,
    ERREUR_DONNEES_INVALIDES = 2,
    ERREUR_MOT_TROP_LONG = 3,
    ERREUR_LETTRE_INTERDITE = 4,
    ERREUR_MOT_NON_EQUILIBRE = 5
};


bool verifierLettres(const char *nombre, const char *un, const char *deux) {
    bool valeur;
    int p = 0;
    int l = 0;

    for (int i = 0; nombre[i] != '\0'; ++i) {
        if (nombre[i] == un[0] || nombre[i] == deux[0]) {
            valeur = true;
        } else {
            valeur = false;
            break;
        }
    }
    if (valeur) {
        for (int k = 0; nombre[k]; k++) {
            if (nombre[k] == un[0]) {
                p++;
            }
        }
        for (int k = 0; nombre[k]; k++) {
            if (nombre[k] == deux[0]) {
                l++;
            }
        }
        if (p != l) {
            printf("mot non equilibre\n");
            exit(0);
        }

    }
    return valeur;
}

int main(int argc, char *argv[]) {
    char arr[100];
    char un[3] = "\0";
    char deux[3] = "\0";
    char trois[40];
    int pos;
    int x = 0;
    int y = 0;
    int max = -1;


    pos = ftell(stdin);
    fseek(stdin, 0, SEEK_END);
    if (pos - ftell(stdin) ) {
        rewind(stdin);
        fgets(arr, 100, stdin);
        sscanf(arr, "%s %s %s", un, deux, trois);
        //printf("Input: %s\n", arr);
    } else if (argc == 4) {
        un[0] = *argv[1];
        deux[0] = *argv[2];
        strcpy(trois, argv[3]);
    } else if (argc == 5) {
        un[0] = *argv[2];
        deux[0] = *argv[3];
        strcpy(trois, argv[4]);
    } else if (argc == 1) {
        printf(USAGE, "./motdedyck");
        exit(0);
    } else {
        printf("donnees invalides\n");
        exit(0);
    }

    /*fgets(arr, 100, stdin);
    sscanf(arr, "%s %s %s", &un, &deux, &trois);*/

    if (strlen(un) != 1 || strlen(deux) != 1 || trois[0] == 0 || un[0] == deux[0]) {
        printf("donnees invalides\n");
        exit(0);
    }

    if (un[0] == 0 && deux[0] == 0 && trois[0] == 0 && argc == 1) {
        printf("Texte du man\n");
        exit(0);
    }

    if (strlen(trois) <= 40) {
        if (verifierLettres(trois, un, deux)) {
            char tab[100][100];

            for (int i = 0; trois[i] != '\0'; ++i) {
                if (trois[i] == un[0]) {
                    tab[x][y] = '/';
                    x++;
                    y++;
                } else {
                    x--;
                    tab[x][y] = '\\';
                    y++;
                }
                if (max < x) {
                    max = x;
                }
                if (x < 0) {
                    printf("mot non equilibre\n");
                    exit(0);
                }
            }

            for (int i = 0; i < 40; ++i) {
                for (int j = 0; j < 40; ++j) {
                    if (tab[i][j] == '\0') {
                        tab[i][j] = '*';
                    }
                }
            }
            if (argc >= 2) {
                if ((argc == 2 || argc == 5) && (strcmp(argv[1], "hauteur") == 0 || strcmp(argv[1], "hauteur") == 0)) {
                    printf("%d\n", max);
                    exit(0);
                } else if ((argc == 2 || argc == 5) && (strcmp(argv[1], "aire") == 0 || strcmp(argv[1], "aire") == 0)) {
                    int aire = (max * y) / 2;
                    printf("%d\n", aire);
                    exit(0);
                } else if ((argc == 2 || argc == 5) && (strcmp(argv[1], "hauteur") != 0 || strcmp(argv[1], "aire") != 0)) {
                    printf("argument invalide\n");
                    exit(0);
                }
            }
            if (argc == 1 || argc == 4) {
                for (int i = max - 1; i >= 0; --i) {
                    for (int j = 0; j < y; ++j) {
                        printf("%c", tab[i][j]);
                    }
                    printf("\n");
                }
            }

        } else {
            printf("lettre interdite\n");
        }
    } else {
        printf("mot trop long\n");
    }
    return 0;
}


