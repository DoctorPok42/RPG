/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** npc
*/

#include "game.h"
#include "create.h"

static const sfVector2f NPC_POS[7] = {
    {290, 1220}, {400, 1288}, {615, 1030}, {310, 915},
    {710, 1350}, {810, 850}, {600, 1288}};

static const sfIntRect NPC_RECT[7] = {
    {.position = {0, 0}, .size = {100, 100}},
    {.position = {105, 0}, .size = {100, 100}},
    {.position = {200, 0}, .size = {100, 100}},
    {.position = {290, 0}, .size = {100, 100}},
    {.position = {395, 0}, .size = {100, 100}},
    {.position = {0, 105}, .size = {100, 100}},
    {.position = {105, 100}, .size = {110, 110}}};

static const int NPC_DIALOG[7] = {0, 2, 0, 0, 0, 0, 1};

static void create_each_npc(game_t *game, int i)
{
    game->npc[i]->texture = sfTexture_createFromFile("assets/imgs/npc.png",
        NULL);
    game->npc[i]->sprite = sfSprite_create(game->npc[i]->texture);
    sfSprite_setTexture(game->npc[i]->sprite, game->npc[i]->texture, true);
    game->npc[i]->pos = NPC_POS[i];
    game->npc[i]->rect = NPC_RECT[i];
    sfSprite_setTextureRect(game->npc[i]->sprite, game->npc[i]->rect);
    sfSprite_setScale(game->npc[i]->sprite, (sfVector2f){0.75, 0.75});
    game->npc[i]->clock = sfClock_create();
    game->npc[i]->time = sfClock_getElapsedTime(game->npc[i]->clock);
    game->npc[i]->seconds = game->npc[i]->time.microseconds / 1000000.0;
    game->npc[i]->distance_to_player = 0;
    game->npc[i]->state = NPC_NONE;
    game->npc[i]->dialog_index = NPC_DIALOG[i];
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
    int i = 0;

    game->npc = malloc(sizeof(npc_t *) * 8);
    game->npc[7] = NULL;
    for (i = 0; i < 7; i++) {
        game->npc[i] = malloc(sizeof(npc_t));
        create_each_npc(game, i);
    }
    put_text(game);
}
