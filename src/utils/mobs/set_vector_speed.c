/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** set_vector_speed
*/

#include <math.h>

#include "game.h"

sfVector2f set_vector_speed (sfVector2f vec, float speed)
{
    while (fabsf(vec.x) < speed || fabsf(vec.y) < speed) {
        vec.x *= 10;
        vec.y *= 10;
    }

    float length = sqrt(vec.x * vec.x + vec.y * vec.y);

    sfVector2f longerVec = vec;
    longerVec.x *= speed / length;
    longerVec.y *= speed / length;

    return longerVec;
}
