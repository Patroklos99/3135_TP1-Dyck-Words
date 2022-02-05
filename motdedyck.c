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
    bool valeur;           //valeur de vérité du mot.

} motDeDyck;

enum error {
    OK = 0,
    ERREUR_ARGUMENTS_INVALIDES = 1,
    ERREUR_DONNEES_INVALIDES = 2,
    ERREUR_MOT_TROP_LONG = 3,
    ERREUR_LETTRE_INTERDITE = 4,
    ERREUR_MOT_NON_EQUILIBRE = 5
};

/*
 * Valide que le mot contient seulement les deux caractères données.
 *
 * @param motDeDyck1 reference vers structure contenant les variables requises.
 * @return valeur booleenne de l'operation
 * */
bool validerLettre(motDeDyck motDeDyck1) {
    for (int i = 0; motDeDyck1.mot[i] != '\0'; ++i) {
        if (motDeDyck1.mot[i] != motDeDyck1.charUn[0] && motDeDyck1.mot[i] != motDeDyck1.charDeux[0]) {
            motDeDyck1.valeur = false;
            printf("lettre interdite\n");
            break;
        }
    }
    return motDeDyck1.valeur;
}

/*
 * Valide l'equilibre du mot selon le nb d'occurrences des 2 caractères. Affiche l'erreur
 * assignée et arrête le programme si le mot est non equilibré.
 *
 * @param motDeDyck1 reference vers structure contenant les variables requises.
 * */
void validerEquilibre(motDeDyck motDeDyck1) {
    int nbCharUn = 0;
    int nbCharDeux = 0;

    if (motDeDyck1.valeur) {
        for (int k = 0; motDeDyck1.mot[k]; k++) {
            motDeDyck1.mot[k] == motDeDyck1.charUn[0] ? nbCharUn++ : nbCharDeux++;
        }
        if (nbCharUn != nbCharDeux) {
            printf("mot non equilibre\n");
            exit(0);
        }
    }
};

/*
 * Valide l'equilibre du mot selon la valeur axialle Y. Affiche l'erreur et arrête le programme
 * si le mot n'est pas equilibré.
 *
 * @param positionY Valeur continue de Y par rapport au son seuil 0.
 * */
void validerEquilibreAxial(int positionY) {
    if (positionY < 0) {
        printf("mot non equilibre\n");
        exit(0);
    }
};

/*
 * Insere des asteriques dans les cases vides de l'array 2D
 *
 * @param tab Array 2d de [40]x[40].
 * */
void insererAsterikx(char tab[40][40]) {
    for (int i = 0; i < 40; ++i) {
        for (int j = 0; j < 40; ++j) {
            if (tab[i][j] == '\0') {
                tab[i][j] = '*';
            }
        }
    }
};

/*
 * Valide les arguments recus par le programme. Affiche la hauteur ou l'aire ou arrête le programme
 * si l'argument est invalide.
 *
 * @param argc nb d'arguments.
 * @param **argc pointeur du tableau contenant les arguments.
 * @param hauteurMax valeur de l'hauteur de l'image ASCII.
 * @param aire valeur de l'aire sous la courbe de l'image ASCII.
 * */
void validerArgument(int argc, char **argv, const int hauteurMax, int aire) {
    if (argc >= 2) {
        if ((argc == 2 || argc == 5) && (strcmp(argv[1], "hauteur") == 0 || strcmp(argv[1], "hauteur") == 0)) {
            printf("%d\n", hauteurMax);
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

/*
 * Affiche une partie du tableau 2D à partir des coordonnées hauteurMax (longueur) * psitionY (largeur)
 *
 * @param hauteurMax valeur de l'hauteur de l'image ASCII.
 * @param psitionY valeur de la largeur max l'image.
 * @param tab Array 2d de [40]x[40].
 * */
void afficherAscii(const int hauteurMax, int psitionY, char tab[40][40]) {
    for (int i = hauteurMax - 1; i >= 0; --i) {
        for (int j = 0; j < psitionY; ++j) {
            printf("%c", tab[i][j]);
        }
        printf("\n");
    }
};

/*
 * Valide les 3 exigences pour les données. Affiche l'erreur correspondante et arrête le programme si il y a des
 * données invalides.
 *
 * @param argc nb d'arguments.
 * @param motDeDyck1 reference vers structure contenant les variables requises.
 * */
void validerDonnees(int argc, motDeDyck motDeDyck1) {
    if (strlen(motDeDyck1.charUn) != 1 || strlen(motDeDyck1.charDeux) != 1 || motDeDyck1.mot[0] == 0 ||
        motDeDyck1.charUn[0] == motDeDyck1.charDeux[0] || argc == 3 || argc > 5) {
        printf("donnees invalides\n");
        exit(0);
    }
};

/*
 * Insere les caractères / ou \ dans leur coordonnée correspondante.
 *
 * @param motDeDyck1 reference vers structure contenant les variables requises.
 * @param tab Array 2d de [40]x[40].
 * @param *hauteurMax pointeur pour le calcul et sauvegarde de cette variable.
 * @param *aire pointeur pour le calcul et sauvegarde de cette variable.
 * @param *psitionY pointeur pour la sauvegarde de la nouvelle valeur.
 * */
void insererBarres(motDeDyck motDeDyck1, char tab[40][40], int *hauteurMax, int *aire, int *psitionY) {
    int positionX = 0;
    int positionY = 0;

    for (int i = 0; motDeDyck1.mot[i] != '\0'; ++i) {
        if (motDeDyck1.mot[i] == motDeDyck1.charUn[0]) {
            tab[positionY][positionX] = '/';
            positionY++;
            positionX++;
        } else {
            positionY--;
            tab[positionY][positionX] = '\\';
            positionX++;
        }
        if (*hauteurMax < positionY)
            *hauteurMax = positionY;
        validerEquilibreAxial(positionY);
        *aire += positionY;
    }
    *psitionY = positionX;
}

/*
 * Valide la longueur du mot de Dyck. Affiche l'erreur si le mot est trop long.
 *
 * @param motDeDyck1 reference vers structure contenant la variable requise.
 * return la valeur de verité correspondate.
 * */
bool validerLongueurMot(motDeDyck motDeDyck1) {
    bool validation = false;
    strlen(motDeDyck1.mot) <= 40 ? validation = true : printf("mot trop long\n");
    return validation;
}

/*
 * Distribue les arguments ou entrées redirectionnées, vers leur variable correspondate, selon la forme des
 * qu'ils sont soumis. Affiche le manuel si aucun argument/entrée sont soumis à l'exécution et arrête le programme.
 *
 * @param *mddCharUn pointeur vers l'attribut charUn de la variable motDeDyck1
 * @param *mddCharDeux pointeur vers l'attribut charDeux de la variable motDeDyck1
 * @param *mddMot pointeur vers l'attribut mot de MotDeDyck1 de la variable motDeDyck1
 * @param argc nb d'arguments.
 * @param **argc pointeur vers pointeur du tableau contenant les arguments.
 * */
void distribuerEntrees_Args(char *mddCharUn, char *mddCharDeux, char *mddMot, int argc, char **argv) {
    int pos;
    char arr[100];

    pos = ftell(stdin);
    fseek(stdin, 0, SEEK_END);
    if (pos - ftell(stdin)) {
        rewind(stdin);
        fgets(arr, 100, stdin);
        sscanf(arr, "%s %s %s", mddCharUn, mddCharDeux, mddMot);
    } else if (argc == 4) {
        strcpy((char *) mddCharUn, argv[1]);
        strcpy((char *) mddCharDeux, argv[2]);
        strcpy((char *) mddMot, argv[3]);
    } else if (argc == 5) {
        strcpy((char *) mddCharUn, argv[2]);
        strcpy((char *) mddCharDeux, argv[3]);
        strcpy((char *) mddMot, argv[4]);
    } else if (argc == 1) {
        printf(USAGE, "./motdedyck");
        exit(0);
    }
}

/*
 * Méthode main, lance tous les sous-methodes correspondate.
 *
 * @param argc nb d'arguments.
 * @param *argc pointeur du tableau contenant les arguments.
 * */
int main(int argc, char *argv[]) {
    motDeDyck motDeDyck1 = {{0}, {0}, {0}, true};

    int psitionY = 0;
    int hauteurMax = -1;
    int aire = 0;
    char tab[40][40] = {0};

    distribuerEntrees_Args((char *) &motDeDyck1.charUn, (char *) &motDeDyck1.charDeux,
                           (char *) &motDeDyck1.mot, argc, argv);
    validerDonnees(argc, motDeDyck1);
    if (validerLongueurMot(motDeDyck1)) {
        if (validerLettre(motDeDyck1)) {
            insererBarres(motDeDyck1, tab, &hauteurMax, &aire, &psitionY);
            validerEquilibre(motDeDyck1);
            insererAsterikx(tab);
            validerArgument(argc, argv, hauteurMax, aire);
            afficherAscii(hauteurMax, psitionY, tab);
        }
    }
    return 0;
}

