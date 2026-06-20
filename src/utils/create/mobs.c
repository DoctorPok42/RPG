/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** init_mobs
*/

#include "game.h"
#include "create.h"

static const sfIntRect BETTERFLY = {.position = {5, 70}, .size = {33, 40}};

static const sfVector2f ZONE1_POS[13] = {
    {1000, 1300}, {1160, 1100}, {1230, 930}, {1160, 650}, {1000, 650},
    {1708, 930}, {1638, 840}, {1708, 530}, {1530, 550}, {1708, 215},
    {1530, 135}, {1105, 448}, {1083, 215}};

static const sfVector2f ZONE2_POS[11] = {
    {810, 100}, {810, 360}, {600, 515}, {570, 290}, {340, 200},
    {150, 430}, {170, 560}, {2215, 1100}, {2300, 1050}, {2170, 1300},
    {1330, 1250}};

static const sfVector2f ZONE3_POS[4] = {
    {2030, 495}, {1990, 220}, {2430, 150}, {2440, 390}};

static void add_type(game_t *game, int i, const sfIntRect *rect)
{
    if (rect->size.x == 50) {
        game->mobs[i]->mob_type = 1;
        game->mobs[i]->combat->life = 100;
        game->mobs[i]->left_display = 52;
        game->mobs[i]->combat->attack = 20;
    } else {
        game->mobs[i]->mob_type = 0;
        game->mobs[i]->left_display = 40;
    }
}

static void init_mob_stats(game_t *game, int idx, const sfIntRect *rect,
    sfTexture *texture)
{
    game->mobs[idx]->clock = sfClock_create();
    game->mobs[idx]->clock_anime = sfClock_create();
    game->mobs[idx]->speed = 2;
    game->mobs[idx]->is_alive = true;
    game->mobs[idx]->state = NEUTRAL;
    game->mobs[idx]->TextureRect = *rect;
    game->mobs[idx]->sprite = sfSprite_create(texture);
    game->mobs[idx]->combat = malloc(sizeof(mob_combat_t));
    game->mobs[idx]->combat->attack = rand() % 5 + 8;
    game->mobs[idx]->combat->life = rand() % 10 + 20;
    sfSprite_setScale(game->mobs[idx]->sprite, (sfVector2f){2.5, 2.5});
    sfSprite_setTexture(game->mobs[idx]->sprite, texture, 0);
}

static void add_mob(game_t *game, const sfVector2f *pos_in,
    const sfIntRect *rect, sfTexture *texture)
{
    int idx = 0;

    for (; game->mobs[idx] != NULL; idx++);
    game->mobs[idx + 1] = NULL;
    game->mobs[idx] = malloc(sizeof(mobs_t));
    game->mobs[idx]->pos = (sfVector2f){pos_in->x * 3, pos_in->y * 3};
    init_mob_stats(game, idx, rect, texture);
    add_type(game, idx, rect);
}

static void add_mob_batch(game_t *game, const sfVector2f *pos, int count,
    sfTexture *texture)
{
    int i = 0;

    for (i = 0; i < count; i++)
        add_mob(game, &pos[i], &BETTERFLY, texture);
}

void create_mobs(game_t *game)
{
    sfTexture *texture = sfTexture_createFromFile("assets/imgs/mobs.png", NULL);
    sfIntRect special = {.position = {205, 0}, .size = {50, 70}};
    sfVector2f special_pos = {2190, 300};

    game->mobs = malloc(sizeof(mobs_t *) * 100);
    game->mobs[0] = NULL;
    add_mob_batch(game, ZONE1_POS, 13, texture);
    add_mob_batch(game, ZONE2_POS, 11, texture);
    add_mob(game, &special_pos, &special, texture);
    add_mob_batch(game, ZONE3_POS, 4, texture);
}
