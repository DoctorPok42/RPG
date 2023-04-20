/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** raycasting
*/

#include "game.h"

raycast_map_t *get_map (char *path);
int create_entities (game_t *game);

int create_maps (game_t *game)
{
    game->raycasting->selected_map = 0;

    game->raycasting->maps = malloc(sizeof(map_t *) * 3);
    if (game->raycasting->maps == NULL)
        return -1;

    game->raycasting->maps[0] = *get_map("assets/maps/map");
    game->raycasting->maps[1] = *get_map("assets/maps/map2");

    return 0;
}

int create_rays (game_t *game)
{
    game->raycasting->nb_rays = game->raycasting->fov *
    game->raycasting->resolution;
    game->raycasting->rays = malloc(sizeof(ray_t *) *
    (game->raycasting->nb_rays + 1));

    if (game->raycasting->rays == NULL)
        return -1;

    for (int i = 0; i < game->raycasting->nb_rays; i++) {
        game->raycasting->rays[i] = malloc(sizeof(ray_t));
        if (game->raycasting->rays[i] == NULL)
            return -1;
    }

    game->raycasting->rays[game->raycasting->nb_rays] = NULL;

    return 0;
}

int create_textures (game_t *game)
{
    game->raycasting->wall_shape = sfRectangleShape_create();
    if (game->raycasting->wall_shape == NULL)
        return -1;

    game->raycasting->textures = malloc(sizeof(sfTexture *) * 5);
    if (game->raycasting->textures == NULL)
        return -1;

    game->raycasting->textures[0] =
    sfTexture_createFromFile("assets/imgs/brick.png", 0);
    if (game->raycasting->textures[0] == NULL)
        return -1;

    game->raycasting->textures[1] =
    sfTexture_createFromFile("assets/imgs/grass.jpeg", 0);
    if (game->raycasting->textures[1] == NULL)
        return -1;

    return 0;
}

int create_player (game_t *game)
{
    game->raycasting->player = malloc(sizeof(raycasting_player_t));
    if (game->raycasting->player == NULL)
        return -1;

    game->raycasting->player->position = (sfVector2f) {400, 400};
    game->raycasting->player->direction = -30;
    game->raycasting->player->pitch = 0;

    game->raycasting->fov = 60;
    game->raycasting->resolution = 5;
    game->raycasting->sensitivity = 5;
    game->raycasting->speed = 5;

    return 0;
}

int create_raycasting (game_t *game)
{
    game->is_raycasting = false;
    game->raycasting = malloc(sizeof(raycasting_t));
    if (game->raycasting == NULL)
        return -1;

    if (create_textures(game) == -1)
        return -1;
    if (create_maps(game) == -1)
        return -1;
    if (create_player(game) == -1)
        return -1;
    if (create_rays(game) == -1)
        return -1;
    if (create_entities(game) == -1)
        return -1;

    return 0;
}
