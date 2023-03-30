/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** create
*/

#include "rpg.h"
#include "lists.h"

void create_all(menu_t *menu);
void display_all(menu_t *menu);
void events(menu_t *menu, sfEvent event);

static menu_t *init_game(sfRenderWindow *window, game_t *game)
{
    game->menu[0] = malloc(sizeof(menu_t));
    game->menu[0]->window = window;
    game->menu[0]->window_size = sfRenderWindow_getSize(window);
    return game->menu[0];
}

void create_start_window(game_t *game)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, "Start | RPG",
        sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, game->frameRate);
    game->menu[0] = init_game(window, game);
    sfEvent event;
    create_all(game->menu[0]);
    while (sfRenderWindow_isOpen(window) && !game->menu[0]->close) {
        events(game->menu[0], event);
        display_all(game->menu[0]);
    }
    sfRenderWindow_destroy(window);
}
