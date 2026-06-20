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

#include "game.h"
#include "my_str.h"
#include "raycasting_functions.h"

static int get_file_size(char *path)
{
    struct stat sb;

    if (stat(path, &sb) == -1)
        return -1;
    return (int)sb.st_size;
}

static char *read_file(char *path)
{
    int fd = open(path, O_RDONLY);
    int size = get_file_size(path);
    char *buffer = NULL;

    if (fd == -1 || size <= 0)
        return NULL;
    buffer = malloc(sizeof(char) * (size + 1));
    if (buffer == NULL || read(fd, buffer, size) == -1) {
        free(buffer);
        close(fd);
        return NULL;
    }
    buffer[size] = '\0';
    close(fd);
    return buffer;
}

static int count_to_char(char *buffer, int i, char c)
{
    while (buffer[i] != '\0' && buffer[i] != c)
        i++;
    return i;
}

static raycast_map_t *fail_map(raycast_map_t *map)
{
    free(map);
    return NULL;
}

static int parse_dimensions(raycast_map_t *map, char *buffer)
{
    int slash = count_to_char(buffer, 0, '/');
    int nl = 0;

    if (buffer[slash] == '\0')
        return -1;
    map->width = my_getnbr(buffer);
    map->height = my_getnbr(&buffer[slash + 1]);
    if (map->width <= 0 || map->height <= 0)
        return -1;
    nl = count_to_char(buffer, slash, '\n');
    if (buffer[nl] == '\0')
        return -1;
    return nl + 1;
}

static void fill_map(raycast_map_t *map, char *buffer, int i)
{
    int total = map->width * map->height;
    int x = 0;

    for (x = 0; buffer[i] != '\0' && x < total; x++) {
        map->map[x] = my_getnbr(&buffer[i]);
        i = count_to_char(buffer, i, ',');
        i++;
    }
}

static raycast_map_t *parse_map(char *buffer)
{
    raycast_map_t *map = malloc(sizeof(raycast_map_t));
    int start = 0;

    if (map == NULL)
        return NULL;
    start = parse_dimensions(map, buffer);
    if (start == -1)
        return fail_map(map);
    map->map = calloc((size_t)(map->width * map->height), sizeof(int));
    if (map->map == NULL)
        return fail_map(map);
    fill_map(map, buffer, start);
    return map;
}

raycast_map_t *get_map(char *path)
{
    char *buffer = read_file(path);
    raycast_map_t *map = NULL;

    if (buffer == NULL)
        return NULL;
    map = parse_map(buffer);
    free(buffer);
    return map;
}
