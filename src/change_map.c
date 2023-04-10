/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** change_map
*/

#include "game.h"

void change_map(game_t *game)
{
    if (game->menu == 1) {
        if (game->perso->pos.x > game->map->rect.width * 3 - 32) {
            game->map->rect.left += game->map->rect.width / 2;
            game->perso->pos.x = (game->map->rect.width * 3) / 2;
        }
        if (game->perso->pos.x < 0 - 32) {
            game->map->rect.left -= game->map->rect.width / 2;
            game->perso->pos.x = (game->map->rect.width * 3) / 2;
        }
        if (game->perso->pos.y > game->map->rect.height * 3 - 32) {
            game->map->rect.top += game->map->rect.height / 2;
            game->perso->pos.y = (game->map->rect.height * 3) / 2;
        }
        if (game->perso->pos.y < 0 - 32) {
            game->map->rect.top -= game->map->rect.height / 2;
            game->perso->pos.y = (game->map->rect.height * 3) / 2;
        }
        sfSprite_setTextureRect(game->map->sprite, game->map->rect);
    }
}
