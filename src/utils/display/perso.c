/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** perso
*/

#include <math.h>

#include "game.h"
#include "collisions.h"
#include "display.h"
#include "menu.h"
#include "input.h"

static void set_perso_move(perso_t *perso, int rect_y, int dir)
{
    perso->rect.position.y = rect_y;
    perso->move = 1;
    perso->direction = dir;
}

static void move_player_vertical(game_t *game)
{
    perso_t *perso = game->perso;
    float speed = perso->combat->speed;
    sfVector2f pos = perso->pos;
    sfVector2f dim = {45, 50};

    if (is_key_held(game, game->keys->left)
        || is_key_held(game, game->keys->right))
        speed = 2.8;
    if (is_key_held(game, game->keys->up)
        && is_colliding(game, &(sfVector2f){pos.x, pos.y - 4}, &dim) == 0) {
        perso->pos.y -= speed;
        set_perso_move(perso, 18, 1);
    } else if (is_key_held(game, game->keys->down)
        && is_colliding(game, &(sfVector2f){pos.x, pos.y + 4}, &dim) == 0) {
        perso->pos.y += speed;
        set_perso_move(perso, 0, 2);
    }
}

static void move_player_horizontal(game_t *game)
{
    perso_t *perso = game->perso;
    float speed = perso->combat->speed;
    sfVector2f pos = perso->pos;
    sfVector2f dim = {45, 50};

    if (is_key_held(game, game->keys->up)
        || is_key_held(game, game->keys->down))
        speed = 2.8;
    if (is_key_held(game, game->keys->left)
        && is_colliding(game, &(sfVector2f){pos.x - 4, pos.y}, &dim) == 0) {
        perso->pos.x -= speed;
        set_perso_move(perso, 36, 3);
    } else if (is_key_held(game, game->keys->right)
        && is_colliding(game, &(sfVector2f){pos.x + 4, pos.y}, &dim) == 0) {
        perso->pos.x += speed;
        set_perso_move(perso, 54, 4);
    }
}

static void anime_player(game_t *game)
{
    perso_t *perso = game->perso;

    perso->time = sfClock_getElapsedTime(perso->clock);
    perso->seconds = perso->time.microseconds / 1000000.0;
    if (perso->seconds > 0.08) {
        perso->rect.position.x += 18;
        if (perso->rect.position.x >= 36)
            perso->rect.position.x = 0;
        sfClock_restart(perso->clock);
    }
    sfSprite_setTextureRect(perso->sprite, perso->rect);
}

static void check_room_teleport(game_t *game)
{
    perso_t *perso = game->perso;
    sfVector2f player_pos = {perso->pos.x + game->map->rect.position.x * 3,
        perso->pos.y + game->map->rect.position.y * 3};
    sfVector2f room_pos = {6590, 1408};
    float diff = sqrt(pow(player_pos.x - room_pos.x, 2)
        + pow(player_pos.y - room_pos.y, 2));

    if (diff < 30)
        perso->pos.y -= 2000;
}

void display_perso(game_t *game)
{
    perso_t *perso = game->perso;

    if (!menu_in_overworld(game))
        return;
    move_player_horizontal(game);
    move_player_vertical(game);
    if (perso->move == 1) {
        anime_player(game);
        perso->move = 0;
    }
    check_room_teleport(game);
    sfSprite_setPosition(perso->sprite, perso->pos);
    sfRenderWindow_drawSprite(game->window->window, perso->sprite, NULL);
}
