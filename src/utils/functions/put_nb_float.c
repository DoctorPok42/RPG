/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-remi.mazat
** File description:
** put_nb_float
*/

#include "my_str.h"

int my_float(int prec, double n, int fd)
{
    long int_part = 0;
    long scale = 1;
    int count = 0;
    int i = 0;

    if (n < 0) {
        my_putchar('-', fd);
        n = -n;
    }
    int_part = (long)n;
    for (i = 0; i < prec; i++)
        scale *= 10;
    count += my_put_nbr((int)int_part, fd);
    my_putchar('.', fd);
    count += my_put_nbr((int)((n - (double)int_part) * scale), fd);
    return count;
}
