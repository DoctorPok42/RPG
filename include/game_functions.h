/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** game_functions
*/

#ifndef GAME_FUNCTIONS_H_
    #define GAME_FUNCTIONS_H_

typedef struct game_s game_t;

void change_to_inventory(game_t *game);
void change_to_character(game_t *game);
void change_to_option(game_t *game);
void exit_start_all(game_t *game);
void change_to_quest(game_t *game);

typedef struct game_functions_s {
    void (*function)(game_t *game);
} game_functions_t;

extern const game_functions_t MENU_FLAGS[];

#endif /* !GAME_FUNCTIONS_H_ */
