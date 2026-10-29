#include <stdio.h>
/**
 * Cheminement de pensée pour afficher un chargement qui part de 0 jusqu'à 10,
 * et qui va remplacer le 5 par un X pour signifier la moitié du chargement. 
 * 
 * Declarer un indice et l'assigner 0.
 * while boucle tant que indice n'est pas arrivé à 10 inferieur ou egal
 *  si l'indice n'est pas 10
 *      Affichage de l'indice
 *      Ajout de 1 à l'indice
 *      Si indice est 5:
 *          affichage de X
 *          indice + 1 
 *  else:
 *      affichage de 1 puis de 0 puis retour a la ligne
 * 
 * return (0);
 */
int main(void)
{
    int i = 0;
    while (i <= 10)
    {
        if (i != 10)
        {
            putchar(i + '0');
            i++;
            if (i == 5)
            {
                putchar('X');
                i++;
            }   
        }
        else
        {
            putchar('1');
            putchar('0');
            putchar('\n');
            i++;
        }

    }

    return (0);
}



 