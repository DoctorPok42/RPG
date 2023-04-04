/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** main
*/

#include "rpg.h"
#include "lists.h"

int create_start_window(game_t *game);

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    game_t *game = malloc(sizeof(game_t));
    game->menu = malloc(sizeof(menu_t *) * 2);
    game->frameRate = 60;
    game->volume = 100;
    game->mode = (sfVideoMode){1920, 1080, 32};
    game->menu[0] = malloc(sizeof(menu_t));
    while (game->menu[0]->close == 0) {
        create_start_window(game);
    }
    return (0);
}
