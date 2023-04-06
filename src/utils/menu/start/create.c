/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** create
*/

#include "rpg.h"
#include "lists.h"

void create_start_all(menu_t *menu, sfIntRect *rect[4]);
void create_start_settings(game_t *game);
void display_start_all(game_t *game, menu_t *menu);
void display_start_settings(game_t *game, menu_t *menu);
void events_start(game_t *game, menu_t *menu, sfEvent event);

static menu_t *init_game(sfRenderWindow *window, game_t *game)
{
    game->menu[0]->window = window;
    game->window_size = sfRenderWindow_getSize(window);
    game->menu[0]->current = 0;
    game->menu[0]->close = 0;
    return game->menu[0];
}

int create_start_window(game_t *game)
{
    sfVideoMode mode = game->mode;
    sfRenderWindow *window = sfRenderWindow_create(mode, "Start | RPG",
        sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, game->frameRate);
    game->menu[0] = init_game(window, game);
    sfEvent event;
        sfIntRect *rect[4] = {&(sfIntRect){0, 5, 225, 105},
        &(sfIntRect){0, 330, 225, 105}, &(sfIntRect){0, 223, 225, 105},
        &(sfIntRect){0, 115, 225, 105}};
    create_start_all(game->menu[0], rect); create_start_settings(game);
    while (sfRenderWindow_isOpen(window) && game->menu[0]->close == 0) {
        events_start(game, game->menu[0], event);
        if (game->menu[0]->current == 0) {
            display_start_all(game, game->menu[0]);
        }
        if (game->menu[0]->current == 2) {
            display_start_settings(game, game->menu[0]);
        }
    }
    sfRenderWindow_destroy(window); return 0;
}
