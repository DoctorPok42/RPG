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
    if (sfKeyboard_isKeyPressed(game->keys->left) ||
    sfKeyboard_isKeyPressed(game->keys->right))
        speed = 2.8;

    sfVector2f pos = game->perso->pos;

    if (sfKeyboard_isKeyPressed(game->keys->up) &&
    is_colliding(game, (sfVector2f){pos.x, pos.y - 4},
    (sfVector2f) {45, 50}) == 0) {
        game->perso->pos.y -= speed;
        game->perso->rect.top = 18;
        game->perso->move = 1; game->perso->direction = 1;
    } else if (sfKeyboard_isKeyPressed(game->keys->down) &&
    is_colliding(game, (sfVector2f){pos.x, pos.y + 4},
    (sfVector2f) {45, 50}) == 0) {
        game->perso->pos.y += speed;
        game->perso->rect.top = 0;
        game->perso->move = 1; game->perso->direction = 2;
    }
}

void move_player_horizontal (game_t *game)
{
    float speed = game->perso->combat->speed;
    if (sfKeyboard_isKeyPressed(game->keys->up) ||
    sfKeyboard_isKeyPressed(game->keys->down))
        speed = 2.8;

    sfVector2f pos = game->perso->pos;

    if (sfKeyboard_isKeyPressed(game->keys->left) &&
    is_colliding(game, (sfVector2f){pos.x - 4, pos.y},
    (sfVector2f) {45, 50}) == 0) {
        game->perso->pos.x -= speed;
        game->perso->rect.top = 36;
        game->perso->move = 1; game->perso->direction = 3;
    } else if (sfKeyboard_isKeyPressed(game->keys->right) &&
    is_colliding(game, (sfVector2f){pos.x + 4, pos.y},
    (sfVector2f) {45, 50}) == 0) {
        game->perso->pos.x += speed;
        game->perso->rect.top = 54;
        game->perso->move = 1; game->perso->direction = 4;
    }
}

void anime_player(game_t *game)
{
    game->perso->time = sfClock_getElapsedTime(game->perso->clock);
    game->perso->seconds = game->perso->time.microseconds / 1000000.0;
    if (game->perso->seconds > 0.08) {
        game->perso->rect.left += 18;
        if (game->perso->rect.left >= 36)
            game->perso->rect.left = 0;
        sfClock_restart(game->perso->clock);
    }
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
    }
    sfVector2f player_pos2 = (sfVector2f){game->perso->pos.x +
        (game->map->rect.left * 3), game->perso->pos.y +
        (game->map->rect.top * 3)};
    sfVector2f room_pos = (sfVector2f){6590, 1408};
    float diff = sqrt(pow(player_pos2.x - room_pos.x, 2) + pow(player_pos2.y -
    room_pos.y, 2));

    if (diff < 30) {
        game->perso->pos.y -= 2000;

    sfSprite_setPosition(game->perso->sprite, game->perso->pos);
    sfRenderWindow_drawSprite(game->window->window, game->perso->sprite, NULL);
}
