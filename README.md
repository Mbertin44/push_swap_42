# Push Swap

Push Swap est un programme qui trie une pile d'entiers en utilisant un ensemble d'instructions limité. Ce projet est réalisé dans le cadre de la formation à l'école 42.

## Installation

Pour installer Push Swap, il suffit de cloner le dépôt depuis GitHub et de compiler le programme avec la commande `make`.

## Utilisation

Pour utiliser Push Swap, il faut fournir une liste d'entiers à trier en tant qu'arguments de la ligne de commande. Par exemple :

`./push_swap 3 1 4 2

Le programme affichera alors une série d'instructions à exécuter pour trier la pile d'entiers.

## Instructions

Push Swap utilise deux piles, appelées A et B. Les instructions suivantes sont utilisées pour manipuler les piles :

- `sa` : échanger les deux premiers éléments de la pile A.
- `sb` : échanger les deux premiers éléments de la pile B.
- `ss` : équivalent à `sa` et `sb` en même temps.
- `pa` : déplacer le premier élément de la pile B au sommet de la pile A.
- `pb` : déplacer le premier élément de la pile A au sommet de la pile B.
- `ra` : déplacer le premier élément de la pile A au bas de la pile A.
- `rb` : déplacer le premier élément de la pile B au bas de la pile B.
- `rr` : équivalent à `ra` et `rb` en même temps.
- `rra` : déplacer le dernier élément de la pile A au sommet de la pile A.
- `rrb` : déplacer le dernier élément de la pile B au sommet de la pile B.
- `rrr` : équivalent à `rra` et `rrb` en même temps.
