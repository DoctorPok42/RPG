/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** inventory
*/

#ifndef INVENTORY_H_
    #define INVENTORY_H_

    #include "rpg.h"

    typedef struct {
        sfRectangleShape *container;
        sfRectangleShape *content;
        sfTexture *texture;
        sfVector2f pos;
    } item_t;

    typedef struct {
        item_t **items;
        int item_selected;
    } inventory_t;

#endif /* !INVENTORY_H_ */
