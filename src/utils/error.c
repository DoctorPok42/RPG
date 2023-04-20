/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** error
*/
#include <stdbool.h>
#include <unistd.h>

int my_strncmp(char const *s1, char const *s2, int n);
int my_strcmp(char const *s1, char const *s2);

bool is_error(const char **env)
{
    for (int i = 0; env[i] != NULL; i++) {
        if (my_strncmp("DISPLAY=", env[i], 8) == 0) {
            return false;
        }
    }
    return true;
}
