/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** map
*/

#ifndef MAP_H_
    #define MAP_H_

    #include "rpg.h"

    typedef struct {
        sfTexture *texture;
        sfSprite *sprite;
        sfTexture *iso_texture;
        sfSprite *iso_sprite;
        sfRectangleShape *rectangle;
        sfVector2f scale;
        sfVector2f pos;
        sfImage *colls_image;
        sfIntRect rect;
    } map_t;

#endif /* !MAP_H_ */
