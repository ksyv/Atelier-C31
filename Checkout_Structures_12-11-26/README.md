# 🗡️ Atelier RPG : L'Arène de Velen (Structures & Pointeurs)

Bienvenue dans ce mini-projet d'entraînement ! 
Ce dépôt contient le code de l'atelier live-coding sur les **Structures**, le **Typedef**, et la manipulation des **Pointeurs de structures**.

L'objectif de cet exercice est de coder un moteur de combat basique pour un RPG (The Witcher), en comprenant bien la différence entre manipuler une donnée directement (avec le point `.`) et la manipuler à distance via son adresse (avec la flèche `->`).

---

## 🎯 Objectifs d'apprentissage

À la fin de cet atelier, vous devez être capables de :
1. Créer un "moule" (plan de construction) avec `struct` et le renommer avec `typedef`.
2. Instancier plusieurs personnages indépendants à partir de ce même moule.
3. Comprendre pourquoi on doit passer l'**adresse** (`&`) d'un personnage à une fonction pour modifier ses points de vie réels.
4. Maîtriser l'utilisation du point `.` (pour la variable physique) et de la flèche `->` (pour le pointeur).

---

## 📜 Le Scénario : Comment refaire l'atelier de zéro

Pour vous entraîner, essayez de recréer ce programme par vous-mêmes en suivant ces 3 étapes :

### Étape 1 : Le Moule (`hero.h`)
Oubliez les variables éparpillées (`char *name`, `int hp`, `int attack`). 
Créez un fichier d'en-tête (Header) contenant la définition de votre entité. 
Utilisez `typedef` pour créer l'alias `player_t`. Un joueur possède un nom, des points de vie (HP) et des points d'attaque. N'oubliez pas les Include Guards (`#ifndef`, etc.) !

### Étape 2 : L'Invocation (`hero.c` - dans le main)
Dans votre fonction `main`, créez deux combattants : `witcher` et `drowner` (le Noyeur).
Puisque vous créez ces variables localement dans le `main` (sur la Stack), ce sont des boîtes physiques. Remplissez leurs caractéristiques en utilisant **le point** (`witcher.name = "Geralt";`).

### Étape 3 : La Bagarre (`strike`)
Créez une fonction `strike` au-dessus de votre main. 
Cette fonction prend **l'attaquant** et **la cible**. 
⚠️ *Attention :* Si vous ne passez pas des pointeurs (`*`), le C fera une photocopie des personnages. Le clone prendra des dégâts, mais l'original dans le `main` restera intact.
La fonction doit donc prendre des pointeurs. À l'intérieur, utilisez **la flèche** (`->`) pour dire : *"Va à l'adresse de la cible, ouvre la boîte, et diminue ses HP en fonction de l'attaque du lanceur"*.

Dans le `main`, appelez la fonction en passant les adresses (`&`) de vos combattants.

---

## 🛠️ Compilation et Exécution

Compilez votre code avec les flags stricts de l'école :

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 hero.c -o arena 
```

Lancez le combat :

```bash
./arena
```