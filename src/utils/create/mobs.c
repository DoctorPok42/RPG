/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** init_mobs
*/

#include "game.h"

void add_type(game_t *game, int i, sfIntRect texture_rec)
{
    if (texture_rec.width == 50) {
        game->mobs[i]->mob_type = 1;
        game->mobs[i]->combat->life = 100;
        game->mobs[i]->left_display = 52;
        game->mobs[i]->combat->attack = 20;
    } else {
        game->mobs[i]->mob_type = 0;
        game->mobs[i]->left_display = 40;
    }
}

void add_mob (game_t *game, sfVector2f pos, sfIntRect texture_rec,
sfTexture *texture)
{
    int mob_index = 0;
    pos.x *= 3;
    pos.y *= 3;
    for (;game->mobs[mob_index] != NULL; mob_index++);
    game->mobs[mob_index + 1] = NULL;
    game->mobs[mob_index] = malloc(sizeof(mobs_t));
    game->mobs[mob_index]->clock = sfClock_create();
    game->mobs[mob_index]->clock_anime = sfClock_create();
    game->mobs[mob_index]->pos = pos;
    game->mobs[mob_index]->speed = 2;
    game->mobs[mob_index]->is_alive = sfTrue;
    game->mobs[mob_index]->state = Neutral;
    game->mobs[mob_index]->TextureRect = texture_rec;
    game->mobs[mob_index]->sprite = sfSprite_create();
    game->mobs[mob_index]->combat = malloc(sizeof(mob_combat_t));
    game->mobs[mob_index]->combat->attack = rand() % 5 + 8;
    game->mobs[mob_index]->combat->life = rand() % 10 + 20;
    add_type(game, mob_index, texture_rec);
    sfSprite_setScale(game->mobs[mob_index]->sprite, (sfVector2f) {2.5, 2.5});
    sfSprite_setTexture(game->mobs[mob_index]->sprite, texture, 0);
}

void create_second_zone_mobs(game_t *game, sfIntRect betterfly,
    sfTexture *texture)
{
    add_mob(game, (sfVector2f) {810, 100}, betterfly, texture);
    add_mob(game, (sfVector2f) {810, 360}, betterfly, texture);
    add_mob(game, (sfVector2f) {600, 515}, betterfly, texture);
    add_mob(game, (sfVector2f) {570, 290}, betterfly, texture);
    add_mob(game, (sfVector2f) {340, 200}, betterfly, texture);
    add_mob(game, (sfVector2f) {150, 430}, betterfly, texture);
    add_mob(game, (sfVector2f) {170, 560}, betterfly, texture);

    add_mob(game, (sfVector2f) {2215, 1100}, betterfly, texture);
    add_mob(game, (sfVector2f) {2300, 1050}, betterfly, texture);
    add_mob(game, (sfVector2f) {2170, 1300}, betterfly, texture);
    add_mob(game, (sfVector2f) {1330, 1250}, betterfly, texture);

    add_mob(game, (sfVector2f) {2190, 300}, (sfIntRect) {205, 0, 50, 70},
        texture);
    add_mob(game, (sfVector2f) {2030, 495}, betterfly, texture);
    add_mob(game, (sfVector2f) {1990, 220}, betterfly, texture);
    add_mob(game, (sfVector2f) {2430, 150}, betterfly, texture);
    add_mob(game, (sfVector2f) {2440, 390}, betterfly, texture);
}

void create_mobs (game_t *game)
{
    game->mobs = malloc(sizeof(mobs_t *) * 100);
    game->mobs[0] = NULL;

    sfTexture *texture = sfTexture_createFromFile("assets/imgs/mobs.png", NULL);
    sfIntRect betterfly = {5, 70, 33, 40};

    add_mob(game, (sfVector2f) {1000, 1300}, betterfly, texture);
    add_mob(game, (sfVector2f) {1160, 1100}, betterfly, texture);
    add_mob(game, (sfVector2f) {1230, 930}, betterfly, texture);
    add_mob(game, (sfVector2f) {1160, 650}, betterfly, texture);
    add_mob(game, (sfVector2f) {1000, 650}, betterfly, texture);
    add_mob(game, (sfVector2f) {1708, 930}, betterfly, texture);
    add_mob(game, (sfVector2f) {1638, 840}, betterfly, texture);
    add_mob(game, (sfVector2f) {1708, 530}, betterfly, texture);
    add_mob(game, (sfVector2f) {1530, 550}, betterfly, texture);
    add_mob(game, (sfVector2f) {1708, 215}, betterfly, texture);
    add_mob(game, (sfVector2f) {1530, 135}, betterfly, texture);
    add_mob(game, (sfVector2f) {1105, 448}, betterfly, texture);
    add_mob(game, (sfVector2f) {1083, 215}, betterfly, texture);
    create_second_zone_mobs(game, betterfly, texture);
}
