/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** create
*/

#include "rpg.h"
#include "lists.h"

void create_game_all(game_t *game);
void display_game_all(game_t *game);
void events_game(game_t *game, menu_t *menu, sfEvent event);

int create_game_window(game_t *game)
{
    sfVideoMode mode = game->mode;
    sfRenderWindow *window = sfRenderWindow_create(mode, "RPG",
        sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, game->frameRate);
    game->menu[1]->window = window;
    game->menu[1]->current = 0;
    game->menu[1]->close = 0;
    sfEvent event;

    create_game_all(game);
    while (sfRenderWindow_isOpen(window) && game->menu[1]->close == 0) {
        events_game(game, game->menu[1], event);
        display_game_all(game);
    }
    sfRenderWindow_destroy(window);
    return 0;
}
