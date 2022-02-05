# TP1: Chemins de Dyck


## Description

Projet d'introduction au langage C. Ce projet demande des entrées par stdin et des arguments.
Fait l'affichage d'une image ASCII, de l'hauteur, de l'aire ou du manuel d'usage.

Les entrées demandées par stdin seront transmises à travers un fichier entree.txt ou en tant
qu'arguments.
Lors d'une redirection les seuls arguments acceptés sont l'hauteur et l'aire. 
Ils sont generés uniquement en ecrivant le mot `hauteur` et le mot `aire`.

*Fichier `Makefile:`*
Il contient la construction de chaque commande make. C'est-à-dire leur cible et leurs
dépendences pour l'exécution correct.

*Commandes make et leur rôle:*
* `make:` Compile le fichier `motdedyck`.
* `make test:` Execute les tests du fichier `check.bats` sur `motdedyck`. Ou Compile 
`motdedyck.c` s'il ne l'est pas encore et execute les tests par la suite.
* `make html:` Convertit `README.md` et `sujet.md` en fichiers html.
* `make clean:` Efface les fichiers `\*.o` et/ou `\*.html` ainsi que tout autre type de fichier
ce trouvant dans le fichier `gitignore`.

Ce travail est realisé en vue du travail TP1 dans le cadre du cours Construction et
maintenance de logiciels INF3135. Cours donné par Serge Dogny à l'Université de Québec à Montreal.

Lien vers le [sujet du travail](https://gitlab.info.uqam.ca/salcedo_salcedo.renzo/h22-inf3135-tp1/-/blob/master/sujet.md).

***Tous les 11 tests ont étés réussis sur ma machine comme sur le serveur Labunix de l'UQAM***

## Auteur

Renzo Arturo Salcedo (SALR02089408).

## Fonctionnement

Pour commencer, compilez le fichier `motdedyck.c` avec la commande:
```sh
$ gcc -o motdedyck -Wall -Wextra -std=c11 motdedyck.c
```
ou
```sh
$ make
```
Vous obtiendrez l'exécutable `motdedyck`. 

Par la suite, ecrivez les entrées sur la ligne de commande (i.e `./motdedyck a b aabb`)
ou par rédirection en les plaçants dans un fichier `.txt`. Ecrivez `hauteur` ou `aire` après 
`./motdedyck` si vous voulez obtenir leurs valeurs respectives.

Voici les regles à respecter pour vos entrées:
* `Format:` ./motdedyck [HEIGHT,AREA] <LETTER 1> <LETTER 2> <\WORD>
* Les des 2 caractères et le mot sont obligatoires.
* Les deux caractères doivent être différents.
* Le mot a une taille maximale de 40 caractères.
* Le mot peut être composé uniquement des deux premiers caractères donnés.
* Les deux caractères ont exactement le même nombre d'occurrences.
* Le 1er caractère a une valeur de +1 et le 2ieme a une valeur de -1, il est donc interdit
que la valeur soit en dessous de l'axe des Y. (i.e `abba`).
* Seuls les arguments `hauteur` ou `aire` sont acceptés.
* Pour obtenir le manuel du programme, exécutez `./motdedyck` uniquement.

Voici une suite de tests valides comme exemple (stdin sur la ligne de commande commme arg):
```sh
$ gcc -o motdedyck -Wall -Wextra -std=c11 ou $ make 
$ ./motdedyck a b aabb
$ ./motdedyck hauteur a b aabb
$ ./motdedyck aire a b aabb
$ ./motdedyck
```
Voici une suite de tests valides comme exemple (par redirection):
```sh
$ echo "a b aabb" > entree.txt
$ gcc -o motdedyck -Wall -Wextra -std=c11 ou $ make
$ ./motdedyck < entree.txt
$ ./motdedyck hauteur < entree.txt
$ ./motdedyck aire < entree.txt
$ ./motdedyck
```

## Tests

Pour lancer les tests ecrivez `make test` sur la ligne de commande.
Vous obtiendrez les résultats du fichier `check.bats`, qui vous informera de vos tests réussis et ceux 
échoués.

Si vous n'avez pas le fichier `motdedyck` avant de lancer cette commande, la 
commande `gcc -o motdedyck -Wall -Wextra -std=c11 motdedyck.c` sera lancée en parellèle et 
un fichier `motdedyck`sera créé automatiquement. 
```sh
$ make test
``` 
Cette commande exécute les tests du fichier `check.bats` sur `motdedyck`. Ou Compile 
`motdedyck.c` s'il ne l'est pas encore et execute les tests par la suite.

## Dépendances

* [GCC](https://gcc.gnu.org/).
* [Bats](https://github.com/bats-core/bats-core).
* [Pandoc](https://pandoc.org/).
* [Make](https://www.gnu.org/software/make/).

## Références

De facon générale le site [Stackoverflow](https://stackoverflow.com/) a été utilisé pour la 
compréhension et utilisation des methodes pour le `STDIN`. 
Des discussions sur le mattermost du cours ont aussi servis d'inspiraton dans ce travail.

## État du projet

* [X] Le nom du dépôt GitLab est exactement `h22-inf3135-tp1` (Pénalité de
  **50%**).
* [X] L'URL du dépôt GitLab est exactement `https://gitlab.info.uqam.ca/utilisateur/h22-inf3135-tp1`
https://gitlab.info.uqam.ca/salcedo_salcedo.renzo/h22-inf3135-tp1
  (Pénalité de **50%**).
* [X] L'utilisateur `dogny_g` a accès au projet en mode *Developer*
  (Pénalité de **50%**).
* [X] Les correcteurs ont accès au projet en mode *Developer* (`id`à venir)
* [X] Le dépôt GitLab est un *fork* de [ce
  dépôt](https://gitlab.info.uqam.ca/inf3135-sdo/h22-inf3135-tp1)
  (Pénalité de **50%**).
* [X] Le dépôt GitLab est privé (Pénalité de **50%**).
* [X] Le dépôt contient au moins un fichier `.gitignore`.
* [X] Le fichier `Makefile` permet de compiler le projet lorsqu'on entre
  `make`. Il supporte les cibles `html`, `test` et `clean`.
* [X] Le nombre de tests qui réussissent/échouent avec la `make test` est
  indiqué quelque part dans le fichier `README.md`.
* [X] Les sections incomplètes de ce fichier (`README.md`) ont été complétées.
* [ ] L'en-tête du fichier est documentée.
* [ ] L'en-tête des déclarations des fonctions est documentée (*docstring*).
* [X] Le programme ne contient pas de valeurs magiques.
