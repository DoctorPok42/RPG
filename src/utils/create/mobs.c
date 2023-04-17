/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** init_mobs
*/

#include "game.h"

void add_mob (game_t *game, sfVector2f pos, sfIntRect texture_rec,
sfTexture *texture)
{
    int mob_index = 0;

    for (;game->mobs[mob_index] != NULL; mob_index++);
    game->mobs[mob_index + 1] = NULL;

    game->mobs[mob_index] = malloc(sizeof(mobs_t));
    game->mobs[mob_index]->clock = sfClock_create();
    game->mobs[mob_index]->pos = pos;
    game->mobs[mob_index]->speed = 2;
    game->mobs[mob_index]->is_alive = sfTrue;
    game->mobs[mob_index]->state = Neutral;
    game->mobs[mob_index]->TextureRect = texture_rec;
    game->mobs[mob_index]->sprite = sfSprite_create();
    sfSprite_setTexture(game->mobs[mob_index]->sprite, texture, 0);
}

void create_mobs (game_t *game)
{
    game->mobs = malloc(sizeof(mobs_t *) * 100);
    game->mobs[0] = NULL;

    sfTexture *texture = sfTexture_createFromFile("assets/imgs/mobs.png", NULL);

    add_mob(game, (sfVector2f) {1000, 500}, (sfIntRect)
    {10, 20, 25, 25}, texture);

    add_mob(game, (sfVector2f) {1100, 600}, (sfIntRect)
    {10, 20, 25, 25}, texture);
}
