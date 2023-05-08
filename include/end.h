/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** end
*/

#ifndef END_H_
    #define END_H_

    #include "rpg.h"

    typedef struct s_end {
        sfRectangleShape *container;
        sfRectangleShape *content;
        sfText *text;
        sfFont *font;
        sfVector2f pos;
        sfVector2f size;
        sfVector2f pos_text;
        sfVector2f size_text;
        sfColor color;
        sfColor color_text;
        int is_end;
    } end_t;

#endif /* !END_H_ */
