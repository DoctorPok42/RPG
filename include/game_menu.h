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
        sfText **name;
        sfText **value;
    } character_t;

    typedef struct {
        sfRectangleShape *container;
        sfRectangleShape *content;
        sfFont *font;
        sfText *achievement;
        sfRectangleShape *bar;
        sfVector2f pos;
        sfVector2f size;
        int nb_achievement;
        int nb_achievement_second;
    } quest_t;

    typedef struct {
        sfRectangleShape *container;
        sfRectangleShape *content;
        sidebar_t *sidebar;
        character_t *character;
        quest_t *quest;
        sfFont *font;
        sfText **title;
    } game_menu_t;

#endif /* !GAME_MENU_H_ */
