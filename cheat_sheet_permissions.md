# Cheat Sheet : Les Permissions Linux (Sans s'arracher les cheveux)

Dans le monde Linux, tout est fichier, et chaque fichier possède une carte d'identité stricte. Comprendre les permissions, c'est maîtriser 90% de la sécurité de votre système. 

Voici l'antisèche pour lire, calculer et modifier les droits sans hésiter.

---

## 1. La Trinité Linux (À QUI s'appliquent les droits ?)

Chaque fichier est régi par trois entités, toujours dans cet ordre :
*   **`u` (User / Owner) :** Le propriétaire du fichier.
*   **`g` (Group) :** Le groupe rattaché au fichier (ex: l'équipe de dev).
*   **`o` (Others) :** Le reste du monde (tous les autres utilisateurs du serveur).
*   *Bonus :* **`a` (All) :** Tout le monde (u + g + o).

Lorsque vous tapez `ls -l`, vous voyez un bloc de 10 caractères, par exemple : `-rwxr-xr--`
*   Le 1er caractère indique le type (`-` pour un fichier, `d` pour un dossier, `l` pour un lien).
*   Les 3 suivants : droits du **User** (`rwx`).
*   Les 3 d'après : droits du **Group** (`r-x`).
*   Les 3 derniers : droits des **Others** (`r--`).

---

## 2. Les Pouvoirs (QUELS sont les droits ?)

Il existe 3 droits fondamentaux. À chacun correspond une lettre et une valeur mathématique (une puissance de 2) :

| Droit | Lettre | Valeur (Octal) | Sur un Fichier | Sur un Dossier |
| :--- | :---: | :---: | :--- | :--- |
| **Read** | `r` | **4** | Lire le contenu du fichier | Lister le contenu du dossier (`ls`) |
| **Write** | `w` | **2** | Modifier ou supprimer le fichier | Créer ou supprimer des fichiers dedans |
| **Execute**| `x` | **1** | Lancer le fichier comme un script | **Traverser le dossier (`cd`)** |

**Le Piège du `x` :** On n'exécute pas un dossier. Sur un répertoire, le `x` donne le droit d'y "entrer". Si vous enlevez le `x` d'un dossier, personne ne pourra faire `cd` dedans, même avec le droit `r` !

---

## 3. Modifier les droits : La méthode Mathématique (dite octale)

C'est la méthode préférée des pros car elle règle tous les droits en une seule commande `chmod`. 
Il suffit d'**additionner les valeurs (4, 2, 1)** pour chaque entité (User, Group, Others).

**Exemple :** On veut donner "Lecture/Écriture/Exécution" au User, "Lecture/Écriture" au Group, et rien aux Others.
*   **User :** 4 (r) + 2 (w) + 1 (x) = **7**
*   **Group :** 4 (r) + 2 (w) = **6**
*   **Others :** Rien = **0**
*   **Commande :** `chmod 760 mon_fichier`

### Les "Classiques" de l'industrie à retenir :
*   `chmod 777` : **Open bar.** Tout le monde peut tout faire. À fuir absolument sur un serveur.
*   `chmod 644` : **Standard fichier.** Le propriétaire lit/écrit, les autres ne font que lire.
*   `chmod 755` : **Standard dossier / exécutable.** Le proprio a tous les droits, les autres peuvent lire et exécuter/traverser.
*   `chmod 400` : **Blindage absolu.** Seul le proprio peut lire. Utilisé pour les mots de passe (`.env`) ou les clés SSH privées.

---

## 4. Modifier les droits : La méthode Symbolique

Pratique pour ajouter ou retirer un droit précis sans recalculer tout le reste.
On utilise la formule : `Qui` + `Action` + `Droit`

*   **Ajouter l'exécution au proprio :** `chmod u+x mon_script.sh` (L'erreur "Permission denied" disparaît !)
*   **Retirer l'écriture au groupe :** `chmod g-w fichier.txt`
*   **Ajouter la lecture à tout le monde :** `chmod a+r document.pdf`
*   **Forcer des droits exacts (écrase le reste) :** `chmod o=rx dossier/` (Les "Others" auront lecture et exécution, l'écriture est retirée si elle y était).

---

## 5. Changer de Propriétaire (`chown` & `chgrp`)

Parfois, changer les droits ne suffit pas, il faut changer *à qui* appartient le fichier.

*   **Changer le User :** `sudo chown nouveau_user fichier`
*   **Changer le Group :** `sudo chgrp nouveau_groupe fichier`
*   **Changer les DEUX d'un coup (Le combo magique) :** `sudo chown nouveau_user:nouveau_groupe fichier`

**Pourquoi `sudo` obligatoire ?** Un utilisateur normal n'a pas le droit de donner un de ses fichiers à un autre utilisateur (imaginez les failles de sécurité si on pouvait attribuer des fichiers illégaux à son voisin). Seul Dieu (Root / `sudo`) peut changer l'appartenance d'un fichier.