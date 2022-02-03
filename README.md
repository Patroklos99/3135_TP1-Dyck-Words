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
Fait l'affichage d'une image ASCII, l'hauteur, de l'aire ou du manuel d'usage.

Les entrées demandées par stdin seront transmises à travers un fichier entree.txt ou en tant
qu'arguments
Les seuls arguments acceptés sont l'hauteur et l'aire. Ils sont generés uniquement en ecrivant 
le mot `hauteur ` et le mot `aire`.

Ce travail est realisé en vue du travail TP1 dans le cadre du cours Construction et
maintenance de logiciels INF3135. Cours donné par Serge Dogny à l'Université de Québec à Montreal.

Lien vers le [sujet du travail](https://gitlab.info.uqam.ca/salcedo_salcedo.renzo/h22-inf3135-tp1/-/blob/master/sujet.md).

## Auteur

Renzo Arturo Salcedo (SALR02089408).

## Fonctionnement

Premierement assemblez et compiler le fichier `motdedyck.c`. 
Vous obtiendrez l'exécutable `motdedyck`. 

Deuxièmement ajoutez les entrees par la ligne de commande en les écrivant `./motdedyck a b aabb`
ou par rédirection en les plaçants dans un fichier .txt 

Expliquez d'abord en mots comment faire fonctionner le projet (imaginez que la
personne qui l'utilisera ne connaît pas C, ne connaît pas le projet et souhaite
seulement saisir une série de commandes pour l'exécuter). En particulier,
indiquez les commandes qui doivent être entrées pour la compilation et
l'exécution.

## Tests

Pour lancer les tests vous devez ecrire `make test` sur la ligne de commande.
Vous obtiendrez les resultats du fichier `check.bats`, qui vous informera de vos tests réussis et ceux 
échoués.

Si vous n'avez pas le fichier `motdedyck` avant de lancer cette commande, la 
commande `gcc -o motdedyck -Wall -Wextra -std=c11 motdedyck.c` sera lancée et 
un fichier `motdedyck`sera créé automatiquement. Il est possible aussi qu'un fichier 
`motdedyck.o` soit créé.

## Dépendances

Indiquez les dépendances du projet, avec lien officiel. Il faudrait au moins
mentionner GCC et [Bats](https://github.com/bats-core/bats-core). Utiliser une
liste à puces pour donner la liste des dépendances.

## Références

Indiquez ici les références que vous avez utilisées pour compléter le projet,
avec l'hyperlien vers la référence. Pas besoin de mentionner les diapositives
du cours, mais si vous avez eu recours à un site d'aide, un fragment de code ou
une discussion sur un forum, mentionnez-le.

## État du projet

Indiquez toutes les tâches qui ont été complétés en insérant un `X` entre les
crochets. Si une tâche n'a pas été complétée, expliquez pourquoi (lors de la
remise, vous pouvez supprimer ce paragraphe).

* [ ] Le nom du dépôt GitLab est exactement `h22-inf3135-tp1` (Pénalité de
  **50%**).
* [ ] L'URL du dépôt GitLab est exactement (remplacer `utilisateur` par votre
  nom identifiant GitLab) `https://gitlab.info.uqam.ca/utilisateur/h22-inf3135-tp1`
  (Pénalité de **50%**).
* [ ] L'utilisateur `dogny_g` a accès au projet en mode *Developer*
  (Pénalité de **50%**).
* [ ] Les correcteurs ont accès au projet en mode *Developer* (`id`à venir)
* [ ] Le dépôt GitLab est un *fork* de [ce
  dépôt](https://gitlab.info.uqam.ca/inf3135-sdo/h22-inf3135-tp1)
  (Pénalité de **50%**).
* [ ] Le dépôt GitLab est privé (Pénalité de **50%**).
* [ ] Le dépôt contient au moins un fichier `.gitignore`.
* [ ] Le fichier `Makefile` permet de compiler le projet lorsqu'on entre
  `make`. Il supporte les cibles `html`, `test` et `clean`.
* [ ] Le nombre de tests qui réussissent/échouent avec la `make test` est
  indiqué quelque part dans le fichier `README.md`.
* [ ] Les sections incomplètes de ce fichier (`README.md`) ont été complétées.
* [ ] L'en-tête du fichier est documentée.
* [ ] L'en-tête des déclarations des fonctions est documentée (*docstring*).
* [ ] Le programme ne contient pas de valeurs magiques.
