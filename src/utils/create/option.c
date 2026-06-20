/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** option
*/

#include "game.h"
#include "create.h"

void create_options(game_t *game)
{
    game->params->visu = malloc(sizeof(visu_t));
    create_navbar(game);
    create_fps(game);
    create_music(game);
    create_keyboard(game);
    create_window_button(game);
}
