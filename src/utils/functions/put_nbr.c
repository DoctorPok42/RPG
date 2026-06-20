/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-remi.mazat
** File description:
** put_nbr
*/

#include <unistd.h>
#include "my_str.h"

int my_putchar(char c, int fd)
{
    return write(fd, &c, 1);
}

int my_put_nbr(int value, int fd)
{
    long nb = value;
    int count = 0;

    if (nb < 0) {
        count += my_putchar('-', fd);
        nb = -nb;
    }
    if (nb >= 10)
        count += my_put_nbr(nb / 10, fd);
    count += my_putchar('0' + nb % 10, fd);
    return count;
}
