# Recap : Checkout - Variables, if, else, while
**Date :** 29 Octobre 2026

Ce dossier contient les codes vus lors du live-coding d'aujourd'hui. Un bon ingénieur ne retient pas la syntaxe par cœur, il comprend la logique. Voici de quoi vous rafraîchir la mémoire !

## 1. L'Alias de Survie (à mettre tout en bas de votre `~/.bashrc`)
Pour compiler façon Holberton sans y laisser vos doigts :
```bash
alias gccc='gcc -Wall -Werror -Wextra -pedantic -std=gnu89'
```
*(N'oubliez pas de faire un `source ~/.bashrc` après l'avoir ajouté).*

## 2. Les Fichiers Pratiques Inclus
* **`ascii_magic.c`** : Comment utiliser `putchar` pour faire des maths avec des lettres. N'oubliez pas : les caractères n'existent pas, tout est nombre dans la table ASCII !
* **`loading.c`** : L'utilisation combinée d'une boucle `while` (l'ouvrier) et d'un `if` (le gardien). L'incrémentation (`i++`) est votre assurance-vie contre les boucles infinies.
* **`calcul.c`** : La "Solution de l'Ingénieur" pour l'exercice des virgules (Task 9). Au lieu de mettre un `if` lourd dans la boucle pour retirer la dernière virgule, on imprime le premier chiffre *avant* la boucle.

Bon courage pour la suite du projet. Passez un coup de Betty avant chaque push, et reposez vos yeux !
