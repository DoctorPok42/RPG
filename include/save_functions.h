/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** save_functions
*/

#ifndef SAVE_FUNCTIONS_H_
    #define SAVE_FUNCTIONS_H_

    #include <stdio.h>
    #include "game.h"

    #define SAVE_FIELDS 31

int save(game_t *game);
game_t *load_save(char *filepath, game_t *game);
void write_save(game_t *game, int fd);
void write_params(params_t *params, int fd);
void write_keys(keys_t *key, int fd);
void write_perso(perso_t *perso, int fd);
char **get_text(FILE *file);
char **add_str(char **tab, char *new_var);

#endif /* !SAVE_FUNCTIONS_H_ */
