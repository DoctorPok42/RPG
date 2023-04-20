/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** perso
*/

#ifndef PERSO_H_
    #define PERSO_H_

    #include "game.h"

    typedef struct {
        int attack;
        int defense;
        int life;
        int strength;
        int speed;
        int level;
    } combat_t;

    typedef struct {
        sfTexture *texture;
        sfSprite *sprite;
        sfVector2f pos;
        sfVector2f pos_save;
        sfIntRect rect;
        sfClock *clock;
        sfTime time;
        float seconds;
        int move;
        int direction;
        char *name;
        combat_t *combat;
    } perso_t;

#endif /* !PERSO_H_ */
