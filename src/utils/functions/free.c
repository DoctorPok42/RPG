/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** free
*/

#include "game.h"
int free_tab(char **tab);
void free_game_menu2(game_t *game);
void free_save(game_t *game);
void free_params(game_t * game);

void free_game_menu(game_t *game)
{
    sfRectangleShape_destroy(game->game_menu->container);
    sfFont_destroy(game->game_menu->font);
    for (int i = 0; i < 3; i++) {
        sfText_destroy(game->game_menu->title[i]);
        free(game->game_menu->title[i]);
    }
    free(game->game_menu->title);
    sfRectangleShape_destroy(game->game_menu->sidebar->container);
    for (int i = 0; i < 5; i++) {
        sfRectangleShape_destroy(game->game_menu->sidebar->buttons[i]->rect);
        sfText_destroy(game->game_menu->sidebar->buttons[i]->text);
        free(game->game_menu->sidebar->buttons[i]);
    }
    free(game->game_menu->sidebar->buttons);
    free(game->game_menu->sidebar);
    free_game_menu2(game);
}

void do_free2(game_t *game)
{
    free(game->keys);
    sfClock_destroy(game->clock->clock);
    free(game->clock);
    sfTexture_destroy(game->perso->texture);
    sfSprite_destroy(game->perso->sprite);
    free(game->perso->combat);
    sfClock_destroy(game->perso->clock);
    free(game->perso);
    if (game->network != NULL) {
        sfTexture_destroy(sfSprite_getTexture(game->network->client_sprite));
        sfSprite_destroy(game->network->client_sprite);
        free(game->network->clients); free(game->network);
    }
    sfView_destroy(game->window->view);
    sfMusic_destroy(game->window->song->music);
    free(game->window->song);
    sfTexture_destroy(sfRectangleShape_getTexture(game->window->rect[0]));
    sfRectangleShape_destroy(game->window->rect[0]);
    free(game->window->rect);
    free(game->window);
}

void do_free3(game_t *game)
{
    for (int i = 0; i < 4; i++) {
        sfSprite_destroy(game->start[i]->sprite);
        sfTexture_destroy(game->start[i]->texture);
        free(game->start[i]);
    }
    free(game->start);
    sfTexture_destroy(game->map->texture);
    sfTexture_destroy(game->map->iso_texture);
    sfSprite_destroy(game->map->iso_sprite);
    sfSprite_destroy(game->map->sprite);
    sfImage_destroy(game->map->colls_image);
    free(game->map);
    sfTexture_destroy(game->dialogs->texture);
    sfSprite_destroy(game->dialogs->sprite);
    sfText_destroy(game->dialogs->text);
    sfFont_destroy(game->dialogs->font);
    sfClock_destroy(game->dialogs->clock);
}

void do_free4(game_t *game)
{
    free(game->dialogs);
    sfTexture_destroy(game->go_back->texture);
    sfSprite_destroy(game->go_back->sprite);
    free(game->go_back);
    for (int i = 0; i < 3; i++) {
        sfRectangleShape_destroy(game->inventory->items[i]->container);
        sfRectangleShape_destroy(game->inventory->items[i]->content);
        free(game->inventory->items[i]);
    }
    free(game->inventory->items);
    free(game->inventory);
}

void do_free(game_t *game)
{
    free_params(game);
    do_free2(game);
    free_game_menu(game);
    free_save(game);
    do_free3(game);
    do_free4(game);
    sfRectangleShape_destroy(game->overlay->life->container);
    sfTexture_destroy(game->overlay->life->texture);
    sfSprite_destroy(game->overlay->life->sprite);
    sfRectangleShape_destroy(game->overlay->life->content);
    free(game->overlay->life);
    free(game->overlay);
    sfSprite_destroy(game->mobs[0]->sprite);
    for (int i = 0; game->mobs[i] != NULL; i++) {
        sfClock_destroy(game->mobs[i]->clock);
        sfSprite_destroy(game->mobs[i]->sprite);
        free(game->mobs[i]);
    }
    free(game->mobs);
    free(game);
}
