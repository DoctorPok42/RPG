/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** main
*/

#include "rpg.h"
#include "lists.h"

void create_start_window(game_t *game);

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    game_t *game = malloc(sizeof(game_t));
    game->menu = malloc(sizeof(menu_t *) * 2);
    game->frameRate = 60;
    create_start_window(game);
    return (0);
}
