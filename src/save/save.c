/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-remi.mazat
** File description:
** write_save
*/

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#include "game.h"
#include "my_str.h"
#include "save_functions.h"

void write_save(game_t *game, int fd)
{
    my_put_nbr(game->params->fps, fd);
    write(fd, "\n", 1);
    write_params(game->params, fd);
    write(fd, "\n", 1);
    write_keys(game->keys, fd);
    my_put_nbr(game->menu, fd);
    write_perso(game->perso, fd);
}

int save(game_t *game)
{
    char *paths[3] = {"config/save1", "config/save2", "config/save3"};
    struct stat st = {0};
    int fd = 0;
    int i = 0;

    for (i = 0; i < 3; i++) {
        if (i < 2 && stat(paths[i], &st) != -1)
            continue;
        fd = open(paths[i], O_CREAT | O_TRUNC | O_WRONLY, S_IRWXU);
        if (fd == -1)
            return 84;
        write_save(game, fd);
        close(fd);
        return 0;
    }
    return 0;
}
