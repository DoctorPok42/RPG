/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** perso
*/

#include "game.h"

int is_colliding(game_t *game, sfVector2f pos, sfVector2f offset);

void move_player_vertical (game_t *game)
{
    float speed = game->perso->combat->speed;
    if (sfKeyboard_isKeyPressed(sfKeyLeft) ||
    sfKeyboard_isKeyPressed(sfKeyRight))
        speed = 2.8;

    sfVector2f pos = game->perso->pos;

    if (sfKeyboard_isKeyPressed(sfKeyUp) &&
    is_colliding(game, (sfVector2f){pos.x, pos.y - 4},
    (sfVector2f) {45, 50}) == 0) {
        game->perso->pos.y -= speed;
        game->perso->rect.top = 600;
        game->perso->move = 1; game->perso->direction = 1;
    } else if (sfKeyboard_isKeyPressed(sfKeyDown) &&
    is_colliding(game, (sfVector2f){pos.x, pos.y + 4},
    (sfVector2f) {45, 50}) == 0) {
        game->perso->pos.y += speed;
        game->perso->rect.top = 400;
        game->perso->move = 1; game->perso->direction = 2;
    }
}

void move_player_horizontal (game_t *game)
{
    float speed = game->perso->combat->speed;
    if (sfKeyboard_isKeyPressed(sfKeyUp) ||
    sfKeyboard_isKeyPressed(sfKeyDown))
        speed = 2.8;

    sfVector2f pos = game->perso->pos;

    if (sfKeyboard_isKeyPressed(sfKeyLeft) &&
    is_colliding(game, (sfVector2f){pos.x - 4, pos.y},
    (sfVector2f) {45, 50}) == 0) {
        game->perso->pos.x -= speed;
        game->perso->rect.top = 500;
        game->perso->move = 1; game->perso->direction = 3;
    } else if (sfKeyboard_isKeyPressed(sfKeyRight) &&
    is_colliding(game, (sfVector2f){pos.x + 4, pos.y},
    (sfVector2f) {45, 50}) == 0) {
        game->perso->pos.x += speed;
        game->perso->rect.top = 700;
        game->perso->move = 1; game->perso->direction = 4;
    }
}

void anime_player(game_t *game)
{
    game->perso->time = sfClock_getElapsedTime(game->perso->clock);
    game->perso->seconds = game->perso->time.microseconds / 1000000.0;
    if (game->perso->seconds > 0.1) {
        game->perso->rect.left += 275;
        if (game->perso->rect.left >= 900)
            game->perso->rect.left = 0;
        sfClock_restart(game->perso->clock);
    }
    sfSprite_setTextureRect(game->perso->sprite, game->perso->rect);
}

static void anime_unmove_player(game_t *game)
{
    if (game->perso->direction == 1)
        game->perso->rect.top = 200;
    if (game->perso->direction == 2)
        game->perso->rect.top = 0;
    if (game->perso->direction == 3)
        game->perso->rect.top = 100;
    if (game->perso->direction == 4)
        game->perso->rect.top = 300;

    game->perso->rect.left = 0;

    sfSprite_setTextureRect(game->perso->sprite, game->perso->rect);
}

void display_perso(game_t *game)
{
    if (game->menu < 5 || game->menu >= 10)
        return;

    move_player_horizontal(game);
    move_player_vertical(game);

    if (game->perso->move == 1) {
        anime_player(game);
        game->perso->move = 0;
    } else
        anime_unmove_player(game);
    sfSprite_setPosition(game->perso->sprite, game->perso->pos);
    sfRenderWindow_drawSprite(game->window->window, game->perso->sprite, NULL);
}
