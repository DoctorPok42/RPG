/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** perso
*/

#include "game.h"

void create_perso(game_t *game)
{
    game->perso->texture = sfTexture_createFromFile(
        "assets/imgs/perso.png", NULL);
    game->perso->sprite = sfSprite_create();
    sfSprite_setTexture(game->perso->sprite, game->perso->texture, sfTrue);
    sfSprite_setPosition(game->perso->sprite, (sfVector2f){0, 0});
    game->perso->pos = (sfVector2f) {760, 480};
    game->perso->rect = (sfIntRect){0, 0, 70, 85};
    sfSprite_setTextureRect(game->perso->sprite, game->perso->rect);
    sfSprite_setScale(game->perso->sprite, (sfVector2f){0.7, 0.7});
    game->perso->combat = malloc(sizeof(combat_t));
    game->perso->name = "Link";
    game->perso->combat->life = 100;
    game->perso->combat->attack = 10;
    game->perso->combat->defense = 5;
    game->perso->combat->speed = 4;
    game->perso->combat->level = 1;
    game->perso->combat->strength = 5;
}
