/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** buttons
*/

#ifndef BUTTONS_H_
    #define BUTTONS_H_

    #include "rpg.h"

    enum stats {
        none,
        HOVER,
        CLICK,
        RELEASE,
    };

    typedef struct {
        sfVector2f pos;
        sfVector2f size;
        sfTexture *texture;
        sfSprite *sprite;
        sfRectangleShape *rect;
        sfIntRect rect_text;
        sfColor color;
        sfText *text;
        sfFont *font;
        sfVector2f text_pos;
        enum stats state;
        void (*callback)(void *);
    } buttons_t;

#endif /* !BUTTONS_H_ */
