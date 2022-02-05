#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define TAILLE_MOT 80
#define TAILLE_CHAR 3
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

typedef struct {
    char mot[TAILLE_MOT];   //Le mot saisi
    char charUn[TAILLE_CHAR];              //Caractere ascendant
    char charDeux[TAILLE_CHAR];               //Caractere descendant
    bool valeur;

} motDeDyck;

enum error {
    OK = 0,
    ERREUR_ARGUMENTS_INVALIDES = 1,
    ERREUR_DONNEES_INVALIDES = 2,
    ERREUR_MOT_TROP_LONG = 3,
    ERREUR_LETTRE_INTERDITE = 4,
    ERREUR_MOT_NON_EQUILIBRE = 5
};


bool validerLettre(const char *nombre, const char *un, const char *deux, bool valeur) {

    for (int i = 0; nombre[i] != '\0'; ++i) {
        if (nombre[i] != un[0] && nombre[i] != deux[0]) {
            valeur = false;
            printf("lettre interdite\n");
            break;
        }
    }
    return valeur;
}

void validerEquilibre(bool valeur, const char *nombre, const char *un) {
    int nbCharUn = 0;
    int nbCharDeux = 0;

    if (valeur) {
        for (int k = 0; nombre[k]; k++) {
            nombre[k] == un[0] ? nbCharUn++ : nbCharDeux++;
        }
        if (nbCharUn != nbCharDeux) {
            printf("mot non equilibre\n");
            exit(0);
        }
    }
};

void validerEquilibreAxial(int positionX) {
    if (positionX < 0) {
        printf("mot non equilibre\n");
        exit(0);
    }
};

void insererAsterikx(char tab[40][40]) {
    for (int i = 0; i < 40; ++i) {
        for (int j = 0; j < 40; ++j) {
            if (tab[i][j] == '\0') {
                tab[i][j] = '*';
            }
        }
    }
};

void validerArgument(int argc, char **argv, const int *hauteurMax, int aire) {
    if (argc >= 2) {
        if ((argc == 2 || argc == 5) && (strcmp(argv[1], "hauteur") == 0 || strcmp(argv[1], "hauteur") == 0)) {
            printf("%d\n", *hauteurMax);
            exit(0);
        } else if ((argc == 2 || argc == 5) && (strcmp(argv[1], "aire") == 0 || strcmp(argv[1], "aire") == 0)) {
            printf("%d\n", aire);
            exit(0);
        } else if ((argc == 2 || argc == 5) && (strcmp(argv[1], "hauteur") != 0 || strcmp(argv[1], "aire") != 0)) {
            printf("argument invalide\n");
            exit(0);
        }
    }
};

void afficherAscii(int argc, const int *hauteurMax, int psitionY, char tab[40][40]) {
    if (argc == 1 || argc == 4) {
        for (int i = *hauteurMax - 1; i >= 0; --i) {
            for (int j = 0; j < psitionY; ++j) {
                printf("%c", tab[i][j]);
            }
            printf("\n");
        }
    }
};

void validerDonnees(int argc, motDeDyck motDeDyck1) {
    if (strlen(motDeDyck1.charUn) != 1 || strlen(motDeDyck1.charDeux) != 1 || motDeDyck1.mot[0] == 0 ||
        motDeDyck1.charUn[0] == motDeDyck1.charDeux[0]
        || argc == 3 || argc > 5) {
        printf("donnees invalides\n");
        exit(0);
    }
};

void insererBarres(motDeDyck motDeDyck1, char tab[40][40], int *hauteurMax, int *aire, int *psitionY) {
    int positionX = 0;
    int positionY = 0;

    for (int i = 0; motDeDyck1.mot[i] != '\0'; ++i) {
        if (motDeDyck1.mot[i] == motDeDyck1.charUn[0]) {
            tab[positionX][positionY] = '/';
            positionX++;
            positionY++;
        } else {
            positionX--;
            tab[positionX][positionY] = '\\';
            positionY++;
        }
        if (*hauteurMax < positionX)
            *hauteurMax = positionX;
        validerEquilibreAxial(positionX);
        *aire += positionX;
    }
    *psitionY = positionY;
}

bool validerLongueurMot(motDeDyck motDeDyck1) {
    bool validation = false;
    strlen(motDeDyck1.mot) <= 40 ? validation = true : printf("mot trop long\n");
    return validation;
}

void distribuerEntrees_Args(char *motDeDyckUn, char *motDeDyckDeux, char *motDeDyckTrois, int argc, char **argv) {
    int pos;
    char arr[100];

    pos = ftell(stdin);
    fseek(stdin, 0, SEEK_END);
    if (pos - ftell(stdin)) {
        rewind(stdin);
        fgets(arr, 100, stdin);
        sscanf(arr, "%s %s %s", motDeDyckUn, motDeDyckDeux, motDeDyckTrois);
    } else if (argc == 4) {
        strcpy((char *) motDeDyckUn, argv[1]);
        strcpy((char *) motDeDyckDeux, argv[2]);
        strcpy((char *) motDeDyckTrois, argv[3]);
    } else if (argc == 5) {
        strcpy((char *) motDeDyckUn, argv[2]);
        strcpy((char *) motDeDyckDeux, argv[3]);
        strcpy((char *) motDeDyckTrois, argv[4]);
    } else if (argc == 1) {
        printf(USAGE, "./motdedyck");
        exit(0);
    }
}

int main(int argc, char *argv[]) {
    motDeDyck motDeDyck1 = {{0}, {0}, {0}, true};

    int psitionY = 0;
    int hauteurMax = -1;
    int aire = 0;
    char tab[40][40] = {0};

    distribuerEntrees_Args((char *) &motDeDyck1.charUn, (char *) &motDeDyck1.charDeux, (char *) &motDeDyck1.mot, argc, argv);
    validerDonnees(argc, motDeDyck1);
    if (validerLongueurMot(motDeDyck1)) {
        if (validerLettre(motDeDyck1.mot, motDeDyck1.charUn, motDeDyck1.charDeux, motDeDyck1.valeur)) {
            insererBarres(motDeDyck1, tab, &hauteurMax, &aire, &psitionY);
            validerEquilibre(motDeDyck1.valeur, motDeDyck1.mot, motDeDyck1.charUn);
            insererAsterikx(tab);
            validerArgument(argc, argv, &hauteurMax, aire);
            afficherAscii(argc, &hauteurMax, psitionY, tab);
        }
    }
    return 0;
}



