#include <stdio.h>

int main(void)
{
    int i = 1;

    /* On imprime le premier chiffre en dehors de la boucle */
    putchar('0');
    /* La boucle gère uniquement le motif répétitif : Virgule + Espace + Chiffre */
    while(i <= 9)
    {
        putchar(',');
        putchar(' ');
        putchar(i + '0');
        i++;
    }

    return (0);
}