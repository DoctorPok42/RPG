/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** main
*/

#include "game.h"
#include <SFML/Window/Keyboard.h>

int start_game(game_t *game);
network_t *connect_to_server (void);

int main(int ac, char **av)
{
    (void)ac;
    (void)av;

    game_t *game = malloc(sizeof(game_t));
    if (game == NULL)
        return 84;


    start_game(game);
    return (0);
}

    // game->network = connect_to_server();
    // if (game->network == NULL) {
    //     free(game);
    //     return 84;
    // }
