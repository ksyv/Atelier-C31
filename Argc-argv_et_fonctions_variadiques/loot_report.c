#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void log_loot(const char * const format, ...)
{
    va_list bag;
    int i = 0;
    char *str;

    if (format == NULL)
        return;

    va_start(bag, format);

    while (format[i] != '\0')
    {
        if(format[i] == 's')
        {
            str = va_arg(bag, char *);
            if (str == NULL)
                printf("(vide)");
            else
                printf("%s", str);
        }
        else if (format[i] == 'i')
        {
            printf("%d", va_arg(bag, int));
        }
        else if (format[i] == 'c')
        {
            printf("%c", va_arg(bag, int));
        }

        if (format[i + 1] != '\0')
            printf(" | ");
        i++;
    }
    printf("\n");
    va_end(bag);
}

int main(int argc, char *argv[])
{
    char *hero;
    char rank;
    int gold;
    int bonus;
    int total;

    if (argc != 4)
    {
        printf("Usage: %s <nom_heros> <or> <bonus>\n", argv[0]);
        return (1);
    }

    hero = argv[1];
    gold = atoi(argv[2]);
    bonus = atoi(argv[3]);
    total = gold + bonus;

    if (total >= 100)
        rank = 'S';
    else 
        rank = 'B';

    printf("--- RAPPORT DE CONTRAT ---\n");
    log_loot("sic", hero, total, rank);
    log_loot("ss", "Statut", "Contrat valide");

    return (0);
}