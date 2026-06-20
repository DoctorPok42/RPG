/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** movement
*/

#include <math.h>
#include <stdbool.h>

#include "game.h"
#include "collisions.h"
#include "mobs_functions.h"

static bool are_vectors_colliding(const sfVector2f *a, const sfVector2f *b)
{
    return sqrt(pow(a->x - b->x, 2) + pow(a->y - b->y, 2)) < 25;
}

static bool is_mob_colliding_with_other_mob(game_t *game, int idx,
    const sfVector2f *offset)
{
    sfVector2f target = {game->mobs[idx]->pos.x + offset->x,
        game->mobs[idx]->pos.y + offset->y};
    int i = 0;

    for (i = 0; game->mobs[i] != NULL; i++) {
        if (i == idx)
            continue;
        if (are_vectors_colliding(&game->mobs[i]->pos, &target))
            return true;
    }
    return false;
}

static void move_ennemy_while_colliding(game_t *game, int idx,
    const sfVector2f *offset, const sfVector2f *mob_pos)
{
    mobs_t *mob = game->mobs[idx];
    sfVector2f dim = {mob->TextureRect.size.x, mob->TextureRect.size.y};
    sfVector2f hx = {mob_pos->x + offset->x, mob_pos->y};
    sfVector2f hy = {mob_pos->x, mob_pos->y + offset->y};

    if (is_colliding(game, &hx, &dim) && !is_colliding(game, &hy, &dim))
        mob->pos.y += set_vector_speed(offset, 4).y > 0 ? mob->speed
            : -mob->speed;
    if (!is_colliding(game, &hx, &dim) && is_colliding(game, &hy, &dim))
        mob->pos.x += set_vector_speed(offset, 4).x > 0 ? mob->speed
            : -mob->speed;
}

void move_ennemi(game_t *game, int mob_index, const sfVector2f *offset,
    const sfVector2f *mob_pos)
{
    mobs_t *mob = game->mobs[mob_index];
    sfVector2f off = set_vector_speed(offset, 2);
    sfVector2f dim = {mob->TextureRect.size.x, mob->TextureRect.size.y};
    sfVector2f next = {mob_pos->x + off.x, mob_pos->y + off.y};

    if (is_mob_colliding_with_other_mob(game, mob_index, &off))
        return;
    if (!is_colliding(game, &next, &dim)) {
        mob->pos.x += off.x;
        mob->pos.y += off.y;
    } else
        move_ennemy_while_colliding(game, mob_index, &off, mob_pos);
}
