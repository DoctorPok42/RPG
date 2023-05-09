/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** window
*/

#include "game.h"

void create_window(game_t *game)
{
    game->window = malloc(sizeof(window_t));
    game->window->title = "Start";

    game->window->window = sfRenderWindow_create(game->params->mode,
        game->window->title, sfClose | sfResize, NULL);

    game->window->view = sfView_createFromRect((sfFloatRect){0, 0, 1920, 1080});
    sfRenderWindow_setFramerateLimit(game->window->window, 3000);
    sfRenderWindow_setVerticalSyncEnabled(game->window->window, sfTrue);
    sfRenderWindow_setView(game->window->window, game->window->view);

    game->window->song = malloc(sizeof(song_t));
    game->window->song->music =
        sfMusic_createFromFile("assets/songs/main.ogg");
    sfMusic_setLoop(game->window->song->music, sfTrue);
    sfMusic_setVolume(game->window->song->music, game->params->volume);
    sfMusic_play(game->window->song->music);
}
