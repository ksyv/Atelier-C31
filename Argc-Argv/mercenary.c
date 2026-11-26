#include <stdio.h>

int main(int argc, char *argv[])
{
    int i;

    printf("Le mercenaire a reçu %d instructions.\n", argc);

    printf("Mon nom de code est : %s\n", argv[0]);

    for (i = 1; i < argc; i++)
    {
        printf("Instruction %d : %s\n", i, argv[i]);
    }

    return (0);
}

