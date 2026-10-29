#include <stdio.h>

int main(void)
{
    /*Je donne un nombre, il va afficher une lettre*/
    putchar(65);
    putchar('\n');
    
    /*Je donne un caractère et j'ajoute une valeur, il va se 'déplacer' d'une lettre*/
    putchar('A' + 1);
    putchar('\n');

    /*Je donne une lettre majuscule et j'ajoute 32, j'arrive à la même lettre en minuscule*/
    putchar('A' + 32);
    putchar('\n');

    /*Valeur de l'affichage du 0 */
    putchar(48);
    putchar('\n');

    /*Valeur de l'affichage du 0 et j'ajoute 2, il va afficher 2*/
    putchar(48 + 2);
    putchar('\n');

    /*Caractère d'affichage de 0 et j'ajoute 2, il va afficher aussi 2*/
    putchar('0' + 2);
    putchar('\n');

    return (0);
}