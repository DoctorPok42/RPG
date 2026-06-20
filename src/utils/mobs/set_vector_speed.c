/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** set_vector_speed
*/

#include <math.h>

#include "game.h"
#include "mobs_functions.h"

sfVector2f set_vector_speed(const sfVector2f *vec, float speed)
{
    float length = sqrtf(vec->x * vec->x + vec->y * vec->y);
    sfVector2f result = {0, 0};

    if (length == 0)
        return result;
    result.x = vec->x * speed / length;
    result.y = vec->y * speed / length;
    return result;
}
