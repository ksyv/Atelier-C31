# 🛠️ Pimp My Terminal & L'Atelier du Fainéant

Bienvenue dans le récapitulatif de l'atelier ! Vous trouverez ici toutes les commandes et astuces abordées pour personnaliser votre environnement Bash et automatiser vos tâches.

---

## 1. Le Piège des Quotes : Simple vs Double

La règle absolue pour éviter les bugs avec vos variables :
* **Les doubles quotes (`"`) libèrent la magie :** Bash lit l'intérieur et remplace les variables par leur valeur.
* **Les simples quotes (`'`) enferment la magie :** Bash affiche le texte brut, exactement comme vous l'avez tapé.

```bash
PRENOM="Gandalf"

echo "Je suis $PRENOM"
# Résultat : Je suis Gandalf

echo 'Je suis $PRENOM'
# Résultat : Je suis $PRENOM
```

---

## 2. Le Script Assistant (`assistant.sh`)

Voici le code de notre script de "fainéant" qui compte les fichiers et calcule des points d'XP. Il utilise trois concepts clés :
1. **Les variables d'environnement natives** (ex: `$USER`).
2. **La substitution de commande `$()`** : Capture le résultat d'une commande pour le mettre dans une variable.
3. **L'expansion arithmétique `$(( ))`** : Demande à Bash de faire des mathématiques.

**Le code :**
```bash
#!/bin/bash
echo "Analyse en cours..."
#On capture le resultat de ls | wc -l
NB_FICHIERS=$(ls | wc -l)

#On fait des maths avec $(())
NIVEAU=$(( NB_FICHIERS * 10 ))

echo "Salut $USER !"
echo "Tu as créé $NB_FICHIERS fichiers ici."
echo "Ton niveau de développeur est de : $NIVEAU XP."
```

⚠️ **N'oubliez pas :** Un script texte n'est pas exécutable par défaut. Avant de le lancer avec `./assistant.sh`, vous devez lui donner les droits :
```bash
chmod u+x assistant.sh
```

---

## 3. Les Alias & Le Fichier `.bashrc`

Pour ne plus jamais retaper les mêmes longues commandes, on utilise des **alias**. Pour qu'ils survivent à la fermeture du terminal, il faut les inscrire tout en bas du fichier `~/.bashrc`.

Pour éditer le fichier :
```bash
nano ~/.bashrc
```

**Le kit de survie Holberton (à coller à la fin du fichier) :**
```bash
# Mes raccourcis persos
alias c='clear'
alias ll='ls -la'
alias maj='sudo apt update && sudo apt upgrade'
alias please='sudo'
alias ..='cd ..'

# Rendre un script exécutable instantanément
alias x='chmod u+x'

# Pour le fun
alias meteo='curl wttr.in/Bordeaux'
```

Pour que le terminal prenne en compte vos modifications sans avoir à le redémarrer :
```bash
source ~/.bashrc
```

---

## 4. Customiser son Prompt (`PS1`)

Le texte affiché à gauche de votre curseur (le prompt) est géré par la variable globale `$PS1`. 
Vous pouvez la modifier temporairement en tapant directement dans le terminal, ou définitivement en ajoutant la ligne tout en bas de votre `.bashrc`.

**Le prompt "Pro" (Heure, Batterie, Git) :**
Copiez-collez cette commande exacte pour un tableau de bord complet :
```bash
PS1="[\t] 🔋 \$(cat /sys/class/power_supply/BAT0/capacity 2>/dev/null)% 🌿 \$(git branch --show-current 2>/dev/null) \w $ "
```
*Note : Le `2>/dev/null` permet simplement de cacher les messages d'erreur si vous n'avez pas de batterie (ex: sur une machine virtuelle) ou si vous n'êtes pas dans un dossier Git.*

---

