# Documentation du Code de Benchmark d'Algorithmes de Tri

Cette documentation décrit la finalité et le fonctionnement du code C fourni, utilisé pour évaluer et analyser les performances de divers algorithmes de tri. Le code comprend des algorithmes de tri tels que le Smooth Sort, le Cocktail Sort, le Tri pair-impair, le Quick Sort et le Tri par insertion. Il interagit également avec un script Python pour visualiser les résultats de l'évaluation à l'aide de Gnuplot.

## Table des matières
1. Introduction
2. Descriptions des fonctions et algorithmes
3. Comment utiliser
4. Remarques complémentaires

## 1. Introduction

Le code C fourni est conçu pour évaluer et analyser les performances de cinq algorithmes de tri différents : le Smooth Sort, le Cocktail Sort, le Tri pair-impair, le Quick Sort et le Tri par insertion. Le code génère des données aléatoires, les trie à l'aide de chacun de ces algorithmes, enregistre le temps d'exécution de chacun d'eux et génère des graphiques pour la visualisation.

De plus, ce code interagit avec un script Python pour générer le graphique et utilise Gnuplot pour la visualisation. Il lit également des coefficients à partir d'un fichier pour ajuster et afficher des courbes représentant la complexité temporelle attendue de chaque algorithme.

## 2. Descriptions des fonctions et algorithmes

### 2.1. Fonction `smooth_sort`
- Description : Implémente le Smooth Sort, un algorithme de tri basé sur les nombres de Leonardo.
- Entrée : Un tableau d'entiers et sa taille.
- Sortie : Renvoie un nouveau tableau contenant les entiers triés.

### 2.2. Fonction `CocktailSort`
- Description : Implémente le Cocktail Sort (Tri à bulles bidirectionnel), un algorithme de tri qui trie en comparant et en échangeant des éléments dans les deux sens.
- Entrée : Un tableau d'entiers et sa taille.
- Sortie : Renvoie un nouveau tableau contenant les entiers triés.

### 2.3. Fonction `oddEvenSort`
- Description : Implémente le Tri pair-impair (Tri en briques), un algorithme de tri qui trie de manière itérative des paires adjacentes d'éléments.
- Entrée : Un tableau d'entiers et sa taille.
- Sortie : Renvoie un nouveau tableau contenant les entiers triés.

### 2.4. Fonction `quick_Sort`
- Description : Implémente le Quick Sort, un algorithme de tri diviser-pour-régner populaire.
- Entrée : Un tableau d'entiers et sa taille.
- Sortie : Renvoie un nouveau tableau contenant les entiers triés.

### 2.5. Fonction `insertion_Sort`
- Description : Implémente le Tri par insertion, un algorithme de tri simple qui construit le tableau trié final un élément à la fois.
- Entrée : Un tableau d'entiers et sa taille.
- Sortie : Renvoie un nouveau tableau contenant les entiers triés.

### 2.6. Fonction `RandTab`
- Description : Génère un tableau d'entiers aléatoires.
- Entrée : Le pointeur vers le tableau, sa taille et un indicateur pour indiquer s'il faut créer un nouveau tableau.
- Sortie : Renvoie le tableau mis à jour.

### 2.7. Fonction `executePythonScript`
- Description : Exécute un script Python (main.py) pour la visualisation.

### 2.8. Fonction `readCoefficientsFromFile`
- Description : Lit les coefficients pour l'ajustement de courbe à partir d'un fichier (res.txt).

### 2.9. Fonction `calcTemp`
- Description : Évalue et enregistre le temps d'exécution des algorithmes de tri pour plusieurs ensembles de données aléatoires et écrit les données dans un fichier.

### 2.10. Fonction `writeDataToFile`
- Description : Écrit les données de l'évaluation dans un fichier texte (data.txt).

### 2.11. Fonction `plotData`
- Description : Utilise Gnuplot pour créer un graphique des données de l'évaluation, y compris les courbes ajustées pour la complexité temporelle attendue.

## 3. Comment utiliser

Pour utiliser ce code pour l'évaluation et la visualisation, suivez ces étapes :

1. Compilez le code C et exécutez-le.
2. Le code génère des données aléatoires, les trie à l'aide de divers algorithmes de tri, enregistre les temps d'exécution et génère des graphiques en utilisant Gnuplot.
3. Examinez le graphique généré pour analyser les performances des algorithmes de tri.
4. Assurez-vous que Python, Gnuplot et les fichiers nécessaires (main.py et res.txt) sont disponibles dans le répertoire de travail.

## 4. Remarques complémentaires

- Le code fournit un cadre pour évaluer et visualiser les performances des algorithmes de tri.
- Assurez-vous d'avoir Python et Gnuplot installés pour exécuter le code avec succès.
- Les algorithmes de tri utilisés dans ce code comprennent le Smooth Sort, le Cocktail Sort, le Tri pair-impair, le Quick Sort et le Tri par insertion. Vous pouvez modifier le code pour inclure d'autres algorithmes si nécessaire.
- Les coefficients d'ajustement de courbe (res.txt) peuvent être utilisés pour estimer et visualiser la complexité temporelle attendue de chaque algorithme.
