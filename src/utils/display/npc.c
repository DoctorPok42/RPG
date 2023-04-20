/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** npc
*/

#include <math.h>
#include "game.h"

int diplay_text(game_t *game, char *str);

static void get_distance(game_t *game, int i, sfVector2f second_pos)
{
    game->npc[i]->distance_to_player = sqrt(pow(game->perso->pos.x +
        (game->npc[i]->rect.width / 2.0) - second_pos.x, 2) +
        pow(game->perso->pos.y + (game->npc[i]->rect.height / 2.0) -
        second_pos.y, 2));

    if (game->npc[i]->distance_to_player < 100 &&
        sfKeyboard_isKeyPressed(game->keys->interact)) {
            game->menu = 5;
            diplay_text(game, game->npc[i]->dialog);
            if (game->npc[i]->dialog_index != 0 &&
                game->npc[i]->dialog_index >
                game->game_menu->quest->nb_achievement)
                game->game_menu->quest->nb_achievement =
                game->npc[i]->dialog_index;
    }
}

void display_npc(game_t *game)
{
    if (game->menu < 5 || game->menu >= 10)
        return;

    for (int i = 0; i < 7; i++) {
        sfVector2f second_pos = {(game->npc[i]->pos.x * 3) -
            (game->map->rect.left * 3), (game->npc[i]->pos.y * 3) -
            (game->map->rect.top * 3)};
        get_distance(game, i, second_pos);
        sfSprite_setPosition(game->npc[i]->sprite, second_pos);
        sfRenderWindow_drawSprite(game->window->window,
        game->npc[i]->sprite, NULL);
    }
}
