/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** main
*/

#include "game.h"
#include <SFML/Window/Keyboard.h>

void do_free(game_t *game);
bool is_error(const char **env);
int start_game(game_t *game);
network_t *connect_to_server (void);

int main(int ac, char **av, const char **env)
{
    (void)ac;
    (void)av;
    if (is_error(env))
        return 84;

    game_t game = {0};

    game.network = connect_to_server();

    start_game(&game);
    do_free(&game);

    return (0);
}
