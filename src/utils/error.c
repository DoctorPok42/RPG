/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** error
*/

#include <stdbool.h>
#include "my_str.h"

#ifdef __APPLE__

bool is_error(const char **env)
{
    (void)env;
    return false;
}

#else

bool is_error(const char **env)
{
    int i = 0;

    if (env == NULL)
        return true;
    for (i = 0; env[i] != NULL; i++) {
        if (my_strncmp(env[i], "DISPLAY=", 8) == 0)
            return false;
    }
    return true;
}

#endif
