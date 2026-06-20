/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** raycasting_functions
*/

#ifndef RAYCASTING_FUNCTIONS_H_
    #define RAYCASTING_FUNCTIONS_H_

    #include "game.h"

int raycasting(game_t *game);
void move_raycasting_player(game_t *game);
void get_wall(game_t *game, float i);
void define_wall(game_t *game, float i);
void sort_walls_by_distance(game_t *game);
void calculate_entity_form(game_t *game, entity_t *entity);
raycast_map_t *get_map(char *path);
int raycast_cell(const raycast_map_t *map, int col, int row);

#endif /* !RAYCASTING_FUNCTIONS_H_ */
