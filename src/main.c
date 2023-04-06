/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** main
*/

#include "rpg.h"
#include "lists.h"

int create_game_window(game_t *game);
int create_start_window(game_t *game);

static void init_game(game_t *game)
{
    game->menu[0]->current = 0;
    game->menu[0]->close = 0;
    game->menu[1]->current = 0;
    game->menu[1]->close = 0;
    game->keys = malloc(sizeof(keys_t));
    game->keys->up = sfKeyUp;
    game->keys->down = sfKeyDown;
    game->keys->left = sfKeyLeft;
    game->keys->right = sfKeyRight;
}

int main(int ac, char **av)
{
    (void)ac; (void)av;
    game_t *game = malloc(sizeof(game_t));
    game->menu = malloc(sizeof(menu_t *) * 3);
    game->frameRate = 60;
    game->volume = 100;
    game->mode = (sfVideoMode){1920, 1080, 32};
    game->menu[0] = malloc(sizeof(menu_t));
    game->menu[1] = malloc(sizeof(menu_t));
    game->menu[1]->perso = malloc(sizeof(perso_t));
    game->menu[1]->perso->clock = sfClock_create();
    init_game(game);
    while (game->menu[0]->close == 0) {
        create_start_window(game);
    }
    if (game->menu[0]->close == 2)
        return 0;
    while (game->menu[1]->close == 0) {
        create_game_window(game);
    }
    return (0);
}
