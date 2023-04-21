/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** mobs
*/

#include <math.h>

#include "game.h"

void move_ennemi (game_t *game, int mob_index, sfVector2f offset,
sfVector2f mob_pos);

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

void win_perso(game_t *game, mobs_t *mob)
{
    if (sfKeyboard_isKeyPressed(game->keys->attack) &&
        mob->distance_to_player < 50) {
        mob->is_alive = sfFalse;
        game->perso->combat->defense += 1;
        game->perso->combat->life += 10;
        game->perso->combat->attack += 1;
        game->perso->combat->strength += 5;
    }
    if (game->perso->combat->life > 100)
        game->perso->combat->life = 100;
}

void anime_ennemie(mobs_t *mob)
{
    if (sfClock_getElapsedTime
        (mob->clock_anime).microseconds / 1000000.0 > 0.7) {
        mob->TextureRect.left += 40;
        if (mob->TextureRect.left >= 70)
            mob->TextureRect.left = 0;
        sfClock_restart(mob->clock_anime);
    }
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
        if (game->mobs[i]->state == Attacking
        && game->mobs[i]->distance_to_player < 70 && sfClock_getElapsedTime
        (game->mobs[i]->clock).microseconds / 1000000.0 > 1.0) {
            game->perso->combat->life -= 10 - game->perso->combat->defense;
            sfClock_restart(game->mobs[i]->clock);
        }
        anime_ennemie(game->mobs[i]);
        win_perso(game, game->mobs[i]);
    }
}
