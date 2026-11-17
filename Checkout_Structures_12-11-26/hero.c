#include <stdio.h>
#include <stdlib.h>
#include "hero.h"


void strike(player_t *attacker, player_t *target)
{
    target->hp = target->hp - attacker->attack;
    printf("%s attaque %s et lui inflige %d degats! \n", attacker->name, target->name, attacker->attack);
}

int main(void)
{
    player_t witcher;
    player_t drowner;

    witcher.name = "Geralt";
    witcher.hp = 100;
    witcher.attack = 25;

    drowner.name = "Noyeur";
    drowner.hp = 40;
    drowner.attack = 8;

    printf("Combat : %s (%d) VS %s (%d)\n", witcher.name, witcher.hp, drowner.name, drowner.hp);

    strike(&witcher, &drowner);
    strike(&drowner, &witcher);

    return (0);
}