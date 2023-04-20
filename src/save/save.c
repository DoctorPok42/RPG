/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-remi.mazat
** File description:
** write_save
*/

#include "game.h"
#include<unistd.h>
#include "fcntl.h"
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
int my_strlen(char const *str);
int my_put_nbr(int valeur, int fd);
int my_float(int prec, double n, int fd);
char **get_text(FILE *file);
int my_strncmp(char const *s1, char const *s2, int n);
int free_tab(char **tab);
void write_keys(keys_t *key, int fd);
void write_params(params_t *params, int fd);
void write_perso(perso_t *perso, int fd);

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
    char *filepath1 = "config/save1";
    char *filepath2 = "config/save2";
    char *filepath3 = "config/save3";
    int fd; struct stat st = {0};
    if (stat(filepath1, &st) == -1) {
        fd = open(filepath1, O_CREAT | O_TRUNC | O_RDWR, S_IRWXU);
        write_save(game, fd);
        close(fd);
        return 0;
    }
    if (stat(filepath2, &st) == -1) {
        fd = open(filepath2, O_CREAT | O_TRUNC | O_RDWR, S_IRWXU);
        write_save(game, fd);
        close(fd);
        return 0;
    }
    fd = open(filepath3, O_CREAT | O_TRUNC | O_RDWR, S_IRWXU);
    write_save(game, fd);
    close(fd);
    return 0;
}
