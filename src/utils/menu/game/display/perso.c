/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** perso
*/

#include "lists.h"

void move_player_vertical (menu_t *menu);
void move_player_horizontal (menu_t *menu);

sfClock *create_clock(void)
{
    sfClock *clock = sfClock_create();
    return clock;
}

void anime_player(game_t *game)
{
    menu_t *menu = game->menu[1];
    menu->perso->time = sfClock_getElapsedTime(menu->perso->clock);
    menu->perso->seconds = menu->perso->time.microseconds / 1000000.0;
    if (menu->perso->seconds > 0.1) {
        menu->perso->rect.left += 275;
        if (menu->perso->rect.left >= 900)
            menu->perso->rect.left = 0;
        sfClock_restart(menu->perso->clock);
    }
    sfSprite_setTextureRect(menu->perso->sprite, menu->perso->rect);
}

void display_perso(game_t *game)
{
    menu_t *menu = game->menu[1];
    move_player_horizontal(game->menu[1]);
    move_player_vertical(game->menu[1]);
    if (menu->perso->move == 1) {
        anime_player(game);
        menu->perso->move = 0;
    }
    sfSprite_setPosition(menu->perso->sprite, menu->perso->pos);
    sfRenderWindow_drawSprite(menu->window, menu->perso->sprite, NULL);
}
