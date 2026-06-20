/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** main
*/

#include "game.h"

int main(int ac, char **av, const char **env)
{
    game_t game = {0};

    (void)ac;
    (void)av;
    if (is_error(env))
        return EPITECH_ERROR;
    start_game(&game);
    do_free(&game);
    return EPITECH_SUCCESS;
}
