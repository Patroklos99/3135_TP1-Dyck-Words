# TP1: Chemins de Dyck


## Format Markdown (supprimer cette section avant la remise)

Sauter une ligne pour changer de paragraphe.

Mettre les noms de fichier et bout de code courts entre apostrophes inversés.
Par exemple, si vous parlez du fichier `Makefile`.

Mettre les longs bouts de code dans des blocs de code (triples apostrophes
inversés). Par exemple, vous pouvez donner un exemple de commande comme suit:

```sh
$ make
$ ls -a
```

Utiliser des listes à puces ou des énumérations le plus possible (plus agréable
à lire). Par exemple, pour décrire le contenu du projet:

* `README.md`: ce fichier
* `Makefile`: permet d'automatiser la compilation
* etc.

Bien aérer le contenu du fichier source (`README.md`). Éviter les longues
lignes dans le fichier Markdown (par exemple, limiter à 80) pour une meilleure
lisibilité avec un éditeur de texte.

## Description

Projet d'introduction au langage C. Ce projet demande des entrées par stdin et des arguments.
Fait l'affichage d'une image ASCII, de l'hauteur, de l'aire ou du manuel d'usage.

Les entrées demandées par stdin seront transmises à travers un fichier entree.txt ou en tant
qu'arguments.
Les seuls arguments acceptés sont l'hauteur et l'aire. Ils sont generés uniquement en ecrivant 
le mot `hauteur` et le mot `aire`.

Ce travail est realisé en vue du travail TP1 dans le cadre du cours Construction et
maintenance de logiciels INF3135. Cours donné par Serge Dogny à l'Université de Québec à Montreal.

Lien vers le [sujet du travail](https://gitlab.info.uqam.ca/salcedo_salcedo.renzo/h22-inf3135-tp1/-/blob/master/sujet.md).

## Auteur

Renzo Arturo Salcedo (SALR02089408).

## Fonctionnement

Premierement compiler le fichier `motdedyck.c`. 
Vous obtiendrez l'exécutable `motdedyck`. 

Deuxièmement ecrivez les entrées par la ligne de commande (i.e `./motdedyck a b aabb`)
ou par rédirection en les plaçants dans un fichier `.txt`. Ecrivez `hauteur` ou `aire` après 
`./motdedyck` si vous voulez obtenir leurs valeurs respectives.

Voici les regles à respecter pour pour vos entrées:
* `Format:` ./motdedyck [HEIGHT,AREA] <LETTER 1> <LETTER 2> <WORD>
* Les des 2 caractères et le mot sont obligatoires.
* Les deux caractères doivent être différentes.
* le mot a une taille de plus de 40 caractères.
* Le mot peut être composé uniquement des deux premieres caractères donnés.
* Le deux caractères ont exactement le même nombre d'occurrences.
* Le 1er caractère a une valeur de +1 et le 2ieme a une valeur de -1, il est donc interdit
que la valeur soit en dessous de l'axe des Y. (i.e abba).
* Seuls les arguments `hauteur` ou `aire` sont acceptés.
* Pour obtenir le manuel du programme, exécutez `./motdedyck` uniquement.

Voici une suite de tests valides comme exemples (stdin sur la ligne de commande commme arg) :
```
$ gcc -o motdedyck -Wall -Wextra -std=c11 
$ ./motdedyck a b aabb
$ ./motdedyck hauteur a b aabb
$ ./motdedyck aire a b aabb
$ ./motdedyck
```
Voici une suite de tests valides comme exemple: (par redirection)
```
$ echo "a b aabb" > entree.txt
$ ./motdedyck < entree.txt
$ ./motdedyck hateur < entree.txt
$ ./motdedyck aire < entree.txt
$ /motdedyck
```

souhaite saisir une série de commandes pour l'exécuter). En particulier,
indiquez les commandes qui doivent être entrées pour la compilation et
l'exécution.

## Tests

Pour lancer les tests vous devez ecrire `make test` sur la ligne de commande.
Vous obtiendrez les resultats du fichier `check.bats`, qui vous informera de vos tests réussis et ceux 
échoués.

Si vous n'avez pas le fichier `motdedyck` avant de lancer cette commande, la 
commande `gcc -o motdedyck -Wall -Wextra -std=c11 motdedyck.c` sera lancée en parellèle et 
un fichier `motdedyck`sera créé automatiquement. Il est possible aussi qu'un fichier 
`motdedyck.o` soit créé.

## Dépendances

Indiquez les dépendances du projet, avec lien officiel. Il faudrait au moins
mentionner GCC et [Bats](https://github.com/bats-core/bats-core). Utiliser une
liste à puces pour donner la liste des dépendances.

## Références

De facon générale le site [Stackoverflow](https://stackoverflow.com/) a été utilisé pour la 
compréhension et utilisation des methodes pour le `STDIN`. 
Des discussions sur le mattermost du cours ont servi d'inspiraton dans ce travail.

## État du projet

* [X] Le nom du dépôt GitLab est exactement `h22-inf3135-tp1` (Pénalité de
  **50%**).
* [X] L'URL du dépôt GitLab est exactement `https://gitlab.info.uqam.ca/utilisateur/h22-inf3135-tp1`
https://gitlab.info.uqam.ca/salcedo_salcedo.renzo/h22-inf3135-tp1
  (Pénalité de **50%**).
* [X] L'utilisateur `dogny_g` a accès au projet en mode *Developer*
  (Pénalité de **50%**).
* [ ] Les correcteurs ont accès au projet en mode *Developer* (`id`à venir)
* [X] Le dépôt GitLab est un *fork* de [ce
  dépôt](https://gitlab.info.uqam.ca/inf3135-sdo/h22-inf3135-tp1)
  (Pénalité de **50%**).
* [X] Le dépôt GitLab est privé (Pénalité de **50%**).
* [X] Le dépôt contient au moins un fichier `.gitignore`.
* [X] Le fichier `Makefile` permet de compiler le projet lorsqu'on entre
  `make`. Il supporte les cibles `html`, `test` et `clean`.
* [ ] Le nombre de tests qui réussissent/échouent avec la `make test` est
  indiqué quelque part dans le fichier `README.md`.
* [ ] Les sections incomplètes de ce fichier (`README.md`) ont été complétées.
* [ ] L'en-tête du fichier est documentée.
* [ ] L'en-tête des déclarations des fonctions est documentée (*docstring*).
* [X] Le programme ne contient pas de valeurs magiques.
