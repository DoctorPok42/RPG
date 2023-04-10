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
        sfTexture *texture;
        sfSprite *sprite;
        sfVector2f scale;
        sfVector2f pos;
        sfIntRect rect;
    } overlay_t;

#endif /* !OVERLAY_H_ */
