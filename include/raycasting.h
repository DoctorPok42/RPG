/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** raycasting
*/

#ifndef _RAYCASTING_H_
    #define _RAYCASTING_H_

    #include "game.h"

    #define PI 3.14159265358979323846

    typedef struct {
        int sprite;
        sfIntRect texture_rect;
        sfColor color;
        sfVector2f position;
        sfVector2f size;
        float distance;
        int x_detect;
        int y_detect;
        float depth;
        float form_height;
        float brightness;
    } ray_t;

    typedef struct {
        int width;
        int height;
        int *map;
    } raycast_map_t;

    typedef struct {
        sfVector2f position;
        float direction;
        float pitch;
    } raycasting_player_t;

    typedef struct {
        sfVector2f position;
        sfSprite *sprite;
        sfIntRect dimensions;
        int map;
        sfTexture *texture;
        double distance;
        float form_height;
        float depth;
        float angle;
        bool is_drawn;
    } entity_t;

    typedef struct {
        ray_t **rays;
        int fov;
        int resolution;
        int sensitivity;
        int speed;
        sfTexture **textures;
        sfRectangleShape *wall_shape;
        raycast_map_t *maps;
        int selected_map;
        raycasting_player_t *player;
        int nb_rays;
        entity_t **entities;
    } raycasting_t;

#endif /*_RAYCASTING_H_*/
