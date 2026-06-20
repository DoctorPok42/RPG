/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** window
*/

#include "game.h"
#include "create.h"
#include "config.h"

void create_window(game_t *game)
{
    game->window = malloc(sizeof(window_t));
    game->window->title = "Start";
    game->window->window = sfRenderWindow_create(game->params->mode,
        game->window->title, sfClose | sfResize, sfWindowed, NULL);
    if (game->window->window == NULL)
        return;
    game->window->view = sfView_createFromRect((sfFloatRect){
            .position = {0, 0}, .size = {DEFAULT_WIDTH, DEFAULT_HEIGHT}});
    sfRenderWindow_setFramerateLimit(game->window->window, FPS_CAP);
    sfRenderWindow_setVerticalSyncEnabled(game->window->window, true);
    sfRenderWindow_setView(game->window->window, game->window->view);
    game->window->song = malloc(sizeof(song_t));
    game->window->song->music =
        sfMusic_createFromFile("assets/songs/main.ogg");
    sfMusic_setLooping(game->window->song->music, true);
    sfMusic_setVolume(game->window->song->music, game->params->volume);
    sfMusic_play(game->window->song->music);
}
