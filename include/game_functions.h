/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** game_functions
*/

#ifndef GAME_FUNCTIONS_H_
    #define GAME_FUNCTIONS_H_

    #include "game.h"

    void change_to_inventory(game_t *game);
    void change_to_character(game_t *game);
    void change_to_option(game_t *game);
    void exit_start_all(game_t *game);
    void change_to_quest(game_t *game);

    typedef struct game_functions_s {
        void (*function)(game_t *game);
    } game_functions_t;

    static const game_functions_t MENU_FLAGS[] = {
        {function : &change_to_inventory},
        {function : &change_to_character},
        {function : &change_to_quest},
        {function : &change_to_option},
        {function : &exit_start_all},
        {function : NULL},
    };

#endif /* !GAME_FUNCTIONS_H_ */
