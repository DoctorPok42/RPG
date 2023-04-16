/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** game_menu
*/

#ifndef GAME_MENU_H_
    #define GAME_MENU_H_

    #include "rpg.h"
    #include "buttons.h"

    typedef struct {
        sfRectangleShape *container;
        buttons_t **buttons;
    } sidebar_t;

    typedef struct {
        sfRectangleShape *container;
        sfRectangleShape *content;
        sidebar_t *sidebar;
    } game_menu_t;

#endif /* !GAME_MENU_H_ */
