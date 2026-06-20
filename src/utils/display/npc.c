/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** npc
*/

#include <math.h>

#include "game.h"
#include "display.h"
#include "menu.h"
#include "input.h"

static void try_interact(game_t *game, int i)
{
    quest_t *quest = game->game_menu->quest;

    game->menu = MENU_GAME;
    diplay_text(game, game->npc[i]->dialog);
    if (game->npc[i]->dialog_index != 0
        && game->npc[i]->dialog_index > quest->nb_achievement)
        quest->nb_achievement = game->npc[i]->dialog_index;
}

static void get_distance(game_t *game, int i, const sfVector2f *second_pos)
{
    float dx = game->perso->pos.x + game->npc[i]->rect.size.x / 2.0
        - second_pos->x;
    float dy = game->perso->pos.y + game->npc[i]->rect.size.y / 2.0
        - second_pos->y;

    game->npc[i]->distance_to_player = sqrt(pow(dx, 2) + pow(dy, 2));
    if (game->npc[i]->distance_to_player < 100
        && is_key_held(game, game->keys->interact))
        try_interact(game, i);
}

void display_npc(game_t *game)
{
    sfVector2f second_pos = {0};
    int i = 0;

    if (!menu_in_overworld(game))
        return;
    for (i = 0; i < 7; i++) {
        second_pos = (sfVector2f){game->npc[i]->pos.x * 3
            - game->map->rect.position.x * 3, game->npc[i]->pos.y * 3
            - game->map->rect.position.y * 3};
        get_distance(game, i, &second_pos);
        sfSprite_setPosition(game->npc[i]->sprite, second_pos);
        sfRenderWindow_drawSprite(game->window->window,
            game->npc[i]->sprite, NULL);
    }
}
