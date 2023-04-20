/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** npc
*/

#include "game.h"

static void create_each_npc(game_t *game, int i, sfVector2f pos, sfIntRect rect)
{
    game->npc[i]->texture = sfTexture_createFromFile("assets/imgs/npc.png",
        NULL);
    game->npc[i]->sprite = sfSprite_create();
    sfSprite_setTexture(game->npc[i]->sprite, game->npc[i]->texture, sfTrue);
    game->npc[i]->pos = pos;
    game->npc[i]->rect = rect;
    sfSprite_setTextureRect(game->npc[i]->sprite, game->npc[i]->rect);
    sfSprite_setScale(game->npc[i]->sprite, (sfVector2f){0.75, 0.75});
    game->npc[i]->clock = sfClock_create();
    game->npc[i]->time = sfClock_getElapsedTime(game->npc[i]->clock);
    game->npc[i]->seconds = game->npc[i]->time.microseconds / 1000000.0;
    game->npc[i]->distance_to_player = 0;
    game->npc[i]->state = None;
}

static void put_text(game_t *game)
{
    game->npc[0]->dialog = game->dialogs->dialog_text[3];
    game->npc[1]->dialog = game->dialogs->dialog_text[2];
    game->npc[2]->dialog = game->dialogs->dialog_text[4];
    game->npc[3]->dialog = game->dialogs->dialog_text[5];
    game->npc[4]->dialog = game->dialogs->dialog_text[6];
    game->npc[5]->dialog = game->dialogs->dialog_text[7];
    game->npc[6]->dialog = game->dialogs->dialog_text[1];
}

void create_npc(game_t *game)
{
    game->npc = malloc(sizeof(npc_t *) * 8);
    game->npc[7] = NULL;
    sfVector2f pos[7] = {
        (sfVector2f){290, 1220}, (sfVector2f){400, 1288},
        (sfVector2f){615, 1030}, (sfVector2f){310, 915},
        (sfVector2f){710, 1350}, (sfVector2f){810, 850},
        (sfVector2f){600, 1288}};
    sfIntRect rect[7] = {
        (sfIntRect){0, 0, 100, 100}, (sfIntRect){105, 0, 100, 100},
        (sfIntRect){200, 0, 100, 100}, (sfIntRect){290, 0, 100, 100},
        (sfIntRect){395, 0, 100, 100}, (sfIntRect){0, 105, 100, 100},
        (sfIntRect){105, 100, 110, 110}};

    int dialog_index[7] = {0, 2, 0, 0, 0, 0, 1};
    for (int i = 0; i < 7; i++) {
        game->npc[i] = malloc(sizeof(npc_t));
        create_each_npc(game, i, pos[i], rect[i]);
        game->npc[i]->dialog_index = dialog_index[i];
    }
    put_text(game);
}
