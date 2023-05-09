/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** index
*/

#include "game.h"

void display_window(game_t *game);
void display_start_menu(game_t *game);
void change_to_game(game_t *game);
void display_perso(game_t *game);
void change_map(game_t *game);
void display_dialog(game_t *game);
void display_options(game_t *game);
void display_save(game_t *game);
void display_inventory(game_t *game);
void display_overlay(game_t *game);
void display_menu(game_t *game);
void display_iso_map(game_t *game);
void display_clients (game_t *game);
void display_mobs (game_t *game);
void display_npc(game_t *game);
void display_end(game_t *game);

void display_all(game_t *game)
{
    sfRenderWindow_clear(game->window->window, (sfColor){85, 61, 51, 255});
    sfRenderWindow_setFramerateLimit(game->window->window, game->params->fps);
    display_window(game);
    display_start_menu(game);
    change_to_game(game);
    sfRenderWindow_setTitle(game->window->window, game->window->title);
    display_perso(game);
    change_map(game);
    display_dialog(game);
    display_iso_map(game);
    display_save(game);
    display_inventory(game);
    display_menu(game);
    display_options(game);
    display_clients(game);
    display_mobs(game);
    display_overlay(game);
    display_npc(game);
    display_end(game);
    sfRenderWindow_display(game->window->window);
}
