/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** perso
*/

#ifndef PERSO_H_
    #define PERSO_H_

    #include "lists.h"

typedef struct {
    int attack;
    int defense;
    int life;
    int force;
} combat_t;

typedef struct {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfIntRect rect;
    sfClock *clock;
    sfTime time;
    float seconds;
    int move;
    int direction;
    combat_t combat;
} perso_t;

#endif /* !PERSO_H_ */
