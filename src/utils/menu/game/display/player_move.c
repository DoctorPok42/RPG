/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** player_move
*/

#include "lists.h"

int is_colliding(menu_t *menu, sfVector2f pos);

void move_player_vertical (menu_t *menu)
{
    int speed = 4;
    if (sfKeyboard_isKeyPressed(sfKeyLeft) ||
    sfKeyboard_isKeyPressed(sfKeyRight))
        speed = 3;

    sfVector2f pos = menu->perso->pos;
    if (sfKeyboard_isKeyPressed(sfKeyUp) &&
    is_colliding(menu, (sfVector2f) {pos.x, pos.y - 4}) == 0) {
        menu->perso->pos.y -= speed;
        menu->perso->rect.top = 600;
        menu->perso->move = 1; menu->perso->direction = 1;
    } else if (sfKeyboard_isKeyPressed(sfKeyDown) &&
    is_colliding(menu, (sfVector2f) {pos.x, pos.y + 4}) == 0) {
        menu->perso->pos.y += speed;
        menu->perso->rect.top = 400;
        menu->perso->move = 1; menu->perso->direction = 2;
    }

}

void move_player_horizontal (menu_t *menu)
{
    int speed = 4;
    if (sfKeyboard_isKeyPressed(sfKeyUp) ||
    sfKeyboard_isKeyPressed(sfKeyDown))
        speed = 3;

    sfVector2f pos = menu->perso->pos;
    if (sfKeyboard_isKeyPressed(sfKeyLeft) &&
    is_colliding(menu, (sfVector2f) {pos.x - 4, pos.y}) == 0) {
        menu->perso->pos.x -= speed;
        menu->perso->rect.top = 500;
        menu->perso->move = 1; menu->perso->direction = 3;
    } else if (sfKeyboard_isKeyPressed(sfKeyRight) &&
    is_colliding(menu, (sfVector2f) {pos.x + 4, pos.y}) == 0) {
        menu->perso->pos.x += speed;
        menu->perso->rect.top = 700;
        menu->perso->move = 1; menu->perso->direction = 4;
    }
}
