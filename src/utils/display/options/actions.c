/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** actions
*/

#include "game.h"

void set_fullscreen(game_t *game)
{
    game->params->is_fullscreen = true;
    sfRenderWindow_destroy(game->window->window);
    game->window->window = sfRenderWindow_create(game->params->mode,
        game->window->title, sfNone, sfFullscreen, NULL);
}

void set_windowed(game_t *game)
{
    game->params->is_fullscreen = false;
    sfRenderWindow_destroy(game->window->window);
    game->window->window = sfRenderWindow_create(game->params->mode,
        game->window->title, sfClose | sfResize, sfWindowed, NULL);
}

void set_1920x1080(game_t *game)
{
    game->params->mode.size.x = 1920;
    game->params->mode.size.y = 1080;
    if (game->params->is_fullscreen == true) {
        sfRenderWindow_destroy(game->window->window);
        game->window->window = sfRenderWindow_create(game->params->mode,
            game->window->title, sfNone, sfFullscreen, NULL);
    } else {
        sfRenderWindow_destroy(game->window->window);
        game->window->window = sfRenderWindow_create(game->params->mode,
            game->window->title, sfClose | sfResize, sfWindowed, NULL);
    }
}

void set_1280x720(game_t *game)
{
    game->params->mode.size.x = 1280;
    game->params->mode.size.y = 720;
    if (game->params->is_fullscreen == true) {
        sfRenderWindow_destroy(game->window->window);
        game->window->window = sfRenderWindow_create(game->params->mode,
            game->window->title, sfNone, sfFullscreen, NULL);
    } else {
        sfRenderWindow_destroy(game->window->window);
        game->window->window = sfRenderWindow_create(game->params->mode,
            game->window->title, sfClose | sfResize, sfWindowed, NULL);
    }
}

void set_800x600(game_t *game)
{
    game->params->mode.size.x = 800;
    game->params->mode.size.y = 600;
    if (game->params->is_fullscreen == true) {
        sfRenderWindow_destroy(game->window->window);
        game->window->window = sfRenderWindow_create(game->params->mode,
            game->window->title, sfNone, sfFullscreen, NULL);
    } else {
        sfRenderWindow_destroy(game->window->window);
        game->window->window = sfRenderWindow_create(game->params->mode,
            game->window->title, sfClose | sfResize, sfWindowed, NULL);
    }
}
