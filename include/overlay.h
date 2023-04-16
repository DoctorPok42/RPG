/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** overflow
*/

#ifndef OVERLAY_H_
    #define OVERLAY_H_

    #include "rpg.h"

    typedef struct {
        sfRectangleShape *container;
        sfRectangleShape *content;
        sfTexture *texture;
        sfSprite *sprite;
        sfVector2f scale;
        sfVector2f pos;
        sfIntRect rect;
    } life_t;

    typedef struct {
        life_t *life;
    } overlay_t;

#endif /* !OVERLAY_H_ */
