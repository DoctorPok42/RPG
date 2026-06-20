/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** tests for memory-safe map parsing
*/

#include <criterion/criterion.h>
#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include "raycasting_functions.h"

static void write_file(const char *path, const char *content)
{
    FILE *f = fopen(path, "w");

    fputs(content, f);
    fclose(f);
}

static void free_map(raycast_map_t *m)
{
    free(m->map);
    free(m);
}

Test(get_map, parses_a_valid_map)
{
    raycast_map_t *m = NULL;

    write_file("/tmp/cr_map_valid", "3/2\n1,2,3,4,5,6,");
    m = get_map("/tmp/cr_map_valid");
    cr_assert_not_null(m);
    cr_assert_eq(m->width, 3);
    cr_assert_eq(m->height, 2);
    cr_assert_eq(m->map[0], 1);
    cr_assert_eq(m->map[5], 6);
    free_map(m);
}

Test(get_map, rejects_malformed_and_missing)
{
    write_file("/tmp/cr_map_bad", "garbage_no_slash");
    cr_assert_null(get_map("/tmp/cr_map_bad"));
    cr_assert_null(get_map("/tmp/cr_does_not_exist_xyz"));
}

Test(get_map, truncated_map_zero_fills)
{
    raycast_map_t *m = NULL;

    write_file("/tmp/cr_map_trunc", "3/2\n7,8,");
    m = get_map("/tmp/cr_map_trunc");
    cr_assert_not_null(m);
    cr_assert_eq(m->map[0], 7);
    cr_assert_eq(m->map[2], 0);
    cr_assert_eq(m->map[5], 0);
    free_map(m);
}
