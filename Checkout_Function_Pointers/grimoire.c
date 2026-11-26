#include <stdio.h>
#include <string.h>

/*Nos formules qui ont toutes la même forme*/
void spell_fire(char *target)
{
    printf("Une boule de feu incinère %s ! \n", target);
}
void spell_ice(char *target)
{
    printf(" %s est congelé sur place! \n", target);
}
void spell_heal(char *target)
{
    printf(" %s récupère ses points de vie! \n", target);
}
void spell_poison(char *target)
{
    printf("%s est empoisonné et perd des forces! \n", target);
}

/* Le moule de notre index magique*/
typedef struct spell_mapping {
    char *spell_name;
    void (*cast_funct)(char *);
}spell_t;

/* Rempolir notre grimoire*/
spell_t grimoire[] = {
    {"feu", spell_fire},
    {"glace", spell_ice},
    {"soin", spell_heal},
    {"poison", spell_poison},
    {NULL, NULL}
};

/*moteur de recherche*/
void (*get_spell(char *name))(char *)
{
    int i = 0;
    
    while (grimoire[i].spell_name != NULL)
    {
        if (strcmp(name, grimoire[i].spell_name) == 0)
        {
            return (grimoire[i].cast_funct);
        }
        i++;
    }

    return (NULL);
}

int main(void)
{
    void (*my_spell)(char *target);
    printf("---- SImulateur de magie ---- \n");

    my_spell = get_spell("feu");

    if (my_spell != NULL)
    {
        my_spell("le gobelin");
    }

    my_spell = get_spell("soin");
    if (my_spell != NULL)
    {
        my_spell("le héro");
    }

    my_spell = get_spell("foudre");
    if (my_spell != NULL)
    {
        my_spell("le dragon");
    }
    else
    {
        printf(" Pfuiiit, Rien ne se passe, le sort n'existe pas\n");
    }

    return (0);
}