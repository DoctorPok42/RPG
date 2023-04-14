/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** option
*/

#include "game.h"

void create_navbar(game_t *game);
void create_fps(game_t *game);
void create_music(game_t *game);
void create_keyboard(game_t *game);
void create_window_button(game_t *game);

void create_options(game_t *game)
{
    game->params->visu = malloc(sizeof(visu_t));
    create_navbar(game);
    create_fps(game);
    create_music(game);
    create_keyboard(game);
    create_window_button(game);
}
