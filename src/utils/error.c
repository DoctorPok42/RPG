/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** error
*/
#include <stdbool.h>
#include <unistd.h>
bool is_error(const char **env)
{
    for (int i = 0; env[i] != NULL; i++) {
        if (my_strncmp("DISPLAY=", env[i], 8) == 0) {
            return false;
        }
    }
    return true;
}