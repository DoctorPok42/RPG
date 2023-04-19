/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** movement
*/

#include <math.h>
#include <stdbool.h>

#include "game.h"

int is_colliding(game_t *game, sfVector2f pos, sfVector2f offset);
sfVector2f set_vector_speed (sfVector2f vec, float speed);

void move_ennemy_while_colliding (game_t *game, int mob_index,
sfVector2f offset, sfVector2f mob_pos)
{
    sfVector2f mob_dim = (sfVector2f) {game->mobs[mob_index]->TextureRect.width,
    game->mobs[mob_index]->TextureRect.height};

    if (is_colliding(game, (sfVector2f) {mob_pos.x + offset.x, mob_pos.y},
    mob_dim) && !is_colliding(game, (sfVector2f) {mob_pos.x , mob_pos.y +
    offset.y}, mob_dim)) {

        if (set_vector_speed(offset, 4).y > 0)
            game->mobs[mob_index]->pos.y += game->mobs[mob_index]->speed;
        else
            game->mobs[mob_index]->pos.y -= game->mobs[mob_index]->speed;
    } if (!is_colliding(game, (sfVector2f) {mob_pos.x + offset.x, mob_pos.y},
    mob_dim) && is_colliding(game, (sfVector2f) {mob_pos.x , mob_pos.y +
    offset.y}, mob_dim)) {

        if (set_vector_speed(offset, 4).x > 0)
            game->mobs[mob_index]->pos.x += game->mobs[mob_index]->speed;
        else
            game->mobs[mob_index]->pos.x -= game->mobs[mob_index]->speed;
    }
}

bool are_vectors_colliding (sfVector2f vec1, sfVector2f vec2)
{
    if (sqrt(pow(vec1.x - vec2.x, 2) + pow(vec1.y - vec2.y, 2)) < 25)
        return true;

    return false;
}

bool is_mob_colliding_with_other_mob (game_t *game, int mob_index,
sfVector2f offset)
{
    for (int i = 0; game->mobs[i] != NULL; i++) {
        if (i == mob_index)
            continue;

        if (are_vectors_colliding(game->mobs[i]->pos,
        (sfVector2f) {game->mobs[mob_index]->pos.x + offset.x,
        game->mobs[mob_index]->pos.y + offset.y})) {
            offset = set_vector_speed(offset, 0);
            return true;
        }
    }

    return false;
}

void move_ennemi (game_t *game, int mob_index, sfVector2f offset,
sfVector2f mob_pos)
{
    offset = set_vector_speed(offset, 2);

    if (is_mob_colliding_with_other_mob(game, mob_index, offset))
        return;

    sfVector2f mob_dim = (sfVector2f) {game->mobs[mob_index]->TextureRect.width,
    game->mobs[mob_index]->TextureRect.height};

    if (!is_colliding(game, (sfVector2f) {mob_pos.x + offset.x
    , mob_pos.y + offset.y }, mob_dim)) {
        game->mobs[mob_index]->pos.x += offset.x ;
        game->mobs[mob_index]->pos.y += offset.y ;
    } else {
        move_ennemy_while_colliding(game, mob_index, offset, mob_pos);
    }
}
