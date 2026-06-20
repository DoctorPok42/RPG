/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** tests for the bounded map accessor and mob vector helper
*/

#include <criterion/criterion.h>
#include "game.h"
#include "raycasting_functions.h"
#include "mobs_functions.h"

Test(raycast_cell, out_of_range_is_a_wall)
{
    int data[6] = {0, 1, 2, 3, 4, 5};
    raycast_map_t m = {3, 2, data};

    cr_assert_eq(raycast_cell(&m, 0, 0), 0);
    cr_assert_eq(raycast_cell(&m, 2, 1), 5);
    cr_assert_eq(raycast_cell(&m, -1, 0), 1);
    cr_assert_eq(raycast_cell(&m, 0, -5), 1);
    cr_assert_eq(raycast_cell(&m, 3, 0), 1);
    cr_assert_eq(raycast_cell(&m, 0, 2), 1);
    cr_assert_eq(raycast_cell(&m, 99999, 99999), 1);
}

Test(set_vector_speed, normalises_and_survives_zero)
{
    sfVector2f zero = {0, 0};
    sfVector2f a = {3, 4};
    sfVector2f r = set_vector_speed(&zero, 2);

    cr_assert_float_eq(r.x, 0, 0.01);
    cr_assert_float_eq(r.y, 0, 0.01);
    r = set_vector_speed(&a, 5);
    cr_assert_float_eq(r.x, 3, 0.01);
    cr_assert_float_eq(r.y, 4, 0.01);
}
