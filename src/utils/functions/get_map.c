/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** get_map
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

#include "game.h"

int get_file_size (char *path)
{
    struct stat sb;

    if (stat(path, &sb) == -1)
        return -1;

    return sb.st_size;
}

char *read_file (char *path)
{
    int save = open(path, O_RDONLY);
    if (save == -1)
        return NULL;

    int save_size = get_file_size(path);
    if (save_size == -1)
        return NULL;

    char *buffer = malloc(sizeof(char) * save_size);
    memset(buffer, '\0', save_size);

    if (read(save, buffer, (size_t) save_size - 1) == -1)
        return NULL;

    if (close(save) == -1)
        return NULL;

    return buffer;
}

raycast_map_t *parse_map (char *buffer)
{
    int i = 0;
    raycast_map_t *map = malloc(sizeof(raycast_map_t));

    map->width = atoi(buffer);
    while (buffer[i] != '/')
        i++;
    i++;

    map->height = atoi(&buffer[i]);
    map->map = malloc(sizeof(int) * ((map->height * map->width) + 1));
    while (buffer[i] != '\n')
        i++;
    for (int x = 0; buffer[i] != '\0' && x < map->height *
    map->width; x++) {
        map->map[x] = atoi(&buffer[i]);
        while (buffer[i] != ',' && buffer[i] != '\0')
            i++;
        i++;
    }
    return map;
}

raycast_map_t *get_map (char *path)
{
    char *buffer = read_file(path);
    if (buffer == NULL)
        return NULL;

    raycast_map_t *map = parse_map(buffer);

    return map;
}
