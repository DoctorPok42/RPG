/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** save
*/

#ifndef SAVE_H_
    #define SAVE_H_

    #include "rpg.h"

    typedef struct {
        sfRectangleShape **rect;
        sfTexture **texture;
        sfText *title;
        sfText **name;
    } save_view_t;

    typedef struct {
        save_view_t *view;
    } save_t;

#endif /* !SAVE_H_ */
