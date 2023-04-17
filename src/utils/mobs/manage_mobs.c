/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** mobs
*/

#include <math.h>

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

void move_ennemi (game_t *game, int mob_index, sfVector2f offset,
sfVector2f mob_pos)
{
    offset = set_vector_speed(offset, 2);

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

sfVector2f update_and_draw_ennemy (game_t *game, int i)
{
    sfVector2f mob_pos = game->mobs[i]->pos;
    mob_pos.x -= game->map->rect.left * 3;
    mob_pos.y -= game->map->rect.top * 3;

    game->mobs[i]->distance_to_player = sqrt(pow(game->perso->pos.x +
    (game->mobs[i]->TextureRect.width / 2.0) - mob_pos.x,
    game->mobs[i]->speed) + pow(game->perso->pos.y + (game->mobs[i]->
    TextureRect.height / 2.0) - mob_pos.y, game->mobs[i]->speed));

    sfSprite_setPosition(game->mobs[i]->sprite, mob_pos);
    sfSprite_setTextureRect(game->mobs[i]->sprite,
    game->mobs[i]->TextureRect);


    return mob_pos;
}

void change_ennemi_status (game_t *game, int i)
{
    if (game->mobs[i]->state != Attacking &&
    game->mobs[i]->distance_to_player < 300)
        game->mobs[i]->state = Attacking;

    if (game->mobs[i]->state == Attacking
    && game->mobs[i]->distance_to_player > 500)
        game->mobs[i]->state = Neutral;
}

void manage_mobs (game_t *game)
{
    for (int i = 0; game->mobs[i] != NULL; i++) {
        if (game->mobs[i]->is_alive == sfFalse)
            continue;

        sfVector2f mob_pos = update_and_draw_ennemy(game, i);
        change_ennemi_status(game, i);

        if (game->mobs[i]->state == Attacking
        && game->mobs[i]->distance_to_player > 50) {
            sfVector2f offset = {game->perso->pos.x + 22 - mob_pos.x,
            game->perso->pos.y + 25 - mob_pos.y};

            move_ennemi(game, i, offset, mob_pos);
        }

    }
}
