/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-remi.mazat
** File description:
** put_nb_float
*/

int my_put_nbr(int nb, int fd);

int my_putchar(char c, int fd);

int nbrlencmp(float reste, int toprintrest)
{
    if (toprintrest == 0)
        return 0;
    while (toprintrest <= 10) {
        toprintrest = toprintrest * 10;
        reste = reste * 10;
    }
    for (int i = 10; toprintrest / i >= 1; i = i * 10) {
        if (toprintrest / i >= 10 && reste / i < 10) {
            return 1;
        }
    }
    return 0;
}

int put(int deci, int toprintrest, int compteur, int fd)
{
    compteur += my_put_nbr(deci, fd);
    compteur += my_putchar('.', fd);
    compteur += my_put_nbr(toprintrest, fd);
    return compteur;
}

int rounding(int deci, float reste, int compteur, int fd)
{
    int toprintrest = reste;
    if ((reste * 10) - (toprintrest * 10) >= 5) {
        toprintrest = toprintrest + 1;
        }
        int n = nbrlencmp(reste, toprintrest);
        if (n == 1) {
            toprintrest = 0 ;
            deci = deci + 1;
        }
    compteur = put(deci, toprintrest, compteur, fd);
    return compteur;
}

int my_float(int prec, double n, int fd)
{
    int compteur = 0;
    if (n < 0) {
        my_putchar('-', fd);
        n = -n;
    }
    int deci = n;
    float reste = n - deci;
    for (int i = 0;i < prec; i++) {
        reste = reste * 10;
    }
    compteur = rounding(deci, reste, compteur, fd);
    return compteur;
}
