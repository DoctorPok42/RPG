/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** main
*/

#include "game.h"

int start_game(game_t *game);

int main(int ac, char **av)
{
    (void)ac; (void)av;
    game_t *game = malloc(sizeof(game_t));
    start_game(game);
    return (0);
}
